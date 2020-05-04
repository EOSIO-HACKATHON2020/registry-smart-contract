#include "response.hpp"

response::response()
{
}

response::response(const uint64_t &_key, std::vector<std::string> &_answers)
    : key(_key), answers(_answers)
{
}

uint64_t response::primary_key() const
{
    return key;
}

std::vector<std::string> response::get_answers() const
{
    return answers;
}

void response::set_answers(const std::vector<std::string> &_answers)
{
    answers = _answers;
}