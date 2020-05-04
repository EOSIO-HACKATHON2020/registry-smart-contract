#include "registry_tester.hpp"

BOOST_AUTO_TEST_SUITE(create_form_tests)

BOOST_FIXTURE_TEST_CASE(create_existing_form_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form1), q));
    
    BOOST_REQUIRE_EQUAL(wasm_assert_msg("create_form : form already exist"), 
                        create_form(N(registry), N(form1), q));
}
FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE(create_empty_form_test, registry_tester)
try
{
    std::vector<std::string> q;    
    BOOST_REQUIRE_EQUAL(wasm_assert_msg("create_form : questions should not be empty"), 
                        create_form(N(registry), N(form1), q));
}
FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE(succeed_create_form_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));
    
    auto form = get_form(N(form2));
    auto form_array = form["questions"].get_array();
    BOOST_REQUIRE_EQUAL(form["name"], fc::variant("form2"));
    BOOST_REQUIRE_EQUAL(form_array[0], fc::variant("Q1"));
    BOOST_REQUIRE_EQUAL(form_array[1], fc::variant("Q2"));  
    BOOST_REQUIRE_EQUAL(form_array[2], fc::variant("Q3"));  
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
