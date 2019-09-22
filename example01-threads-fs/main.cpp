#include "dirmgr.hpp"
#include <iostream>

using namespace std;

int main()
{
   DirManager::check_dirs();
   DirManager obj_dm;

   if (!obj_dm.start_watching("./in"))
   {
      cout << "Could not start Directory Monitor." << endl;
      return EXIT_FAILURE;
   }

   for (int n = 0; n <= 20; n++)
   {
      this_thread::sleep_for(chrono::seconds(2));
      cout << "Main thread alive." << endl;
   }

   obj_dm.stop_watching();

   cout << "Main thread finished." << endl;

   return EXIT_SUCCESS;
}