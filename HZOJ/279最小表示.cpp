/*************************************************************************
	> File Name: 279最小表示.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月20日 星期一 09时21分56秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2000100


int find_min(char *s, int n) {
    int i = 1, j = 2, k;
    while(i <= n && j <= n ) {
        k = 0;
        for(; s[i + k] == s[j + k] && k <= n; k++);

        if(k == n) break;
        if(s[i + k] > s[j + k]) {
            i = i + k + 1;
            if(i == j) i++;
        } else {
            j = j + k + 1;
            if(j == i) j++;
        }
    }
    return min(i, j);
}

int main() {
    char s1[MAX], s2[MAX];
    int n;
    scanf("%s %s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1);

    memcpy(s1 + 1 + n, s1 + 1, n);
    memcpy(s2 + 1 + n, s2 + 1, n);

    //cout << s1 + 1 << endl << s2 + 1 << endl;

    int postion1 = find_min(s1, n);
    int postion2 = find_min(s2, n);
    //cout << postion1 << endl << postion2 << endl;
    
    s1[postion1 + n] = '\0';
    s2[postion2 + n] = '\0';
    if(!strcmp(s1 + postion1, s2 + postion2)) cout << "Yes\n" << s1 + postion1 << endl;
    else cout << "No" << endl;
    
    return 0;
}

