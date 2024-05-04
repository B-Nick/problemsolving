#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


class Box final
{
public:
    Box() = default;
    Box (const int _l, const int _b, const int _h)
        : l{_l}, b{_b}, h{_h}
    {
        if (l < 0 || l > 100000 || b < 0 || b > 100000 || h < 0 || h > 100000)
        {
            throw std::invalid_argument("Invalid dimension");
        }
    }
    Box(const Box &other) = default;
    Box(Box &&other) = default;

    ~Box() = default;

    Box &operator= (const Box &other) = default;
    Box &operator= (Box &&other) = default;

    inline int getLength() const {return l;}
    inline int getBreadth() const {return b;}
    inline int getHeight() const {return h;}

    inline long long CalculateVolume() const
    {
        return static_cast<long long>(l) * b * h;
    }

    bool operator< (const Box &other) const
    {
        if (l == other.l)
        {
            if (b == other.b)
            {
                if (h == other.h)
                {
                    throw std::invalid_argument("Boxes annot be equal");
                }
                return h < other.h;
            }
            return b < other.b;
        }
        return l < other.l;
    }


private:
    friend std::ostream &operator<< (ostream &os, const Box &a);

    int l {0};
    int b {0};
    int h {0};
};

std::ostream &operator<< (ostream &os, const Box &box)
{
    os << box.l << " " << box.b << " " << box.h;
    return os;
}



void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}
