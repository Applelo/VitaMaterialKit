#pragma once
#include <stdexcept>

template <class T>
class UtilsSingleton
{
public:
  template <typename... Args>
  static T* create_instance(Args... args)
  {
    if (!instance_)
      {
        instance_ = new T(std::forward<Args>(args)...);
      }

    return instance_;
  }

  static T* get_instance()
  {
    if (!instance_)
      {
        throw std::runtime_error("Accessed UtilsSingleton before that instance is created");
      }

    return instance_;
  }

  static
  void destroy_instance()
  {
    delete instance_;
    instance_ = nullptr;
  }

private:
  static T* instance_;
};

template <class T> T*  UtilsSingleton<T>::instance_ = nullptr;
