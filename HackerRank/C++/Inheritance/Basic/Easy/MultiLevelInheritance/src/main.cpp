#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle
{
public:
    void triangle()
    {
        std::cout << "I am a triangle" << std::endl;
    }
};

class Isosceles : public Triangle
{
public:
    void isosceles()
    {
        std::cout << "I am an isosceles triangle" << std::endl;
    }
};

//Write your code here.
class Equilateral : public Isosceles
{
public:
    void equilateral()
    {
        std::cout << "I am an equilateral triangle" << std::endl;
    }
};


int main(){

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
