/*************************************************************************
	> File Name: 4.回文数字.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Sep 29 19:17:49 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int ans;
int is_val(int n, int base) {
    int m = n, t = 0;
    while (m) {
        t = t * base + m % base;
        m /= base;
    }
    return t == n;
}



int main() {
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (is_val(i * j, 10) && i * j > ans) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
