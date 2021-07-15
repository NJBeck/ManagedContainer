# ManagedContainer

A wrapper for vector where newly added objects are inserted into vacancies of previously erased objects.  

* Insertion and deletion are constant time

## Cloning

Use `git clone --recursive` to download the googletest submodule as well

## Building Tests

1. from root directory `mkdir build` and `cd build/`
2. execute `cmake ..`
3. use the generated build file to build the project
4. execute `ctest` to run the tests