     #include <iostream>
using namespace std;

bool pal(string &s,int i)
{   
    if(s.length()==1)
    return true;
    if(i>(s.length()-1-i))
    return true;

    if(s[i]!=s[(s.length()-1-i)])
    return false;
    i++;
    
    pal(s,i);

}
int main()
{ 
 string s="1018";
 
 if(pal(s,0))
 {
    cout<<"palndrome"<<endl;
 }else
 {
    cout<<"Not a palindrome"<<endl;
 }
}