/*************************************************************************
	> File Name: 49.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时44分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int all, n, ind, w[100005],v[1000055], ans[100005];
int t[20];
int main() {
    int tt = 1;
    for (int i = 0; i < 20; i++) {
        t[i] = tt;
        tt *= 2;
    }
    cin >> all >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z, temp = 0;
        cin >> x >> y >> z;
        while (z > 0) {
            ind++;
            if (z >= t[temp]) {
                w[ind] = x * t[temp];
                v[ind] = y * t[temp];
                z -= t[temp];
            } else {
                w[ind] = x * z;
                v[ind] = y * z;
                z = 0;
            }
            temp++;
        }
    }
    for (int i = 1; i <= ind; i++) {
        for (int j = all; j >= w[i]; j--) {
            ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
        }
    }
    cout << ans[all] << endl;

    return 0;
}
