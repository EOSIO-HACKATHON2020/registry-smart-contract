#include "registry_tester.hpp"

BOOST_AUTO_TEST_SUITE(add_response_tests)

BOOST_FIXTURE_TEST_CASE(wrong_form_name_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));

    std::vector<std::string> a{"A1","A2","A3"};
    BOOST_REQUIRE_EQUAL(wasm_assert_msg("add_response : form not exist"),
                        add_response(N(registry), N(form), a));
}
FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE(wrong_answers_size_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));

    std::vector<std::string> a{"A1"};
    BOOST_REQUIRE_EQUAL(wasm_assert_msg("add_response : answers size should be equal questions size"),
                        add_response(N(registry), N(form2), a));
}
FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE(empty_answers_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));

    std::vector<std::string> a;
    BOOST_REQUIRE_EQUAL(wasm_assert_msg("add_response : answers should not be empty"),
                        add_response(N(registry), N(form2), a));
}
FC_LOG_AND_RETHROW()


BOOST_FIXTURE_TEST_CASE(succeed_add_response_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));

    std::vector<std::string> a{"A1","A2","A3"};
    BOOST_REQUIRE_EQUAL(success(), add_response(N(registry), N(form2), a));
    
    auto response = get_response(N(form2),account_name(0));
    auto response_arr = response["answers"].get_array();
    BOOST_REQUIRE_EQUAL(response["key"], fc::variant(0));
    BOOST_REQUIRE_EQUAL(response_arr[0], fc::variant("A1"));
    BOOST_REQUIRE_EQUAL(response_arr[1], fc::variant("A2"));  
    BOOST_REQUIRE_EQUAL(response_arr[2], fc::variant("A3"));  
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
