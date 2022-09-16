//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_LINEARALGEBRA_H
#define PHYSICSFORMULA_LINEARALGEBRA_H

#include <iostream>

#include "Constants.h"

class LinearAlgebra {
public:
    LinearAlgebra() = default;

    template<typename VECTOR>
    static auto dotV(VECTOR& v, VECTOR& u)
    {
        auto sum = 0;
        for (auto i = 0; i < v.size(); i++)
        {
            sum += v[i] * u[i];
        }
        return sum;
    }

    template<typename MATRIX>
    static auto dotM(MATRIX& m, MATRIX& n)
    {
        auto sum = 0;
        for (auto i = 0; i < m.size(); i++)
        {
            for (auto j = 0; j < m[i].size(); j++)
            {
                sum += m[i][j] * n[i][j];
            }
        }
        return sum;
    }


    template<typename VECTOR>
    static VECTOR crossV(VECTOR& v, VECTOR& u)
    {
        VECTOR w;
        w[0] = v[1] * u[2] - v[2] * u[1];
        w[1] = v[2] * u[0] - v[0] * u[2];
        w[2] = v[0] * u[1] - v[1] * u[0];
        return w;
    }

    template<typename MATRIX>
    static double determinant(MATRIX& m)
    {
        double det = 0;
        if (m.size() == 1)
        {
            return m[0][0];
        }
        else if (m.size() == 2)
        {
            return m[0][0] * m[1][1] - m[0][1] * m[1][0];
        }
        else
        {
            for (auto i = 0; i < m.size(); i++)
            {
                det += m[0][i] * cofactor(m, 0, i);
            }
        }
        return det;
    }

    template<typename MATRIX>
    static double cofactor(MATRIX& m, int row, int col)
    {
        auto sign = 1;
        if ((row + col) % 2 == 1)
        {
            sign = -1;
        }
        return sign * determinant(minor(m, row, col));
    }


    template<typename MATRIX>
    static MATRIX minor(MATRIX& m, int row, int col)
    {
        MATRIX minor;
        for (auto i = 0; i < m.size(); i++)
        {
            if (i != row)
            {
                vector<double> temp;
                for (auto j = 0; j < m[i].size(); j++)
                {
                    if (j != col)
                    {
                        temp.push_back(m[i][j]);
                    }
                }
                minor.push_back(temp);
            }
        }
        return minor;
    }


    template<typename MATRIX>
    static MATRIX crossM(MATRIX& m, MATRIX& n)
    {
        MATRIX o;
        for (auto i = 0; i < m.size(); i++)
        {
            for (auto j = 0; j < m[i].size(); j++)
            {
                o[i][j] = m[i][j] * n[i][j];
            }
        }
        return o;
    }

    template<typename MATRIX>
    static bool isSquare(MATRIX& m)
    {
        for (auto i = 0; i < m.size(); i++)
        {
            if (m[i].size() != m.size())
            {
                return false;
            }
        }
        return true;
    }

    template<typename MATRIX>
    static bool isDiagonal(MATRIX& m)
    {
        for (auto i = 0; i < m.size(); i++)
        {
            for (auto j = 0; j < m[i].size(); j++)
            {
                if (i != j && m[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    template<typename MATRIX>
    static bool isUpperTriangular(MATRIX& m)
    {
        for (auto i = 0; i < m.size(); i++)
        {
            for (auto j = 0; j < m[i].size(); j++)
            {
                if (i > j && m[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    template<typename MATRIX>
    static bool isLowerTriangular(MATRIX& m)
    {
        for (auto i = 0; i < m.size(); i++)
        {
            for (auto j = 0; j < m[i].size(); j++)
            {
                if (i < j && m[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

};





#endif //PHYSICSFORMULA_LINEARALGEBRA_H
