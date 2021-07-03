# ManagedContainer

A container where newly added objects are inserted into vacancies of previously freed objects.  

* Instead of refering to an object by it's index the user gives the container a unique handle along with the data.  

* When the container is beyond a specified limit of emptiness it rebuilds the vector to shrink the size.

* Insertion and deletion are constant time, but the shrinking operation is linear in the number of allocated objects.