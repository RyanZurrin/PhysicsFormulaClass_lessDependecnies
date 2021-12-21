#include <stack>

#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"



int main(int argc, char* argv[])
{
    //starting time do not edit code between solid comment lines
    //_________________________________________________________________________
    RunTimer timer;
    timer.start();
    //_________________________________________________________________________
    //add test code between starred areas
    //*************************************************************************



    vector<double> v1 = {1,2,4,-2,1,0,-2,1,2};
    // test the matrixND class making a random matrix
    MatrixND<double> randMat(v1, 3, 3);
    cout  << "random matrix: " << endl << randMat << endl;

    // adjoint of the randMat
    MatrixND<double> adjugate = randMat.adjoint();
    cout << "adjoint of the random matrix: " << endl << adjugate << endl;

    // finding the inverse of a matrix
    MatrixND<double> invMat = randMat.inverse();
    cout << "inverse of random matrix: " << endl << invMat << endl;
    // finding the determinant of a matrix
    double det = randMat.determinant();
    std::cout << "The determinant of the matrix is: " << det << std::endl;
    // finding the transpose of a matrix
    MatrixND<double> transMat = randMat.transpose();
    cout << "transpose of random matrix: " << endl << transMat << endl;
    // finding the trace of a matrix
    double trace = randMat.trace();
    std::cout << "The trace of the matrix is: " << trace << std::endl;
    // finding the rank of a matrix
    int rank = randMat.rank();
    std::cout << "The rank of the matrix is: " << rank << std::endl;
    // finding the rref of a matrix
    MatrixND<double> rref = randMat.rref();
    cout << "rref of random matrix: " << endl << rref << endl;
    // finding the characteristic polynomial of a matrix
    vector<double> charPoly = randMat.characteristicPolynomial();
    cout << "characteristic polynomial of random matrix: " << endl;
    printVector(charPoly);

    // test multiplication of two matrices
    MatrixND<double> mat1(3,3,1,2,3,4,5,6,7,8,9);
    MatrixND<double> mat2(3,3,1,2,3,4,5,6,7,8,9);
    MatrixND<double> mat3 = mat1 * mat2;
    cout << "mat1 * mat2: " << endl << mat3 << endl;




    double M[3][4] = { {  1, 2, -1,  -4 },
                       {  2, 3, -1, -11 },
                       { -2, 0, -3,  22 } };

    rez::to_reduced_row_echelon_form(M);
    cout << "reduced row echelon form: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
            std::cout << M[i][j] << '\t';
        std::cout << "\n";
    }



    //*************************************************************************
    //Stopping timer and displaying the programs execution time
    //_________________________________________________________________________
    timer.stop();
    timer.displayRunTime("ms");
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
