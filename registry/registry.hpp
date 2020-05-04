#pragma once
#include <eosio/eosio.hpp>
#include "form.hpp"
#include "response.hpp"

using namespace eosio;

class [[eosio::contract("registry")]] registry : public contract
{
public:
    registry(name receiver, name code, datastream<const char *> ds);

    //For managing forms
    [[eosio::action("createform")]] void create_form(const name &form, const std::vector<std::string> &questions);

    [[eosio::action("deleteform")]] void delete_form(const name &form);

    //For managing responses
    [[eosio::action("addresponse")]] void add_response(const name &form, const std::vector<std::string> &answers);
};