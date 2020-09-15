/*************************************************************************
	> File Name: 397.僵尸来袭.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Sep 15 11:13:37 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, mp[150][150], ans = 0, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

void dfs(int x, int y) {
    for (int k = 0; k < 4; k++) {
        int tx = x + dir[k][0];
        int ty = y + dir[k][1];
        if (mp[tx][ty] != 0) {
            mp[tx][ty] = 0;
            dfs(tx, ty);
        }
    }
    return ;
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
            if (mp[i][j] != 0) {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
