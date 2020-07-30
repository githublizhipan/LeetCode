/*************************************************************************
	> File Name: 279.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 22时11分02秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001050

int n, m, Next[MAX];
char s1[2 * MAX], s2[MAX];

void get_next() {
    for(int i = 2, j = 0; i <= m; ++i) {
        while(j > 0 && s2[i] != s2[j + 1]) j = Next[j];
        if(s2[i] == s2[j + 1]) j++;
        Next[i] = j;
    }
    return ;
}

int kmp() {
    for(int i = 1, j = 0; i <= 2 * n; i++) {
        while(j && s1[i] != s2[j + 1]) j = Next[j];
        if(s1[i] == s2[j + 1]) j++;
        if(j == m) return 1; 
    }
    return 0;
}

int find_min() {
    int i = 1, j = 2, k;
    while(i <= n && j <= n) {
        for(k = 0; k <= n && s1[i + k] == s1[j + k]; k++);
        
        //比对到最后相等,则该字符串所有字符都一样
        if(k == n) break;

        if(s1[i + k] > s1[j + k]) {
            i = i + k + 1;
            if(i == j) i += 1;
        } else {
            j = j + k + 1;
            if(i == j) j += 1;
        }
    }
    return min(i, j);
}

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1), m = strlen(s2 + 1);
    for(int i = 1; i <= n; ++i) s1[n + i] = s1[i];
    get_next();
    if(kmp()) {
        printf("Yes\n");
    } else printf("No\n");

    int position = find_min();
    //cout << "position:" << position << endl;
    s1[position + n] = '\0';

    printf("%s", s1 + position);
    printf("\n");
    return 0;
}
