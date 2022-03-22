//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_RANDOMNUMBERS_H
#define PHYSICSFORMULA_RANDOMNUMBERS_H

#include <functional>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
//#include <map>


class RandomNumbers
{
    int min;
    int max;
    double mean;
    double std;
    std::random_device rd{};
public:
    RandomNumbers();
    RandomNumbers(int min_Mean, int max_Std, string mode = "ud");



    std::mt19937 mt_gen;//32 bit mersenne twister engine with 19,937 bits
    std::uniform_int_distribution<int> ud;//uniform distribution
    std::normal_distribution<double> nd;
    static void generate_and_print_distribution(
            std::function<int(void)> gen, int const iterations = 10000);

    static auto generate_random_integer(int lb, int ub);
    static auto generate_normDis_double(double mean_, double std_);
    static auto generate_random_double(double lb, double ub);


    double return_mean()const;
    double return_std()const;
    int return_min()const;
    int return_max()const;

    void set_min(int min_);
    void set_max(int max_);
    void set_mean(double mean_);
    void set_std(double std_);

    ~RandomNumbers();
};

#endif //PHYSICSFORMULA_RANDOMNUMBERS_H


inline RandomNumbers::RandomNumbers()
{
    min = 1;
    max = 6;
    mean = 5.0;
    std = 2.0;
    mt_gen = std::mt19937{ rd() };
    ud = std::uniform_int_distribution<>{ min, max };
    nd = std::normal_distribution<double>{ mean, std };
}

inline RandomNumbers::RandomNumbers(int min_Mean, int max_Std, string mode)
{
    if (mode == "ud")
    {
        min = min_Mean;
        max = max_Std;
        mean = 5.0;
        std = 2.0;
    }
    else
    {
        min = 1;
        max = 6;
        mean = min_Mean;
        std = max_Std;
    }

    mt_gen = std::mt19937{ rd() };
    ud = std::uniform_int_distribution<>{ min, max };
    nd = std::normal_distribution<double>{ static_cast<double>(min), static_cast<double>(max) };
}

inline void RandomNumbers::generate_and_print_distribution(
        std::function<int(void)> gen, int const iterations)
{
    // map to store the numbers and their repetitions
    auto data = std::map<int, int>{};

    for (auto n = 0; n < iterations; ++n)
        ++data[gen()];

    auto max = std::max_element(
            std::begin(data), std::end(data),
            [](auto kvp1, auto kvp2){
                return kvp1.second < kvp2.second;});

    // print the bars
    for (auto i = max->second / 200; i > 0; --i)
    {
        for (auto kvp : data)
        {
            std::cout
                    << std::fixed << std::setprecision(1) << std::setw(3)
                    << (kvp.second / 200 >= i ? (char)219 : ' ');
        }
        std::cout << '\n';
    }

    //print the numbers
    for (auto kvp : data)
    {
        std::cout
                << std::fixed << std::setprecision(1) << std::setw(3)
                << kvp.first;
    }
    std::cout << '\n';
}

inline auto RandomNumbers::generate_random_integer(int lb, int ub)
{
    std::random_device rd{};
    std::array<int, std::mt19937::state_size> seed_data{};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto eng = std::mt19937{ seq };
    const auto randInt = std::uniform_int_distribution<>{ lb,ub };
    return randInt;
}

inline auto RandomNumbers::generate_random_double(double lb, double ub)
{
    std::random_device rd{};
    std::array<double, std::mt19937::state_size> seed_data{};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto eng = std::mt19937{ seq };
    const auto randDouble = std::uniform_real_distribution<>{ lb,ub };
    return randDouble;
}


inline auto RandomNumbers::generate_normDis_double(double mean_, double std_)
{
    std::random_device rd{};
    std::array<double, std::mt19937::state_size> seed_data{};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto eng = std::mt19937{ seq };
    auto randNormDist = std::normal_distribution<>{ mean_,std_ };
    return randNormDist(eng);
}
inline double RandomNumbers::return_mean() const
{
    return mean;
}

inline double RandomNumbers::return_std() const
{
    return std;
}
inline int RandomNumbers::return_min()const
{
    return min;
}

inline int RandomNumbers::return_max()const
{
    return max;
}
inline void RandomNumbers::set_min(int min_)
{
    min = min_;
    ud = std::uniform_int_distribution<>{ min, max };
}

inline void RandomNumbers::set_max(int max_)
{
    max = max_;
    ud = std::uniform_int_distribution<>{ min, max };
}

inline void RandomNumbers::set_mean(double mean_)
{
    mean = mean_;
    nd = std::normal_distribution<double>{ mean, std };
}

inline void RandomNumbers::set_std(double std_)
{
    std = std_;
    nd = std::normal_distribution<double>{ mean, std };
}


inline RandomNumbers::~RandomNumbers() = default;

/*
 *
 * 	RandomNumbers r{};

	auto mtgen = r.mt_gen;
	auto u_d = r.ud;
	//auto n_d = r.nd;
	r.set_mean(3.0);
	auto n_d = r.nd;

	r.generate_and_print_distribution([&mtgen, &n_d]()
	{
		return static_cast<int>(std::round(n_d(mtgen)));
	});

	for (size_t i = 0; i < 100; i++)
	{
		std::cout << r.generate_random_integer(5, 100) << " ";
	}
	std::cout << std::endl<<std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << r.generate_random_double(1.0, 25.0) << " ";
	}
 */

