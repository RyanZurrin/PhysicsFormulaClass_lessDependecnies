//
// Created by ryanz on 8/26/2022.
//

#ifndef PHYSICSFORMULA_UNITVECTOR_H
#define PHYSICSFORMULA_UNITVECTOR_H
#include <iostream>
#include <cmath>
using namespace std;

class UnitVector {
    long double x{};
    long double y{};
    long double z{};
    long double x2{};
    long double y2{};
    long double z2{};
    long double magnitude{};
public:
    constexpr UnitVector() {
        x = 0;
        y = 0;
        z = 0;
        x2 = 0;
        y2 = 0;
        z2 = 0;
        magnitude = 0;
    }
    constexpr UnitVector(long double x, long double y, long double x2_, long double y2_) {
        this->x = x;
        this->y = y;
        this->z = 0;
        this->x2 = x2_;
        this->y2 = y2_;
        this->z2 = 0;
        this->magnitude = this->calculateMagnitude();
    }
    constexpr UnitVector(pair<long double, long double> p, pair<long double, long double> p2) {
        this->x = p.first;
        this->y = p.second;
        this->z = 0;
        this->x2 = p2.first;
        this->y2 = p2.second;
        this->z2 = 0;
        this->magnitude = this->calculateMagnitude();
    }
    constexpr UnitVector(long double x_, long double y_, long double z_, long double x2_, long double y2_, long double z2_) {
        this->x = x_;
        this->y = y_;
        this->z = z_;
        this->x2 = x2_;
        this->y2 = y2_;
        this->z2 = z2_;
        this->magnitude = this->calculateMagnitude();
    }
    constexpr UnitVector(const UnitVector& u_) {
        this->x = u_.x;
        this->y = u_.y;
        this->z = u_.z;
        this->x2 = u_.x2;
        this->y2 = u_.y2;
        this->z2 = u_.z2;
        this->magnitude = u_.magnitude;
    }
    constexpr UnitVector(UnitVector&& u_) noexcept {
        this->x = u_.x;
        this->y = u_.y;
        this->z = u_.z;
        this->x2 = u_.x2;
        this->y2 = u_.y2;
        this->z2 = u_.z2;
        this->magnitude = u_.magnitude;
    }
    constexpr UnitVector& operator=(const UnitVector& u_) {
        if (this != &u_) {
            this->x = u_.x;
            this->y = u_.y;
            this->z = u_.z;
            this->x2 = u_.x2;
            this->y2 = u_.y2;
            this->z2 = u_.z2;
            this->magnitude = u_.magnitude;
        }
        return *this;
    }
    constexpr UnitVector& operator=(UnitVector&& u_) noexcept {
        if (this != &u_) {
            this->x = u_.x;
            this->y = u_.y;
            this->z = u_.z;
            this->x2 = u_.x2;
            this->y2 = u_.y2;
            this->z2 = u_.z2;
            this->magnitude = u_.magnitude;
        }
        return *this;
    }
    [[nodiscard]] long double getX() const { return x; }
    [[nodiscard]] long double getY() const { return y; }
    [[nodiscard]] long double getZ() const { return z; }
    [[nodiscard]] long double getX2() const { return x2; }
    [[nodiscard]] long double getY2() const { return y2; }
    [[nodiscard]] long double getZ2() const { return z2; }

    [[nodiscard]] long double getMagnitude() const { return magnitude; }
    void setX(long double x_) { this->x = x_; }
    void setY(long double y_) { this->y = y_; }
    void setZ(long double z_) { this->z = z_; }
    void setX2(long double x2_) { this->x2 = x2_; }
    void setY2(long double y2_) { this->y2 = y2_; }
    void setZ2(long double z2_) { this->z2 = z2_; }

    [[nodiscard]] constexpr long double calculateMagnitude() const {
        return sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y) + (z2-z)*(z2-z));
    }

    void set(long double x_, long double y_, long double z_, long double x2_, long double y2_, long double z2_) {
        this->x = x_;
        this->y = y_;
        this->z = z_;
        this->x2 = x2_;
        this->y2 = y2_;
        this->z2 = z2_;
        this->magnitude = this->calculateMagnitude();
    }

    [[nodiscard]] string toString() const {
        // print in form of using i, j, k notation
        return "(" + to_string((x + x2)/magnitude) + "i, + " + to_string
                ((y + y2)/magnitude) + "j, + "
               + to_string((z+ z2)/magnitude) + "k)";
    }
    constexpr void print(bool print = true) const {
        // print in form of using i, j, k notation
        if (print) {
            cout << this->getX() << "i + " << this->getY() << "j + "
                 << this->getZ() << "k" << endl;
            cout << this->getX2() << "i + " << this->getY2() << "j + "
                 << this->getZ2() << "k" << endl;
            cout << "Magnitude: " << this->getMagnitude() << endl;
            cout << "(" << (x+x2) / magnitude << "i, + " << (y+y2) / magnitude
                 << "j, + " << (z+z2)/magnitude << "k)";
        }
    }

    // add Unit Vectors
    constexpr UnitVector operator+(const UnitVector& u_) const {
        return UnitVector(x + u_.x, y + u_.y, z + u_.z, x2 + u_.x2, y2 + u_.y2, z2 + u_.z2);
    }
    constexpr UnitVector operator+(const UnitVector&& u_) const {
        return UnitVector(x + u_.x, y + u_.y, z + u_.z, x2 + u_.x2, y2 + u_.y2, z2 + u_.z2);
    }
    constexpr UnitVector& operator+=(const UnitVector& u_) {
        this->x += u_.x;
        this->y += u_.y;
        this->z += u_.z;
        this->x2 += u_.x2;
        this->y2 += u_.y2;
        this->z2 += u_.z2;
        this->magnitude = this->calculateMagnitude();
        return *this;
    }
    constexpr UnitVector& operator+=(const UnitVector&& u_) {
        this->x += u_.x;
        this->y += u_.y;
        this->z += u_.z;
        this->x2 += u_.x2;
        this->y2 += u_.y2;
        this->z2 += u_.z2;
        this->magnitude = this->calculateMagnitude();
        return *this;
    }
    // subtract Unit Vectors
    constexpr UnitVector operator-(const UnitVector& u_) const {
        return UnitVector(x - u_.x, y - u_.y, z - u_.z, x2 - u_.x2, y2 - u_.y2, z2 - u_.z2);
    }
    constexpr UnitVector operator-(const UnitVector&& u_) const {
        return UnitVector(x - u_.x, y - u_.y, z - u_.z, x2 - u_.x2, y2 - u_.y2, z2 - u_.z2);
    }
    constexpr UnitVector& operator-=(const UnitVector& u_) {
        this->x -= u_.x;
        this->y -= u_.y;
        this->z -= u_.z;
        this->x2 -= u_.x2;
        this->y2 -= u_.y2;
        this->z2 -= u_.z2;
        this->magnitude = this->calculateMagnitude();
        return *this;
    }
    constexpr UnitVector& operator-=(const UnitVector&& u_) {
        this->x -= u_.x;
        this->y -= u_.y;
        this->z -= u_.z;
        this->x2 -= u_.x2;
        this->y2 -= u_.y2;
        this->z2 -= u_.z2;
        this->magnitude = this->calculateMagnitude();
        return *this;
    }
    // multiply Unit and Scalar
    constexpr UnitVector operator*(const long double& s_) const {
        return UnitVector(x * s_, y * s_, z * s_, x2 * s_, y2 * s_, z2 * s_);
    }
    constexpr UnitVector operator*(const long double&& s_) const {
        return UnitVector(x * s_, y * s_, z * s_, x2 * s_, y2 * s_, z2 * s_);
    }
    constexpr UnitVector& operator*=(const long double& s_) {
        this->x *= s_;
        this->y *= s_;
        this->z *= s_;
        this->x2 *= s_;
        this->y2 *= s_;
        this->z2 *= s_;
        this->magnitude = this->calculateMagnitude();
        return *this;
    }
    // normalize Unit Vector in place
    constexpr void normalize() {
        this->x /= magnitude;
        this->y /= magnitude;
        this->z /= magnitude;
        this->x2 /= magnitude;
        this->y2 /= magnitude;
        this->z2 /= magnitude;
        this->magnitude = this->calculateMagnitude();

    }

}; // end of class UnitVector


#endif //PHYSICSFORMULA_UNITVECTOR_H
