#pragma once

template<typename T>
class Singleton {
public:
    static T& Singleton<T>::get()
    {
        static T instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton) = delete;

protected:
    Singleton() = default;
};


