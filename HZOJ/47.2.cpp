/*************************************************************************
	> File Name: DP.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月22日 星期三 20时04分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int all, n, w, v, ans[10005];

int main() {
    cin >> all >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w >> v;
        for(int j = all; j >= w; j--) {
            ans[j] = max(ans[j], v + ans[j - w]);
        }
    }
    cout << ans[all] << endl;
    return 0;
}
