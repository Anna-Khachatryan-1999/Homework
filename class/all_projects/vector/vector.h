#include <utility>
#include <stdlib.h>
#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
public:
    Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    virtual ~Vector();

public:
    T& operator[](int)const;
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    Vector& operator+(Vector&);

public:
    void push_back(const T&);
    void push_front(const T&);

public:
    int get_size() const;
    int get_capasity() const;
    void print() const;

protected:
    int m_capacity;
    int m_size;
    T* m_arr;
    void recapasity();
    void copy(const Vector&);
    void movecopy(Vector&&);
};

/////////// implementation ///////////
template <class T>
Vector<T>::Vector(): m_capacity{10}, m_size{0}, m_arr{new (std::nothrow)T[m_capacity]}
{
    if(!m_arr) {
        std::cout << "Memory allocation failed\n";
            abort();
    }
}

template <class T>
Vector<T>::Vector(const Vector& vec)
{
    copy(vec);
}

template <class T>
Vector<T>::Vector(Vector&& v)
{
    m_capacity = std::exchange(v.m_capacity, 0);
    m_size = std::exchange(v.m_size, 0);
    m_arr = v.m_arr;
    v.m_arr = nullptr;
}

template <class T>
Vector<T>::~Vector()
{
    delete[] m_arr;
}

template <class T>
void Vector<T>::push_back(const T& elem)
{
    if (m_size == m_capacity) {
        recapasity();
    }
    m_arr[m_size++] = elem;
}

template <class T>
void Vector<T>::push_front(const T& elem)
{
    if (m_size == m_capacity) {
        recapasity();
    }
    for (int i = m_size - 1; i >= 0; --i) {
        m_arr[i+1] = m_arr[i];
    }
    m_arr[0] = elem;
}

template <class T>
T& Vector<T>::operator[](int i) const
{
    if (i >= m_size && i < 0) {
        std::cout << "segmentation fault";
        abort();
    }
    return m_arr[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& vec)
{
    copy(vec);
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector&& vec)
{
    movecopy(std::move(vec));
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+(Vector& vec)
{
    std::cout << "~~~~~~~~~~~~~~~~~ operator+ ~~~~~~~~~~~~~~~~~" << std::endl;
    T* arr = new T[m_capacity + vec.m_capacity];
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

template <class T>
int Vector<T>::get_size() const
{
    return m_size;
}

template <class T>
int Vector<T>::get_capasity() const
{
    return m_capacity;
}

template <class T>
void Vector<T>::print() const
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Vector<T>::recapasity()
{
    m_capacity *= 2;
    T* tmp = new (std::nothrow) T[m_capacity];
    if (!tmp) {
        ++m_capacity;
        tmp = new (std::nothrow) T[m_capacity];
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

template <class T>
void Vector<T>::copy(const Vector& vec)
{
    if (this != &vec) {
        m_capacity = vec.m_capacity;
        m_size = vec.m_size;
        m_arr = new T[m_capacity];
        if (m_size != 0) {
            for (int i = 0; i < m_size; ++i) {
                m_arr[i] = vec.m_arr[i];
            }
        }
    }
}

template <class T>
void Vector<T>::movecopy(Vector&& v)
{
    m_capacity = std::exchange(v.m_capacity, 0);
    m_size = std::exchange(v.m_size, 0);
    delete[] m_arr;
    std::cout << "((((((((((((" << std::endl;
    m_arr = v.m_arr;
    v.m_arr = nullptr;
}
#endif // VECTOR_H
