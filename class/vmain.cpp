#include <iostream>
#include "vector.h"

int main()
{
    Vector v;
    v.push_back(12);
    v.push_back(13);
    v.push_front(2);
    v.push_back(16);
    v.push_back(17);
    v.push_back(19);
    v.push_back(21);
    v.push_back(121);
    v.push_back(212);
  //  std::cout << v[8];  //^_^
    v.print();
    Vector v1 = v;
    v1.push_back(2212);
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(v1[8]);
    v1.print();
    Vector v2;
    v2 = v;
    v2.print();
    Vector v9;
    v9 = Vector();
    Vector v10;
    v10 = v1 + v2;
    v10.print();
    //Vector v11(v + v);
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    //v11.print();
    Vector v12({Vector()});
    v1.print();
    std::cout << v1[0];
     int a = v1[0];
    std::cout << a << std::endl;
    a = 4;
    v1[0] = 4;
    std::cout << a << std::endl;
    v1.print();
    return 0;
}
