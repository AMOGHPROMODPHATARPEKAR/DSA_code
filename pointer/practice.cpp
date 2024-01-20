#include <iostream>
#include <vector>
using namespace std;

int main()
{
 int i=8;
 int *p=&i;
 cout<<(*p)++<<" ";
 cout<<i<<endl;
//  int *q;
//  cout<<sizeof(q);
 char s[]="abc\0de";
 char *q=s;
 cout<<s[0]<<"  "<<q<<endl;;

 int first=110;
 p=&first;
 int **p2=&p;
int sec=(**p2)++ + 9;
cout<<first<<"  "<<sec<<endl;
    return 0;
}