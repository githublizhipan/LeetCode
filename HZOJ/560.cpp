/*************************************************************************
	> File Name: 560.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 21时27分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, v[30], p[30], ans[30][30005];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < v[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - v[i]] + v[i] * p[i]);
            }
        }
    }
    
    cout << ans[m][n] << endl;

    return 0;
}
