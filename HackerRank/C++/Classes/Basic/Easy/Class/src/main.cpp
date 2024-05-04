#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student
{
public:
    inline void set_age(const int a) {age = a;}
    inline int get_age() const {return age;}

    inline void set_standard(const int s) {standard = s;}
    inline int get_standard() const {return standard;}

    inline void set_first_name(const std::string &fn) {first_name = fn;}
    inline std::string get_first_name() const {return first_name;}

    inline void set_last_name(const std::string &ln) {last_name = ln;}
    inline std::string get_last_name() const {return last_name;}

    std::string to_string() const
    {
        static const std::string delimiter(",");

        std::stringstream sStream;
        sStream << age << delimiter <<
            first_name << delimiter <<
            last_name << delimiter <<
            standard;
        return sStream.str();
    }

private:
    int age;
    int standard;
    std::string first_name;
    std::string last_name;

};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
