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


    ETL<string> etl("winedata.csv", ",", true);
    std::vector<std::vector<std::string>> dataSet = etl.readCSV();

    int rows = dataSet.size();
    int cols = dataSet[0].size();

    MatrixND<double> dataMat = etl.CSVtoMatrix(dataSet, rows, cols);

    std::cout << "Data Matrix: " << std::endl;
    //MatrixND<double> tDataMat = dataMat.transpose();

    dataMat.print();
    //cout << dataMat << endl;





    //*************************************************************************
    //Stopping timer and displaying the programs execution time
    //_________________________________________________________________________
    timer.stop();
    timer.displayRunTime("ms");
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
