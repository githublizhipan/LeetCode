/*************************************************************************
	> File Name: 188.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 19时14分46秒
 ************************************************************************/

#include<stdio.h>
#define max 1000000

int prime[max + 5] = {0};

void init(int m){
    for(int i = 2; i <= m; ++i) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; ++j) {
            if(prime[j] * i > m) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 1; i <= n; ++i) {
        if(prime[i] >= m) printf("%d\n", prime[i]);
    }
    return 0;
}
