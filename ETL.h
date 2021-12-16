//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_ETL_H
#define PHYSICSFORMULA_ETL_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "MatrixND.h"

//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
/**
 * @class ETL
 * @details Extract transform and load, class for reading in data from a csv
 * file and transforms it for use in machine learning and data analysis
 * @author AI coding, implemented by Ryan Zurrin
 * dateBuilt  5/26/2021
 * lastEdit 5/26/2021
 */
template <typename T>
class ETL
{
    std::string dataset;
    std::string delimiter;
    bool header;

public:
    ETL()
    {
        dataset = "";
        delimiter = " ";
        header = false;
    }
    ETL(std::string data, std::string separator, bool head) : dataset(data), delimiter(separator), header(head)
    {}

    std::vector<std::vector<std::string>> readCSV();
   MatrixND<T> CSVtoEigen(std::vector<std::vector<std::string>> ds, int rows, int cols);

    static MatrixND<T> Normalize(MatrixND<T> data, bool normalizeTarget);
    //auto Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean());
    //auto Std(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum())/(data.rows()-1)).sqrt());

    std::tuple<MatrixND<T>,MatrixND<T>,MatrixND<T>,MatrixND<T>>
    TrainTestSplit(MatrixND<T> data, float train_size)const;

    void VectorToFile(std::vector<float> vector, std::string filename)const;
    static void EigenToFile(MatrixND<T> data,const std::string& filename);
};

#endif //PHYSICSFORMULA_ETL_H
template <typename T>
std::vector<std::vector<std::string>> ETL<T>::readCSV()
{

    std::ifstream file(dataset);
    std::vector<std::vector<std::string>> dataString;

    std::string line = "";

    while(getline(file,line)){
        std::vector<std::string> vec;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,delimiter[0])){
            vec.push_back(token);
        }
        dataString.push_back(vec);
    }

    file.close();

    return dataString;
}
template <typename T>
MatrixND<T> ETL<T>::CSVtoEigen(std::vector<std::vector<std::string>>
                                ds, int rows, int cols)
{

    if(header){
        rows = rows - 1;
    }

    MatrixND<T> mat(cols,rows);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; ++j){
            mat(j,i) = atof(ds[i][j].c_str());
        }
    }

    return mat.transpose();
}
template <typename T>
inline std::tuple<MatrixND<T>,MatrixND<T>,MatrixND<T>,MatrixND<T>>
ETL<T>::TrainTestSplit(MatrixND<T> data, float train_size)const
{

    const int rows = static_cast<int>( data.rows());
    const int train_rows = static_cast<int>( round(train_size*rows));
    const int test_rows = rows - train_rows;

    MatrixND<T> train = data.topRows(train_rows);

    MatrixND<T> X_train = train.leftCols(data.cols()-1);
    MatrixND<T> y_train = train.rightCols(1);

    MatrixND<T> test = data.bottomRows(test_rows);

    MatrixND<T> X_test = test.leftCols(data.cols()-1);
    MatrixND<T> y_test = test.rightCols(1);

    return std::make_tuple(X_train, y_train, X_test, y_test);
}
template <typename T>
inline auto Mean(MatrixND<T> data) -> decltype(data.colwise().mean())
{
    return data.colwise().mean();
}
template <typename T>
inline auto Std(MatrixND<T> data) ->
decltype(((data.array().square().colwise().sum())/(data.rows()-1)).sqrt())
{
    return ((data.array().square().colwise().sum())/(data.rows()-1)).sqrt();
}
template <typename T>
inline MatrixND<T> ETL<T>::Normalize(MatrixND<T> data, bool normalizeTarget)
{
    MatrixND<T> dataNorm;
    if(normalizeTarget==true) {
        dataNorm = data;
    } else {
        dataNorm = data.leftCols(data.cols()-1);
    }

    auto mean = dataNorm.colwise().mean();
    MatrixND<T> scaled_data = dataNorm.rowwise() - mean;
    auto std = ((scaled_data.array().square().colwise().sum()) /
                (scaled_data.rows() - 1)).sqrt();

    MatrixND<T> norm = scaled_data.array().rowwise()/std;

    if(normalizeTarget==false) {
        norm.conservativeResize(norm.rows(), norm.cols()+1);
        norm.col(norm.cols()-1) = data.rightCols(1);
    }

    return norm;
}
template <typename T>
inline void ETL<T>::VectorToFile(std::vector<float> vector, std::string filename)const
{
    std::ofstream output_file(filename);
    std::ostream_iterator<float> output_iterator(output_file, "\n");
    std::copy(vector.begin(), vector.end(), output_iterator);
}
template <typename T>
inline void ETL<T>::EigenToFile(MatrixND<T> data,const std::string& filename)
{
    std::ofstream output_file(filename);
    if(output_file.is_open()){
        output_file << data << "\n";
    }
}

