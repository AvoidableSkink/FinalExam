// FinalExam.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

namespace usu
{
    template <typename T>
    class unique_ptr
    {
      public:
        unique_ptr() { data = nullptr; }

        unique_ptr(T dta) { data = new T(dta); }

        unique_ptr(T* dta) { data = dta; }

        unique_ptr(const unique_ptr& obj) = delete;

        unique_ptr(unique_ptr&& obj) noexcept
        {
            // transfer ownership
            data = obj.data;
            obj.data = nullptr;
        }

        // destructor
        ~unique_ptr() { delete data; }

        unique_ptr& operator=(const unique_ptr& rhs) = delete;

        unique_ptr& operator=(unique_ptr&& rhs) noexcept
        {
            if (this != &rhs)
            {
                std::swap(data, rhs.data);
            }
            return *this;
        }

        T* operator->() { return data; }

        T operator*() { return *data; }

        bool operator==(const unique_ptr& rhs)
        {
            if (rhs.data == data)
                return true;
            else
                return false;
        }

        bool operator!=(const unique_ptr& rhs)
        {
            if (rhs.data == data)
                return false;
            else
                return true;
        }

        T* get() const { return data; }

        T* release()
        {
            T* tmp = data;
            data = nullptr;
            return tmp;
        }

      private:
        T* data;
    };

    template <typename T, typename... Args>
    unique_ptr<T> make_unique(Args&&... args)
    {
        return unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

} // namespace usu
