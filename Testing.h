//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_TESTING_H
#define PHYSICSFORMULA_TESTING_H
#pragma once
#pragma warning(suppress : 4996)

#include <iostream>
#include <any>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <set>

template <typename T>
auto add(T value)
{
    return value;
}


template<typename T, typename... Ts>
auto add(T head, Ts... rest)
{
    return head + add(rest...);
}


template<typename... T>
auto make_even_tuple(T... a)
{
    static_assert(sizeof...(a) % 2 == 0,
                  "expected an even number of arguments");
    std::tuple<T...> t{ a... };

    return t;
}


//left folding wit a unary form (... op pack):
template <typename... Ts>
auto add(Ts... args)
{
    return (... + args);
}

//left folding with a binary form (init op ... op pack):
template <typename... Ts>
auto add_to_one(Ts... args)
{
    return (1 + ... + args);
}
/*
//right folding wit a unary form (pack op ...):
template <typename... Ts>
auto add(Ts... args)
{
	return (args + ...);
}

//right folding with a binary form (pack op ... op init):
template <typename... Ts>
auto add_to_one(Ts... args)
{
	return (args + ... + 1);
}

*/

template <typename T>
struct wrapper
{
    T const& value;
};

template <typename T>
constexpr auto operator<(wrapper<T> const & lhs,
                         wrapper<T> const & rhs)
{
    return wrapper<T> {
            lhs.value < rhs.value ? lhs.value : rhs.value};
}

template <typename... Ts>
constexpr auto min(Ts&&... args)
{
    return (wrapper<Ts>{args} < ...).value;
}


inline void log(std::any const & value)
{
    if (value.has_value())
    {
        auto const& tv = value.type();
        if (tv == typeid(int))
        {
            std::cout << std::any_cast<int>(value) << '\n';
        }
        else if (tv == typeid(std::string))
        {
            std::cout << std::any_cast<std::string>(value) << '\n';
        }
        else if (tv == typeid(double))
        {
            std::cout << std::fixed << std::setprecision(2) << std::any_cast<double>(value) << '\n';
        }
        else if (tv == typeid(char))
        {
            std::cout << std::any_cast<char>(value) << '\n';
        }
        else if (tv == typeid(std::chrono::time_point<std::chrono::system_clock>))
        {
            auto t = std::any_cast<std::chrono::time_point<std::chrono::system_clock>>(value);
            auto now = std::chrono::system_clock::to_time_t(t);
            std::cout << std::put_time(std::localtime(&now), "%F %T")
                      << '\n';
        }
        else
        {
            std::cout << "Unexpected value type: " << '\n';
        }
    }
    else
    {
        std::cout << "(empty)" << '\n';
    }
}

inline bool isPrime(int n)
{
    if (n == 1)
        return false;
    auto ret = true;
    for(int i = 2; i <= static_cast<int>(floor(sqrt(n))); i++)
    {
        if(n % i == 0)
        {
            ret = false;
            break;
        }
    }
    return ret || (n==2);
}

template<typename T, std::size_t size>
auto ascendingSort(T (&arr)[size])
{

    //std::cout << "n = 1 op: size is " << size << std::endl;
    for(int i = 1; i < size; i++)
    {
        //std::cout << "1st for loop = 3 op * n\n";
        for(int j = 0; j < size - i; j++)
        {
            //std::cout << "2nd for loop = 4 op * n\n";
            if (arr[j] > arr[j+1])
            {
                //std::cout << "if statement\n";
                auto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //std::cout << "return 1 op\n";
    return arr;
}

template<typename T>
auto fastExponentiation(T x, T y)
{
    unsigned long long p = 1;
    T s = x, r = y;

    while(r > 0)
    {
        if (r % 2 == 1)
        {
            p = p * s;
        }
        s = s * s;
        r = r / 2.0;
    }
    return p;
}

template<typename T, std::size_t size>
auto y_minus_x(T (&arr)[size],T x, T y)
{
    auto n = size;
    auto k = 0;
    for(size_t i = 1; i < n; i++)
    {
        if (arr[i] + x == y)
        {
            k = k + 1;
        }
        else if (arr[i] + x > y)
        {
            break;
        }

    }
    return k;
}

inline auto double_sum(int ilow, int iMax, int jlow, int jMax)
{
    auto total = 0;
    for(int iLow = ilow;iLow <= iMax; iLow++){
        //std::cout << "outter i: " << iLow << std::endl;
        for(int jLow = jlow;jLow <= jMax; jLow++){
            //std::cout <<"inner j: " << jLow << " total: "<< total << std::endl;
            total = total + (iLow*iLow)+(jLow*jLow);
        }
    }
    return total;
}


#endif //PHYSICSFORMULA_TESTING_H
