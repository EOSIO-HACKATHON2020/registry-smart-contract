#include "form.hpp"

form::form()
{
}

form::form(const eosio::name &_name, const std::vector<std::string> &_questions)
    : name(_name), questions(_questions)
{
}

uint64_t form::primary_key() const
{
    return name.value;
}

std::vector<std::string> form::get_questions() const
{
    return questions;
}

void form::set_questions(const std::vector<std::string> &_questions)
{
    questions = _questions;
}