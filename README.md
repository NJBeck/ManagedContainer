# ManagedContainer

A wrapper for vector where newly added objects are inserted into vacancies of previously erased objects.

Also keeps reference counts of objects in the container, so elements can be used and "deleted" by users.

* Insertion and deletion are constant time
* Indices are stable so they can be safely stored/used by other structures

## Cloning

Use `git clone --recursive` to download the googletest submodule as well

## Building Tests

1. from root directory `mkdir build` and `cd build/`
2. execute `cmake ..`
3. use the generated build file to build the project
4. execute `ctest` to run the tests