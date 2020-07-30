/*************************************************************************
	> File Name: 191.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 20时13分14秒
 ************************************************************************/

#include<stdio.h>
#define max 8000000
int prime[max + 5] = {0};
int arr[max + 5] = {0};

void init(int b) {
    for(int i = 2; i <= b; ++i) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; ++j) {
            if(prime[j] * i > b) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

void solve(int a, int b) {
    int n = -1, m = -1, c = -1, d = -1;
    int max_len = 0, min_len = max;
    for(int i = 2; i <= prime[0] && prime[i] <= b; ++i) {
        if(prime[i] < a) continue;
        int temp = prime[i] - prime[i - 1];
        if(temp < min_len) {
            n = prime[i - 1];
            m = prime[i];
            min_len = temp;
        }
        if(temp > max_len) {
            c = prime[i - 1];
            d = prime[i];
            max_len = temp;
        }

    }
    if(n == -1) printf("There are no adjacent primes.\n");
    else printf("%d,%d are closest, %d,%dare most distant.\n", n, m, c, d);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    init(b);
    solve(a, b);
    return 0;
}
