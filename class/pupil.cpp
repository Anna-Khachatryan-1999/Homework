#include <iostream>
#include <vector>

class Pupil
{
public:
    struct Quarter
    {
        std::string subject;
        int rating;
    };

public:
    Pupil();
    Pupil(std::string, int, int);
    Pupil(const Pupil&);
    Pupil& operator=(const Pupil&);
    ~Pupil();


public:
    void set_name(std::string);
    void set_age(int);
    void set_classroom(int);
    void push(std::string, int);
    std::string get_name() const;
    int get_age() const;
    int get_classroom() const;
    int get_id() const;
    std::vector<Quarter> get_quarter()const;
    double average_of_quarters() const;
public:
    static int m_count;

private:
    std::string m_name;
    int m_age;
    int m_classroom;
    int m_id;
    std::vector<Quarter> m_quarter;
};

int Pupil::m_count = 0;

Pupil::Pupil()
{
    m_id = ++Pupil::m_count;
}

Pupil::Pupil(std::string name, int age, int classroom)
{
    m_id = ++Pupil::m_count;
    m_name = name;
    m_age = age;
    m_classroom = classroom;
}

Pupil::Pupil(const Pupil& p)
{
    m_id = ++Pupil::m_count;
    m_name = p.m_name;
    m_age = p.m_age;
    m_classroom = p.m_classroom;
    m_quarter = p.m_quarter;
}

Pupil& Pupil::operator=(const Pupil& p)
{
    m_name = p.m_name;
    m_age = p.m_age;
    m_classroom = p.m_classroom;
    m_quarter = p.m_quarter;
    return *this;
}

Pupil::~Pupil(){}

void Pupil::set_name(std::string name)
{
    m_name = name;
}

void Pupil::set_age(int age)
{
    if (age >= 5 && age <= 20) {
        m_age = age;
    } else {
        std::cout << "age does not correspond to the student!" << std::endl;
    }
}

void Pupil::set_classroom(int classroom)
{
    if (classroom >= 0 && classroom <= 11) {
        m_classroom = classroom;
    } else {
        std::cout << "the classroom does not correspond to the range [0, 12]" << std::endl;
    }
}

void Pupil::push(std::string subject, int rating)
{
    int size = m_quarter.size();
    for(int i = 0; i < size; ++i) {
        if (subject == m_quarter[i].subject) {
            std::cout << "You have already entered a subject named '" << subject << "'" << std::endl;
            return;
        }
    }
    Pupil::Quarter q;
    q.subject = subject;
    q.rating = rating;
    m_quarter.push_back(q);
}

std::string Pupil::get_name() const
{
    return m_name;
}

int Pupil::get_age() const
{
    return m_age;
}

int Pupil::get_classroom() const
{
    return m_classroom;
}

int Pupil::get_id() const
{
    return m_id;
}

std::vector<Pupil::Quarter> Pupil::get_quarter()const
{
    return m_quarter;
}

double Pupil::average_of_quarters() const
{
    int size = m_quarter.size();
    double avg = 0.0;
    for(int i = 0; i < size; ++i) {
        avg += m_quarter[i].rating;
    }
    return avg / size;
}

int main()
{
    Pupil p;
    p.set_name("Nika");
    p.set_age(13);
    p.set_classroom(7);
    p.push("Mathematics", 7);
    p.push("Chemistry", 8);
    p.push("Physics", 7);
    p.push("Armenian language", 9);
    p.push("History", 9);
    p.push("English", 7);
    std::cout << p.get_id() << " " << p.average_of_quarters() << std::endl;
    Pupil p1(p);
    Pupil p2;
    p2 = p;
    std::cout << p1.get_id() << " " << p1.average_of_quarters() << std::endl;
    std::cout << p2.get_id() << " " << p2.average_of_quarters() << std::endl;

return 0;
}
