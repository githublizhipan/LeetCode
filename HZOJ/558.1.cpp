/*************************************************************************
	> File Name: 558.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 20时13分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int T, M, t[105], v[105], ans[1005];

int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        cin >> t[i] >> v[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = T; j >= 1; j--) {
            if (j < t[i]) {
                break;
            } else {
                ans[j] = max(ans[j], v[i] + ans[j - t[i]]);
            }
        }
    }

    cout << ans[T] << endl;

    return 0;
}
