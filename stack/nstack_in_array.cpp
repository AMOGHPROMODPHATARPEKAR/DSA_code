#include <bits/stdc++.h>
using namespace std;
class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
    // stack, and false otherwise.
    void push(int x, int m)
    { // check for overflow
        if (freespot == -1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert element
        arr[index] = x;
        // update next
        next[index] = top[m - 1];
        // update top
        top[m - 1] = index;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }
        // reverse the flow
        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
int main()
{
    NStack ns(3, 6);
    ns.push(10,1);
    ns.push(20,2);
    ns.push(40,3);
    ns.push(15,1);
    ns.push(25,2);
    cout<<"popped from 1 : "<<ns.pop(1)<<endl;
    cout<<"popped from 1 : "<<ns.pop(1)<<endl;
    cout<<"popped from 2 : "<<ns.pop(2)<<endl;

}