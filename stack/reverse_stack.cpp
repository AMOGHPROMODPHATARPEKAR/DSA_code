#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(num);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty())
    {
        return;
    }
    int num =stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,num);
}
void PrintStack(stack<int> s)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();
    // Recursively call the function PrintStack
    PrintStack(s);
    cout << x << " ";

    s.push(x);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(15);
    s.push(3);
    s.push(54);
    s.push(32);
    PrintStack(s);
    cout << endl;

    reverseStack(s);
    PrintStack(s);
}