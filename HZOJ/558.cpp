/*************************************************************************
	> File Name: 558.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 20时13分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int T, M, t[105], v[105], ans[105][1005];

int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        cin >> t[i] >> v[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= T; j++) {
            if (j < t[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[i - 1][j - t[i]]);
            }
        }
    }

    cout << ans[M][T] << endl;

    return 0;
}
