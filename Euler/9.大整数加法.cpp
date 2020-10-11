/*************************************************************************
	> File Name: 9.大整数加法.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Oct  3 21:29:10 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define max_n 52
char str[max_n + 5] = {0};
int ans[max_n + 5];

int main() {
    while (~scanf("%s", str)) {
        int len = strlen(str);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; i < len; i++) {
            ans[len - i] += str[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
