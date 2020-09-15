/*************************************************************************
	> File Name: 404.01迷宫简易版.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Sep 15 16:11:19 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 }, ans = 1, sx, sy;
int check[3100][3100];
char mp[3100][3100];

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
        if (!check[tx][ty] && mp[x][y] != mp[tx][ty]) {
            ans++;
            check[tx][ty] = 1;
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
    cin >> sx >> sy;
    check[sx][sy] = 1;
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}
