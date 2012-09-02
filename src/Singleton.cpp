#include "Singleton.h"

template<typename T>
T* Singleton<T>::_instance =nullptr;

template<typename T>
Singleton<T>::Singleton(){}

template<typename T>
 T* Singleton<T>::getInstance(){

     //Test
    assert(_instance == nullptr);

    if(_instance == nullptr)
        _instance = new T();
    return _instance;
}

template<typename T>
Singleton<T>::~Singleton(){}

template class Singleton<Http>;
