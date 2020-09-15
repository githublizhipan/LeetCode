/*************************************************************************
	> File Name: 406.水坑数量.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Sep 15 15:53:56 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, ans, dir[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, -1, -1, 1, 1, 1, -1, -1 };
char mp[2100][2100];

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mp[tx][ty] == '#') {
            mp[tx][ty] = '.';
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
            if (mp[i][j] == '#') {
                ans++;
                mp[i][j] = '.';
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
