#include <iostream>
#include <stdlib.h>
#include <utility>
#include "vector.h"

Vector::Vector(): m_capacity{10}, m_size{0}, m_arr{new (std::nothrow)int[m_capacity]}
{
    std::cout << "############ ctor ##########" << std::endl;
    if(!m_arr) {
        std::cout << "Memory allocation failed\n";
            abort();
    }
}

Vector::Vector(const Vector& vec)
{
    std::cout << "*********** copy ctor *********" << std::endl;
    copy(vec);
}

Vector::Vector(Vector&& v)
{
    std::cout << "@@@@@@@@@@@@@@@@ move ctor @@@@@@@@@@@@@@@@" << std::endl;
    m_capacity = std::exchange(v.m_capacity, 0);
    m_size = std::exchange(v.m_size, 0);
    m_arr = v.m_arr;
    v.m_arr = nullptr;

}

Vector::~Vector()
{
    std::cout << "^^^^^^^^^^^^^^^^^^ dtor ^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    delete[] m_arr;
}

void Vector::push_back(int elem)
{
    if (m_size == m_capacity) {
        recapasity();
    }
    m_arr[m_size++] = elem;
}

void Vector::push_front(int elem)
{
    if (m_size == m_capacity) {
        recapasity();
    }
    for (int i = m_size - 1; i >= 0; --i) {
        m_arr[i+1] = m_arr[i];
    }
    m_arr[0] = elem;
}

int& Vector::operator[](int i) const
{
    if (i >= m_size) {
        std::cout << "segmentation fault";
        abort();
    }
    return m_arr[i];
}

Vector& Vector::operator= (const Vector& vec)
{
    std::cout << "!!!!!!!!!!!!!!!!!!! operator= !!!!!!!!!!!!!!!!!!" << std::endl;
    copy(vec);
    return *this;
}

Vector& Vector::operator=(Vector&& vec)
{
    std::cout << "$$$$$$$$$$$$$ move operator= &&&&&&&&&&&&&&&" << std::endl;
    movecopy(std::move(vec));
    return *this;
}

Vector& Vector::operator+(Vector& vec)
{
    std::cout << "~~~~~~~~~~~~~~~~~ operator+ ~~~~~~~~~~~~~~~~~" << std::endl;
    int* arr = new int[m_capacity + vec.m_capacity];
    int i = 0;
    for (; i < m_size; ++i) {
        arr[i] = m_arr[i];
    }
    for (int j = 0; i < vec.m_size; ++i) {
        arr[i] = vec[i];
        ++i;
    }
    delete[] m_arr;
    m_arr = arr;
    m_size = i;
    m_capacity += vec.m_capacity;
    arr = nullptr;
    vec.m_capacity = 0;
    vec.m_size = 0;
    return *this;
}

int Vector::get_size() const
{
    return m_size;
}

int Vector::get_capasity() const
{
    return m_capacity;
}

void Vector::print() const
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::recapasity()
{
    m_capacity *= 2;
    int* tmp = new (std::nothrow) int[m_capacity];
    if (!tmp) {
        ++m_capacity;
        tmp = new (std::nothrow) int[m_capacity];
        if (!tmp) {
            std::cout << "Memory allocation failed\n";
            abort();
        }
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = tmp;
    tmp = nullptr;
    }
}

void Vector::copy(const Vector& vec)
{
    if (this != &vec) {
        m_capacity = vec.m_capacity;
        m_size = vec.m_size;
        m_arr = new int[m_capacity];
        if (m_size != 0) {
            for (int i = 0; i < m_size; ++i) {
                m_arr[i] = vec.m_arr[i];
            }
        }
    }
}

void Vector::movecopy(Vector&& v)
{
    m_capacity = std::exchange(v.m_capacity, 0);
    m_size = std::exchange(v.m_size, 0);
    delete[] m_arr;
    std::cout << "((((((((((((" << std::endl;
    m_arr = v.m_arr;
    v.m_arr = nullptr;
}

