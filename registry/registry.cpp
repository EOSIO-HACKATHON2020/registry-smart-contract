#include "registry.hpp"

registry::registry(name receiver, name code, datastream<const char *> ds)
    : contract::contract(receiver, code, ds)
{
}

void registry::create_form(const name &form, const std::vector<std::string> &questions)
{
    require_auth(get_self());
    form_table _form_table(get_self(), get_self().value);
    auto it = _form_table.find(form.value);
    check(it == _form_table.end(), "create_form : form already exist");
    check(!questions.empty(), "create_form : questions should not be empty");

    _form_table.emplace(get_self(), [&](auto &r) {
        form temp(form, questions);
        r = temp;
    });
}

void registry::delete_form(const name &form)
{
    require_auth(get_self());
    form_table _form_table(get_self(), get_self().value);
    auto it = _form_table.find(form.value);
    check(it != _form_table.end(), "delete_form : form not exist");
    _form_table.erase(it);

    response_table _response_table(get_self(), form.value);
    auto itr = _response_table.begin();
    while(itr != _response_table.end())
    {
        itr = _response_table.erase(itr);
    }
}

void registry::add_response(const name &form, const std::vector<std::string> &answers)
{
    require_auth(get_self());
    form_table _form_table(get_self(), get_self().value);
    auto it = _form_table.find(form.value);
    check(it != _form_table.end(), "add_response : form not exist");
    check(!answers.empty(), "add_response : answers should not be empty");
    response_table _response_table(get_self(), form.value);

    _response_table.emplace(get_self(), [&](auto &r) {
        response temp(_response_table.available_primary_key(), answers);
        r = temp;
    });
}