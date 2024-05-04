#include<iostream>

using namespace std;

class A
{
public:
    A(){
        callA = 0;
    }
private:
    int callA;
    void inc(){
        callA++;
    }

protected:
    void func(int & a)
    {
        a = a * 2;
        inc();
    }
public:
    int getA(){
        return callA;
    }
};

class B
{
public:
    B(){
        callB = 0;
    }
private:
    int callB;
    void inc(){
        callB++;
    }
protected:
    void func(int & a)
    {
        a = a * 3;
        inc();
    }
public:
    int getB(){
        return callB;
    }
};

class C
{
public:
    C(){
        callC = 0;
    }
private:
    int callC;
    void inc(){
        callC++;
    }
protected:
    void func(int & a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC(){
        return callC;
    }
};

class D : private A, private B, private C
{

    int val;
public:
        //Initially val is 1
    D()
    {
        val = 1;
    }


    //Implement this function
    void update_val(int new_val)
    {
        if (new_val < 1 || new_val > 10000) throw std::invalid_argument("Invalid val");

        int degree = factorDegree(new_val, 5);

        while (degree--)
        {
            C::func(val);
        }
        degree = factorDegree(new_val, 3);
        while (degree--)
        {
            B::func(val);
        }
        degree = factorDegree(new_val, 2);
        while (degree--)
        {
            A::func(val);
        }
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.

private:
    static int factorDegree(int val, const int factor)
    {
        int result {0};
        while (val && !(val % factor))
        {
            val /= factor;
            ++result;
        }
        return result;
    }


};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
