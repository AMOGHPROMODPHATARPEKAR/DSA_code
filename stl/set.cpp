#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout<<"5 is present "<<s.count(5)<<endl;
    
}