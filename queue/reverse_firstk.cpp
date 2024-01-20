
   #include <bits/stdc++.h>
using namespace std;
void modifyQueue(queue<int> &q, int k) {
   stack<int>s;
   
   for(int i=0;i<k;i++)
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
   //fetch n-k element from q and push back
   int  t = q.size()-k;
   while(t--)
   {
      int val = q.front();
       q.pop();
       q.push(val);
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
    modifyQueue(q,3);
    Printqueue(q);


}