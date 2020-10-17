#pragma once

#include "type.h"

#include <vector>


Type BuiltinInt(const std::vector<Type>& args);
Type BuiltinString(const std::vector<Type>& args);
Type BuiltinBool(const std::vector<Type>& args);
Type BuiltinStringAt(const std::vector<Type>& args);