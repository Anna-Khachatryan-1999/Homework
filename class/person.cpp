#include <iostream>

class Person
{
public:
    Person();
    Person(std::string, int);
    Person(const Person&);
    Person(Person&&);
    Person& operator=(const Person&);
    Person& operator=(Person&&);
    ~Person();
public:
    void set_name(std::string);
    void set_age(int);
    std::string get_name() const;
    int get_age() const;

private:
    std::string m_name;
    int m_age;
};


Person::Person() : m_age{0}
{
    std::cout << "default ctor" << std::endl;
}

Person::Person(std::string name, int age) : m_name{name}, m_age{age}
{
    std::cout << "ctor with parametrs" << std::endl;
}

Person::Person(const Person& p)
{
    m_name = p.m_name;
    m_age = p.m_age;
    std::cout << "copy ctor" << std::endl;
}

Person::Person(Person&& p)
{
    std::cout << "move ctor" << std::endl;
    m_name = p.m_name;
    m_age = p.m_age;
}

Person& Person::operator=(const Person& p)
{
    m_name = p.m_name;
    m_age = p.m_age;
    std::cout << "operator=" << std::endl;
    return *this;
}

Person& Person::operator=(Person&& p)
{
    m_name = p.m_name;
    m_age = p.m_age;
    std::cout << "move operator=" << std::endl;
    return *this;
}

Person::~Person()
{
    std::cout << "destructor" << std::endl;
}

void Person::set_name(std::string name)
{
    m_name = name;
    std::cout << "set name" << std::endl;
}

void Person::set_age(int age)
{
    m_age = age;
    std::cout << "set age" << std::endl;
}

std::string Person::get_name() const
{
   // std::cout << "get name" << std::endl;
    return m_name;
}

int Person::get_age() const
{
   // std::cout << "get age" << std::endl;
    return m_age;
}


int main()
{
    Person p;
    std::cout << "############################" << std::endl;
    p.set_name("John");
    p.set_age(12);
    std::cout << "############################" << std::endl;
    Person p2("Nika", 20);
    std::cout << "############################" << std::endl;
    Person p3(p);
    std::cout << "############################" << std::endl;
    Person p4 = p2;
    std::cout << "############################" << std::endl;
    p = p4;
    std::cout << "############################" << std::endl;
    

    //Person p5(Person("nune", 6));
    Person p5{Person()};
    std::cout << "############################" << std::endl;
//    std::cout << p.get_name() << " " << p.get_age() << std::endl;
//    std::cout << p2.get_name() << " " << p2.get_age() << std::endl;
//    std::cout << p3.get_name() << " " << p3.get_age() << std::endl;
//    std::cout << p4.get_name() << " " << p4.get_age() << std::endl;
    std::cout << p5.get_name() << " " << p5.get_age();
    Person* p = new Person;
    return 0;
}


