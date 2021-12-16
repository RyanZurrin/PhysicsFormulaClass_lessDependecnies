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
 * lastEdit 9/5/2021
 */
#ifndef Vector2D_H
#define Vector2D_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cassert>

using namespace std;


constexpr auto _PI_ = 3.141592653589793238462643383;
constexpr auto DEGREE = 180/_PI_;
constexpr auto RADIAN = _PI_/180;
constexpr auto _Ga_ = 9.81;
static int vec2d_object_counter = 0;

class Vector2D
{
    friend class Vector3D;
    string		ID;
    long double		x;
    long double		y;
    unsigned long		magnitude;
    long double		angle;
    long double		arcLength;
    long double		revolutionAngle_inDegrees;
    static void countShow() { std::cout << "Vector2D count: "
                                        << vec2d_object_counter << std::endl; }
    //void    calculate_parametric_equation();
    void 		validate_setMode();
    void		calculate_magnitude();
    void		calculate_angle();
    void		adjust_angle();
    void		calculate_rectangular();
    void		calculate_polar();
    void		calculate_arcLength();
    static void countIncrease() { vec2d_object_counter += 1; }
    static void countDecrease() { vec2d_object_counter -= 1; }

public:
    char mode;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'
    Vector2D(string id = ""); //default constructor
    Vector2D(char, string id = "");//mode select, defaults to 0, in rectangular, constructor
    Vector2D(long double, long double, char _mode = 'r', string id = ""); //constructor takes both coordinates and mode
    Vector2D(const Vector2D &, string id = "");	//copy constructor
    virtual void displayAllData(const std::string& label = "")const; //virtual so any derived classes must redefine
    virtual void display(const std::string& label = "")const;
    virtual void showRectCord(const std::string& label = "")const;
    void		 showPolarCord(const std::string& label = "")const;
    void		 showRevolutionAngle(const std::string&  label = "")const;
    void		 show_x()const;
    void		 show_y()const;
    void		 show_mag()const;
    void		 show_angle()const;
    void		 show_mode()const;
    void		 show_arcLength()const;
    std::string	 getID() const { return ID; }
    long double		 return_x()const;
    long double		 return_y()const;
    virtual unsigned long return_mag()const;
    virtual long double return_angle()const;
    virtual long double return_arcLength()const;
    virtual char return_mode()const;
    static int	 return_objectCount(){return vec2d_object_counter;}
    void		 set_coordinates(long double, long double, char _mode = 'r');
    void		 set_rectCord(long double, long double);
    void		 set_polarCord(unsigned long, long double);
    void		 set_x(long double);
    void		 set_y(long double);
    void		 set_mag(unsigned long);
    void		 set_mode(char);
    Vector2D	 projection(Vector2D& v);
    Vector2D	 projection(Vector2D&)const;
    long double		 angle_between_vectors(Vector2D&)const;
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
    virtual unsigned long square()const;              //gives square olong double the Vector2D
    virtual unsigned long find_magnitude()const;             //magnitude olong double the Vector2D
    long double		 dot_product(const Vector2D&)const; //scalar dot_product
    long double		 distance(const Vector2D&)const;    //gives distance between two Vector2Ds
    long double		 cross_product(const Vector2D&)const;    //cross_product
    Vector2D	 normalize_Vector2D();   //normalized Vector2D
    bool isOrthogonalWith(Vector2D& v)const;
    void typeOfAngleBetween(const Vector2D& v)const;
    static void  show_objectCount() { std::cout << "\n vector2D object count: "
                                                << vec2d_object_counter << std::endl; }
    static int	 get_objectCount() { return vec2d_object_counter; }
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
    magnitude = static_cast<unsigned long>( 0.0);
    angle = static_cast<long double>(0.0);
    calculate_arcLength();
    arcLength =  static_cast<long double>(0.0);
    revolutionAngle_inDegrees =  static_cast<long double>(0.0);
    mode = 'r';
    validate_setMode();
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
    magnitude =  static_cast<unsigned long>( 0.0);
    angle =  static_cast<long double>(0.0);
    calculate_arcLength();
    revolutionAngle_inDegrees = 0;
    mode                      = _mode;
    validate_setMode();
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
    magnitude =  static_cast<unsigned long>(0.0);
    angle =  static_cast<long double>(0.0);
    mode = _mode;
    validate_setMode();
    x = xMag;
    y = yAng;
    set_coordinates(x, y, _mode);
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
    validate_setMode();
    x = v.x;
    y = v.y;
    set_coordinates(x, y, mode);
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
    showRectCord(label);
    showPolarCord(label);
    showRevolutionAngle(label);
    show_arcLength();
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

inline void Vector2D::showRectCord(const std::string& label)const
{
    cout << setprecision(6);
    cout<< "\n" <<((label.empty()) ? ID : label) << ":(x,y) = ";
    if(x < 0 && x > -1 ){
        cout << setiosflags(ios::fixed);
        cout << fixed << "(" << x << ","
             << resetiosflags(ios::fixed);
    }
    else{
        cout << "(" << x << ",";
    }
    if(y<0 && y>-1){
        cout << setiosflags(ios::fixed);
        cout << y << ")" <<endl;
        cout << resetiosflags(ios::fixed);
    }
    else{
        cout << y << ")";
    }
}
inline void Vector2D::showPolarCord(const std::string& label)const
{
    cout<< "\n" << ((label.empty()) ? ID : label) << setprecision(6);
    if(magnitude >= 0 && angle >= 0){
        cout << ":<r,\xE9> = <" << magnitude << "," << angle << ">";
    }
    else{
        cout << setiosflags(ios::fixed);
        cout << ":<r,\xE9> = <" << magnitude << "," << angle << ">";
        cout << resetiosflags(ios::fixed) << endl;
    }
}
inline void Vector2D::showRevolutionAngle(const std::string& label)const
{
    cout<< "\n" << ((label.empty()) ? ID : label) << ":rev\xE9\xF8 = "
        << revolutionAngle_inDegrees <<"\xF8";
}
inline void Vector2D::show_x() const
{
    cout << "\nx: " << x << endl;
}
inline void Vector2D::show_y() const
{
    cout << "\ny: " << y << endl;
}
inline void Vector2D::show_mag() const
{
    cout << "\nr: " << magnitude << endl;
}
inline void Vector2D::show_angle() const
{
    cout << "\n\xE9: " << angle << "\xF8" << endl;
}
inline void Vector2D::show_mode()const
{
    if (mode == 'p' || mode == 'P') {
        cout << "\nmode: Polar" << endl;
    }
    else
        cout << "\nmode: Rectangular" << endl;
}
inline void Vector2D::show_arcLength() const
{
    cout << setprecision(4);
    cout << "\narc length: " << arcLength << endl;
}
inline long double Vector2D::return_x() const
{
    return x;
}
inline long double Vector2D::return_y()const
{
    return y;
}
inline unsigned long Vector2D::return_mag()const
{
    return magnitude;
}
inline long double Vector2D::return_angle()const
{
    return angle;
}
inline long double Vector2D::return_arcLength() const
{
    return arcLength;
}
inline char Vector2D::return_mode()const
{
    return mode;
}
/**
 *method: set_coordinates(long double xMag, long double yAng, char _mode)
* arguments: x, y mode = 'r' or 'p' .by default is 'r'ectangular, 'p'= polar.
* Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
inline void Vector2D::set_coordinates(long double xMag, long double yAng, char _mode)
{
    validate_setMode();

    if (tolower(_mode) ==  'r') {
        set_rectCord(xMag, yAng);
    }
    else{
        set_polarCord(static_cast<unsigned long>(xMag), yAng);
    }
    calculate_angle();
    adjust_angle();
    calculate_arcLength();
}
inline void Vector2D::set_rectCord(long double _x, long double _y)
{
    x = _x;
    y = _y;
    mode = 'r';
    calculate_polar();
    revolutionAngle_inDegrees = angle;
}
inline void Vector2D::set_polarCord(unsigned long mag, long double ang)
{
    magnitude = mag;
    angle =ang;
    revolutionAngle_inDegrees = ang;
    mode = 'p';
    calculate_rectangular();
    calculate_angle();
    adjust_angle();
    calculate_arcLength();
}
inline void Vector2D::set_x(long double _x)
{
    x = _x;
    calculate_polar();
}
inline void Vector2D::set_y(long double _y)
{
    y = _y;
    calculate_polar();
}
inline void Vector2D::set_mag(unsigned long mag)
{
    magnitude = mag;
    calculate_rectangular();
    calculate_arcLength();
}

inline void Vector2D::set_mode(char _mode)
{
    mode = _mode;
    validate_setMode();
}
inline Vector2D Vector2D::projection(Vector2D& v)
{
    const long double xx = dot_product(v) / v.dot_product(v);
    return Vector2D(xx*v.x , xx*v.y, this->mode);
}
inline Vector2D Vector2D::projection(Vector2D& v) const
{
    const Vector2D temp(this->x, this->y);
    const auto dotProd   = this->dot_product(v);
    const auto dpdevisor = this->dot_product(temp);
    const auto scalar    = dotProd / dpdevisor;
    Vector2D resultant   = temp * scalar;
    return resultant;
}
inline long double Vector2D::angle_between_vectors(Vector2D& v) const
{
    return acos((x*v.x+y*v.y) / (sqrt(x*x+y*y)*
                                 sqrt(v.x*v.x+v.y*v.y))) * DEGREE;
}
inline unsigned long Vector2D::square()const
{
    return  static_cast<unsigned long>( x * x + y * y);
}
inline long double Vector2D::dot_product(const Vector2D& vec)const
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
inline long double Vector2D::cross_product(const Vector2D& v)const
{
    return (x * v.y) - (y * v.x);
}
inline Vector2D Vector2D::normalize_Vector2D()
{
    assert(find_magnitude() != 0);  // NOLINT(clang-diagnostic-float-equal)
    const auto length = sqrt((this->x * this->x) + (this->y * this->y));
    this->x /= length;
    this->y /= length;
    calculate_polar();
    calculate_angle();
    adjust_angle();
    calculate_arcLength();
    return *this;
}
inline bool Vector2D::isOrthogonalWith(Vector2D& v) const
{
    return this->dot_product(v) == 0;
}
inline unsigned long Vector2D::find_magnitude()const
{
    return static_cast<unsigned long>(sqrt(square()));
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
inline void Vector2D::validate_setMode()
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

inline void Vector2D::calculate_magnitude()
{
    magnitude = static_cast<unsigned long>( sqrt(x * x + y * y));
}
inline void Vector2D::calculate_angle()
{
    angle = atan2(y, x) * DEGREE;
}
inline void Vector2D::adjust_angle()
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
inline void Vector2D::calculate_rectangular()
{
    x = magnitude* cos(angle*RADIAN);
    y = magnitude* sin(angle*RADIAN);
}
inline void Vector2D::calculate_polar()
{
    magnitude = static_cast<unsigned long>( sqrt(x * x + y * y));
    if (x == 0.0 && y == 0.0)
        angle = 0.0;
    else
        angle = atan2(y, x)*DEGREE;

    adjust_angle();
    calculate_arcLength();
    revolutionAngle_inDegrees = angle;
}
inline void Vector2D::calculate_arcLength()
{
    adjust_angle();
    arcLength = (_PI_ * (magnitude*2.0)) *
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
    Vector2D resultant(s-v.return_x(),s-v.return_y(),v.return_mode());
    return resultant;
}
inline Vector2D operator+(long double s, Vector2D& v)
{
    Vector2D resultant(s+v.return_x(),s+v.return_y(),v.return_mode());
    return resultant;
}
inline Vector2D& Vector2D::operator=(const Vector2D &right)
{
    if (this != &right) {

        x = right.x;
        y = right.y;
        calculate_polar();
        calculate_arcLength();
    }
    return *this;
}
inline Vector2D& Vector2D::operator=(const Vector2D *vec)
{
    x = vec->x;
    y = vec->y;
    calculate_polar();
    calculate_arcLength();
    return *this;
}
inline Vector2D& Vector2D::operator=(Vector2D&& right)noexcept
{
    if (this != &right)
    {
        swap(x, right.x);
        swap(y, right.y);
        this->calculate_polar();
    }
    return *this;
}
inline Vector2D::Vector2D(Vector2D&& temp) noexcept
{
    x = temp.x;
    y = temp.y;
    mode = temp.mode;
    calculate_polar();
    calculate_arcLength();
    revolutionAngle_inDegrees = Vector2D::return_angle();
    angle                     = Vector2D::return_angle();
    magnitude                 = Vector2D::return_mag();
    arcLength                 = Vector2D::return_arcLength();
    calculate_arcLength();
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
        v.calculate_polar();
    }
    else{
        is>> v.magnitude >> v.angle;
        v.calculate_rectangular();
    }
    return is;
}
inline Vector2D::~Vector2D()
{
    countDecrease();
}

inline void Vector2D::typeOfAngleBetween(const Vector2D& v)const
{
    if(dot_product(v) < 0)
    {
        std::cout << "vectors are obtuse\n";
    }
    else if(dot_product(v) > 0)
    {
        std::cout << "vectors are acute\n";
    }
    else if(dot_product(v) == 0)
    {
        std::cout << "vectors are right";
    }
}

template<typename T>
inline long double Vector2D::distance_to_line(T a, T b, T c)
{
    auto top = abs(((a * x) + (b * y) + c));
    auto bot = sqrt((a * a) + (b * b));
    return top / bot;
}
#endif //PHYSICSFORMULA_VECTOR2D_H
