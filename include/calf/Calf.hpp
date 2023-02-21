#pragma once

#include <calf/Base.hpp>
#include <string>
#include <iostream>

#define CALF_CLASS(name) \
        class name; \
        class name##_register \
        { \
        public: \
            name##_register() \
            { \
                calf::Calf::registerClass( #name, calf::classCreator<name>); \
                std::cout << "registering class " << #name << std::endl; \
            } \
        }; \
        name##_register name##_register_obj

namespace calf {

using Calf=Base<std::string>;

}

