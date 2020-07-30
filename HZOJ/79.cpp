/*************************************************************************
	> File Name: 79.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 21时56分10秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 10000000
int prime[MAX + 5];

void init(int b) {
    for(int i = 2; i <= b; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > b) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    init(b);
    for(int i = 1; i <= prime[0]; ++i) {
        if(prime[i] < a) continue;
        if(prime[i] > b) break;
        printf("%d\n", prime[i]);
    }
    return 0;
}

