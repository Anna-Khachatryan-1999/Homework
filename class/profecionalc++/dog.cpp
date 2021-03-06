#include <iostream>
class Animal
{
public:
    virtual void eat() = 0;
};

class Dog : public Animal
{
public:
    virtual void bark() { std::cout << "Woof!" << std::endl; }
    void eat() override { std::cout << "The dog ate." << std::endl; }
};

class Bird : public Animal
{
public:
    virtual void chirp() { std::cout << "Chirp!" << std::endl; }
    void eat() override { std::cout << "The bird ate." << std::endl; }
};

class DogBird : public Dog, public Bird
{
public:
    using Dog::eat;
};
int main()
{}
