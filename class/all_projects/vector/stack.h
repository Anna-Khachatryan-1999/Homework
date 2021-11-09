#ifndef STACK_H
#define STACK_H
#include "vector.h"

template <class T>
class Stack: private Vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;
public:
    void push(const T& elem);
    T pop();
    T& top()const;
    bool isempty()const;
    int size() const;
private:
};

template <class T>
void Stack<T>::push(const T& elem)
{
    Vector<T>::push_back(elem);
   //Vector<T>::print();
}

/////////// implementation ///////////
template <class T>
T Stack<T>::pop()
{
    if(isempty()) {
        std::cout << "Stack is empty" << std::endl;
        abort();
    }
    --Vector<T>::m_size;
    return Vector<T>::m_arr[Vector<T>::m_size - 1];
}

template <class T>
T& Stack<T>::top()const
{
    if(isempty()) {
        std::cout << "don't element" << std::endl;
        abort();
    }
    return Vector<T>::m_arr[Vector<T>::m_size - 1];
}

template <class T>
bool Stack<T>::isempty()const
{
    if(!Vector<T>::m_size) {
        return true;
    } else {
        return false;
    }
}
template <class T>
int Stack<T>::size() const
{
    return Vector<T>::m_size;
}
#endif //STACK_H


