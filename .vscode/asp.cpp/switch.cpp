#include<iostream>
using namespace std;
int  main()
{
    int n;
    cin>>n;
    char c;
    cin>>c;
    while(1){
    switch(n)
    {
        case 1: cout<<"bhai"<<endl;
        continue;//not valid means no use 
        case 2:cout<<"bahh"<<endl;

    exit(0);
        default: switch(c){
            case 'a':cout<<"the character is "<<c<<endl;
        exit(0);
            default: cout<<"entered default in nested switch and character is "<<c<<" and num is "<<n<<endl;
        }
        ;
    exit(0);
    }  
    }  
    return 0;
}