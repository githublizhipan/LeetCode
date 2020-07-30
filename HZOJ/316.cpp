/*************************************************************************
	> File Name: 316.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月27日 星期一 18时43分08秒
 ************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

#define MAX 10000000

ll prime[MAX], is_prime[MAX], sum[MAX];

void init() {
    is_prime[0] = 1, is_prime[1] = 1;
    for(ll i = 2; i <= MAX; ++i) {
        if(!is_prime[i]) {
            prime[++prime[0]] = i;
            sum[i] = i + 1;
            is_prime[i] = i;
        }
        for(ll j = 1; j <= prime[0]; ++j) {
            if(prime[j] * i > MAX) break;
            is_prime[i * prime[j]] = 1;
            if(i % prime[j]) {
                sum[i * prime[j]] = sum[i] * sum[prime[j]];
                is_prime[i * prime[j]] = prime[j];
            } else {
                sum[i * prime[j]] = sum[i] * (is_prime[i] * prime[j] * prime[j] - 1) / (is_prime[i] * prime[j] - 1);
                is_prime[i * prime[j]] = is_prime[i] * prime[j];
                break;
            }
        }
    }
    return ;
}


ll gcd(ll N, ll m) {
    return m ? gcd(m, N % m) : N;
}

int main() {
    init();
    ll N;
    scanf("%lld", &N);
    ll ans = sum[N];
    for(int i = 2; i < N; ++i) {
        if(N % i == 0) continue;
        ans += gcd(N, i);
    }

    printf("%lld\n", ans);
    return 0;
}
