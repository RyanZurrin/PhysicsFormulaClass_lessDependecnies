//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_VECTOR3D_H
#define PHYSICSFORMULA_VECTOR3D_H

/**
 * @class Vector3D
 * @details class for operating with 3D vectors
 * @author Ryan Zurrin
 * dateBuilt  11/22/2020
 * lastEdit 9/5/2021
 */
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Vector2D.h"
static int vec3d_objectCount = 0;



class Vector3D : public Vector2D
{
    long double z, xAngle, yAngle, zAngle,radius, inclination, azimuth;
    void		setRadius();
    void		setInclination();
    void		setAzimuth();
    void		calculate_spherical();
    void		set_allAngles();
    void		set_magnitude();
    void		updateVector();
    static void countIncrease() { vec3d_objectCount += 1; }
    static void countDecrease() { vec3d_objectCount -= 1; }
public:
    Vector3D(string id = ""); //constructor
    Vector3D(long double, long double, long double, string id = "");  //initializing object with values.
    Vector3D(const Vector3D &vec, string id = "");    //copy constructor
    void		setX(long double);
    void		setY(long double);
    void		setZ(long double);
    void		set_coordinates(long double, long double, long double);
    void		displayAllData(const std::string& label = "")const override;
    void		showRectCord(const std::string& label = "")const override;
    void		showSphericalCoordinates(const std::string& label = "")const;
    void		showAllAngles(const std::string& label = "")const;
    void		display(const std::string& label = "")const override;    //display value of vector
    static int	return_objectCount(){return vec3d_objectCount;}
    [[nodiscard]] long double	return_z()const; //return z
    [[nodiscard]] long double	return_xAngle()const; //return x angle
    [[nodiscard]] long double	return_yAngle()const; //return y angle
    [[nodiscard]] long double	return_zAngle()const; //return z angle
    [[nodiscard]] long double	return_mag()const override;
    [[nodiscard]] long double	return_angle()const override;
    [[nodiscard]] long double	return_arcLength()const override;
    [[nodiscard]] char			return_mode()const override;

    /// <summary>
    /// gives the projection of v onto this
    /// </summary>
    /// <param name="v">The vector being projected.</param>
    /// <returns>3D vector of v onto this</returns>
    Vector3D	projection(Vector3D& v)const;

    long double	angle_between_vectors(Vector3D& v)const;
    /// <summary>
    /// The distance from a point(vector head) to a plane is equal to length of the perpendicular
    /// lowered from a point on a plane. If Ax + By + Cz + D = 0 is a plane equation,
    /// then distance from point M(Mx, My, Mz) to plane can be found using the
    /// following formula d =  	(|A·Mx + B·My + C·Mz + D))/(√A2 + B2 + C2)
    /// </summary>
    /// <param name="a">a.</param>
    /// <param name="b">The b.</param>
    /// <param name="c">The c.</param>
    /// <param name="d">The d.</param>
    /// <returns>distance from the vector head to plane with given equations
    /// coefficients</returns>
    template<typename T>
    long double distance_to_plane(T a, T b, T c, T d);
    [[nodiscard]] long double	square() const override; //gives square of the vector
    [[nodiscard]] long double	dot_product(const Vector3D &vec) const; //scalar dot_product
    [[nodiscard]] static long double dot_product(const long double uMag, const long double vMag, const long double angleBetween);
    [[nodiscard]] long double	distance(const Vector3D &vec)const;    //gives distance between two vectors
    [[nodiscard]] long double	find_magnitude()const override;  //magnitude of the vector
    [[nodiscard]] Vector3D		cross_product(const Vector3D &vec)const;    //cross_product
    [[nodiscard]] long double	scaler_triple_product(Vector3D& b, Vector3D& c) const;
    Vector3D	normalize_vector();   //normalized vector
    bool isOrthogonalWith(Vector3D& v)const;
    void typeOfAngleBetween(const Vector3D& v)const;
    static void show_objectCount() { std::cout << "\n vector3D object count: "
                                               << vec3d_objectCount << std::endl; }
    static int	get_objectCount() { return vec3d_objectCount; }
    bool operator==(const Vector3D& v)const;
    bool operator!=(const Vector3D& v)const;
    bool operator>(const Vector3D& v)const;
    bool operator>=(const Vector3D& v)const;
    bool operator<(const Vector3D& v)const;
    bool operator<=(const Vector3D& v)const;
    Vector3D operator+(const Vector3D &vec)const;    //addition
    Vector3D operator+(Vector3D &vec)const;
    Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D &vec)const;    //subtraction
    Vector3D operator-(const long double number)const;
    Vector3D operator-()const;
    Vector3D operator--();
    Vector3D operator--(int);
    Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
    Vector3D operator*(long double value)const;    //multiplication
    Vector3D &operator*=(long double value);  //assigning new result to the vector.
    Vector3D &operator=(const Vector3D &vec);
    friend ostream& operator<<(ostream&, const Vector3D&);
    friend istream& operator>>(istream&, Vector3D&);


    ~Vector3D()override;

};
#endif


inline Vector3D::Vector3D(string id) //constructor
{
    x=0;
    y=0;
    z=0;
    xAngle = 0.0;
    yAngle = 0.0;
    zAngle = 0.0;
    magnitude = static_cast<long double>(0.0);
    radius = 0.0;
    inclination = 0.0;
    azimuth = 0.0;
    countIncrease();
    if (id == "")
    {
        ID = "vec3d_" + std::to_string(vec3d_objectCount);
    }
    else
    {
        ID = id;
    }
    //cout<< object_counter << ": " <<"in the 3dVector default constructor"<<endl;
}
inline Vector3D::Vector3D(long double x1,long double y1,long double z1,string id) //initializing object with values.
{
    ID = id;
    x=x1;
    y=y1;
    z=z1;
    updateVector();
    countIncrease();
    if (id == "")
    {
        ID = "vec3d_" + std::to_string(vec3d_objectCount);
    }
    else
    {
        ID = id;
    }
    //cout<< object_counter << ": " <<"in the x,y,z constructor" << endl;;
}
inline Vector3D::Vector3D(const Vector3D &vec, string id)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
    updateVector();
    countIncrease();
    if (id == "")
    {
        ID = "vec3d_" + std::to_string(vec3d_objectCount);
    }
    else
    {
        ID = id;
    }

}
inline void Vector3D::setX(long double _x)
{
    x = _x;
    updateVector();
}
inline void Vector3D::setY(long double _y)
{
    y = _y;
    updateVector();
}
inline void Vector3D::setZ(long double _z)
{
    z = _z;
    updateVector();
}

inline void Vector3D::set_coordinates(long double x1, long double y1, long double z1)
{
    x = x1;
    y = y1;
    z = z1;
    updateVector();
}
inline void Vector3D::displayAllData(const std::string& label)const
{
    std::cout << ((label.empty()) ? ID : label);
    showRectCord();
    showSphericalCoordinates();
    showAllAngles();
    cout<< "mag: " << magnitude << endl;

}
inline void Vector3D::showRectCord(const std::string& label) const
{
    cout << setprecision(6);

    cout<< "\n" <<((label.empty()) ? ID : label) << ":(x,y,z) = ";
    if (x < 0 && x > -1) {
        cout << setiosflags(ios::fixed);
        cout << fixed << "(" << x << ","
             << resetiosflags(ios::fixed);
    }
    else {
        cout << "(" << x << ",";
    }
    if (y<0 && y>-1) {
        cout << setiosflags(ios::fixed);
        cout << y << ",";
        cout << resetiosflags(ios::fixed);
    }
    else {
        cout << y << ",";
    }
    if (z<0 && z>-1) {
        cout << setiosflags(ios::fixed);
        cout << z << ")" << endl;
        cout << resetiosflags(ios::fixed);
    }
    else {
        cout << z << ")";
    }
    std::cout << std::endl;
}
inline void Vector3D::showSphericalCoordinates(const std::string& label)const
{
    cout<<((label.empty()) ? ID : label) << setprecision(6)
        << ":<r,\xE9,\xE8> = <" << radius
        << ", " << inclination << ", " << azimuth << ">"<<std::endl;
}
inline void Vector3D::showAllAngles(const std::string& label) const
{
    cout <<((label.empty()) ? ID : label) << ":(\xE9x,\xE9y,\xE9z) = ("
         << xAngle << ", " << yAngle
         << ", " << zAngle << ")" <<std::endl;
}
inline void Vector3D::setRadius()
{
    radius = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}
inline void Vector3D::setInclination()
{
    inclination = acos(z / radius)*DEGREE;
}
inline void Vector3D::setAzimuth()
{
    azimuth = atan(y / x)*DEGREE;
}
inline void Vector3D::calculate_spherical()
{
    setRadius();
    setInclination();
    setAzimuth();
}
inline void Vector3D::set_allAngles()
{
    xAngle = return_xAngle();
    yAngle = return_yAngle();
    zAngle = return_zAngle();
    //angle =
}

inline void Vector3D::set_magnitude()
{
    magnitude = find_magnitude();
}

inline void Vector3D::updateVector()
{
    set_magnitude();
    set_allAngles();
    calculate_spherical();
}

//addition
inline Vector3D Vector3D::operator+(const Vector3D &vec)const
{
    return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
inline Vector3D Vector3D::operator+(Vector3D &vec)const
{
    return Vector3D(x+vec.x,y+vec.y,z);
}

inline Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    updateVector();
    return *this;
}

//subtraction//
inline Vector3D Vector3D::operator-(const Vector3D &vec)const
{
    return Vector3D(x-vec.x,y-vec.y,z-vec.z);
}
inline Vector3D Vector3D::operator-(const long double n) const
{
    return Vector3D(x-n, y-n, z-n);
}
inline Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}
inline Vector3D Vector3D::operator--()
{
    return Vector3D(--x, --y, --z);
}
inline Vector3D Vector3D::operator--(int)
{
    return Vector3D(x--, y--, z--);
}
inline Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
    updateVector();
    return *this;
}

//scalar multiplication
inline Vector3D Vector3D::operator*(long double value)const
{
    return Vector3D(x*value,y*value,z*value);
}
inline Vector3D &Vector3D::operator*=(long double value)
{
    x*=value;
    y*=value;
    z*=value;
    set_allAngles();
    return *this;
}


inline Vector3D& Vector3D::operator=(const Vector3D& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    set_allAngles();

    return *this;
}

inline ostream& operator<<(ostream& os, const Vector3D & v)
{
    if(v.mode == 'R' || v.mode == 'r'){
        v.showRectCord();
    }
    else{
        v.showPolarCord();
    }
    return os;
}

inline istream& operator>>(istream& is, Vector3D& v)
{
    long double x_, y_, z_;
    std::string id = v.getID();
    std::cout << "please enter the x y z values of " << id << "\n>>";
    is >> x_ >> y_ >> z_;
    v.setX(x_); v.setY(y_); v.setZ(z_);
    return is;
}


//Dot product
inline long double Vector3D::dot_product(const Vector3D &vec) const
{
    return x * vec.x + vec.y * y + vec.z * z;
}
inline long double Vector3D::dot_product(const long double uMag, const long double vMag, const long double angleBetween)
{
    return uMag * vMag * cos(angleBetween*RADIAN);
}
//cross product
inline Vector3D Vector3D::cross_product(const Vector3D &vec)const
{
    long double ni=y*vec.z-z*vec.y;
    long double nj=z*vec.x-x*vec.z;
    long double nk=x*vec.y-y*vec.x;
    return Vector3D(ni,nj,nk);
}
inline long double Vector3D::scaler_triple_product(Vector3D& b, Vector3D& c) const
{
    return this->dot_product(b.cross_product(c));
}
inline long double Vector3D::find_magnitude()const
{
    return static_cast<long double>( sqrt(square()));
}
inline long double Vector3D::square()const
{
    return static_cast<long double>( x*x+y*y+z*z);
}

inline Vector3D Vector3D::normalize_vector()
{
    //assert(find_magnitude()!=0);
    const auto length = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
    this->x /= length;
    this->y /= length;
    this->z /= length;
    calculate_spherical();
    set_allAngles();
    return *this;
}

inline bool Vector3D::isOrthogonalWith(Vector3D& v)const
{
    return this->dot_product(v) == 0.0;
}

inline void Vector3D::typeOfAngleBetween(const Vector3D& v) const
{
    if (dot_product(v) < 0)
    {
        std::cout << "vectors are obtuse\n";
    }
    else if (dot_product(v) > 0)
    {
        std::cout << "vectors are acute\n";
    }
    else if (dot_product(v) == 0)
    {
        std::cout << "vectors are right";
    }

}

inline bool Vector3D::operator==(const Vector3D& v) const
{
    return std::make_tuple(this->x, this->y, this->z) ==
           std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator!=(const Vector3D& v) const
{
    return std::make_tuple(this->x, this->y, this->z) !=
           std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator>(const Vector3D& v) const
{
    return std::make_tuple(this->x, this->y, this->z) >
           std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator>=(const Vector3D& v) const
{
    return std::make_tuple(this->x, this->y, this->z) >=
           std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator<(const Vector3D& v) const
{
    return std::make_tuple(this->x, this->y, this->z) <
           std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator<=(const Vector3D& v) const
{
    return std::make_tuple(this->x, this->y, this->z) <=
           std::make_tuple(v.x, v.y, v.z);
}


inline long double Vector3D::distance(const Vector3D &vec)const
{
    long double x1, x2, y1, y2, z1, z2;
    x1 = this->x;
    x2 = vec.x;
    y1 = this->y;
    y2 = vec.y;
    z1 = this->z;
    z2 = vec.z;
    return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)));
}

inline long double Vector3D::return_z()const
{
    return z;
}
inline long double Vector3D::return_xAngle()const
{
    return atan2(sqrt(y * y + z * z), x) * DEGREE;
}
inline long double Vector3D::return_yAngle()const
{
    return atan2(sqrt(x * x + z * z), y) * DEGREE;
}
inline long double Vector3D::return_zAngle()const
{
    return atan2(sqrt(x * x  + y * y), z) * DEGREE;
}
inline long double Vector3D::return_mag() const
{
    return static_cast<long double>(sqrt(x * x + y * y + z * z));
}
inline long double Vector3D::return_angle() const
{
    std::cout << "there is no one angle in a 3d vector class so this"
              << " returns the sum of the three angles instead\n";
    return return_xAngle()+return_yAngle()+ return_zAngle();
}
inline long double Vector3D::return_arcLength() const
{
    return return_mag()*return_angle()*RADIAN;
}
inline char Vector3D::return_mode() const
{
    return 0;
}

inline Vector3D Vector3D::projection(Vector3D& v) const
{
    const Vector3D temp(this->x, this->y, this->z);
    const auto dotProd   = this->dot_product(v);
    const auto dpdevisor = this->dot_product(temp);
    const auto scalar    = dotProd / dpdevisor;
    Vector3D resultant   = temp * scalar;
    return resultant;
    //const auto Θ = this->angle_between_vectors(v);
    //return this->magnitude * cos(Θ * RADIAN);
}
inline long double Vector3D::angle_between_vectors(Vector3D& v)const
{
    return acos((x*v.x+y*v.y+z*v.z) / (sqrt(x*x+y*y+z*z)*
                                       sqrt(v.x*v.x+v.y*v.y+v.z*v.z))) * DEGREE;
}
inline void Vector3D::display(const std::string& label)const
{
    std::cout << ((label.empty()) ? ID : label)
              <<":<x,y,z,> = "<<"<"<<x<<", "<<y<<", "<<z<<">"<<endl;
}

inline Vector3D::~Vector3D()
{
    countDecrease();
}

template<typename T>
inline long double Vector3D::distance_to_plane(T a, T b, T c, T d)
{
    auto top = abs(((a * x) + (b * y) + (c * z) + d));
    auto bot = sqrt((a * a) + (b * b) + (c * c));
    return top/bot;
}

#endif //PHYSICSFORMULA_VECTOR3D_H
