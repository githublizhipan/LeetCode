/*************************************************************************
	> File Name: 8.因子个数.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Oct  3 20:56:16 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;
#define maxn 1000

int prime[maxn], min_prime_divisor_num[maxn], f[maxn];



void init() {
    for (int i = 2; i <= maxn; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_prime_divisor_num[i] = 1;
            f[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > maxn) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                f[i * prime[j]] = f[i] * f[prime[j]];
                min_prime_divisor_num[i * prime[j]] = 1;
            } else {
                f[i * prime[j]] = f[i] / (min_prime_divisor_num[i] + 1) * (min_prime_divisor_num[i] + 2);
                min_prime_divisor_num[i * prime[j]] = min_prime_divisor_num[i] + 1;
                break;
            }
        }
    }
    return ;
}


int main() {
    init();
    for (int i = 1; i <= 100; i++) {
        cout << i << " 因子个数: " << f[i] << "个" << endl;
    }
    return 0;
}
