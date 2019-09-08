# Exemplo 01 - Threads e FileSystem no C++17

Pequeno programa para demonstrar aplicação de multithreading e da biblioteca filesystem no C++17.

A thread principal (na função main()) roda a cada 2 segundos. Há uma classe DirManager que tem dois papéis: 1) Verificar a existencia dos diretórios [in]/[out] (para alguma futura simulacao de processamento de arquivos), criando-os caso nao existam e 2) Monitorar (numa thread secundária, que roda a cada 3 segundos) a entrada de arquivos em [in].

## Build

Utilizei clang-7 no Debian 10 com CMake. Para gerar o build, procedimento padrão:

No diretorio do projeto,

```sh
export CXX=/usr/bin/clang++
mkdir build && cd build
cmake ..
make

```

Se não tiver/quiser o CMake instalado, dá pra gerar o executavel diretamente com:

```
clang++ -std=c++17 -stdlib=libc++ -Wextra -Wall -pedantic main.cpp dirmgr.cpp -o lesson.exe -lc++fs \
-pthread
```
# 
Precisa dos pacotes instalados:

* clang-7
* libc++1-7
* libc++-7-dev
* libc++abi1-7
* libc++abi-7-dev

Ou para gerar o executavel com g++

```
g++ -std=c++17 -Wextra -Wall -pedantic main.cpp dirmgr.cpp -o lesson.exe -lstdc++fs -pthread
```
