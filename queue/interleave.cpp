#include <bits/stdc++.h>
using namespace std;
void interleave(queue<int>&q)
{
   int n=q.size();
   stack<int>s;
   //step1 half in stack
   for(int i=0;i<n/2;i++)
   {
    int val = q.front();
    q.pop();
    s.push(val);
   }
   while(!s.empty())
   {
    int val = s.top();
    s.pop();
    q.push(val);
   }
   for(int i=0;i<n/2;i++)
   {
    int val = q.front();
    q.pop();
    q.push(val);
   }
    for(int i=0;i<n/2;i++)
   {
    int val = q.front();
    q.pop();
    s.push(val);
   }
   while (!s.empty())
   {
    int val = s.top();
    s.pop();
    q.push(val);
    val = q.front();
    q.pop();
    q.push(val);
   }

}
//optimal is using queue
void Printqueue(queue<int> s)
{
    if (s.empty())
        return;

    int x = s.front();
    s.pop();
    // Recursively call the function PrintStack
    cout << x << " ";
    Printqueue(s);

    s.push(x);
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
     q.push(6);
    q.push(10);
     q.push(9);
     q.push(8);
    q.push(7);
    Printqueue(q);
    cout<<endl;
interleave(q);
     Printqueue(q);


}