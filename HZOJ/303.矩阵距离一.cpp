/*************************************************************************
	> File Name: 303.矩阵距离一.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 19 15:42:17 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, check[1100][1100], ans[1100][1100], dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
char mp[1100][1100];
queue<node> que;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '1') {
                que.push({i, j, 0});
            }
        }
    }
    
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mp[x][y] == '0' && check[x][y] == 0) {
                check[x][y] = 1;
                ans[x][y] = temp.step + 1;
                que.push({x, y, ans[x][y]});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > 1) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }


    return 0;
}

