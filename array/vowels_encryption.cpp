#include<bits/stdc++.h>

using namespace std;
map < char, char > M;
map < int, bool > prime;

int main() {
    prime[2] = true;
    prime[3] = true;
    prime[5] = true;
    prime[7] = true;
    char vow[] = {
        'a',
        'e',
        'i',
        'o',
        'u'
    };
    char con[] = {
        'b',
        'c',
        'd',
        'f',
        'g',
        'h'
    };
    int jv = 0, jc = 0;
    string s;
    cin >> s;
    for (auto i: s) {
        if (prime[i - '0']) {
            if (M[i]) {} else {
                M[i] = vow[jv];
                jv++;
            }
        } else if (M[i]) {} else {
            M[i] = con[jc];
            jc++;
        }
    }
    for (auto i: s) cout << M[i];
}