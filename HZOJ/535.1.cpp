/*************************************************************************
	> File Name: 535.1.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Mon Sep 14 19:42:26 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;
int w, h, dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}, sx, sy, ans = 1;
char mp[55][55];

void dfs(int sx, int sy) {
    for (int i = 0; i < 4; i++) {
        int tx = sx + dir[i][0];
        int ty = sy + dir[i][1];
        if (mp[tx][ty] == '.') {
            ans++;
            mp[tx][ty] = 0;
            dfs(tx, ty);
        }
    }
    return ;
}


int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}
