#include <iostream>
#include "hero.cpp" //class initiate
using namespace std;
class am
{
    int a;
    char b;
    char c;
}; // data padding and alignment
class h2{
        public:
    int level;
    h2()
    {
        cout<<"\ndefault construct called\n";//if we make any construct the default constructor which compiler creates deletes
        level=0;
    }

    h2(int level)
    {
        this->level=level;//this pointer stores the adress of cureent object
        cout<<"this --> "<<this<<endl;
    }
    void set()
    {
        cin>>level;
    }
    int get()
    {
        return level;
    }
};
int main()
{
    hero h1;
    cout << "size of " << sizeof(h1) << endl;
    am a;
    cout << "size of " << sizeof(a)<<endl; // normal calculation 4+1+1=6 but due to padding its 8
    h2 *h = new h2;//dynamic in heap
    h->set();
    cout<<"level  is "<<h->get();
    h2 am(12);
    cout<<"adress of am "<<&am<<endl;
     
}