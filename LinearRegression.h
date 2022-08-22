//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_LINEARREGRESSION_H
#define PHYSICSFORMULA_LINEARREGRESSION_H
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
#include <iostream>
#include "ETL.h"
/**
 * @class LinearRegression
 * @details
 * dateBuilt  5/26/2021
 * lastEdit 5/26/2021
 */
 template <typename T>
class LinearRegression
{

public:
    LinearRegression()
    {}

    /// <summary>
    /// Ordinary least squares (OLS) used to find the slope m of a data set
    /// </summary>
    /// <param name="X_">The x.</param>
    /// <param name="y">The y.</param>
    /// <param name="theta">The theta.</param>
    /// <returns></returns>
    float OLS_Cost(MatrixND<T> X, MatrixND<T> y, MatrixND<T> theta)const;
    std::tuple<VectorND<T>,std::vector<float>>
    GradientDescent(MatrixND<T> X, MatrixND<T> y,
                    VectorND<T> theta, float alpha, int iters)const;
    float RSquared(MatrixND<T> y, MatrixND<T> y_hat)const;
};

#endif //LinearRegression_h
template <typename T>
inline float LinearRegression<T>::OLS_Cost(MatrixND<T> X, MatrixND<T> y, MatrixND<T> theta)const
{

    MatrixND<T> inner = pow(((X*theta)-y).array(),2);

    return static_cast<float>( inner.sum()/(2*X.rows()));
}
template <typename T>
inline std::tuple<VectorND<T>,std::vector<float>>
LinearRegression<T>::GradientDescent(MatrixND<T> X, MatrixND<T> y,
                                  VectorND<T> theta, float alpha, int iters)const
{

    MatrixND<T> temp = theta;

    const int parameters = static_cast<int>( theta.rows());

    std::vector<float> cost;
    cost.push_back(OLS_Cost(X,y,theta));

    for(int i=0; i<iters; ++i){
        MatrixND<T> error = X*theta - y;
        for(int j=0; j<parameters; ++j){
            MatrixND<T> X_i = X.col(j);
            MatrixND<T> term = error.cwiseProduct(X_i);
            temp(j,0) = theta(j,0) - ((alpha/X.rows())*term.sum());
        }
        theta = temp;
        cost.push_back(OLS_Cost(X,y,theta));
    }

    return std::make_tuple(theta,cost);
}
template <typename T>
inline float LinearRegression<T>::RSquared(MatrixND<T> y, MatrixND<T> y_hat)const
{
    std::cout << "in Rsq - y:" << y << std::endl;
    std::cout << "in Rsq - yhat: " << y_hat << std::endl;
    auto num = pow((y-y_hat).array(),2).sum();
    std::cout << "in Rsq num: " << num << std::endl;
    auto den = pow(y.array()-y.mean(),2).sum();
    std::cout << "in Rsq den: " << den << std::endl;
    return static_cast<float>( 1 - num/den);
}




