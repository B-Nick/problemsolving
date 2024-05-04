#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person
{
public:
    Person() = default;
    Person(const Person &other) = default;
    Person(Person &&other) = default;

    virtual ~Person() = default;

    Person &operator= (const Person &other) = default;
    Person &operator= (Person &&other) = default;

    virtual void getdata()
    {
        // std::cout << "Enter the name: " << std::endl;
        std::cin >> name;
        if (name.empty() || name.length() > 100) throw std::invalid_argument("Invalid name");
        // std::cout << "Enter age: " << std::endl;
        std::cin >> age;
        if (age < 1 || age > 80) throw std::invalid_argument("Invalid age");
    }

    virtual void putdata() const
    {
        //std::cout << "Name: " << name << std::endl;
        //std::cout << "Age: " << age << std::endl;
        std::cout << name << " " << age << " ";
    }

private:
    std::string name;
    int age {30};
};

class Professor final : public Person
{
public:
    Professor() = default;
    Professor(const Professor &other) = default;
    Professor(Professor &&other) = default;

    virtual ~Professor() override final = default;

    Professor &operator= (const Professor &other) = default;
    Professor &operator= (Professor &&other) = default;

    virtual void getdata() override final
    {
        Person::getdata();
        //std::cout << "Enter publication count: " << std::endl;
        std::cin >> publications;
        if (publications < 1 || publications > 1000)
        {
            throw std::invalid_argument("Invalid publication count");
        }
    }

    virtual void putdata() const override final
    {
        Person::putdata();
        //std::cout << "Current ID: " << curr_id << std::endl;
        //std::cout << "Publications: " << publications << std::endl;
        std::cout << publications << " " << curr_id << std::endl;
    }

private:
    static int curr_id_counter;

    int curr_id {curr_id_counter++};
    int publications {0};
};

int Professor::curr_id_counter {1};

class Student final : public Person
{
public:
    Student() = default;
    Student(const Student &other) = default;
    Student(Student &&other) = default;

    virtual ~Student() override final = default;

    Student &operator= (const Student &other) = default;
    Student &operator= (Student &&other) = default;

    virtual void getdata() override final
    {
        Person::getdata();
        markSum = 0;
        for (int i = 0; i < MarkCount; ++i)
        {
            int mark;
            //std::cout << "Enter the mark for the " << i << "th subject" << std::endl;
            std::cin >> mark;
            if (mark < 0 || mark > 100) throw std::invalid_argument("Invalid mark");
            marks[i] = mark;
            markSum += mark;
        }
    }

    virtual void putdata() const override final
    {
        Person::putdata();
        //std::cout << "Current ID: " << curr_id << std::endl;
        //std::cout << "Sum of the marks: " << markSum << std::endl;
        std::cout << markSum << " " << curr_id << std::endl;
    }

private:
    static const int MarkCount {6};
    static int curr_id_counter;

    int curr_id {curr_id_counter++};
    int marks[MarkCount] = {0};
    int markSum {0};
};

int Student::curr_id_counter {1};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
