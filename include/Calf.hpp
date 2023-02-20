#pragma once

#include "Base.hpp"
#include <string>

#define CALF_CLASS(name) \
    do { \
        class name; \
        class name##_register \
        { \
        public: \
            name##_register() \
            { \
                calf::Calf::registerClass( #name, CalfCreator<name>); \
            } \
        }; \
        name##_register name##_register_obj; \
    } while(0)

namespace calf {

using Calf=Base<std::string>;

}

