#include <bits/stdc++.h>
using namespace std;
void rev(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        s.push(ele);
    }
    while (!s.empty())
    {
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
}
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
     q.push(94);
    q.push(10);
    Printqueue(q);
    cout<<endl;
    rev(q);
    Printqueue(q);


}