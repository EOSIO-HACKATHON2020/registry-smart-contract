#include "registry_tester.hpp"

BOOST_AUTO_TEST_SUITE(add_response_tests)

BOOST_FIXTURE_TEST_CASE(add_response_test, registry_tester)
try
{
    BOOST_REQUIRE_EQUAL(wasm_assert_msg("add_shareholder : user_name account not exist"),
                        add_share_holder(N(list.token), N(notexisten), asset::from_string("100.0 PERCENT")));

    BOOST_REQUIRE_EQUAL(wasm_assert_msg("add_shareholder : share not valid"),
                        add_share_holder(N(list.token), N(alice), asset::from_string("150.0 PERCENT")));

    BOOST_REQUIRE_EQUAL(success(),
                        add_share_holder(N(list.token), N(alice), asset::from_string("20.0 PERCENT")));

    auto share_holder = get_shareholder(N(alice));
    REQUIRE_MATCHING_OBJECT(share_holder, mvo()("account", "alice")("share","20.0 PERCENT"));

    BOOST_REQUIRE_EQUAL(wasm_assert_msg("add_shareholder : shareholders sum not valid"),
                        add_share_holder(N(list.token), N(bob), asset::from_string("100.0 PERCENT")));
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
