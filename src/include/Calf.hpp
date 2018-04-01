#pragma once

#include <map>
#include <functional>

#define CALF_CLASS(name) \
    class name; \
    class name##_register \
    { \
    public: \
        name##_register() \
        { \
            Calf::registerClass( #name, CalfCreator<name>); \
        } \
    }; \
    name##_register name##_register_obj

template <typename T>
void* CalfCreator()
{
    return static_cast<void*>(new T());
}

class Calf
{
public:
    using Creator_t = std::function<void*()>;
    using FunctionTable_t = std::map<const std::string, std::function<void*()>>;
public:
    static void registerClass(const std::string& name, Creator_t creator);

    static void removeClass(const std::string& name);

    static bool classExists(const std::string& name);

    template <typename T>
    static T* create(const std::string& name);

protected:
    Calf()
    {

    }
private:
    static FunctionTable_t _creatorTable;
};
