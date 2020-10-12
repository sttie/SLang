#pragma once

#include <string>
#include <variant>


enum class TypeName {
    INT,
    BOOL,
    STRING
};


class Type
{
public:
    using Variant = std::variant<int, bool, std::string>;

    Type() = default;
    Type(const std::string& type_name_, std::string value_);
    Type(const TypeName& type_name_, std::string value_);

    const Variant& Value() const;
    const TypeName& GetTypeName() const;
    std::string GetStringTypeName() const;

    Type operator+ (const Type& right) const;
    Type operator- (const Type& right) const;
    Type operator* (const Type& right) const;
    Type operator/ (const Type& right) const;
    Type operator> (const Type& right) const;
    Type operator< (const Type& right) const;
    Type operator>=(const Type& right) const;
    Type operator<=(const Type& right) const;
    Type operator==(const Type& right) const;
    Type operator!=(const Type& right) const;
    Type operator&&(const Type& right) const;
    Type operator||(const Type& right) const;
    Type operator! () const;
    operator bool() const;

private:
    void InitValue(std::string value_);
    void CheckTypes(const Type& other_type, const std::string& operation) const;

    static void ThrowTypeError(const std::string& error_msg);
    static std::string ToString(int to_convert);
    static std::string ToString(bool to_convert);

    TypeName type_name;
    Variant value;
};