//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_TRIANGLESOLVER_H
#define PHYSICSFORMULA_TRIANGLESOLVER_H
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin
#include <cmath>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Vector2D.h"

static int triangle_object_count = 0;


class TriangleSolver
{
    void badTriangle();
    template<typename T>
    T negativeNumCheck(T& num);
    template<typename T>
    T negativeNumFix(T& num);
    double pythagoreanTheorem(double, double)const;
    void update_triangle();
    void triangleTypeBySide();
    void triangleTypeByAngle();
    void initiate_triangle(string id);
    void calculate_angleA();
    void calculate_angleB();
    void calculate_angleC();
    void calculate_All_angles();
    void calculate_AllHeight();
    void calculate_heightBase_a(),
            calculate_heightBase_b(),
            calculate_heightBase_c();
    void calculate_medians_abc();
    void findMissingSide();
    void find_base();
    void calculate_area();
    void calculate_perimeter();
    void calculate_rVal();
    void calculate_sVal();
    void calculate_iVal();
    void set_vertices();
    void set_centroid();
    void set_eulersDistance();
    void set_ccc();//sets the circumcenter coordinates
    bool checkSimilarity(TriangleSolver& T);
    bool check_SSS(TriangleSolver&);// by Arnab Kundu
    bool check_SAS(TriangleSolver&);
    bool check_AAA(TriangleSolver&);
    bool cong_SAS(TriangleSolver& t);
    bool cong_ASA(TriangleSolver& t);
    bool cong_AAS(TriangleSolver& t);
    bool cong_SSS(TriangleSolver& t);
    bool cong_HL(TriangleSolver& t);

    TriangleSolver *solve_by_AAA(const double&, const double&, const double&); // three sides known
    TriangleSolver *solve_by_AAS(const double&, const double&, const double&); // two angles and a side not between
    TriangleSolver *solve_by_ASA(const double&, const double&, const double&); // two angles and a side bewteen them
    TriangleSolver *solve_by_SAS(const double&, const double&, const double&); // two sides and the included angle.
    TriangleSolver *solve_by_SSA(const double&, const double&, const double&); //  two sides and one angle that is not the included angle
    TriangleSolver *solve_by_SSS(const double&, const double&, const double&); //  all three sides of a triangle, but no angles

    // member variablesfor keeping track of triangle data
    string ID;
    double max_side;
    double height_a, altHeight_a;
    double height_b, altHeight_b;
    double height_c, altHeight_c;
    double max_height;
    double side_a;
    double side_b;
    double side_c, altSide;
    double angle_A, altAngle_A;
    double angle_B, altAngle_B;
    double angle_C, altAngle_C;
    double area, altArea;
    double perimeter, altPerimeter;
    double sVal, altSval; // Semiperimeter
    double rVal, altRval; // Circumradius
    double iVal, altIval; // inradius
    // these bools are for determining congruency and similarity type
    double median_a, altMedian_a;
    double median_b, altMedian_b;
    double median_c, altMedian_c;
    bool   sssFlag, congSSSflag,
            aaaFlag, congSASflag,
            sasFlag, congASAflag,
            ssaFlag, congAASflag,
            asaFlag, congHLflag,
            aasFlag,
            missingSideFlag,
            altTriFlag;
    string sideType;
    string angleType;
    double eulersDistance;
    vector<pair<double ,double>> vertices;
    pair<double,double> centroid;
    pair<double, double> circumcenterCoordinate;


public:
    TriangleSolver(string id = "");

    /// <summary>
    /// Initializes a new instance of the TriangleSolver class.\n
    /// type of triangle:->("use")\n
    /// <defaulted "sss" = no argument needed>side, side, side->("sss")\n
    /// else use:___________________________________________\n
    /// side angle side->("sas")\n
    /// side, side, angle->("ssa")\n
    /// angleA, angleB, angleC->("aaa")\n
    /// angleA ,side_c, angleB->("asa")\n
    ///	angleA angleC side_c->("aas")\n
    ///	_____________________________________________________
    /// </summary>
    /// <param name="param1">The first parameter.</param>
    /// <param name="param2">The second parameter.</param>
    /// <param name="param3">The third parameter.</param>
    /// <param name="type">Three letter string literal or The type of triangle to be solved.</param>
    /// <param name="id">object identifier if wanted</param>
    TriangleSolver(const double param1, const double param2, const double param3,
                   const string type = "sss", const string id = "");

    TriangleSolver( TriangleSolver&); // copy constructor
    TriangleSolver(TriangleSolver&& t)noexcept;
    TriangleSolver& operator=(TriangleSolver const& t);
    TriangleSolver& operator=(TriangleSolver&& t)noexcept;



    [[nodiscard]] bool checkSides()const;
    [[nodiscard]] bool checkTriangle()const;
    [[nodiscard]] bool checkAngles()const;

    void similarBy(TriangleSolver&);
    bool isCongruent(TriangleSolver& t);
    void congruentBy(TriangleSolver& t);
    void displayTriangleData(std::string label = "")const;
    void showVertices()const;
    void showCentroid()const;
    void showEulersDistance()const;
    void showCircumcenterCoordinates()const;
    void showSides()const;
    void showAngles()const;
    void showAngleType()const;
    void showAreaPerimeter()const;
    void showSide_a()const { cout << "side a: " << side_a<< endl; }
    void showSide_b()const { cout << "side b: " << side_b << endl; }
    void showSide_c()const { cout << "side c: " << side_c << endl; }
    void showAngle_A()const { cout << "angle A: " << angle_A<< endl; }
    void showAngle_B()const { cout << "angle B: " << angle_B<< endl; }
    void showAngle_C()const { cout << "angle C: " << angle_C<< endl; }
    void showArea()const { cout << "area: " << area << endl; }
    void showParameter()const { cout << "parameter: "<< perimeter<< endl; }
    void showMaxHeight()const { cout << "Max Height: " << max_height << endl; }
    void showHeight_a()const { cout << "height_a: " << height_a << endl; }
    void showHeight_b()const { cout << "height_b: " << height_b << endl; }
    void showHeight_c()const { cout << "height_c: " << height_c << endl; }
    void showMedian_a()const { cout << "median_a: " << median_a << endl; }
    void showMedian_b()const { cout << "median_b: " << median_b << endl; }
    void showMedian_c()const { cout << "median_c: " << median_c << endl; }
    void showAllHeights()const {
        cout << "height_a: " << height_a << endl
             << "height_b: " << height_b << endl
             << "height_c: " << height_c << endl;
    }
    void showAllMedians()const {
        cout << "median_a: " << median_a << endl
             << "median_b: " << median_b << endl
             << "median_c: " << median_c << endl;
    }
    void showLargestSide()const { cout << "most stable base: " << max_side << endl; }
    void showCircumradius()const { cout << "circum-radius: " << rVal << endl; }
    void showInRadius()const { cout << "in-radius: " << iVal << endl; }
    void showSemiParameter()const { cout << "semi-parameter: " << sVal << endl; }
    void showCongruencyFlags()const;

    [[nodiscard]] double returnSide_a()const { return side_a; }
    [[nodiscard]] double returnSide_b()const { return side_b; }
    [[nodiscard]] double returnSide_c()const { return side_c; }
    [[nodiscard]] double returnAngle_A()const { return angle_A; }
    [[nodiscard]] double returnAngle_B()const { return angle_B; }
    [[nodiscard]] double returnAngle_C()const { return angle_C; }
    [[nodiscard]] double returnArea()const { return area; };
    [[nodiscard]] double returnPerimeter()const { return perimeter; }
    [[nodiscard]] double returnBase()const { return max_side; }
    [[nodiscard]] double returnMaxHeight()const { return max_height; }
    [[nodiscard]] double returnHeight_a()const { return height_a; }
    [[nodiscard]] double returnHeight_b()const { return height_a; }
    [[nodiscard]] double returnHeight_c()const { return height_c; }
    [[nodiscard]] double returnMedian_a()const { return median_a; }
    [[nodiscard]] double returnMedian_b()const { return median_b; }
    [[nodiscard]] double returnMedian_c()const { return median_c; }
    [[nodiscard]] double returnCircumradius()const { return rVal; }
    [[nodiscard]] double returnSemiPerimeter()const { return sVal; }
    [[nodiscard]] bool returnSAS()const { return sasFlag; }
    [[nodiscard]] bool returnSSS() const { return sssFlag; }
    [[nodiscard]] bool returnAAA() const { return aaaFlag; }
    [[nodiscard]] bool returnSSA()const { return ssaFlag; }
    [[nodiscard]] bool returnASA() const { return asaFlag; }
    [[nodiscard]] bool returnAAS() const { return aasFlag; }

    void setSide_a(double _a);
    void setSide_b(double _b);
    void setSide_c(double _c);
    void setSides(double, double, double);
    void setAngles(double, double, double);
    static int getTriangleObjectCount() { return triangle_object_count; }
    //double setAngle_A(double _A) { angle_A = _A; update_triangle(); }
    //double setAngle_B(double _B) { angle_B = _B; update_triangle(); }
    //double setAngle_C(double _C) { angle_C = _C; update_triangle(); }
    //double setTriangleArea(double tA) { area = tA; update_triangle(); }


    //overloaded relational operators
    bool operator>(const TriangleSolver& s)const { return area > s.area; }
    bool operator>=(const TriangleSolver& s)const { return area >= s.area; }
    bool operator<(const TriangleSolver& s)const { return area < s.area; }
    bool operator<=(const TriangleSolver& s)const { return area <= s.area; }
    bool operator==(const TriangleSolver& s)const { return area == s.area; }
    bool operator!=(const TriangleSolver& s)const { return !(area == s.area); }
    bool operator>(const double& n)const { return area > n; }
    bool operator>=(const double& n)const { return area >= n; }
    bool operator<(const double& n)const { return n < area; }
    bool operator<=(const double& n)const { return n <= area; }
    bool operator==(const double& n)const { return area == n; }
    bool operator!=(const double& n)const { return !(area == n); }

    //overloaded additon operators
    TriangleSolver operator++();
    TriangleSolver operator++(int);
    TriangleSolver operator+(const TriangleSolver&)const;
    TriangleSolver operator+(double)const;
    TriangleSolver& operator+=(const TriangleSolver&);
    friend TriangleSolver operator+(double num, TriangleSolver&);
    friend TriangleSolver operator+(TriangleSolver& v, TriangleSolver& s);
    TriangleSolver& operator+(const TriangleSolver& rhs);
    //friend Triangle operator+(Triangle lhs, const Triangle&);

    // overloaded subtraction operators
    TriangleSolver operator-()const;
    TriangleSolver operator--();
    TriangleSolver operator--(int);
    TriangleSolver operator-(const TriangleSolver&)const;
    TriangleSolver operator-(double)const;
    TriangleSolver& operator-=(const TriangleSolver&);
    friend TriangleSolver operator-(double num, TriangleSolver&);
    friend TriangleSolver operator-(TriangleSolver&, const TriangleSolver&);

    TriangleSolver operator*(double value)const;   // multiply

    friend TriangleSolver operator*(double s, TriangleSolver& v);
    friend TriangleSolver operator*(TriangleSolver& v, TriangleSolver& s);
    TriangleSolver operator/(double)const;    //division
    TriangleSolver operator/(const TriangleSolver&)const;


    friend ostream& operator<<(ostream&, const TriangleSolver&);
    friend istream& operator>>(istream&, TriangleSolver&);

    ~TriangleSolver() = default;




};
#endif //PHYSICSFORMULA_TRIANGLESOLVER_H

/*______________________________________________________________________________
*/
inline TriangleSolver::TriangleSolver(string id)
{
    triangle_object_count++;
    initiate_triangle(id);
}


inline TriangleSolver::TriangleSolver(const double param1, const double param2, const double param3, const string type, const string id)
{	//sss='s', sas='a', ssa ='b', aaa='l', asa='i', aas='n'
    triangle_object_count++;
    initiate_triangle(id);
    if (type == "sss" || type == "SSS") // side, side, side(sss)
    {
        solve_by_SSS(param1, param2, param3);
    }
    else if (type == "sas" || type == "SAS") // side angle side(sas)
    {
        solve_by_SAS(param1, param2, param3);
    }
    else if (type == "ssa" || type == "SSA") // side, side, angle(ssa)
    {
        solve_by_SSA(param1, param2, param3);
    }
    else if (type == "aaa" || type == "AAA") // angleA, angleB, angleC(aaa)
    {
        solve_by_AAA(param1, param2, param3);
    }
    else if (type == "asa" || type == "ASA") // angleA ,side_c, angleB (asa)
    {
        solve_by_ASA(param1, param2, param3);
    }
    else if (type == "aas" || type == "AAS") // angleA angleC side_c (aas)
    {
        solve_by_AAS(param1, param2, param3);
    }
}

inline TriangleSolver::TriangleSolver(TriangleSolver& t)
{
    ID = "triangle_" + std::to_string(triangle_object_count);
    side_a = t.side_a;
    side_b = t.side_b;
    side_c = t.side_c;
    altSide = t.altSide;
    angle_A = t.angle_A;
    angle_B = t.angle_B;
    angle_C = t.angle_C;
    altAngle_A = t.altAngle_A;
    altAngle_B = t.altAngle_B;
    altAngle_C = t.altAngle_C;
    perimeter = t.perimeter;
    altPerimeter = t.altPerimeter;
    max_height = t.max_height;
    max_side = t.max_side;
    sVal = t.sVal;
    rVal = t.rVal;
    iVal = t.iVal;
    altRval = t.altRval;
    altSval = t.altSval;
    altIval = t.altIval;
    area = t.area;
    altArea = t.altArea;
    sideType = t.sideType;
    sssFlag = t.sssFlag; congSSSflag = t.congSSSflag;
    aaaFlag = t.aaaFlag;
    sasFlag = t.sasFlag; congSASflag = t.congSASflag;
    ssaFlag = t.ssaFlag;
    asaFlag = t.asaFlag; congASAflag = t.congASAflag;
    aasFlag = t.aasFlag; congAASflag = t.congAASflag;
    altTriFlag = t.altTriFlag; congHLflag = t.congHLflag;
    height_a = t.height_a;
    height_b = t.height_b;
    height_c = t.height_c;
    altHeight_a = t.altHeight_a;
    altHeight_b = t.altHeight_b;
    altHeight_c = t.altHeight_c;
    median_a = t.median_a;
    median_b = t.median_b;
    median_c = t.median_c;
    altMedian_a = t.altMedian_a;
    altMedian_b = t.altMedian_b;
    altMedian_c = t.altMedian_c;
    missingSideFlag = t.missingSideFlag;
    vertices = t.vertices;
    centroid = t.centroid;
    circumcenterCoordinate = t.circumcenterCoordinate;
    eulersDistance = t.eulersDistance;
}

inline TriangleSolver::TriangleSolver(TriangleSolver&& t)noexcept
{
    triangle_object_count++;
    ID = "Triangle_" + std::to_string(triangle_object_count);
    side_a = t.side_a;
    side_b = t.side_b;
    side_c = t.side_c;
    altSide = t.altSide;
    angle_A = t.angle_A;
    angle_B = t.angle_B;
    angle_C = t.angle_C;
    altAngle_A = t.altAngle_A;
    altAngle_B = t.altAngle_B;
    altAngle_C = t.altAngle_C;
    perimeter = t.perimeter;
    altPerimeter = t.altPerimeter;
    max_height = t.max_height;
    max_side = t.max_side;
    sVal = t.sVal;
    rVal = t.rVal;
    iVal = t.iVal;
    altRval = t.altRval;
    altSval = t.altSval;
    altIval = t.altIval;
    area = t.area;
    altArea = t.altArea;
    sideType = t.sideType;
    sssFlag = t.sssFlag; congSSSflag = t.congSSSflag;
    aaaFlag = t.aaaFlag;
    sasFlag = t.sasFlag; congSASflag = t.congSASflag;
    ssaFlag = t.ssaFlag;
    asaFlag = t.asaFlag; congASAflag = t.congASAflag;
    aasFlag = t.aasFlag; congAASflag = t.congAASflag;
    altTriFlag = t.altTriFlag; congHLflag = t.congHLflag;
    height_a = t.height_a;
    height_b = t.height_b;
    height_c = t.height_c;
    altHeight_a = t.altHeight_a;
    altHeight_b = t.altHeight_b;
    altHeight_c = t.altHeight_c;
    median_a = t.median_a;
    median_b = t.median_b;
    median_c = t.median_c;
    altMedian_a = t.altMedian_a;
    altMedian_b = t.altMedian_b;
    altMedian_c = t.altMedian_c;
    missingSideFlag = t.missingSideFlag;
    vertices = t.vertices;
    centroid = t.centroid;
    circumcenterCoordinate = t.circumcenterCoordinate;
    eulersDistance = t.eulersDistance;
}


inline TriangleSolver& TriangleSolver::operator=(TriangleSolver const& right)
{
    //cout << "in the overloaded Triangle =operator";
    if (this != &right) {
        this->side_a = right.side_a;
        this->side_b = right.side_b;
        this->side_c = right.side_c;
        this->update_triangle();
        return *this;
    }
    return *this;
}

inline TriangleSolver& TriangleSolver::operator=(TriangleSolver&& t) noexcept
{
    //cout << "in the overloaded Triangle =operator";
    if (this != &t) {
        this->side_a = t.side_a;
        this->side_b = t.side_b;
        this->side_c = t.side_c;
        this->update_triangle();
        return *this;
    }
    return *this;
}

inline void TriangleSolver::update_triangle()
{

    if (angle_C > 0 && missingSideFlag == 1) {
        calculate_perimeter();
        calculate_sVal();
        calculate_area();
        calculate_rVal();
        calculate_iVal();
        calculate_angleA();
        calculate_angleB();
        find_base();
        calculate_AllHeight();
        calculate_medians_abc();
        triangleTypeByAngle();
        triangleTypeBySide();
        set_vertices();
        set_centroid();
        set_eulersDistance();
    }
    else if (max_side > 0 && max_height > 0) {
        calculate_area();
        calculate_All_angles();
        calculate_rVal();
        calculate_sVal();
        calculate_perimeter();
        calculate_iVal();
        calculate_AllHeight();
        calculate_medians_abc();
        triangleTypeByAngle();
        triangleTypeBySide();
        set_vertices();
        set_centroid();
        set_eulersDistance();
        set_ccc();
    }
    else if (side_a > 0 && side_b > 0 && side_c > 0 &&
             angle_A > 0 && angle_B > 0 && angle_C > 0)
    {
        calculate_perimeter();
        calculate_sVal();
        calculate_area();
        calculate_rVal();
        calculate_iVal();
        find_base();
        calculate_AllHeight();
        calculate_medians_abc();
        triangleTypeByAngle();
        triangleTypeBySide();
        set_vertices();
        set_centroid();
        set_eulersDistance();
        set_ccc();
    }
    else {
        calculate_perimeter();
        calculate_sVal();
        calculate_area();
        calculate_rVal();
        calculate_iVal();
        calculate_angleA();
        calculate_angleB();
        calculate_angleC();
        find_base();
        calculate_AllHeight();
        calculate_medians_abc();
        triangleTypeByAngle();
        triangleTypeBySide();
        set_vertices();
        set_centroid();
        set_eulersDistance();
        set_ccc();
    }
    triangleTypeByAngle();
    triangleTypeBySide();
}

inline void TriangleSolver::badTriangle()
{

    double _a, _b, _c;
    do
    {
        cout << "Your triangle is no good" << endl
             << "Lets fix it" << endl;
        cout << "**please enter side a: ";
        cin >> _a;
        if (_a <= 0) {
            negativeNumFix(_a);
        }
        else
            side_a = _a;

        cout << "**please enter side b: ";
        cin >> _b;
        if (_b <= 0) {
            negativeNumFix(_b);
        }
        else
            side_b = _b;

        cout << "**please enter side c: ";
        cin >> _c;
        if (_c <= 0) {
            negativeNumFix(_c);
        }
        else
            side_c = _c;

        if (checkTriangle() == true) {
            update_triangle();
        }
        cin.clear();
        cin.ignore(100, '\n');
    }
    while (!checkSides() || !cin);

}

inline void TriangleSolver::initiate_triangle(string id)
{
    if (id == "")
    {
        ID = "Triangle_" + std::to_string(triangle_object_count);
    }
    else
    {
        ID = id;
    }
    max_side = 0.0;
    max_height = 0.0;
    height_a = 0.0;
    height_b = 0.0;
    height_c = 0.0;
    altHeight_a = 0.0;
    altHeight_b = 0.0;
    altHeight_c = 0.0;
    side_a = 0.0;
    side_b = 0.0;
    side_c = 0.0;
    altSide = 0.0;
    angle_A = 0.0;
    angle_B = 0.0;
    angle_C = 0.0;
    altAngle_A = 0.0;
    altAngle_B = 0.0;
    altAngle_C = 0.0;
    area = 0.0;
    altArea = 0.0;
    perimeter = 0.0;
    altPerimeter = 0.0;
    median_a = 0.0; altMedian_a = 0.0;
    median_b = 0.0; altMedian_b = 0.0;
    median_c = 0.0; altMedian_c = 0.0;
    sssFlag = false;
    aaaFlag = false;
    sasFlag = false;
    ssaFlag = false;
    asaFlag = false;
    aasFlag = false;
    congSASflag = false;
    congSSSflag = false;
    congASAflag = false;
    congAASflag = false;
    congHLflag = false;
    missingSideFlag = false;
    altTriFlag = false;
    rVal = 0.0;
    sVal = 0.0;
    iVal = 0.0;
    altRval = 0.0;
    altSval = 0.0;
    altIval = 0.0;
    eulersDistance = 0.0;
}

inline void TriangleSolver::calculate_angleA()
{
    if (angle_B > 0 && angle_C > 0) {
        angle_A = 180 - (angle_B + angle_C);
    }
    else {
        auto cosA = (pow(side_b, 2) + pow(side_c, 2) -
                     pow(side_a, 2)) / (2.0 * side_b * side_c);
        angle_A = acos(cosA)*DEGREE;
    }
}

inline void TriangleSolver::calculate_angleB()
{
    if (angle_A > 0 && angle_C > 0) {
        angle_B = 180 - (angle_A + angle_C);
    }
    else {
        auto cosB = (pow(side_c, 2) + pow(side_a, 2) -
                     pow(side_b, 2)) / (2.0 * side_c * side_a);
        angle_B =  acos(cosB)*DEGREE;
    }
}

inline void TriangleSolver::calculate_angleC()
{
    if (angle_B > 0 && angle_A > 0) {
        angle_C = 180 - (angle_A + angle_B);
    }
    else {
        auto cosC = (pow(side_a, 2) + pow(side_b, 2) -
                     pow(side_c, 2)) / (2.0 * side_a * side_b);
        angle_C =  acos(cosC)*DEGREE;
    }

}

inline void TriangleSolver::calculate_All_angles()
{
    calculate_angleA();
    calculate_angleB();
    calculate_angleC();
}


inline void TriangleSolver::calculate_AllHeight()
{
    max_height = 2 * area / (max_side);
    calculate_heightBase_a();
    calculate_heightBase_b();
    calculate_heightBase_c();

}

inline void TriangleSolver::calculate_heightBase_a()
{
    height_a = (2 * area) / side_a;
}

inline void TriangleSolver::calculate_heightBase_b()
{
    height_b = (2 * area) / side_b;
}

inline void TriangleSolver::calculate_medians_abc()
{
    double a = 0.0, b = 0.0, c = 0.0;
    a = side_a * side_a;
    b = side_b * side_b;
    c = side_c * side_c;
    median_a = sqrt(((2 * b) + (2 * c) - a) / 4);
    median_b = sqrt(((2 * a) + (2 * c) - b) / 4);
    median_c = sqrt(((2 * a) + (2 * b) - c) / 4);
}

inline void TriangleSolver::calculate_heightBase_c()
{
    height_c = (2 * area) / side_c;
}

inline void TriangleSolver::findMissingSide()
{
    missingSideFlag = true;
    double a, b, angle=0;
    a = side_a;
    b = side_b;
    angle = angle_C;
    if (angle == 90) {
        side_c = pythagoreanTheorem(a, b);
    }
    else {
        side_c = sqrt((a * a) + (b * b) - 2 * a * (b * cos(angle*RADIAN)));
    }
    update_triangle();

}

inline bool TriangleSolver::checkAngles()const
{
    double temp = angle_A + angle_B + angle_C;
    if (temp > 180)
        return false;
    return true;
}

inline double TriangleSolver::pythagoreanTheorem(double a, double b)const
{
    return sqrt(a * a + b * b);
}


inline void TriangleSolver::find_base()
{
    const int size = 3;
    double a, b, c;
    a = side_a;
    b = side_b;
    c = side_c;
    vector<double> biggestSide = { a, b,  c };
    auto min_pos =
            min_element(biggestSide.cbegin(), biggestSide.cend());
    auto max_pos =
            max_element(biggestSide.cbegin(), biggestSide.cend());
    sort(biggestSide.begin(), biggestSide.end());
    max_side = biggestSide[2];
}
inline void TriangleSolver::calculate_area()
{
    if (max_side > 0 && max_height > 0) {
        area = (max_height * max_side) / 2;
    }else
        area = sqrt(sVal * (sVal - side_a) * (sVal - side_b) * (sVal - side_c));

}
inline void TriangleSolver::calculate_perimeter()
{
    perimeter = side_a + side_b + side_c;
}
inline void TriangleSolver::calculate_rVal()
{
    rVal = (side_a * side_b * side_c) / (4 * area);
}
inline void TriangleSolver::calculate_sVal()
{
    sVal = perimeter / 2;
}
inline void TriangleSolver::calculate_iVal()
{
    iVal = area / sVal;
}
inline void TriangleSolver::set_vertices()
{
    pair<double, double> a, b, c;
    a.first = 0;
    a.second = 0;
    b.first = side_c;
    b.second = 0;
    c.first = side_b * (pow(side_b, 2) + pow(side_c, 2) -
                        pow(side_a, 2)) / (2.0 * side_b * side_c);
    c.second = sqrt(pow(side_b, 2) - pow(c.first, 2));
    vertices = vector<pair<double, double>>{ a,b,c };

}
inline void TriangleSolver::set_centroid()
{
    centroid.first = (vertices[0].first + vertices[1].first + vertices[2].first) / 3.0;
    centroid.second = (vertices[0].second + vertices[1].second + vertices[2].second) / 3.0;
}
inline void TriangleSolver::set_eulersDistance()
{
    eulersDistance = sqrt(pow(rVal, 2) - (2 * iVal * rVal));
}
inline void TriangleSolver::set_ccc()
{
    auto d = 2.0 * (vertices[1].first * vertices[2].second -
                    vertices[1].second * vertices[2].first);

    circumcenterCoordinate.first = (vertices[2].second * (pow(vertices[1].first, 2) +
                                                          pow(vertices[1].second, 2)) -	(vertices[1].second * (pow(vertices[2].first, 2) +
                                                                                                                  pow(vertices[2].second, 2)))) / d;

    circumcenterCoordinate.second = (vertices[1].first * (pow(vertices[2].first, 2) +
                                                          pow(vertices[2].second, 2)) -	(vertices[2].first * (pow(vertices[1].first, 2) +
                                                                                                                 pow(vertices[1].second, 2)))) / d;
}
inline TriangleSolver *TriangleSolver::solve_by_AAA(const double& a1, const double& a2, const double& a3)
{
    angle_A = a1; angle_B = a2; angle_C = a3;

    double temp_a=0.0, temp_b=0.0, temp_c=0.0;

    cout << "You need at least one side to solve a triangle\n";
    do {
        cout << "Enter a side length now for the sides you know\n"
             << "if you do not know a side just enter a 0\n"
             << "seperate with spaces input order is sides> a, b, c\n>";
        cin >> temp_a >> temp_b >> temp_c;
        if (!cin) {
            cout << "**ERROR**";
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (!cin);
    if (temp_a < 0) {
        side_a = abs(temp_a);
    }
    else
        side_a = temp_a;

    if (temp_b < 0) {
        side_b = abs(temp_b);
    }
    else
        side_b = temp_b;

    if (temp_c < 0) {
        side_c = abs(temp_c);
    }
    else
        side_c= temp_c;

    if (side_a > 0) {
        side_b = sin(angle_B * RADIAN) * side_a / sin(angle_A * RADIAN);
        side_c = sin(angle_C * RADIAN) * side_a / sin(angle_A * RADIAN);
    }
    else if (side_b > 0) {
        side_a = sin(angle_A * RADIAN) * side_b / sin(angle_B * RADIAN);
        side_c = sin(angle_C * RADIAN) * side_b / sin(angle_B * RADIAN);
    }
    else if (side_c > 0) {
        side_a = sin(angle_A * RADIAN) * side_c / sin(angle_C * RADIAN);
        side_b = sin(angle_B * RADIAN) * side_c / sin(angle_C * RADIAN);
    }
    else
        cout << "You didn't enter a valid side lenght, no further computations made on triangle";

    if (temp_a > 0.0) {
        side_a = temp_a;
    }
    if (temp_b > 0.0) {
        side_b = temp_b;
    }
    if (temp_c > 0.0) {
        side_c = temp_c;
    }

    if (checkTriangle() == true) {
        update_triangle();
    }
    else
        cout << "\nthe data entered does not make a valid Triangle. Please try again.";

    return this;
}
inline TriangleSolver *TriangleSolver::solve_by_AAS(const double& a1, const double& a2, const double& s)
{
    //double tmp1, tmp2, tmp3, tmp4;
    angle_A = a1;
    angle_C = a2;
    side_c = s;
    calculate_angleB();
    side_a = sin(a1 * RADIAN) * s / sin(a2 * RADIAN);
    side_b = sin(angle_B*RADIAN) * s / sin(a2 * RADIAN);


    if (checkTriangle() == true) {
        update_triangle();
    }
    return this;
}
inline TriangleSolver *TriangleSolver::solve_by_ASA(const double& a1, const double& s, const double& a2)
{
    angle_A = a1;
    side_c = s;
    angle_B = a2;

    calculate_angleC();

    side_b = sin(angle_B*RADIAN) * s/sin(angle_C*RADIAN);
    side_a = sin(angle_A*RADIAN) * s/sin(angle_C*RADIAN);

    if (checkTriangle() == true) {
        update_triangle();
    }
    return this;
}
inline TriangleSolver* TriangleSolver::solve_by_SAS(const double &s1, const double &a, const double &s2)
{
    side_a = s1;
    angle_C = a;
    side_b = s2;
    findMissingSide();
    return this;
}
inline TriangleSolver* TriangleSolver::solve_by_SSA(const double& s1, const double& s2, const double& _a)
{
    double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;

    side_a = s1;
    side_b = s2;
    angle_A = _a;
    t1 = s2 / s1;
    t2 = sin(_a * RADIAN);
    t3 = (t1 * t2);
    angle_B = asin(t3) * DEGREE;
    calculate_angleC();
    t4 = side_a * sin(angle_C*RADIAN);
    side_c = t4 / sin(angle_A*RADIAN);
    //side_c = sqrt((s1 * s1) + (s2 * s2) - 2 * s1 * s2 * cos(angle_C));
    if (checkTriangle() == true) {
        update_triangle();
    }
    else
        cout << "this is a bad tringle" << endl;
    double check = sin(angle_B * RADIAN);
    if (side_b > side_a && check >=0 && check <=1) // checking if an alternate triangle can be made
    {											   // and if so then calculates the alternate data.
        altTriFlag = true;
        altAngle_B = 180 - angle_B;
        altAngle_C = 180 - (angle_A + altAngle_B);
        altSide = side_a * sin(altAngle_C * RADIAN) / sin(angle_A * RADIAN);
        altArea = ( side_a * side_b ) * sin(altAngle_C*RADIAN) / 2;
        altPerimeter = side_a + side_b + altSide;
        altHeight_a = 2 * altArea / side_a;
        altHeight_b = 2 * altArea / side_b;
        altHeight_c = 2 * altArea / altSide;
    }

    return this;

}
inline TriangleSolver *TriangleSolver::solve_by_SSS(const double& s1, const double& s2, const double& s3) //law of cosines to solve angle C
{
    side_a = s1;
    side_b = s2;
    side_c = s3;
    if (checkSides() == true) {
        update_triangle();
    }
    else {
        badTriangle();
    }
    return this;
}


inline bool TriangleSolver::check_SSS(TriangleSolver& t)
{

    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };
    //double simi_sss(double s1[], double s2[]);

    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    // Check for SSS
    if (s1[0] / s2[0] == s1[1] / s2[1] &&
        s1[1] / s2[1] == s1[2] / s2[2] &&
        s1[2] / s2[2] == s1[0] / s2[0])
    {
        sssFlag = true;
        return true;
    }
    sssFlag = false;
    return false;

}
inline bool TriangleSolver::check_SAS(TriangleSolver& t)
{// Function for SAS similarity

    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };

    double a1[] = { angle_A, angle_B, angle_C };
    double a2[] = { t.angle_A, t.angle_B, t.angle_C };

    sort(a1, a1 + 3);
    sort(a2, a2 + 3);
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    // Check for SAS

    // angle b / w two smallest
    // sides is largest.
    if (s1[0] / s2[0] == s1[1] / s2[1])
    {
        if (a1[2] == a2[2])
        {
            sasFlag = true;
            return true;
        }
    }
    if (s1[1] / s2[1] == s1[2] / s2[2])
    {
        if (a1[0] == a2[0])
        {
            sasFlag = true;
            return true;
        }
    }
    if (s1[2] / s2[2] == s1[0] / s2[0])
    {
        if (a1[1] == a2[1])
        {
            sasFlag = true;
            return true;
        }
    }
    sasFlag = false;
    return false;

}

inline bool TriangleSolver::check_AAA(TriangleSolver& t)
{
    double a1[] = { angle_A, angle_B, angle_C };
    double a2[] = { t.angle_A, t.angle_B, t.angle_C };

    sort(a1, a1 + 3);
    sort(a2, a2 + 3);

    // Check for AAA
    if (a1[0] == a2[0] &&
        a1[1] == a2[1] &&
        a1[2] == a2[2])
    {
        aaaFlag = true;
        return true;
    }
    aaaFlag = false;
    return false;
}
inline bool TriangleSolver::cong_SAS(TriangleSolver& t)
{
    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };

    double a1[] = { angle_A, angle_B, angle_C };
    double a2[] = { t.angle_A, t.angle_B, t.angle_C };

    sort(a1, a1 + 3);
    sort(a2, a2 + 3);
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    if (s1[0] == s2[0] && s1[1] == s2[1])
    {
        if (a1[2] == a2[2])
        {
            congSASflag = true;
            return true;
        }
    }
    if (s1[1] == s2[1] && s1[2] == s2[2])
    {
        if (a1[0] == a2[0])
        {
            congSASflag = true;
            return true;
        }
    }
    if (s1[2] == s2[2] && s1[0] == s2[0])
    {
        if (a1[1] == a2[1])
        {
            congSASflag = true;
            return true;
        }
    }
    sasFlag = false;
    return false;
}
inline bool TriangleSolver::cong_ASA(TriangleSolver& t)
{
    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };

    double a1[] = { angle_A, angle_B, angle_C };
    double a2[] = { t.angle_A, t.angle_B, t.angle_C };

    sort(a1, a1 + 3);
    sort(a2, a2 + 3);
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    if (a1[0] == a2[0] && a1[1] == a2[1])
    {
        if (s1[2] == s2[2])
        {
            congASAflag = true;
            return true;
        }
    }
    if (a1[1] == a2[1] && a1[2] == a2[2])
    {
        if (s1[0] == s2[0])
        {
            congASAflag = true;
            return true;
        }
    }
    if (a1[2] == a2[2] && a1[0] == a2[0])
    {
        if (s1[1] == s2[1])
        {
            congASAflag = true;
            return true;
        }
    }
    sasFlag = false;
    return false;
}
inline bool TriangleSolver::cong_AAS(TriangleSolver& t)
{
    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };

    double a1[] = { angle_A, angle_B, angle_C };
    double a2[] = { t.angle_A, t.angle_B, t.angle_C };

    sort(a1, a1 + 3);
    sort(a2, a2 + 3);
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    if (a1[0] == a2[0] && a1[1] == a2[1])
    {
        if (s1[0] == s2[0] || s1[1] == s2[1])
        {
            congAASflag = true;
            return true;
        }
    }
    if (a1[1] == a2[1] && a1[2] == a2[2])
    {
        if (s1[1] == s2[1] || s1[2] == s2[2])
        {
            congAASflag = true;
            return true;
        }
    }
    if (a1[2] == a2[2] && a1[0] == a2[0])
    {
        if (s1[0] == s2[0] || s1[2] == s2[2])
        {
            congAASflag = true;
            return true;
        }
    }
    sasFlag = false;
    return false;
}
inline bool TriangleSolver::cong_SSS(TriangleSolver& t)
{
    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    if (s1[0]==s2[0] && s1[1]==s2[1] && s1[2]==s2[2])
    {
        congSSSflag = true;
        return true;
    }
    return false;
}
inline bool TriangleSolver::cong_HL(TriangleSolver& t)
{
    double s1[] = { side_a, side_b, side_c };
    double s2[] = { t.side_a, t.side_b, t.side_c };
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);


    if (s1[2] == s2[2])
    {
        if (s1[1] == s2[1] || s1[0]== s2[0])
        {
            congHLflag = true;
            return true;
        }
    }

    return false;
}
/*______________________________________________________________________________
*/



inline bool TriangleSolver::checkSides()const
{
    if (
            side_a + side_b > side_c &&
            side_c + side_b > side_a &&
            side_a + side_c > side_b
            )
        return true;
    else
        return false;
}

inline bool TriangleSolver::checkTriangle()const
{
    if(checkSides()==true&&checkAngles()==true)
        return true;
    return false;
}

inline bool TriangleSolver::checkSimilarity(TriangleSolver &T)
{
    check_AAA(T);
    check_SAS(T);
    check_SSS(T);
    if (sssFlag == true ||
        sasFlag == true ||
        sssFlag == true
            )
        return true;

    return false;

}

inline void TriangleSolver::similarBy(TriangleSolver &T)
{
    if(checkSimilarity(T)==true){
        cout<< ID << " is similar with "<< T.ID << " by: ";
        if (aaaFlag == 1) cout << "AAA ";
        if (sssFlag == 1) cout << "SSS ";
        if (sasFlag == 1) cout << "SAS ";
        std::cout << endl;
    }
    else
        cout << ID << " is not similar with " << T.ID << std::endl;

}

inline bool TriangleSolver::isCongruent(TriangleSolver& t)
{
    cong_AAS(t);
    cong_ASA(t);
    cong_SAS(t);
    cong_SSS(t);
    cong_HL(t);
    if (congAASflag == true ||
        congSASflag == true ||
        congASAflag == true ||
        congSSSflag == true ||
        congHLflag ==true

            )
        return true;

    return false;
}

inline void TriangleSolver::congruentBy(TriangleSolver& t)
{
    if (isCongruent(t) == true) {
        cout << ID << " is congruent with " << t.ID << " by: ";
        if (congSASflag == 1) cout << "SAS ";
        if (congAASflag == 1) cout << "AAS ";
        if (congASAflag == 1) cout << "ASA ";
        if (congSSSflag == 1) cout << "SSS ";
        if (congHLflag == 1) cout << "HL ";
        std::cout << endl;
    }
    else
        cout << ID << " is not congruent with " << t.ID << std::endl;

}

inline void TriangleSolver::triangleTypeBySide()
{
    if (!checkSides()) {
        //cout << "Not a valid triangle" << endl;
        sideType = "invalid";
    }
    else {
        if (side_a == side_b && side_b == side_c) {
            //cout << "Equilateral" << endl;
            sideType = "Equilateral";
        }
        else if (side_a == side_b || side_b == side_c || side_c == side_a) {
            //cout << "Isosceles" << endl;
            sideType = "Isosceles";
        }
        else {
            //cout << "scalene" << endl;
            sideType = "Scalene";
        }

    }
}

inline void TriangleSolver::triangleTypeByAngle()
{
    double a, b, c;
    a = angle_A;
    b = angle_B;
    c = angle_C;

    if (!checkAngles()) {
        //cout << "Not a valid triangle" << endl;
        //throw ExceptionHandler.
        angleType = "invalid";
    }
    else {
        double longest = c;

        if (longest < a) {
            c = longest;
            longest = b;
            a = c;
        }

        if (longest < b) {
            c = longest;
            longest = b;
            b = c;

        }
        if (a * a + b * b == longest * longest || a == 90 || b == 90 || c==90) {
            //cout << "This is a right-angled triangle.\n";
            angleType = "Right";
        }
        else if (a * a + b * b > longest * longest) {
            //cout << "This is an acute-angled triangle.\n";
            angleType = "Acute";
        }
        else
            //cout << "This is an obtuse-angled triangle.\n";
            angleType = "Obtuse";
    }
}


inline void TriangleSolver::displayTriangleData(std::string label) const
{
    std::cout << ((label == "") ? ID : label);
    showAngleType();
    showSides();
    showAngles();
    showParameter();
    showSemiParameter();
    showArea();
    showInRadius();
    showCircumradius();
    showEulersDistance();
    showAllMedians();
    showAllHeights();
    showVertices();
    showCircumcenterCoordinates();
    showCentroid();
    if (altTriFlag == true) {

        cout << "\nthis Triangle has an alternative" << endl;
        cout << "alt angle B: " << altAngle_B << endl;
        cout << "alt angle C: " << altAngle_C << endl;
        cout << "alt side c: " << altSide << endl;
        cout << "alt area: " << altArea << endl;
        cout << "alt perimeter: " << altPerimeter << endl;
        cout << "alt height_a: " << altHeight_a << endl;
        cout << "alt height_b: " << altHeight_b << endl;
        cout << "alt height_c: " << altHeight_c << endl;
    }
    cout << endl;
}

inline void TriangleSolver::showSides() const
{
    showSide_a();
    showSide_b();
    showSide_c();
}

inline void TriangleSolver::showAngles() const
{
    showAngle_A();
    showAngle_B();
    showAngle_C();

}
inline void TriangleSolver::showVertices()const
{
    size_t it = 0;
    std::cout << "Vertex coordinates:" << setprecision(6);
    for (const auto& v : vertices)
    {
        std::cout << "(" << v.first << "," << v.second
                  << ((it < 2) ? "), " : ")");
        it++;
    }
    std::cout << std::endl;
}
inline void TriangleSolver::showCentroid() const
{
    std::cout << "Centroid: (" << centroid.first
              << "," << centroid.second << ")" <<std::endl;
}
inline void TriangleSolver::showEulersDistance() const
{
    std::cout << "Euler's distance: " << eulersDistance;
    std::cout << std::endl ;
}
inline void TriangleSolver::showCircumcenterCoordinates() const
{
    std::cout << "Circumcenter coordinates: (" << circumcenterCoordinate.first
              << "," << circumcenterCoordinate.second << ")" << std::endl;
}
inline void TriangleSolver::showCongruencyFlags() const
{
    cout << "sssFlag: " << sssFlag << endl;
    cout << "sasFlag: " << sasFlag << endl;
    cout << "aaaFlag: " << aaaFlag << endl;
}

inline void TriangleSolver::showAngleType() const
{
    cout << "\ntype: " << angleType << "  " << sideType << endl;
}
inline void TriangleSolver::showAreaPerimeter() const
{
    showArea();
    showParameter();

}

inline void TriangleSolver::setSide_a(double _a)
{
    side_a = _a;
    do
    {
        if (checkSides())
        {
            update_triangle();
        }
        else
        {
            std::cout << "sides do don't make a proper triangle enter another"
                      << " value for side a now\n>>";
            std::cin >> side_a;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    while (!checkSides() || !cin);

}

inline void TriangleSolver::setSide_b(double _b)
{
    side_b = _b;
    do
    {
        if (checkSides())
        {
            update_triangle();
        }
        else
        {
            std::cout << "sides do don't make a proper triangle enter another"
                      << " value for side b now\n>>";
            std::cin >> side_b;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    while (!checkSides() || !cin);
}

inline void TriangleSolver::setSide_c(double _c)
{
    side_c = _c;
    do
    {
        if (checkSides())
        {
            update_triangle();
        }
        else
        {
            std::cout << "sides do don't make a proper triangle enter another"
                      << " value for side c now\n>>";
            std::cin >> side_c;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    while (!checkSides() || !cin);
}

inline void TriangleSolver::setSides(double _a, double _b, double _c)
{
    side_a = _a;
    side_b = _b;
    side_c = _c;
    if (checkSides() == true) {
        update_triangle();
    }
    else {
        badTriangle();
    }

}
inline void TriangleSolver::setAngles(double aA, double aB, double aC)
{
    // this will essentially build a new triangle from the one you have
    angle_A = aA;
    angle_B = aB;
    angle_C = aC;
    if (double check = aA + aB + aC; check != 180) {
        do {
            cout << "the angles need to add up to 180 degrees to be a real triangle\n"
                 << "please reenter the sides and make sure the total is 180 degrees.\n"
                 << "use spaces to seperate each angle esample: 40.5 65 79.5\n>";
            cin >> aA >> aB >> aC;
            check = aA + aB + aC;
            cin.clear();
            cin.ignore(100, '\n');
        } while (check != 180 || !cin);
    }
    if (checkAngles() == true) {
        solve_by_AAA(aA, aB, aC);
    }
    //update_triangle();
}
/*______________________________________________________________________________
											   overloaded addition opperators*/

inline TriangleSolver TriangleSolver::operator++()
{
    return TriangleSolver{++side_a, ++side_b, ++side_c};
}

inline TriangleSolver TriangleSolver::operator++(int)
{
    return TriangleSolver{side_a++,side_b++,side_c++};
}

inline TriangleSolver TriangleSolver::operator+(const TriangleSolver& tri)const
{
    return TriangleSolver{side_a+tri.side_a, side_b+tri.side_b,side_c+tri.side_c};
}

inline TriangleSolver TriangleSolver::operator+(double n)const
{
    return TriangleSolver{side_a+n,side_b+n,side_c+n};
}

inline TriangleSolver& TriangleSolver::operator+=(const TriangleSolver& rhs)
{
    side_a += rhs.side_a;
    side_b += rhs.side_b;
    side_c += rhs.side_c;
    calculate_All_angles();
    return *this;
}
inline TriangleSolver& TriangleSolver::operator+(const TriangleSolver& rhs)
{
    side_a += rhs.side_a;
    side_b += rhs.side_b;
    side_c += rhs.side_c;
    calculate_All_angles();
    return *this;
}
inline TriangleSolver operator+(double num, TriangleSolver& t)
{
    return TriangleSolver{num+t.side_a,num+t.side_b,num+t.side_c};
}

inline TriangleSolver operator+(TriangleSolver& v, TriangleSolver& s)
{
    return TriangleSolver{v.side_a+s.side_a,v.side_b+s.side_b,v.side_c+s.side_c};
}


/*______________________________________________________________________________
											overloaded subtraction opperators*/

inline TriangleSolver TriangleSolver::operator--()
{
    return TriangleSolver{--side_a, --side_b, --side_c};
}

inline TriangleSolver TriangleSolver::operator--(int)
{
    return TriangleSolver{side_a--,side_b--,side_c--};
}

inline TriangleSolver TriangleSolver::operator-(const TriangleSolver& tri) const
{
    return TriangleSolver{side_a-tri.side_a, side_b-tri.side_b,side_c-tri.side_c};
}

inline TriangleSolver TriangleSolver::operator-(double n) const
{
    return TriangleSolver{side_a-n,side_b-n,side_c-n};
}

inline TriangleSolver& TriangleSolver::operator-=(const TriangleSolver& rhs)
{
    side_a -= rhs.side_a;
    side_b -= rhs.side_b;
    side_c -= rhs.side_c;
    calculate_All_angles();
    update_triangle();
    return *this;
}

inline TriangleSolver operator-(double num, TriangleSolver& t)
{
    return TriangleSolver{num-t.side_a,num-t.side_b,num-t.side_c};
}

inline TriangleSolver operator-(TriangleSolver& v, const TriangleSolver& s)
{
    return TriangleSolver{v.side_a-s.side_a,v.side_b-s.side_b,v.side_c-s.side_c};
}

/*______________________________________________________________________________
												overloaded division opperators*/

inline TriangleSolver TriangleSolver::operator/(double d)const
{
    return TriangleSolver{side_a/d,side_b/d,side_c/d};
}

inline TriangleSolver TriangleSolver::operator/(const TriangleSolver& t)const
{
    return TriangleSolver{side_a/t.side_a,side_b/t.side_b,side_c/t.side_c};
}

/*______________________________________________________________________________
										 overloaded multiplication opperators*/

inline TriangleSolver TriangleSolver::operator*(double t) const
{
    return TriangleSolver{side_a*t,side_b*t,side_c*t};
}

inline TriangleSolver operator*(double s, TriangleSolver& t)
{
    return TriangleSolver{s*t.side_a,s*t.side_b,s*t.side_c};
}

inline TriangleSolver operator*(TriangleSolver& v, TriangleSolver& s)
{
    return TriangleSolver{v.side_a*s.side_a,v.side_b*s.side_b,v.side_c*s.side_c};
}
inline ostream& operator<<(ostream& os, const TriangleSolver& t)
{
    t.displayTriangleData();
    return os;
}

inline istream& operator>>(istream& is, TriangleSolver& t)
{
    is >> t.side_a >> t.side_b >> t.side_c;
    if (t.checkSides())
    {
        t.update_triangle();
        return is;
    }
    else
    {
        t.badTriangle();
    }
    return is;
}

template<typename T>
inline T TriangleSolver::negativeNumCheck(T& num)
{
    if (num > 0)
        return 0;
    else {
        num = negativeNumFix(num);
    }
    return 0;
}

template<typename T>
inline T TriangleSolver::negativeNumFix(T& num)
{
    //double temp;
    if (num < 0) {
        do {
            cout << "You cannot enter a negative value\n:";
            cout << "making it an absolute value instead";
            num = abs(num);
            //return num;
            cin.ignore(100, '\n');
            cin.clear();
        } while (!cin || num < 0);
        return num;
    }
    return num;
}