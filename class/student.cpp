#include <iostream>

class Student
{
public:
    Student();
    Student(std::string, std::string, int, std::string);
    ~Student();

public:
    void set_name(std::string);
    void set_surname(std::string);
    void set_age(int);
    void set_subject_name(std::string);
    std::string get_name() const;
    std::string get_surname() const;
    int get_age() const;
    std::string get_subject_name() const;

private:
    std::string m_name;
    std::string m_surname;
    int m_age;
    std::string m_subject_name;
};

Student::Student() {}

Student::Student(std::string name, std::string surname, int age, std::string subject){
    m_name = name;
    m_surname = surname;
    m_age = age;
    m_subject_name = subject;
}

Student::~Student() {}

void Student::set_name(std::string name)
{
    m_name = name;
}

void Student::set_surname(std::string surname)
{
    m_surname = surname;
}

void Student::set_age(int age)
{
    m_age = age;
}

void Student::set_subject_name(std::string subject)
{
    m_subject_name = subject;
}

std::string Student::get_name() const
{
    return m_name;
}

std::string Student::get_surname() const
{
    return m_surname;
}

int Student::get_age() const
{
    return m_age;
}

std::string Student::get_subject_name() const
{
    return m_subject_name;
}


int main()
{
    Student student;
    student.set_name("Nare");
    student.set_surname("Grigoryan");
    student.set_age(20);
    student.set_subject_name ("Physics");
    Student student1 ("Eva", "Melqonyan", 21, "Mathematics");
    std::cout << student.get_name() << " ";
    std::cout << student.get_surname() << " ";
    std::cout << student.get_age() << " ";
    std::cout << student.get_subject_name() << " ";
    std::cout << std::endl;
    std::cout << student1.get_name() << " ";
    std::cout << student1.get_surname() << " ";
    std::cout << student1.get_age() << " ";
    std::cout << student1.get_subject_name() << " ";
    std::cout << std::endl;
    if (student.get_age() > student1.get_age()) {
        std::cout << student.get_name();
    } else {
        std::cout << student1.get_name();
    }
    Student student2;
    student2.set_name(student.get_name());
    student2.set_surname(student1.get_surname());
    student2.set_age(((student.get_age() + student1.get_age()) / 2));
    student2.set_subject_name ("English");
    std::cout << std::endl;
    std::cout << student2.get_name() << " ";
    std::cout << student2.get_surname() << " ";
    std::cout << student2.get_age() << " ";
    std::cout << student2.get_subject_name() << " ";
    std::cout << std::endl;
    return 0;
}


