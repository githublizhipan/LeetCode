/*************************************************************************
	> File Name: 471.大整数乘法.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Oct 11 20:40:07 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100000

char str1[MAXN], str2[MAXN];
int a[MAXN], b[MAXN], c[MAXN];


int main() {
    cin >> str1 >> str2;
    int len1 = strlen(str1), len2 = strlen(str2);
    int len3 = len1 + len2;
    for (int i = 0; i < len1; i++) {
        a[i] = str1[len1 - 1 - i] - '0';
    }
    for (int i = 0; i < len2; i++) {
        b[i] = str2[len2 - 1 - i] - '0';
    }
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            c[i + j] += a[i] * b[j]; //关键
            if (c[i + j] < 10) continue;
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    while (!c[len3]) len3--; //重要
    for (int i = len3; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
