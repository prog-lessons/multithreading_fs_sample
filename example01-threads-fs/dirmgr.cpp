#include "dirmgr.hpp"
#include <filesystem>
#include <iostream>

using namespace std;

namespace _NS_fs = std::filesystem;

DirManager::~DirManager()
{
   this->obj_linked_thd->join();
   delete this->obj_linked_thd;
}

void DirManager::check_dirs()
{
   try
   {
      if (!(_NS_fs::exists("in")))
         _NS_fs::create_directory("in");

      if (!(_NS_fs::exists("out")))
         _NS_fs::create_directory("out");
   }
   catch (const exception &e)
   {
      cout << "Error on trying to create [in]/[out] directories." << endl;
      cerr << e.what() << endl;
      exit(EXIT_FAILURE);
   }
}

void DirManager::watching_task(string path)
{
   int files_count = this->count_items(path);

   while (!this->stop_flag)
   {
      this_thread::sleep_for(chrono::seconds(3));
      cout << "Monitoring [in] directory, interval 3 secs." << endl;

      if (this->count_items(path) > files_count)
         cout << "New file created." << endl;

      files_count = this->count_items(path);
   }

   cout << "Monitor finished." << endl;
}

bool DirManager::start_watching(string path)
{
   try
   {
      thread* obj_th = new thread(&DirManager::watching_task, this, path);

      this->obj_linked_thd = obj_th;

      return true;
   }
   catch (const std::exception &e)
   {
      std::cerr << e.what() << '\n';

      return false;
   }
}

void DirManager::stop_watching()
{
   this->stop_flag = true;
}

int DirManager::count_items(string path)
{
   int items = 0;

   for (auto& p : _NS_fs::directory_iterator(path))
   {
      if (_NS_fs::is_regular_file(p.path()))
         items++;
   }
   return items;
}
