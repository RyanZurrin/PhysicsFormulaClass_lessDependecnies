//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_VECTOR2D_H
#define PHYSICSFORMULA_VECTOR2D_H
/**
 * @class Vector2D
 * @details class for operating with 2D vectors
 * @author Ryan Zurrin
 * dateBuilt  11/22/2020
 * lastEdit 2/5/2022
 */
#ifndef Vector2D_H
#define Vector2D_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cassert>
#include "Constants.h"

using namespace std;

static int vec2d_object_counter = 0;

class Vector2D
{
    friend class Vector3D;
    string		ID;
    long double		x;
    long double		y;
    long double	    magnitude;
    long double		angle;
    long double		arcLength;
    long double		revolutionAngle_inDegrees;
    static void countShow() { std::cout << "Vector2D count: "
                                        << vec2d_object_counter << std::endl; }
    //void    calculate_parametric_equation();
    void 		validateSetMode();
    void		calculateMagnitude();
    void		calculateAngle();
    void		adjustAngle();
    void		calculateRectangular();
    void		calculatePolar();
    void		calculateArcLength();
    static void countIncrease() { vec2d_object_counter += 1; }
    static void countDecrease() { vec2d_object_counter -= 1; }

public:
    char mode;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'
    explicit Vector2D(string id = ""); //default constructor
    explicit Vector2D(char, string id = "");//mode select, defaults to 0, in rectangular, constructor
    Vector2D(long double, long double, char _mode = 'r', string id = ""); //constructor takes both coordinates and mode
    Vector2D(const Vector2D &, string id = "");	//copy constructor
    virtual void displayAllData(const std::string& label = "")const; //displays all data
    virtual void display(const std::string& label = "")const;
    void showUnitVector(const std::string& label = "")const;

    virtual void showRectCord(const std::string& label = "")const;
    void		 showPolarCord(const std::string& label = "")const;
    void		 showRevolutionAngle(const std::string&  label = "")const;
    void		 showX()const;
    void		 showY()const;
    void		 showMag()const;
    void		 showAngle()const;
    void		 showMode()const;
    void		 showArcLength()const;
    [[nodiscard]] std::string	     getID() const;
    [[nodiscard]] long double		 getX()const;
    [[nodiscard]] long double		 getY()const;
    [[nodiscard]] virtual long double getMag()const;
    [[nodiscard]] virtual long double getAngle()const;
    [[nodiscard]] virtual long double getArcLength()const;
    [[nodiscard]] virtual char getMode()const;
    static int	 getObjectCount(){return vec2d_object_counter;}
    void		 setCoordinates(long double, long double, char _mode = 'r');
    void		 setRectCord(long double, long double);
    void		 setPolarCord(long double, long double);
    void		 setX(long double);
    void		 setY(long double);
    void		 setMag(long double);
    void		 setMode(char);
    Vector2D	 projection(Vector2D& v);
    Vector2D	 projection(Vector2D&)const;
    long double	 angleBetweenVectors(Vector2D&)const;
    /// <summary>
    /// Distance from a point(vector head) to a line is equal to length of the
    /// perpendicular distance from the point to the line. If Ax + By + C = 0,
    /// 2D line equation, then distance between point V(x, y) and line can be
    /// found using the following formula d =  	(|a·x + b·y + c|)/(√a^2 + b^2)
    /// </summary>
    /// <param name="a">coefficient a in ax + by + c = 0.</param>
    /// <param name="b">coefficient b in ax + by + c = 0.</param>
    /// <param name="c">coefficient c in ax + by + c = 0.</param>
    /// <returns>distance from the vector head to line with given equations
    /// coefficients</returns>
    template<typename T>
    long double		 distance_to_line(T a, T b, T c);
    virtual long double square() const;              //gives square olong double the Vector2D
    virtual long double findMagnitude() const;             //magnitude olong double the Vector2D
    [[nodiscard]] long double   dot(const Vector2D&)const; //scalar dot
    [[nodiscard]] long double	distance(const Vector2D&)const;    //gives distance between two Vector2Ds
    [[nodiscard]] long double	cross(const Vector2D&)const;    //cross
    Vector2D	                normalize2D();   //normalized Vector2D
    Vector2D                    getUnitVector()const;
    bool                        isOrthogonalWith(Vector2D& v)const;
    void                        typeOfAngleBetween(const Vector2D& v)const;
    static void                 showObjectCount() { std::cout << "\n vector2D object count: "
                                                              << vec2d_object_counter << std::endl; }
    bool operator>(const Vector2D &)const;
    bool operator>=(const Vector2D&)const;
    bool operator<(const Vector2D &)const;
    bool operator<=(const Vector2D&)const;
    bool operator==(const Vector2D &)const;
    bool operator!=(const Vector2D&)const;
    bool operator>(const long double& n)const { return magnitude > n; }
    bool operator>=(const long double& n)const { return magnitude >= n; }
    bool operator<(const long double& n)const { return magnitude < n; }
    bool operator<=(const long double& n)const { return magnitude <= n; }
    bool operator==(const long double& n)const { return magnitude == n; }
    bool operator!=(const long double& n)const { return !(magnitude == n); }

    Vector2D operator+(const Vector2D &)const;
    Vector2D operator+(long double number)const;
    Vector2D &operator+=(const Vector2D &);
    Vector2D operator+()const;
    Vector2D operator++();
    Vector2D operator++(int);
    Vector2D operator-(const Vector2D&) const;
    Vector2D operator-(const long double number)const;
    Vector2D operator-()const;
    Vector2D operator--();
    Vector2D operator--(int);
    Vector2D& operator=(const Vector2D &);
    Vector2D &operator=(const Vector2D *);
    Vector2D &operator=(Vector2D&& right)noexcept;
    Vector2D(Vector2D&& temp)noexcept;

    Vector2D operator*(long double)const;

    friend Vector2D operator*(long double s, Vector2D& v);
    friend Vector2D operator*(Vector2D& v, Vector2D& s);
    friend Vector2D operator-(long double s, Vector2D& v);
    friend Vector2D operator+(long double s, Vector2D& v);
    friend ostream& operator<<(ostream&, const Vector2D&);
    friend istream& operator>>(istream&, Vector2D&);

    virtual ~Vector2D();


};
#endif
//=============================================================================
//in-line class Implementation

inline Vector2D::Vector2D(string id)
{
    x = static_cast<long double>(0.0);
    y = static_cast<long double>(0.0);
    magnitude = static_cast<long double>( 0.0);
    angle = static_cast<long double>(0.0);
    calculateArcLength();
    arcLength =  static_cast<long double>(0.0);
    revolutionAngle_inDegrees =  static_cast<long double>(0.0);
    mode = 'r';
    validateSetMode();
    countIncrease();
    if (id == "")
    {
        ID = "vec2d_" + std::to_string(vec2d_object_counter);
    }
    else
    {
        ID = id;
    }
    //countShow();
}

inline Vector2D::Vector2D(char _mode, string id)
{
    x =  static_cast<long double>(0.0);
    y =  static_cast<long double>(0.0);
    magnitude =  static_cast<long double>( 0.0);
    angle =  static_cast<long double>(0.0);
    calculateArcLength();
    revolutionAngle_inDegrees = 0;
    mode                      = _mode;
    validateSetMode();
    countIncrease();
    if (id == "")
    {
        ID = "vec2d_" + std::to_string(vec2d_object_counter);
    }
    else
    {
        ID = id;
    }
    //countShow();
}
/*______________________________________________________________________________
  the third argument is the mode setting.
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
inline Vector2D::Vector2D(long double xMag, long double yAng, char _mode, string id)
{
    revolutionAngle_inDegrees = static_cast<long double>(0.0);
    ID = id;
    magnitude =  static_cast<long double>(0.0);
    angle =  static_cast<long double>(0.0);
    mode = _mode;
    validateSetMode();
    x = xMag;
    y = yAng;
    setCoordinates(x, y, _mode);
    countIncrease();
    if (id == "")
    {
        ID = "vec2d_" + std::to_string(vec2d_object_counter);
    }
    else
    {
        ID = id;
    }


}
inline Vector2D::Vector2D(const Vector2D &v, string id)
{

    ID = id;
    revolutionAngle_inDegrees = v.revolutionAngle_inDegrees;
    magnitude = v.magnitude;
    angle = v.angle;
    mode = v.mode;
    validateSetMode();
    x = v.x;
    y = v.y;
    setCoordinates(x, y, mode);
    countIncrease();
    if (id == "")
    {
        ID = "vec2d_" + std::to_string(vec2d_object_counter);
    }
    else
    {
        ID = id;
    }
}
inline void Vector2D::displayAllData(const std::string& label)const
{
    std::cout << ((label.empty()) ? ID : label) << ":";
    showUnitVector(label);
    showRectCord(label);
    showPolarCord(label);
    showRevolutionAngle(label);
    showArcLength();
    std::cout << std::endl;
}
inline void Vector2D::display(const std::string& label)const
{
    if (mode == 'r' || mode == 'R') {
        showRectCord(label);
    }
    else {
        showPolarCord(label);
    }
}

void Vector2D::showUnitVector(const std::string& label)const {
    // display as a unit vector with ihat and jhat
    std::cout << ((label.empty()) ? ID : label) << ":";
    std::cout << 1.0/magnitude << "*"  << "<" << x << "i ," << y << "j>";
}

inline void Vector2D::showRectCord(const std::string& label)const
{
    cout << setprecision(6);
    cout<< "\n" <<((label.empty()) ? ID : label) << ":<x,y> = ";
    if(x < 0 && x > -1 ){
        cout << setiosflags(ios::fixed);
        cout << fixed << "<" << x << ","
             << resetiosflags(ios::fixed);
    }
    else{
        cout << "<" << x << ",";
    }
    if(y<0 && y>-1){
        cout << setiosflags(ios::fixed);
        cout << y << ">" <<endl;
        cout << resetiosflags(ios::fixed);
    }
    else{
        cout << y << ">";
    }
}
inline void Vector2D::showPolarCord(const std::string& label)const
{
    cout<< "\n" << ((label.empty()) ? ID : label) << setprecision(6);
    if(magnitude >= 0 && angle >= 0){
        cout << ":<r,theta> = <" << magnitude << "," << angle << ">";
    }
    else{
        cout << setiosflags(ios::fixed);
        cout << ":<r,theta> = <" << magnitude << "," << angle << ">";
        cout << resetiosflags(ios::fixed) << endl;
    }
}
inline void Vector2D::showRevolutionAngle(const std::string& label)const
{
    cout<< "\n" << ((label.empty()) ? ID : label) << ":rev\xE9\xF8 = "
        << revolutionAngle_inDegrees <<"\xF8";
}
inline void Vector2D::showX() const
{
    cout << "\nx: " << x << endl;
}
inline void Vector2D::showY() const
{
    cout << "\ny: " << y << endl;
}
inline void Vector2D::showMag() const
{
    cout << "\nr: " << magnitude << endl;
}
inline void Vector2D::showAngle() const
{
    cout << "\n\xE9: " << angle << "\xF8" << endl;
}
inline void Vector2D::showMode()const
{
    if (mode == 'p' || mode == 'P') {
        cout << "\nmode: Polar" << endl;
    }
    else
        cout << "\nmode: Rectangular" << endl;
}
inline void Vector2D::showArcLength() const
{
    cout << setprecision(4);
    cout << "\narc length: " << arcLength << endl;
}
inline long double Vector2D::getX() const
{
    return x;
}
inline long double Vector2D::getY()const
{
    return y;
}
inline long double Vector2D::getMag()const
{
    return magnitude;
}
inline long double Vector2D::getAngle()const
{
    return angle;
}
inline long double Vector2D::getArcLength() const
{
    return arcLength;
}
inline char Vector2D::getMode()const
{
    return mode;
}
/**
 *method: setCoordinates(long double xMag, long double yAng, char _mode)
* arguments: x, y mode = 'r' or 'p' .by default is 'r'ectangular, 'p'= polar.
* Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
inline void Vector2D::setCoordinates(long double xMag, long double yAng, char _mode)
{
    validateSetMode();

    if (tolower(_mode) ==  'r') {
        setRectCord(xMag, yAng);
    }
    else{
        setPolarCord(static_cast<long double>(xMag), yAng);
    }
    calculateAngle();
    adjustAngle();
    calculateArcLength();
}
inline void Vector2D::setRectCord(long double _x, long double _y)
{
    x = _x;
    y = _y;
    mode = 'r';
    calculatePolar();
    revolutionAngle_inDegrees = angle;
}
inline void Vector2D::setPolarCord(long double mag, long double ang)
{
    magnitude = mag;
    angle =ang;
    revolutionAngle_inDegrees = ang;
    mode = 'p';
    calculateRectangular();
    calculateAngle();
    adjustAngle();
    calculateArcLength();
}
inline void Vector2D::setX(long double _x)
{
    x = _x;
    calculatePolar();
}
inline void Vector2D::setY(long double _y)
{
    y = _y;
    calculatePolar();
}
inline void Vector2D::setMag(long double mag)
{
    magnitude = mag;
    calculateRectangular();
    calculateArcLength();
}

inline void Vector2D::setMode(char _mode)
{
    mode = _mode;
    validateSetMode();
}
inline Vector2D Vector2D::projection(Vector2D& v)
{
    const long double xx = dot(v) / v.dot(v);
    return {xx*v.x , xx*v.y, this->mode};
}
inline Vector2D Vector2D::projection(Vector2D& v) const
{
    const Vector2D temp(this->x, this->y);
    const auto dotProd   = this->dot(v);
    const auto dpdevisor = this->dot(temp);
    const auto scalar    = dotProd / dpdevisor;
    Vector2D resultant   = temp * scalar;
    return resultant;
}
inline long double Vector2D::angleBetweenVectors(Vector2D& v) const
{
    return acos((x*v.x+y*v.y) / (sqrt(x*x+y*y)*
                                 sqrt(v.x*v.x+v.y*v.y))) * constants::DEGREE;
}
inline long double Vector2D::square() const {
    return  static_cast<long double>( x * x + y * y);
}
inline long double Vector2D::dot(const Vector2D& vec)const
{
    return  x * vec.x + vec.y * y;
}
inline long double Vector2D::distance(const Vector2D& vec)const
{
    long double x1, x2, y1, y2, t1, t2;
    x1 = this->x;
    x2 = vec.x;
    y1 = this->y;
    y2 = vec.y;
    t1 = x2 - x1;
    t2 = y2 - y1;
    return sqrt(pow(t1, 2) + pow(t2, 2));
}
inline long double Vector2D::cross(const Vector2D& v)const
{
    return (x * v.y) - (y * v.x);
}
inline Vector2D Vector2D::normalize2D()
{
    assert(findMagnitude() != 0);  // NOLINT(clang-diagnostic-float-equal)
    const auto length = sqrt((this->x * this->x) + (this->y * this->y));
    this->x /= length;
    this->y /= length;
    calculatePolar();
    calculateAngle();
    adjustAngle();
    calculateArcLength();
    return *this;
}

Vector2D Vector2D::getUnitVector() const {
    Vector2D unitVector(this->x, this->y);
    unitVector.normalize2D();
    return unitVector;
}

inline bool Vector2D::isOrthogonalWith(Vector2D& v) const
{
    return this->dot(v) == 0;
}
inline long double Vector2D::findMagnitude() const {
    return sqrt(square());
}
/*
void Vector2D::setPolarCurve()
{
	cout << "\nEnter the Polar Curve to convert to Cartesian equation\n>";
	cin >> Curve.r;
  Curve.x = sqrt(pow(Curve.r, 2) + pow(Curve.y, 2));
  Curve.theta = atan(y / x);
}
*/
inline void Vector2D::validateSetMode()
{
    do{
        if (tolower(mode) == 'r' || tolower(mode) == 'p') {
            break;
        }
        else {
            cout << "\nEnter a valid mode, r/R for rectangular\n"
                 << "or p/P or polar components\n>";
            cin >> mode;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while(!cin || tolower(mode) != 'r' || tolower(mode) != 'p');
}

inline void Vector2D::calculateMagnitude()
{
    magnitude = static_cast<long double>( sqrt(x * x + y * y));
}
inline void Vector2D::calculateAngle()
{
    angle = atan2(y, x) * constants::DEGREE;
}
inline void Vector2D::adjustAngle()
{
    if(angle == -360 || angle == -720 || angle == -1080 || angle == -1440){  // NOLINT(clang-diagnostic-float-equal)
        angle = 0;
    }
    if (angle >= 360){
        const int rev_degrees = static_cast<int>(angle) / 360;
        const int to_subtract = rev_degrees *360;
        const long double new_angle = angle - to_subtract;
        angle = new_angle;
    }else if (angle < 0 && angle > -360){
        angle += 360;
    }else if(angle < -360){
        const int rev_degrees = static_cast<int>(angle) /360;
        const int to_subtract = rev_degrees *360;
        const long double newAngle = angle - to_subtract + 360;
        angle = newAngle;
    }
}
inline void Vector2D::calculateRectangular()
{
    x = magnitude* cos(angle*constants::RADIAN);
    y = magnitude* sin(angle*constants::RADIAN);
}
inline void Vector2D::calculatePolar()
{
    magnitude = static_cast<long double>( sqrt(x * x + y * y));
    if (x == 0.0 && y == 0.0)
        angle = 0.0;
    else
        angle = atan2(y, x)*constants::DEGREE;

    adjustAngle();
    calculateArcLength();
    revolutionAngle_inDegrees = angle;
}
inline void Vector2D::calculateArcLength()
{
    adjustAngle();
    arcLength = (constants::PI * (magnitude*2.0)) *
                (angle / 360.0);
}

inline bool Vector2D::operator<(const Vector2D &v) const
{
    return magnitude < v.magnitude;
}
inline bool Vector2D::operator<=(const Vector2D& v) const
{
    return magnitude <= v.magnitude;
}
inline bool Vector2D::operator>(const Vector2D & v)const
{
    return magnitude > v.magnitude;
}
inline bool Vector2D::operator>=(const Vector2D& v) const
{
    return magnitude >= v.magnitude;
}
inline bool Vector2D::operator==(const Vector2D & v)const
{
    return magnitude == v.magnitude && angle == v.angle;
}
inline bool Vector2D::operator!=(const Vector2D& v) const
{
    return !(magnitude == v.magnitude && angle == v.angle);
}
inline Vector2D Vector2D::operator+(const long double n)const
{
    //cout << "in  Vector2D::operator+(const long double n)const"<<endl;
    Vector2D total(x + n, y + n);
    total.mode = mode;
    return total;
}
inline Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    //cout << "in Vector2D& Vector2D::operator+=(const Vector2D& v)" << endl;
    Vector2D sum;
    sum.x += v.x;
    sum.y += v.y;
    sum.mode = v.mode;
    return *this;
}
inline Vector2D Vector2D::operator+(const Vector2D& v)const
{
    return Vector2D(x + v.x, y + v.y);
}
inline Vector2D Vector2D::operator+()const
{
    return Vector2D(x+x, y+y);
}
inline Vector2D Vector2D::operator++()
{
    return Vector2D(++x, ++y);
}
inline Vector2D Vector2D::operator++(int)
{
    return Vector2D(x++, y++);
}
inline Vector2D Vector2D::operator-(const Vector2D& v) const
{
    return Vector2D(x-v.x, y-v.y);
}
inline Vector2D Vector2D::operator-(const long double n)const
{
    return Vector2D(x - n, y - n);
}
inline Vector2D Vector2D::operator-()const
{
    return Vector2D(-x, -y);
}
inline Vector2D Vector2D::operator--()
{
    return Vector2D(--x, --y);
}
inline Vector2D Vector2D::operator--(int)
{
    return Vector2D(x--, y--);
}
inline Vector2D operator-(long double s, Vector2D& v)
{
    Vector2D resultant(s-v.getX(),s-v.getY(), v.getMode());
    return resultant;
}
inline Vector2D operator+(long double s, Vector2D& v)
{
    Vector2D resultant(s+v.getX(),s+v.getY(), v.getMode());
    return resultant;
}
inline Vector2D& Vector2D::operator=(const Vector2D &right)
{
    if (this != &right) {

        x = right.x;
        y = right.y;
        calculatePolar();
        calculateArcLength();
    }
    return *this;
}
inline Vector2D& Vector2D::operator=(const Vector2D *vec)
{
    x = vec->x;
    y = vec->y;
    calculatePolar();
    calculateArcLength();
    return *this;
}
inline Vector2D& Vector2D::operator=(Vector2D&& right)noexcept
{
    if (this != &right)
    {
        swap(x, right.x);
        swap(y, right.y);
        this->calculatePolar();
    }
    return *this;
}
inline Vector2D::Vector2D(Vector2D&& temp) noexcept
{
    x = temp.x;
    y = temp.y;
    mode = temp.mode;
    calculatePolar();
    calculateArcLength();
    revolutionAngle_inDegrees = Vector2D::getAngle();
    angle                     = Vector2D::getAngle();
    magnitude                 = Vector2D::getMag();
    arcLength                 = Vector2D::getArcLength();
    calculateArcLength();
}

inline Vector2D Vector2D::operator*(const long double scalar)const
{
    Vector2D results(x*scalar, y*scalar);
    results.mode = mode;
    return results;
}
inline Vector2D operator*(long double s, Vector2D& v)
{
    return v * s;
}

inline Vector2D operator*(Vector2D& v, Vector2D& s)
{
    Vector2D results(v.x*s.x, v.y*s.y, v.mode);
    return results;
}
inline ostream& operator<<(ostream& os, const Vector2D& v)
{
    if(v.mode == 'R' || v.mode == 'r'){
        v.showRectCord();
    }
    else{
        v.showPolarCord();
    }
    return os;
}
inline istream& operator>>(istream& is, Vector2D& v)
{
    std::string id = v.getID();
    std::cout << "please enter the x y values of " << id << "\n>>";
    if(v.mode == 'R' || v.mode == 'r'){
        is>> v.x >> v.y;
        v.calculatePolar();
    }
    else{
        is>> v.magnitude >> v.angle;
        v.calculateRectangular();
    }
    return is;
}
inline Vector2D::~Vector2D()
{
    countDecrease();
}

inline void Vector2D::typeOfAngleBetween(const Vector2D& v)const
{
    if(dot(v) < 0)
    {
        std::cout << "vectors are obtuse\n";
    }
    else if(dot(v) > 0)
    {
        std::cout << "vectors are acute\n";
    }
    else if(dot(v) == 0)
    {
        std::cout << "vectors are right";
    }
}

std::string Vector2D::getID() const
{
    return ID;
}

template<typename T>
inline long double Vector2D::distance_to_line(T a, T b, T c)
{
    auto top = abs(((a * x) + (b * y) + c));
    auto bot = sqrt((a * a) + (b * b));
    return top / bot;
}


#endif //PHYSICSFORMULA_VECTOR2D_H
