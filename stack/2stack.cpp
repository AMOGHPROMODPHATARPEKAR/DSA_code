#include <bits/stdc++.h> 
using  namespace std;
class TwoStack {
  int *arr;
  int top1;
  int top2;
  int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
       this->size = s;
       top1=-1;
       top2 = s;
       arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1)
        {
            arr[++top1] = num;
        }
        else
        {
            cout<<"stack overflow\n";
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1)
        {
            arr[--top2] = num;
        }
        else
        {
            cout<<"stack overflow\n";
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 == -1)
        return -1;
        else{
            return arr[top1--];
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 == size)
        return -1;
        else{
            return arr[top2++];
        }
    }
};
int main()
{
    TwoStack st(8);
    st.push1(10);
     st.push1(5);
      st.push1(4);
       st.push1(3);
cout<<"popped s1  "<<st.pop1()<<endl;
cout<<"popped s1  "<<st.pop1()<<endl;
cout<<"popped s1  "<<st.pop1()<<endl;

        st.push2(2);
        st.push2(4);
        st.push2(6);
cout<<"popped s2  "<<st.pop2()<<endl;
cout<<"popped s2  "<<st.pop2()<<endl;
cout<<"popped s2  "<<st.pop2()<<endl;
}