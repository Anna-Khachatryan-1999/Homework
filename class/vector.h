#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    virtual ~Vector();

public:
    int& operator[](int)const;
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    Vector& operator+(Vector&);

public:
    void push_back(int);
    void push_front(int);

public:
    int get_size() const;
    int get_capasity() const;
    void print() const;

private:
    int m_capacity;
    int m_size;
    int* m_arr;
    void recapasity();
    void copy(const Vector&);
    void movecopy(Vector&&);
};
#endif // VECTOR_H
