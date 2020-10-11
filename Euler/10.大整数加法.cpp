/*************************************************************************
	> File Name: 10.大整数加法.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Oct 11 08:41:24 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define max_n 1000000 
char a[max_n + 5], b[max_n + 5];
int A[max_n + 5], B[max_n + 5], C[max_n];

int main() {
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 0; i < lena; i++) {
        A[i] = a[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        B[i] = b[lenb - i - 1] - '0';
    }
    C[0] = (lena > lenb ? lena : lenb);
    for (int i = 1; i <= C[0]; i++) {
        C[i] = A[i - 1] + B[i - 1];
    }
    for (int i = 1; i <= C[0]; i++) {
        if (C[i] < 10) continue;
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
        C[0] += (i == C[0]);
    }
    for (int i = C[0]; i >= 1; i--) {
        cout << C[i];
    }
    cout << endl;
    return 0;
}
