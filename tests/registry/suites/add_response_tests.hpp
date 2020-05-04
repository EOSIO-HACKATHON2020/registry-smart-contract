#include "registry_tester.hpp"

BOOST_AUTO_TEST_SUITE(add_response_tests)

BOOST_FIXTURE_TEST_CASE(succeed_add_response_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));
    std::vector<std::string> a{"A1","A2","A3"};
    BOOST_REQUIRE_EQUAL(success(), add_response(N(registry), N(form2), a));
    
    auto response = get_response(N(form2),name(0));
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
