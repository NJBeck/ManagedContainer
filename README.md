# ManagedContainer

A container where newly added objects are inserted into vacancies of previously freed objects.  

* Instead of refering to an object by it's index the user gives the container a unique handle along with the data.  

* When the container is beyond a specified limit of emptiness it rebuilds the vector to shrink the size.

* Insertion and deletion are constant time, but the shrinking operation is linear in the number of allocated objects.

## Cloning

Use `git clone --recursive` to download the googletest submodule as well

## Building Tests

1. from root directory `mkdir build` and `cd build/`
2. execute `cmake ..`
3. use the generated build file to build the project
4. execute `ctest` to run the tests