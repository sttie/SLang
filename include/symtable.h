#pragma once

#include "type.h"

#include <string>
#include <map>
#include <memory>
#include <stdexcept>


class SymTable {
public:
    SymTable(std::unique_ptr<SymTable> parent_table_ptr_);
    ~SymTable() = default;

    void UpdateTable(std::string id, Type type);

    bool AlreadyDefined(const std::string& id) const;

    const Type& operator[](const std::string& id) const;
    Type& operator[](const std::string& id);

private:
    std::unique_ptr<SymTable> parent_table_ptr;
    std::map<std::string, Type> table;
};

std::unique_ptr<SymTable> MakeNewSymTable(std::unique_ptr<SymTable> parent = nullptr);