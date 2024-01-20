#include <iostream>
#include "hero.cpp" //class initiate
using namespace std;
class human
{
public:
    int age;
    string name;

    void set()
    {
        cout << "enter age and name\n";
        cin >> age >> name;
    }
    void get()
    {
        cout << " age :" << age<<endl;
        cout << " name :" << name<<endl;
    }
};
class male : public human{
    public:
    string color;
};
int main()
{
    male m1;
    m1.set();
    m1.color = "brown";
    m1.get();
cout<<"color "<<m1.color;

}