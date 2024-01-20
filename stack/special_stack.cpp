#include <bits/stdc++.h>
using namespace std;
class SpecialStack {
    stack<int>s;
    int mini;
    public:
        
    void push(int data) {
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else{
            if(data<mini)
            {
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty())
        {
            return -1;
        }
        int cur =s.top();
        s.pop();
        if(cur > mini)
        {
            return cur;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - cur;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        
        if(s.empty())
        {
            return -1;
        }
        int cur = s.top();
        if(cur>mini)
        {
            return cur;
        }
        else{
            return mini;
        }
    }

    int getMin() {
        if(s.empty())
        {
            return -1;
        }
        else{
            return mini;
        }
    }  
};
int main()
{
    SpecialStack ns;
   
    ns.push(20);
    ns.push(40);
    ns.push(15);
    ns.push(25);
     ns.push(10);
         cout<<"minimum  :  "<<ns.getMin()<<endl;
    cout<<"popped  : "<<ns.pop()<<endl;
    cout<<"popped  : "<<ns.pop()<<endl;
    cout<<"popped : "<<ns.pop()<<endl;
    cout<<"minimum  :  "<<ns.getMin();
}
//TC SC O(1)