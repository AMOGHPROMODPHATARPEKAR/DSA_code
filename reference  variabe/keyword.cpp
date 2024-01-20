#include <iostream>
using namespace std;
#define pi 3.142 // macro variable (doesnt take memeory space)

#define AREA(l, b) (l * b) // function macro
#define ELE 1, \
            2, \
            3 // multi line  macro
int main()
{
    int r = 4;
    float area = pi * r * r;
    cout << area << endl;
    int l = 2, b = 4;
    int ar = AREA(l, b);
    cout << ar;
    int a[] = {ELE};
    cout << "elements are" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }
}

// notes
// A macro is a piece of code in a program that is replaced by the value of the macro. Macro is defined by #define directive. Whenever a macro name is encountered by the compiler, it replaces the name with the definition of the macro. Macro definitions need not be terminated by a semi-colon(;).