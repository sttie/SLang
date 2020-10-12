#include "../include/type.h"
#include <tuple>

using namespace std;


Type::Type(const string& type_name_, string value_)
{
    if (type_name_ == "int") {
        type_name = TypeName::INT;
    }
    else if (type_name_ == "bool") {
        type_name = TypeName::BOOL;
    }
    else if (type_name_ == "string") {
        type_name = TypeName::STRING;
    }
    else {
        ThrowTypeError("Unknown type: " + type_name_);
    }

    InitValue(move(value_));
}

Type::Type(const TypeName& type_name_, string value_)
    : type_name(type_name_)
{
    InitValue(move(value_));
}

void Type::InitValue(string value_) {
    if (type_name == TypeName::STRING) {
        value = move(value_);
    }
    else if (type_name == TypeName::INT) {
        value = stoi(value_);
    }
    else if (type_name == TypeName::BOOL) {
        if (value_ != "true" && value_ != "false") {
            ThrowTypeError("Bool variable can take only \"true\" or \"false\" values");
        }

        value = value_ == "true";
    }
}


const variant<int, bool, string>& Type::Value() const {
    return value;
}

const TypeName& Type::GetTypeName() const {
    return type_name;
}

string Type::GetStringTypeName() const {
    if (type_name == TypeName::INT)
        return "int";
    if (type_name == TypeName::BOOL)
        return "bool";
    return "string";
}


Type Type::operator+ (const Type& right) const {
    CheckTypes(right, "+");

    if (type_name == TypeName::INT) {
        return Type(type_name, ToString(get<int>(value) + get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(type_name, get<string>(value) + get<string>(right.value));
    }

    return Type(TypeName::INT, ToString(get<bool>(value) + get<bool>(right.value)));
}


Type Type::operator- (const Type& right) const {
    CheckTypes(right, "-");

    if (type_name == TypeName::INT) {
        return Type(type_name, ToString(get<int>(value) - get<int>(right.value)));
    }
    if (type_name == TypeName::BOOL) {
        return Type(TypeName::INT, ToString(get<bool>(value) - get<bool>(right.value)));
    }

    ThrowTypeError("Unsupported operation * between types " +
                   GetStringTypeName() + " and " + GetStringTypeName());
    // Making a compiler happy
    return Type();
}


Type Type::operator* (const Type& right) const {
    CheckTypes(right, "*");

    if (type_name == TypeName::INT) {
        return Type(type_name, ToString(get<int>(value) * get<int>(right.value)));
    }
    if (type_name == TypeName::BOOL) {
        return Type(TypeName::INT, ToString(get<bool>(value) * get<bool>(right.value)));
    }

    ThrowTypeError("Unsupported operation * between types " +
                            GetStringTypeName() + " and " + GetStringTypeName());
    // Making a compiler happy
    return Type();
}

Type Type::operator/ (const Type& right) const {
    CheckTypes(right, "/");

    if (type_name == TypeName::INT) {
        return Type(type_name, ToString(get<int>(value) / get<int>(right.value)));
    }
    if (type_name == TypeName::BOOL) {
        if (!get<bool>(right.value)) {
            ThrowTypeError("The second operand is false (interpreted as 0)");
        }

        return Type(TypeName::INT, ToString(get<bool>(value) / get<bool>(right.value)));
    }

    ThrowTypeError("Unsupported operation / between types " +
                   GetStringTypeName() + " and " + GetStringTypeName());
    // Making a compiler happy
    return Type();
}


Type Type::operator> (const Type& right) const {
    CheckTypes(right, ">");

    if (type_name == TypeName::INT) {
        return Type(TypeName::BOOL, ToString(get<int>(value) > get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(TypeName::BOOL, ToString(get<string>(value) > get<string>(right.value)));
    }

    return Type(TypeName::BOOL, ToString(get<bool>(value) > get<bool>(right.value)));
}


Type Type::operator< (const Type& right) const {
    CheckTypes(right, "<");

    if (type_name == TypeName::INT) {
        return Type(TypeName::BOOL, ToString(get<int>(value) < get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(TypeName::BOOL, ToString(get<string>(value) < get<string>(right.value)));
    }

    return Type(TypeName::BOOL, ToString(get<bool>(value) < get<bool>(right.value)));
}

Type Type::operator>=(const Type& right) const {
    CheckTypes(right, ">=");

    if (type_name == TypeName::INT) {
        return Type(TypeName::BOOL, ToString(get<int>(value) >= get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(TypeName::BOOL, ToString(get<string>(value) >= get<string>(right.value)));
    }

    return Type(TypeName::BOOL, ToString(get<bool>(value) >= get<bool>(right.value)));
}

Type Type::operator<=(const Type& right) const {
    CheckTypes(right, "<=");

    if (type_name == TypeName::INT) {
        return Type(TypeName::BOOL, ToString(get<int>(value) <= get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(TypeName::BOOL, ToString(get<string>(value) <= get<string>(right.value)));
    }

    return Type(TypeName::BOOL, ToString(get<bool>(value) <= get<bool>(right.value)));
}

Type Type::operator==(const Type& right) const {
    CheckTypes(right, "==");

    if (type_name == TypeName::INT) {
        return Type(TypeName::BOOL, ToString(get<int>(value) == get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(TypeName::BOOL, ToString(get<string>(value) == get<string>(right.value)));
    }

    return Type(TypeName::BOOL, ToString(get<bool>(value) == get<bool>(right.value)));
}

Type Type::operator!=(const Type& right) const {
    CheckTypes(right, "!=");

    if (type_name == TypeName::INT) {
        return Type(TypeName::BOOL, ToString(get<int>(value) != get<int>(right.value)));
    }
    if (type_name == TypeName::STRING) {
        return Type(TypeName::BOOL, ToString(get<string>(value) != get<string>(right.value)));
    }

    return Type(TypeName::BOOL, ToString(get<bool>(value) != get<bool>(right.value)));
}

Type Type::operator&&(const Type& right) const {
    CheckTypes(right, "and");

    return Type(TypeName::BOOL, ToString(bool(*this) && bool(right)));
}

Type Type::operator||(const Type& right) const {
    CheckTypes(right, "or");

    return Type(TypeName::BOOL, ToString(bool(*this) || bool(right)));
}

Type Type::operator! () const {
    return Type(TypeName::BOOL, ToString(!bool(*this)));
}


Type::operator bool() const {
    if (type_name == TypeName::STRING) {
        return !get<string>(value).empty();
    }
    if (type_name == TypeName::INT) {
        return get<int>(value) != 0;
    }
    return get<bool>(value);
}

void Type::ThrowTypeError(const string& error_msg) {
    throw logic_error(error_msg);
}

void Type::CheckTypes(const Type& other_type, const string& operation) const {
    if (type_name != other_type.type_name) {
        ThrowTypeError("Unsupported operation " + operation +
                            " between types " +
                            GetStringTypeName() + " and " +
                            other_type.GetStringTypeName());
    }
}

string Type::ToString(int to_convert) {
    return to_string(to_convert);
}

string Type::ToString(bool to_convert) {
    return to_convert ? "true" : "false";
}