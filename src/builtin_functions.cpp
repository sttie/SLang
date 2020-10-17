#include "../include/builtin_functions.h"

#include <variant>
#include <stdexcept>

using namespace std;


Type BuiltinInt(const vector<Type>& args) {
    const Type& to_int = args[0];
    if (to_int.GetTypeName() == TypeName::INT)
        return to_int;

    const auto& value = to_int.Value();
    return to_int.GetTypeName() == TypeName::STRING
           ? Type(TypeName::INT, get<string>(value))
           : Type(TypeName::INT, Type::ToString(int(get<bool>(value))));
}

Type BuiltinString(const vector<Type>& args) {
    const Type& to_string = args[0];
    if (to_string.GetTypeName() == TypeName::STRING)
        return to_string;

    const auto& value = to_string.Value();
    return to_string.GetTypeName() == TypeName::INT
           ? Type(TypeName::STRING, Type::ToString(get<int>(value)))
           : Type(TypeName::STRING, Type::ToString(get<bool>(value)));
}

Type BuiltinBool(const vector<Type>& args) {
    const Type& to_bool = args[0];
    if (to_bool.GetTypeName() == TypeName::BOOL)
        return to_bool;

    bool result = bool(to_bool);
    return result ? Type(TypeName::BOOL, "true")
                  : Type(TypeName::BOOL, "false");
}

Type BuiltinStringAt(const std::vector<Type>& args) {
    Type indexation_string = args[0];
    Type index_type = args[1];

    if (indexation_string.GetTypeName() != TypeName::STRING) {
        throw logic_error(indexation_string.GetStringTypeName() +
                          " doesn't support indexation");
    }
    if (index_type.GetTypeName() != TypeName::INT) {
        throw logic_error(indexation_string.GetStringTypeName() +
                          " type got, but int was expected");
    }

    const string& string_value = get<string>(indexation_string.Value());
    int index = get<int>(index_type.Value());
    if (index >= string_value.size() || index < 0) {
        throw logic_error("index is out of bounds");
    }

    return Type(TypeName::STRING, string(1, string_value[index]));
}