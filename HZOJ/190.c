/*************************************************************************
	> File Name: 190.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 19时43分20秒
 ************************************************************************/

#include<stdio.h>
#define max 8000000
int arr[max + 5] = {0};

void init(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!arr[i]) arr[++arr[0]] = i;
        for(int j = 1; j <= arr[0]; ++j) {
            if(i * arr[j] > n) break;
            arr[i * arr[j]] = 1;
            if(i % arr[j] == 0) break;
        }
    }
    return ;
}

int prime[max +5];
int main() {
    int n;
    scanf("%d", &n);
    init(n);
    int sum = 0;
    for(int i = 1; i <= arr[0]; ++i){
        prime[arr[i]] = 1;
    }
    for(int i = 1; i <= n / 2; ++i) {
        if(prime[i] && prime[n - i]) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
