#include "../include/symtable.h"

using namespace std;


SymTable::SymTable(unique_ptr<SymTable> parent_table_ptr_)
    : parent_table_ptr(move(parent_table_ptr_))
{
}


void SymTable::UpdateTable(string id, Type type) {
    table[move(id)] = move(type);
}


bool SymTable::AlreadyDefined(const string& id) const {
    if (table.count(id))
        return true;
    return parent_table_ptr == nullptr ? false : parent_table_ptr->AlreadyDefined(id);
}


const Type& SymTable::operator[](const string& id) const {
    if (table.count(id)) {
        return table.at(id);
    }
    if (AlreadyDefined(id)) {
        return (*parent_table_ptr)[id];
    }

    throw logic_error("undefined variable " + id);
}


Type& SymTable::operator[](const string& id) {
    if (table.count(id)) {
        return table.at(id);
    }
    if (AlreadyDefined(id)) {
        return (*parent_table_ptr)[id];
    }

    throw logic_error("undefined variable " + id);
}


unique_ptr<SymTable> MakeNewSymTable(unique_ptr<SymTable> parent) {
    return make_unique<SymTable>(move(parent));
}