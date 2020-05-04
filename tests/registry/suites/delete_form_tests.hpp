#include "registry_tester.hpp"

BOOST_AUTO_TEST_SUITE(delete_form_tests)

BOOST_FIXTURE_TEST_CASE(succeed_delete_form_test, registry_tester)
try
{
    std::vector<std::string> q{"Q1","Q2","Q3"};
    BOOST_REQUIRE_EQUAL(success(), create_form(N(registry), N(form2), q));
    BOOST_REQUIRE_EQUAL(success(), delete_form(N(registry), N(form2)));

    auto form = get_form(N(form2));
    BOOST_REQUIRE_EQUAL(true, form.is_null());
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
