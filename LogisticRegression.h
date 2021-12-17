//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_LOGISTICREGRESSION_H
#define PHYSICSFORMULA_LOGISTICREGRESSION_H

#include "LinearRegression.h"
#include <list>
#include <iostream>
    template<typename T>
    class LogisticRegression {
    public:
        LogisticRegression() {}

        static MatrixND<T> Sigmoid(MatrixND<T> Z);

        static std::tuple<MatrixND<T>, double, double>
        Propagate(MatrixND<T> W, double b, MatrixND<T> X,
                  MatrixND<T> y, double lambda);

        static std::tuple<MatrixND<T>, double, MatrixND<T>, double, std::list<double>>
        Optimize(MatrixND<T> W, double b, MatrixND<T> X,
                 MatrixND<T> y, int num_iter, double learning_rate,
                 double lambda, bool log_cost);

        MatrixND<T>
        Predict(MatrixND<T> W, double b, MatrixND<T> X) const;
    };

#endif //PHYSICSFORMULA_LOGISTICREGRESSION_H
    template<typename T>
    inline MatrixND<T> LogisticRegression<T>::Sigmoid(MatrixND<T> Z) {
        return 1 / (1 + (-Z.array()).exp());
    }
    template<typename T>
    inline std::tuple<MatrixND<T>, double, double>
    LogisticRegression<T>::Propagate(MatrixND<T> W, double b,
                                  MatrixND<T> X,
                                  MatrixND<T> y, double lambda) {
        const int m = static_cast<int>( y.rows());


        MatrixND<T> Z = (W.transpose() * X.transpose()).array() + b;
        MatrixND<T> A = 1 / (1 + (-Z.array()).exp());//Sigmoid(Z);
        auto ce_var1 =
                y.transpose() * (MatrixND<T>) A.array().log().transpose();
        auto ce_var2 = ((MatrixND<T>)(1 - y.array())).transpose();
        auto ce_var3 = (MatrixND<T>)(1 - A.array()).log().transpose();

        auto cross_entropy =
                -(ce_var1 + ce_var2 * ce_var3) / m;
        double l2_reg_cost = W.array().pow(2).sum() * (lambda / (2.0 * m));
        std::cout << "in Propagate(l2 reg cost) = W.array.pow.sum*lamda/2*m: "
                  << l2_reg_cost << endl;

        double cost = static_cast<const double>((cross_entropy.array()[0])) +
                      l2_reg_cost;
        std::cout << "in Propagate(cost) = cross_entrtopy.array[0]+l2regCost: "
                  << cost << endl;
        MatrixND<T> dw =
                (MatrixND<T>)(
                        ((MatrixND<T>)(A - y.transpose()) * X) / m) +
                ((MatrixND<T>)(lambda / m * W)).transpose();
        double db = (A - y.transpose()).array().sum() / m;
        return std::make_tuple(dw, db, cost);
    }
    template <typename T>
    inline std::tuple<MatrixND<T>, double, MatrixND<T>, double, std::list<double>>
    LogisticRegression<T>::Optimize(MatrixND<T> W, double b,
                                    MatrixND<T> X, MatrixND<T> y,
                                 int num_iter,
                                 double learning_rate, double lambda,
                                 bool log_cost) {
        std::list<double> costsList;
        MatrixND<T> dw;
        double db = 0.0, cost = 0.0;

        for (int i = 0; i < num_iter; i++) {
            std::cout << "in Optimize(for prop loop, lambda): " << lambda
                      << endl;
            std::tuple<MatrixND<T>, double, double> propagate =
                    Propagate(W, b, X, y, lambda);
            std::tie(dw, db, cost) = propagate;

            W = W - (learning_rate * dw).transpose();
            b = b - (learning_rate * db);
            if (i % 100 == 0) {
                costsList.push_back(cost);
            }

            if (log_cost && i % 100 == 0) {
                std::cout << "Cost after iteration " << i << ": " << cost
                          << std::endl;
            }
        }

        return std::make_tuple(W, b, dw, db, costsList);
    }
    template <typename T>
    inline MatrixND<T>
    LogisticRegression<T>::Predict(MatrixND<T> W, double b,
                                   MatrixND<T> X) const {
        const int m = static_cast<int>( X.rows());
        MatrixND<T> y_pred = MatrixND<T>::Zero(m).transpose();

        MatrixND<T> Z = (W.transpose() * X.transpose()).array() + b;
        MatrixND<T> A = 1 / (1 + (-Z.array()).exp());//Sigmoid(Z);

        for (int i = 0; i < A.cols(); i++) {
            if (A(0, i) <= 0.5) {
                y_pred(0, i) = 0;
            } else {
                y_pred(0, i) = 1;
            }
        }
        return y_pred.transpose();
    }

