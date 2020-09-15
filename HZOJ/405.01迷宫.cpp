/*************************************************************************
	> File Name: 405.01迷宫.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Sep 15 19:12:10 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int n, m, k, ans, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 }, check[3100][3100];
char mp[3100][3100];
struct node {
    int x, y;
};
queue<node> que;


void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (check[tx][ty] == 0 && mp[x][y] != mp[tx][ty] && mp[tx][ty]) {
            que.push({tx, ty});
            check[tx][ty] = 1;
            ans++;
            dfs(tx, ty);
        }
    }
    return ;
}


int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j] == 0) {
                que.push({i, j});
                ans = 1;
                check[i][j] = 1;
                dfs(i, j);
                while (!que.empty()) {
                    node nd = que.front();
                    que.pop();
                    check[nd.x][nd.y] = ans;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cout << check[a][b] << endl;
    }
    return 0;
}
