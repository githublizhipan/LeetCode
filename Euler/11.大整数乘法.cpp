/*************************************************************************
	> File Name: 11.大整数乘法.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Oct 11 20:58:36 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 1000000

char str1[MAXN], str2[MAXN];
int a[MAXN], b[MAXN], c[MAXN];

int main() {
    cin >> str1 >> str2;
    int l1 = strlen(str1), l2 = strlen(str2);
    int l3 = l1 + l2;
    for (int i = 0; i < l1; i++) {
        a[i] = str1[l1 - i - 1] - '0';
    }
    for (int j = 0; j < l2; j++) {
        b[j] = str2[l2 - j - 1] - '0';
    }
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] < 10) continue;
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    while (!c[l3]) l3--;
    for (int i = l3; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
