#pragma once
#include <eosio/eosio.hpp>

using namespace eosio;

struct [[eosio::contract("registry"), eosio::table]] response
{
private:
    uint64_t key;
    std::vector<std::string> answers;

public:
    response();
    response(const uint64_t &_key, std::vector<std::string> &_answers);

    uint64_t primary_key() const;
    std::vector<std::string> get_answers() const;

    void set_answers(const std::vector<std::string> &_answers);

    EOSLIB_SERIALIZE(response, (key)(answers))
};
using response_table = multi_index<name("inheritance"), response>;
