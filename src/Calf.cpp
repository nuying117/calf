#include "Calf.hpp"

Calf::FunctionTable_t Calf::_creatorTable;

void Calf::registerClass(const std::string& name, Creator_t creator)
{
    if(classExists(name))
    {
        return;
    }

    _creatorTable[name] = creator;
}

void Calf::removeClass(const std::string& name)
{
    auto iter = _creatorTable.find(name);
    if(iter == _creatorTable.end())
    {
        return;
    }

    _creatorTable.erase(iter);
}

bool Calf::classExists(const std::string& name)
{
    auto iter = _creatorTable.find(name);
    return iter != _creatorTable.end();
}

template <typename T>
T* Calf::create(const std::string& name)
{
    auto iter = _creatorTable.find(name);
    if(iter == _creatorTable.end())
    {
        return nullptr;
    }

    return static_cast<T*>(iter->second());
}
