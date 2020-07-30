/*************************************************************************
	> File Name: 561.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 21时47分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

int E, F, N, P[505], W[505], ans[10005];


int main() {
    cin >> E >> F >> N;
    F -= E;
    for (int i = 0; i < 10005; i++) {
        
    }
    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> W[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = W[i]; j <= F; j++) {
            ans[j] = min(ans[j - 1], ans[j] + P[i]);
        }
    }
    cout << ans[F] << endl;
    return 0;
}

