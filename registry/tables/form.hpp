#pragma once
#include <eosio/eosio.hpp>

using namespace eosio;

struct [[eosio::contract("registry"), eosio::table]] form
{
private:
    name name;
    std::vector<std::string> questions;

public:
    form();
    form(const eosio::name &_name, const std::vector<std::string> &_questions);

    uint64_t primary_key() const;
    std::vector<std::string> get_questions() const;

    void set_questions(const std::vector<std::string> &_questions);

    EOSLIB_SERIALIZE(form, (name)(questions))
};
using form_table = multi_index<name("form"), form>;
