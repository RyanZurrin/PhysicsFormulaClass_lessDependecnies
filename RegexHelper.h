//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_REGEXHELPER_H
#define PHYSICSFORMULA_REGEXHELPER_H
#include <iomanip>
#include <regex>
using namespace std::string_literals;




template<typename CharT>
using t_string =
std::basic_string < CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template<typename CharT>
using t_ss =
std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CharT>>;


static struct RegularExpressionPatterns
{
    t_string<char> EMAIL{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z_]{2,}$)"s };
    t_string<char> PHONE{ R"(\d{3}-\d{3}-\d{4})"s };
    t_string<char> ABSOLUTE_PATH{R"(^\/([A-z0-9-_+]+\/)*([A-z0-9]+\.(jpg|jpeg|txt|zip|png|pdf|doc|docx|exl|gif|dot|dotx|eml|bat|bin|bmp|exe|htm|html|css|iso))$)"s};
    t_string<char> SSN{ R"(^(?!666|000|9\d{2})\d{3}-(?!00)\d{2}-(?!0{4})\d{4}$)"s };
    t_string<char> IPV4{ R"((([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]))"s };
    t_string<char> IPV6{ R"(((([0-9a-fA-F]){1,4})\:){7}([0-9a-fA-F]){1,4})"s };
    t_string<char> MAC{ R"(^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})|([0-9a-fA-F]{4}\.[0-9a-fA-F]{4}\.[0-9a-fA-F]{4})$)"s };
    t_string<char> MATH{ R"(^(?:[0-9 ()\.]+[*+/-])+[0-9 ()\.]+)"s };
    t_string<char> ROOT_PATH{ R"(^[a-zA-Z_]:.*([a-zA-Z_]+([a-zA-Z_]+)+).*[a-zA-Z_]+$)"s };

}rgXRaw;


template<typename CharT>
bool is_valid_format(t_string<CharT> const& testString, t_string<CharT> const pattern)
{
    auto rx = std::regex{ pattern, std::regex_constants::icase };
    return std::regex_match(testString, rx);
}

inline auto reg_test = [](std::string const& text, std::string const& pattern)
{
    std::cout << std::setw(40) << std::left << text << " : "
              << (is_valid_format(text, pattern) ?

                  "valid format" : "invalid format")
              << '\n';
};

#endif //PHYSICSFORMULA_REGEXHELPER_H
