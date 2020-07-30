/*************************************************************************
	> File Name: 560.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 21时27分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, v[30], p[30], ans[30005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 1; j--) {
            if (j < v[i]) {
                break;
            } else {
                ans[j] = max(ans[j], ans[j - v[i]] + v[i] * p[i]);
            }
        }
    }
    
    cout << ans[n] << endl;

    return 0;
}
