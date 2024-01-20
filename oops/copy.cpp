#include <iostream>
using namespace std;

class hero
{
public:
    int level;
    hero()
    {
        cout << "\ndefault construct called\n"; // if we make any construct the default constructor which compiler creates deletes
        level = 0;
    }
    // parameterized constructor
    hero(int level)
    {
        this->level = level; // this pointer stores the adress of cureent object
        cout << "this --> " << this << endl;
    }
    // copy constructor
    hero(hero &h)
    {
        this->level = h.level;
    }
    void set()
    {
        cin >> level;
    }
    int get()
    {
        return level;
    }
    ~hero(){
        cout<<"destructor\n";
    }
};
int main()
{
    hero h1(23);
    cout << "level h1  " << h1.get() << endl;
    hero h2 = h1; // default copy constructor
    cout << "level h2  " << h2.get() << endl;
    hero h3(h2);
    cout << "level h3  " << h3.get() << endl;
   hero *h4= new hero;//call manually the destructor
   delete h4; 
}
// default copy constructor does shallow copy
// stores another object item in same memory

// copy constructor does deep 
// deep cpy stores in new memory
