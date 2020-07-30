/*************************************************************************
	> File Name: 278.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 11时20分19秒
 ************************************************************************/
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 1000000
char s[MAX + 5];
int Next[MAX + 5], n;

void get_next() {
    for(int i = 2, j = 0; i <= n; ++i) {
        while(j && s[i] != s[j + 1]) j = Next[j];
        if(s[i] == s[j + 1]) j++;
        Next[i] = j;
    }
    return ;
}

int main() {
    scanf("%d%s", &n, s + 1);
    get_next();
    for(int i = 2; i <= n; ++i) {
        int t = i - Next[i];
        if(t != i && i % t == 0) printf("%d %d\n", i, i / t);
    }
    return 0;
}
