// TODO:    add an Iterator which insert returns and algorithms can use
//          add a resize method

#pragma once

#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <string>

template<typename T>
class ManagedContainer{
    // contains the indices of freed objects in container_
    std::unordered_set<size_t> free_;   

    std::vector<T> container_;

    public:
    // inserts object T into open spot in container and returns the index
    // it was inserted at
    size_t insert(T const);

    // erase object at this
    void erase(size_t const index);

    T& operator[](size_t index);

    // returns the number of (live) elements
    size_t size();
    // same as vector capacity
    size_t capacity();
};

template<typename T>
size_t ManagedContainer<T>::insert(T const thing){
    if(!free_.empty()){
        auto index = *(free_.begin());
        container_[index] = thing;
        free_.erase(index);
        return index;
    }else{
        container_.push_back(thing);
        return container_.size() - 1;
    }
}

template<typename T>
void ManagedContainer<T>::erase(size_t index){
    auto found = free_.find(index);
    // if that index is already freed or out of bounds we throw
    if (found != free_.end() || index >= container_.size()) {
        std::string err(std::to_string(index) + " not in container");
        throw std::out_of_range(err);
    }
    else {
        free_.emplace(index);
    }
}

template<typename T>
T& ManagedContainer<T>::operator[](size_t index){
    auto found = free_.find(index);
    if(found == free_.end() && index < container_.size()){
        return container_[index];
    }else{
        // if it's been freed already then throw
        std::string err(std::to_string(index) + " not free in container");
        throw std::out_of_range(err);
    }
}

template<typename T>
size_t ManagedContainer<T>::size(){
    return container_.size() - free_.size();
}

template<typename T>
size_t ManagedContainer<T>::capacity(){
    return container_.capacity();
}
