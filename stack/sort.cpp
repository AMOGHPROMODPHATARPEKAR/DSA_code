#include <bits/stdc++.h>
using namespace std;
void sorted_insert(stack<int> &stack,int num)
{
	if(stack.empty() || stack.top()<num)
	{
		stack.push(num);
		return;
	}
	int top = stack.top();
	stack.pop();
	sorted_insert(stack,num);
	stack.push(top);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	int num =  stack.top();
	stack.pop();
	sortStack(stack);
	sorted_insert(stack,num);
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

    sortStack(s);
    PrintStack(s);
}