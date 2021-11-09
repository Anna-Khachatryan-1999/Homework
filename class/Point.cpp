#include <iostream>

class Point
{
public:
    Point() : m_x{0.0}, m_y{0} {};
    Point (double x, double y) : m_x{x}, m_y{y} {}
    ~Point() {}
public:
    void setX (double x) { m_x = x; }
    void setY (double y) { m_y = y; }
    double getX () const { return m_x; }
    double getY () const { return m_y; }
private:
    double m_x;
    double m_y;
};

class Line
{
public:
    Line();
    Line (Point start, Point end);
    ~Line();

public:
    Point& operator[](int);

public:
    void set_start(Point);
    void set_end(Point);
    void set_list(Point, Point);
    Point get_start() const;
    Point get_end() const;
    Point* get_list() const;

private:
    Point* m_line = new Point[10]{Point()};
    Point m_start;
    Point m_end;
};

Line::Line() : m_start{0.0, 0.0}, m_end{0.0, 0.0} {}

Line::Line(Point start, Point end)
{
    m_start = start;
    m_end = end;
    double x1 = start.getX();
    double y1 = start.getY();
    double x2 = end.getX();
    double y2 = end.getY();
    double x = (x1 + x2) / 10;
    double y = (y1 + y2) / 10;
    m_line[0] = m_start;
    for (int i = 1; i < 9; ++i) {
        m_line[i] = Point (m_start.getX() + x*i, m_start.getY() + y*i);
    }
    m_line[9] = m_end;
}

Line::~Line()
{
    delete[] m_line;
}

void Line::set_start(Point start)
{
    m_start = start;
}

void Line::set_end(Point end)
{
    m_end = end;
}

Point& Line::operator[](int i)
{
    return m_line[i];
}

void Line::set_list(Point start, Point end) {
    m_start = start;
    m_end = end;
    double x1 = start.getX();
    double y1 = start.getY();
    double x2 = end.getX();
    double y2 = end.getY();
    double x = (x1 + x2) / 10;
    double y = (y1 + y2) / 10;
    m_line[0] = m_start;
    for (int i = 1; i < 9; ++i) {
        m_line[i] = Point (m_start.getX() + x*i, m_start.getY() + y*i);
    }
    m_line[9] = m_end;
}
Point Line::get_start() const
{
    return m_start;
}

Point Line::get_end() const
{
    return m_end;
}

Point* Line::get_list() const
{
    return m_line;
}

void intersection_of_lines (Point* p1, Point* p2)
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if ((p1[i].getX() == p2[j].getX()) && (p1[i].getY() == p2[j].getY())) {
                std::cout << "YES" << std::endl;
                return;
            }
        }
    }
    std::cout << "NO" << std::endl;
}

int main()
{
    Point p;
    p.setX(12);
    p.setY(15);
    Point p1(2, 5);
    std::cout << "(" << p.getX() << " " << p.getY() << ")";
    std::cout << std::endl;
    std::cout << "(" << p1.getX() << " " << p1.getY() << ")";
    std::cout << std::endl;
    Line l;
    l.set_start(Point(3,5));
    l.set_end(Point(7,5));
    l.set_list(l.get_start(), l.get_end());
    Line l1(p, p1);
    Point* l2 = l1.get_list();
    Point* l3 = l.get_list();
    Point* l4 = l1.get_list();
    for (int i = 0; i < 10; ++i) {
        std::cout << "(" << l2[i].getX() << "," << l2[i].getY() << ")" << " ";
    }
    std::cout << std::endl;
    intersection_of_lines(l2, l3);
    intersection_of_lines(l2, l4);
    return 0;
}
