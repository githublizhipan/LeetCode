/*************************************************************************
	> File Name: 536.最大黑色区域.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Sep 15 11:59:17 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 }, ans;
char mp[150][150];

int dfs(int x, int y) {
    int sum = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mp[tx][ty] == '1') {
            mp[tx][ty] = '0';
            sum += dfs(tx, ty);
        }
    }
    return sum;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '1') {
                mp[i][j] = '0';
                int temp = dfs(i, j);
                if (temp > ans) ans = temp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
