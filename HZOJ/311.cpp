/*************************************************************************
	> File Name: 311.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时53分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 1000005
int prime[MAX] = {0};
int is_prime[MAX] = {0}; 
//int g[MAX][MAX] = {0};


int gcd(int n, int m) {
    return m ? gcd(m, n % m) : n;
}



void init() {
    is_prime[1] = 1, is_prime[0] = 1;
    for(int i = 2; i <= MAX; ++i) {
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > MAX) break;
            is_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}


int main() {
    init();
    int n, ans = 0, cnt = 0;
    cin >> n;
    //cout << is_prime[n] << endl;
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) cnt++;
        for(int j = i; j <= n; j++) {
            //cout << "gcd(" << i << "," << j << "):" << gcd(i, j) << endl;
            if(!is_prime[gcd(i, j)]) {
                //cout << i << " " << j << endl;
                ans++;
            }
        }
    }
    cout << ans * 2 - cnt << endl;
    return 0;
}
