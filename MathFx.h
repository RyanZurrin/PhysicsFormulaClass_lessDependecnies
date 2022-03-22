//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_MATHFX_H
#define PHYSICSFORMULA_MATHFX_H
typedef unsigned long long int uli;
#include <cmath>
namespace  rez
{

    /// <summary>
    /// Calculates the factorial of number n
    /// </summary>
    /// <param name="n">The factorial number to calculate.</param>
    /// <returns>the factorial of n</returns>
    inline uli factorial(size_t n) {
        if (n == 0) {
            return 1;
        }
        uli results = 1;
        for (size_t i = 2; i <= n; i++) {
            results *= i;
        }
        return results;
    }


    /// <summary>
    /// In mathematics, a combination is a selection of items from a set that has distinct members,
    /// such that the order of selection does not matter
    /// </summary>
    /// <param name="n">total number of objects in the set.</param>
    /// <param name="r">number of choosing objects from the set.</param>
    /// <returns>number of combinations</returns>
    inline uli nCr(size_t n, size_t r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }

    /// <summary>
    /// In mathematics, a permutation of a set is, loosely speaking, an arrangement of its
    /// members into a sequence or linear order, or if the set is already ordered, a
    /// rearrangement of its elements. The word "permutation" also refers to the act or
    /// process of changing the linear order of an ordered set
    /// </summary>
    /// <param name="n">total number of objects in the set.</param>
    /// <param name="r">subset of n or sample set</param>
    /// <returns>permutations</returns>
    inline uli nPr(size_t n, size_t r) {
        return factorial(n) / factorial(n - r);
    }

    /// <summary>
    /// Expoes the sum.
    /// </summary>
    /// <param name="x">The x.</param>
    /// <returns></returns>
    inline double expoSum(double x) {
        double ans = 0;
        for (int i = 0;pow(x, i) / factorial(i) > 0.001; i++)	{
            ans += pow(x, i) / factorial(i);
        }
        return ans;
    }

}
#endif //PHYSICSFORMULA_MATHFX_H
