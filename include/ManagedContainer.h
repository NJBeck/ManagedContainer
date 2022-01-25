// TODO:    add an Iterator which insert returns and algorithms can use
//          add a resize method
//          add emplacement

#pragma once

#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <tuple>

template<typename T>
class ManagedContainer{
    // contains the indices of freed objects in container_
    std::unordered_set<size_t> free_;   
    // contains object and reference count
    std::vector<std::tuple<T, size_t>> container_;

    // erase object at this index (if ref count is 1)
    void erase(size_t const index);
    // checks if supplied iterator is valid and throws if not
    void check_bounds(size_t const index);
public:
    // inserts object T into open spot in container and returns the index
    // it was inserted at
    size_t insert(T const);

    T& operator[](size_t index);

    // increment and decrement references to an object in the container
    void increment_reference(size_t const index);
    // erases element if decremented to zero
    void decrement_reference(size_t const index);

    // returns the number of (live) elements
    size_t size();
    // same as vector capacity
    size_t capacity();
};

template<typename T>
void ManagedContainer<T>::check_bounds(size_t const index){
    auto found = free_.find(index);
    if(found != free_.end() || index >= container_.size()){
        std::string err(std::to_string(index) + " not in container");
        throw std::out_of_range(err);
    }
}

template<typename T>
size_t ManagedContainer<T>::insert(T const thing){
    if(!free_.empty()){
        // take a freed index and use it
        auto index = *(free_.begin());
        container_[index] = {thing, 1};
        free_.erase(index);
        return index;
    }else{
        container_.push_back({thing, 1});
        return container_.size() - 1;
    }
}
template<typename T>
T& ManagedContainer<T>::operator[](size_t index){
    check_bounds(index);
    return std::get<0>(container_[index]);
}

template<typename T>
void ManagedContainer<T>::increment_reference(size_t const index){
    check_bounds(index);
    ++std::get<1>(container_[index]);
}

template<typename T>
void ManagedContainer<T>::decrement_reference(size_t const index){
    check_bounds(index);
    auto& count = std::get<1>(container_[index]);
    --count;
    if(count == 0) free_.emplace(index);
}

template<typename T>
size_t ManagedContainer<T>::size(){
    return container_.size() - free_.size();
}

template<typename T>
size_t ManagedContainer<T>::capacity(){
    return container_.capacity();
}
