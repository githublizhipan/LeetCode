/*************************************************************************
	> File Name: 521.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 22时53分31秒
 ************************************************************************/
#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_N 3000005

int n, r, num[35], ans, prime[MAX_N], is_prime[MAX_N] = {1, 1};
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i] == 0) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        } 
    }
    return ;
}

void func(int s, int sum, int deep) {
    if (deep == r) {
        if (is_prime[sum] == 0) ans++;
        return ;
    }
    for (int i = s; i <= n - r + deep; i++) {
        sum += num[i];
        func(i + 1, sum, deep + 1);
        sum -= num[i];
    }
}

int main() {
    init();
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    func(0, 0, 0);
    cout << ans << endl;
    return 0;
}
