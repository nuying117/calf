#pragma once

#include "Base.hpp"
#include <string>

#define CALF_CLASS(name) \
        class name; \
        class name##_register \
        { \
        public: \
            name##_register() \
            { \
                calf::Calf::registerClass( #name, calf::classCreator<name>); \
            } \
        }; \
        name##_register name##_register_obj

namespace calf {

using Calf=Base<std::string>;

}

