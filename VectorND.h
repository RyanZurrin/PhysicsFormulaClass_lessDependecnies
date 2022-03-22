//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_VECTORND_H
#define PHYSICSFORMULA_VECTORND_H
/**
 * @class VectorND
 * @details class of static methods that relate to chapter 29 of the open stax
 * college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  5/22/2021
 * lastEdit 5/26/2021
 */

#ifndef VECTOR_ND_H
#define VECTOR_ND_H
#include <cstdarg>
#include <cmath>
#include <iostream>
#include <vector>
#include "Vector3D.h"
using namespace std;
#define ull unsigned long long
#define lld  long double

//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ


static int vecNd_objCounter = 0;
using namespace std;

template <typename T>
void display_vector(T& v)
{
    // Declare iterator
    typename T::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ++ptr) {
        cout << *ptr << ' ';
    }
    cout << '\n';
}

// Template class to create vector of
// different data_type
template <typename T>
class VectorND {


public:
    explicit VectorND(ull = 4);
    VectorND(VectorND&& v)noexcept
    {
        countIncrease();
        ID = "vecNd_" + std::to_string(vecNd_objCounter);
        this->capacity = v.capacity;
        this->arr = v.arr;
        this->length = 0;
        for (auto i = 0; i < v.length; i++)
        {
            this->push_back(v.arr[i]);
        }
        magnitude = calculateMagnitude();
    };

    VectorND(const VectorND& v)
    {
        countIncrease();
        ID = "vecNd_" + std::to_string(vecNd_objCounter);
        this->capacity = v.capacity;
        this->arr = v.arr;
        this->length = 0;
        for (int i = 0; i < v.length; i++)
        {
            this->push_back(v.arr[i]);
        }
        magnitude = calculateMagnitude();
    }

    template<typename ... Args>
    explicit VectorND(const T& first, const Args&... args);

    // Function that returns the number of
    // elements in array after pushing the data
    ull push_back(T);

    // function that returns the popped element
    T pop_back();


    template<typename... Args>
    void addValuesToVector(const T& first, const Args&... args);

    void display_vector(std::string label = "")const;
    void display_eigen(std::string label = "")const;
    void show_magnitude(std::string label = "")const;

    // Function that return the size of vector
    ull size() const;
    T& operator[](ull);

    // Iterator Class
    class iterator {

    public:
        explicit iterator()
                : ptr(nullptr)
        {
        }
        explicit iterator(T* p)
                : ptr(p)
        {
        }
        bool operator==(const iterator& rhs) const
        {
            return ptr == rhs.ptr;
        }
        bool operator!=(const iterator& rhs) const
        {
            return !(*this == rhs);
        }
        T operator*() const
        {
            return *ptr;
        }
        iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++*this;
            return temp;
        }
    private:
        // Dynamic array using pointers
        T* ptr;

    };

    // Begin iterator
    iterator begin() const;

    // End iterator
    iterator end() const;

    static void show_objectCount() { std::cout << "\nvectorND object count: "
                                               << vecNd_objCounter << std::endl; }
    static int get_objectCount() { return vecNd_objCounter; }

    //VectorNd<T>(VectorNd<T>&& temp)noexcept;
    bool operator==(const VectorND& v);
    bool operator!=(const VectorND& v);
    bool operator>(const VectorND& v)const;
    bool operator>=(const VectorND& v)const;
    bool operator<(const VectorND& v)const;
    bool operator<=(const VectorND& v)const;
    VectorND<T> operator+(const VectorND &vec)const;    //addition
    VectorND<T> operator+(VectorND &vec)const;
    VectorND<T> &operator+=(const VectorND &vec);  ////assigning new result to the vector
    VectorND<T> operator-(const VectorND &vec);    //subtraction
    VectorND<T> operator-(const T number)const;
    VectorND<T> operator-()const;
    VectorND<T> operator--();
    VectorND<T> operator--(int);
    VectorND<T> &operator-=(const VectorND &vec);  //assigning new result to the vector

    VectorND<T> &operator*=(T value);  //assigning new result to the vector.
    VectorND<T> &operator=(const VectorND<T> &vec);
    VectorND<T> &operator=(const VectorND<T> *v);
    VectorND<T> &operator=(VectorND<T>&& right)noexcept;
    VectorND<T> operator*(T);

    friend VectorND<T> operator*(T s, VectorND& v)
    {
        return v*s;
    }
    friend VectorND<T> operator*(VectorND& v, VectorND& s)
    {
        VectorND<T> temp(v.length);
        temp.vec = v.vec;
        temp.length = 0;
        for (int i = 0; i < v.length; i++)
        {
            temp.push_back(v.arr[i] * s.arr[i]);
        }
        return temp;
    }

    [[nodiscard]] double dot_product(const VectorND& v)const;
    [[nodiscard]] VectorND<T> cross_product(const VectorND& v)const;
    [[nodiscard]] double distance(const VectorND& v)const;
    [[nodiscard]] double angle_between_vectors(VectorND& v)const;
    int getSize() const;
    bool isOrthogonalWith(VectorND& v)const;
    void typeOfAngleBetween(const VectorND& v)const;

private:
    T* arr;

    // Variable to store the current capacity
    // of the vector
    ull capacity;

    // Variable to store the length of the
    // vector
    ull length;

    //Variable to store the magnitude of all the elements
    ull magnitude;

    //Variable to store the vector name
    string ID;



    ull calculateMagnitude();

    bool isEqual(VectorND rhs);

    static void countIncrease() { vecNd_objCounter += 1; }
    static void countDecrease() { vecNd_objCounter -= 1; }

public:
    ~VectorND();

    void set(int i, VectorND<float> nd);

    int get(int i);
};
#endif

// Template class to return the size of
// vector of different data_type
template <typename T>
VectorND<T>::VectorND(ull n)
        : arr(new T[n]),
          capacity(n),
          length(0),
          magnitude(0),
          ID("")
{
    magnitude = calculateMagnitude();
    countIncrease();
    ID = "vecNd_" + std::to_string(vecNd_objCounter);
}

template<typename T>
template<typename ...Args>
inline VectorND<T>::VectorND(const T& first, const Args & ...args)
{
    countIncrease();
    ID = "vecNd_" + std::to_string(vecNd_objCounter);
    arr = new T[100];
    capacity = 100;
    length = 0;
    vector<T> container;
    container.push_back(first);
    int dummy[] = { 0, (container.push_back(args), 0)... };
    (void)dummy;

    for (const auto& i : container)
    {
        this->push_back(i);
    }
    magnitude = calculateMagnitude();
}

template<typename T>
template<typename ...Args>
inline void VectorND<T>::addValuesToVector(const T& first, const Args & ...args)
{
    vector<T> container;
    container.push_back(first);
    int dummy[] = { 0, (container.push_back(args), 0)... };
    (void)dummy;

    for (const auto &i : container)
    {
        this->push_back(i);
    }
    magnitude = calculateMagnitude();
}




// Template class to insert the element
// in vector
template <typename T>
ull VectorND<T>::push_back(T data)
{
    if (length == capacity) {
        T* old = arr;
        arr = new T[capacity = capacity * 2];
        copy(old, old + length, arr);
        delete[] old;
    }
    arr[length++] = data;

    magnitude = calculateMagnitude();
    return length;
}

// Template class to return the popped element
// in vector
template <typename T>
T VectorND<T>::pop_back()
{
    auto temp = arr[length-- - 1];
    magnitude = calculateMagnitude();
    return temp;
}

template<class T>
inline void VectorND<T>::display_vector(std::string label)const
{
    std::cout << ((label == "") ? ID : label)<<": ";
    for (typename VectorND::iterator ptr = this->begin(); ptr != this->end(); ++ptr) {
        cout << *ptr << ' ';
    }
    show_magnitude(label);
    cout << '\n';

}

template <typename T>
void VectorND<T>::show_magnitude(std::string label) const
{
    std::cout<< "\n" << ((label.empty()) ? ID : label)<<":";
    std::cout << " Magnitude: " << magnitude << endl;
}

// Template class to return the size of
// vector
template <typename T>
ull VectorND<T>::size() const
{
    return length;
}

// Template class to return the element of
// vector at given index
template <typename T>
T& VectorND<T>::operator[](ull index)
{
    if (index >= length&&index>capacity) {
        cout << "Error: Array index out of bound";
        exit(0);
    }
    return *(arr + index);
}


// Template class to return begin iterator
template <typename T>
typename VectorND<T>::iterator
VectorND<T>::begin() const
{
    return iterator(arr);
}

// Template class to return end iterator
template <typename T>
typename VectorND<T>::iterator
VectorND<T>::end() const
{
    return iterator(arr + length);
}

template <typename T>
ull VectorND<T>::calculateMagnitude()
{
    ull total = static_cast<unsigned long long>(0.0);
    for (size_t i = 0; i < length; i++)
    {
        total = total + static_cast<unsigned long long>(arr[i] * arr[i]);
    }
    total = static_cast<unsigned long long>(sqrt(total));
    return total;
}

template <typename T>
bool VectorND<T>::isEqual(VectorND rhs)
{
    if (this->length != rhs.length)
        return false;

    /* Compare elements of the array */
    for (int i = 0; i < rhs.length; i++)
        if (arr[i] != rhs.arr[i])
            return false; /* Elements are not same */

    /* All elements are same */
    return true;
}


template<typename T>
bool VectorND<T>::operator==(const VectorND& v)
{
    return this->isEqual(v);
}

template<typename T>
bool VectorND<T>::operator!=(const VectorND& v)
{
    return !(this->isEqual(v));
}

template<typename T>
bool VectorND<T>::operator>(const VectorND& v) const
{
    return this->magnitude > v.magnitude;
}

template<typename T>
bool VectorND<T>::operator>=(const VectorND& v) const
{
    return this->magnitude >= v.magnitude;
}

template<typename T>
bool VectorND<T>::operator<(const VectorND& v) const
{
    return this->magnitude < v.magnitude;
}

template<typename T>
bool VectorND<T>::operator<=(const VectorND& v) const
{
    return this->magnitude <= v.magnitude;
}

template<typename T>
VectorND<T> VectorND<T>::operator+(const VectorND& vec) const
{
    VectorND<T> temp;
    for (size_t i = 0; i < vec.length; i++)
    {
        temp.push_back(this->arr[i] + vec.arr[i]);
    }
    magnitude = calculateMagnitude();
    return temp;
}

template <typename T>
VectorND<T> VectorND<T>::operator+(VectorND& vec) const
{
    VectorND<T> temp;
    for (size_t i = 0; i < vec.length; i++)
    {
        temp.push_back(this->arr[i] + vec.arr[i]);
    }
    magnitude = calculateMagnitude();
    return temp;
}

template<typename T>
VectorND<T>& VectorND<T>::operator+=(const VectorND& vec)
{
    for (size_t i = 0; i < length; i++)
    {
        this->arr[i] += vec.arr[i];
    }
    magnitude = calculateMagnitude();
    return *this;
}

template<typename T>
VectorND<T> VectorND<T>::operator-(const VectorND& vec)
{
    VectorND<T> temp;
    for (size_t i = 0; i < length; i++)
    {
        temp.arr[i] = this->arr[i] - vec.arr[i];
    }
    magnitude = calculateMagnitude();
    return temp;
}

template<typename T>
VectorND<T> VectorND<T>::operator-(const T number) const
{
    VectorND<T> temp;
    for (size_t i = 0; i < length; i++)
    {
        temp = this->arr[i] - number;
    }
    magnitude = calculateMagnitude();
    return temp;
}

template<typename T>
VectorND<T> VectorND<T>::operator-() const
{
    VectorND<T> temp;
    for (size_t i = 0; i < length; i++)
    {
        temp.arr[i] = this->arr[-i];
    }
    magnitude = calculateMagnitude();
    return temp;
}

template<typename T>
VectorND<T> VectorND<T>::operator--()
{
    VectorND<T> temp;
    for (size_t i = 0; i < length; i++)
    {
        temp.arr[i] = this->arr[--i];
    }
    magnitude = calculateMagnitude();
    return temp;
}

template<typename T>
VectorND<T> VectorND<T>::operator--(int)
{
    VectorND<T> temp;
    for (int i = 0; i < length; i++)
    {
        temp.arr[i] = this->arr[i--];
    }
    magnitude = calculateMagnitude();
    return temp;
}

template<typename T>
VectorND<T>& VectorND<T>::operator-=(const VectorND& vec)
{
    for (int i = 0; i < length; i++)
    {
        this->arr[i] -= vec.arr[i];
    }
    magnitude = calculateMagnitude();
    return *this;
}

template<typename T>
VectorND<T>& VectorND<T>::operator*=(T value)
{
    for (auto i = 0; i < length; i++)
    {
        arr[i] *= value;
    }
    magnitude = calculateMagnitude();
    return *this;
}

template<typename T>
VectorND<T>& VectorND<T>::operator=(const VectorND& v)
{
    this->length = v.length;
    this->capacity = v.capacity;
    for (int i = 0; i < length; i++)
    {
        this->arr[i] = v.arr[i];
    }
    magnitude = calculateMagnitude();
    return *this;
}

template<typename T>
VectorND<T>& VectorND<T>::operator=(const VectorND<T>* v)
{
    this->capacity = v->capacity;
    this->length = v->length;
    for (size_t i = 0; i < v->size(); i++)
    {
        this->arr[i] = v->arr[i];
    }
    magnitude = calculateMagnitude();
    return *this;
}

template<typename T>
VectorND<T>& VectorND<T>::operator=(VectorND<T>&& right) noexcept
{
    if (this != &right)
    {
        swap(this->capacity, right.capacity);
        swap(this->length, right.length);
        swap(this->vec, right.vec);
        swap(this->magnitude, right.magnitude);
    }
    return *this;
}

template<typename T>
VectorND<T> VectorND<T>::operator*(T s)
{
    VectorND<T> temp;
    for (auto i = 0; i < length; i++)
    {
        temp.push_back(arr[i] * s);
    }
    magnitude = calculateMagnitude();
    return	temp;
}

template<typename T>
inline double VectorND<T>::dot_product(const VectorND& v) const
{
    auto total = 0;
    for (int i = 0; i < length; i++)
    {
        total += arr[i] * v.arr[i];
    }
    return total;
}

template<typename T>
inline VectorND<T> VectorND<T>::cross_product(const VectorND& v) const
{
    if (length != 3)
    {
        std::cout << "cross product can only be used on vectors of length 3.";
        return this;
    }
    long double ni = arr[1] * arr[2] - arr[2] * arr[1];
    long double nj = arr[2] * arr[0] - arr[0] * arr[2];
    long double nk = arr[0] * arr[1] - arr[1] * arr[0];
    return VectorND(ni, nj, nk);
}

template<typename T>
inline double VectorND<T>::distance(const VectorND& v) const
{
    double sum = 0.0;
    for (int i = 0; i < v.length; i++) {
        sum += pow(arr[i] - v.arr[i], 2);
    }
    return sqrt(sum);
}

template<typename T>
inline double VectorND<T>::angle_between_vectors(VectorND& v) const
{
    auto dotProd = dot_product(v);
    auto divisor = magnitude * v.magnitude;
    auto temp = dotProd / divisor;
    return acos(temp)*DEGREE;
}

template<typename T>
inline bool VectorND<T>::isOrthogonalWith(VectorND& v) const
{
    return dot_product(v) == 0.0;
}

template<typename T>
inline void VectorND<T>::typeOfAngleBetween(const VectorND& v) const
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
        std::cout << "vectors are right\n";
    }
}



template<typename T>
VectorND<T>::~VectorND()
{
    countDecrease();
}

template<typename T>
int VectorND<T>::getSize() const {
    return length;
}

template<typename T>
void VectorND<T>::set(int i, VectorND<float> nd) {
    arr[i] = nd;
}

template<typename T>
int VectorND<T>::get(int i) {
    return arr[i];
}
// Template class to display element in
// vector

#endif //PHYSICSFORMULA_VECTORND_H
