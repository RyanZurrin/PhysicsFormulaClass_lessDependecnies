//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_STRINGHELPER_H
#define PHYSICSFORMULA_STRINGHELPER_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std::string_literals;

template<typename CharT>
using t_string =
std::basic_string < CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template<typename CharT>
using t_ss =
std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CharT>>;


/// <summary>
/// Removes the specified text.
/// </summary>
/// <param name="text">The text.</param>
/// <param name="ch">The ch.</param>
/// <returns></returns>
template<typename CharT>
t_string<CharT> remove(t_string<CharT> text, CharT const ch)
{
    auto start = std::remove_if(
            std::begin(text), std::end(text),
            [=](CharT const c) {return c == ch; });
    text.erase(start, std::end(text));
    return text;

}
/// <summary>
/// builds a new string with all uppercase letters.
/// </summary>
/// <param name="text">The text.</param>
/// <returns>new changed string</returns>
template<typename CharT>
t_string<CharT> to_upper(t_string<CharT> text)
{
    transform(
            text,std::begin(text), std::toupper);
    return text;
}

/// <summary>
/// builds a new string with all lowercase letters.
/// </summary>
/// <param name="text">The text.</param>
/// <returns>new changed string</returns>
template<typename CharT>
t_string<CharT> to_lower(t_string<CharT> text)
{
    transform(
            text,std::begin(text), std::tolower);
    return text;
}

/// <summary>
/// builds a new string with the reverse of the specified text.
/// </summary>
/// <param name="text">The text.</param>
/// <returns>new reversed string</returns>
template<typename CharT>
t_string<CharT> reverse(t_string<CharT> text)
{
    std::reverse(std::begin(text), std::end(text));
    return text;
}

/// <summary>
/// Trims the specified text.
/// </summary>
/// <param name="text">The text.</param>
/// <returns>new string with blank spaces trimmed from front and back</returns>
template<typename CharT>
t_string<CharT> trim(t_string<CharT> const& text)
{
    auto first{ text.find_first_not_of(' ') };
    auto last{ text.find_last_not_of(' ') };
    return text.substr(first, (last - first + 1));
}

/// <summary>
/// Trims the left.
/// </summary>
/// <param name="text">The text.</param>
/// <returns>new string with blank spaces trimmed from front</returns>
template<typename CharT>
t_string<CharT> trim_left(t_string<CharT> const& text)
{
    auto first{ text.find_first_not_of(' ') };
    return text.substr(first, text.size() - first);
}

/// <summary>
/// Trims the right.
/// </summary>
/// <param name="text">The text.</param>
/// <returns>new string with blank spaces trimmed from back</returns>
template<typename CharT>
t_string<CharT> trim_right(t_string<CharT> const& text)
{
    auto last{ text.find_last_not_of(' ') };
    return text.substr(0, last + 1);
}

/// <summary>
/// Trims the specified front and back of text of the specified
/// character
/// </summary>
/// <param name="text">The text.</param>
/// <param name="chars">The chars.</param>
/// <returns>new string with trimmed front and back</returns>
template<typename CharT>
t_string<CharT> trim(t_string<CharT> const& text,
                     t_string<CharT> const& chars)
{
    auto first{ text.find_first_not_of(chars) };
    auto last{ text.find_last_not_of(chars) };
    return text.substr(first, (last - first + 1));
}

/// <summary>
/// Trims the front of text of the specified character.
/// </summary>
/// <param name="text">The text.</param>
/// <param name="chars">The chars.</param>
/// <returns>new string with trimmed front</returns>
template<typename CharT>
t_string<CharT> trim_left(t_string<CharT> const& text,
                          t_string<CharT> const& chars)
{
    auto first{ text.find_first_not_of(chars) };
    return text.substr(first, text.size() - first);
}

/// <summary>
/// Trims the back of text of specified character.
/// </summary>
/// <param name="text">The text.</param>
/// <param name="chars">The chars.</param>
/// <returns>new string with trimmed back</returns>
template<typename CharT>
t_string<CharT> trim_right(t_string<CharT> const& text,
                           t_string<CharT> const& chars)
{
    auto last{ text.find_last_not_of(chars) };
    return text.substr(0, last + 1);
}


template<typename CharT>
std::vector<t_string<CharT>> split(t_string<CharT> text, CharT const delimiter)
{
    auto sstr = t_ss<CharT>{ text };
    auto tokens = std::vector<t_string<CharT>>{};
    auto token = t_string<CharT>{};
    while (std::getline(sstr, token, delimiter))
    {
        if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
}
#endif //PHYSICSFORMULA_STRINGHELPER_H
