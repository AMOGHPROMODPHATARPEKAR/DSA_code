#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=4)
    { 
        switch (i)
        {
        case 1:cout<<"no of 100 rupee notes "<<n/100<<endl;
        n=n-100*(n/100);
            break;
        case 2: cout<<"no of 50 rupees notes "<<n/50<<endl;
        n=n-50*(n/50);
        break;
        case 3:cout<<"no of 20 notes "<<n/20<<endl;
        n=n-20*(n/20);
        break;
        case 4:cout<<"no of 1 notes "<<n<<endl;
        break;
        }
        i++;
    }
    return 0;
}