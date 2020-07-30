/*************************************************************************
	> File Name: 49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 21时44分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
int V, n, v[105], w[105], s[105], ans[100005];

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= s[i]; j++) {
            for (int k = V; k >= v[i]; k--) {
                ans[k] = max(ans[k], ans[k - v[i]] + w[i]);
            }
        }
    }
    cout << ans[V] << endl;

    return 0;
}
