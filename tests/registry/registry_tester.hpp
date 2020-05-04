#pragma once
#include <boost/test/unit_test.hpp>
#include <eosio/testing/tester.hpp>
#include <eosio/chain/abi_serializer.hpp>
#include <fc/variant_object.hpp>
#include "contracts.hpp"
#include <vector>

using namespace eosio::testing;
using namespace eosio;
using namespace eosio::chain;
using namespace eosio::testing;
using namespace fc;
using namespace std;

using mvo = fc::mutable_variant_object;

class registry_tester : public tester
{
public:
    registry_tester();

    action_result push_action(const account_name &signer, const action_name &name, const variant_object &data);
    fc::variant get_form(const account_name &name);
    fc::variant get_response(const account_name &name, const account_name &pkey);

    action_result create_form(const account_name &signer, const account_name &form, const std::vector<std::string> &questions);
    action_result delete_form(const account_name &signer, const account_name &form);
    action_result add_response(const account_name &signer, const account_name &form, const std::vector<std::string> &answers);
    
    abi_serializer abi_ser;
};
