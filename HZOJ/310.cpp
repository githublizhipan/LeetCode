/*************************************************************************
	> File Name: 310.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 14时06分50秒
 ************************************************************************/

#include<iostream>
#define MAX 1000000

using namespace std;
int prime[MAX + 5] = {0};
int p_expn[MAX + 5][MAX + 5];

void init(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            p_expn[i][i] = 1;
        }
        for(int j = 1; j <= prime[0]; ++j) {
            if(prime[j] * i > n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                p_expn[i][prime[j]]++;
            } else {
                p_expn[i][prime[j]] = 1;
            }
        }
    }
    return ;
}

int arr[MAX][MAX] = {0};
int main() {
    int n;
    cin >> n;
    init(n);
    for(int i = 1; i <= n; ++i) {
        arr[i][prime[i]] += p_expn[i][prime[i]];
    }
    for(int i = 1; i <= prime[0]; ++i) {
        if(!arr[prime[i]]) continue;
        cout << prime[i] << " " << arr[prime[i]] << endl;
    }

    return 0;
}
