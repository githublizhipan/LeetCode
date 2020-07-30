/*************************************************************************
	> File Name: 310.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 21时44分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max 1000000
int prime[max + 5] = {0};
void init(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > n) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}



int main() {
    int n;
    cin >> n;
    init(n);
    for(int i = 1; i <= prime[0]; ++i) {
        long long cnt = 0;
        for(long long j = prime[i]; j <= n; j *= prime[i]) {
            cnt += n / j;
        }
        cout << prime[i] << " " << cnt << endl;
    }
    return 0;
}
