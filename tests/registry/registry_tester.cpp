#include "registry_tester.hpp"

registry_tester::registry_tester()
{
    produce_blocks(2);

    create_accounts({
        N(registry),
        N(alice)
    });
    produce_blocks(2);

    set_code(N(registry), contracts::registry_wasm());
    set_abi(N(registry), contracts::registry_abi().data());

    produce_blocks();

    const auto &accnt = control->db().get<account_object, by_name>(N(registry));
    abi_def abi;
    BOOST_REQUIRE_EQUAL(abi_serializer::to_abi(accnt.abi, abi), true);
    abi_ser.set_abi(abi, abi_serializer_max_time);
}

registry_tester::action_result registry_tester::push_action(const account_name &signer, const action_name &name, const variant_object &data)
{
    string action_type_name = abi_ser.get_action_type(name);

    action act;
    act.account = N(registry);
    act.name = name;
    act.data = abi_ser.variant_to_binary(action_type_name, data, abi_serializer_max_time);

    return base_tester::push_action(std::move(act), signer.to_uint64_t());
}

fc::variant registry_tester::get_form(const account_name &name)
{
    vector<char> data = get_row_by_account(N(registry), N(registry), N(form), name);
    return data.empty() ? fc::variant() : abi_ser.binary_to_variant("form", data, abi_serializer_max_time);
}

fc::variant registry_tester::get_response(const account_name &name, const account_name &pkey)
{
    vector<char> data = get_row_by_account(N(registry), name, N(response), pkey);
    return data.empty() ? fc::variant() : abi_ser.binary_to_variant("response", data, abi_serializer_max_time);
}

registry_tester::action_result registry_tester::create_form(const account_name &signer, const account_name &form, const std::vector<std::string> &questions)
{
    return push_action(signer, N(createform), mvo()("form", form)("questions", questions));
}

registry_tester::action_result registry_tester::delete_form(const account_name &signer, const account_name &form)
{
    return push_action(signer, N(deleteform), mvo()("form", form));
}

registry_tester::action_result registry_tester::add_response(const account_name &signer, const account_name &form, const std::vector<std::string> &answers)
{
    return push_action(signer, N(addresponse), mvo()("form", form)("answers", answers));
}