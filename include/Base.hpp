#pragma once

#include <map>
#include <functional>

namespace calf {

template <typename T>
void* classCreator()
{
    return static_cast<void*>(new T());
}

template <class KEY_TYPE>
class Base
{
public:
    using Creator_t = std::function<void*()>;
    using FunctionTable_t = std::map<const KEY_TYPE, std::function<void*()>>;
public:
    static void registerClass(const KEY_TYPE& name, Creator_t creator)
    {
        if(classExists(name))
        {
            return;
        }

        _creatorTable[name] = creator;
    }

    static void removeClass(const KEY_TYPE& name)
    {
        auto iter = _creatorTable.find(name);
        if(iter == _creatorTable.end())
        {
            return;
        }

        _creatorTable.erase(iter);
    }

    static bool classExists(const KEY_TYPE& name)
    {
        auto iter = _creatorTable.find(name);
        return iter != _creatorTable.end();
    }

    template <typename T>
    static T* create(const KEY_TYPE& name)
    {
        auto iter = _creatorTable.find(name);
        if(iter == _creatorTable.end())
        {
            return nullptr;
        }

        return static_cast<T*>(iter->second());
    }

protected:
    Base()
    {

    }
private:
    static FunctionTable_t _creatorTable;
};

}
