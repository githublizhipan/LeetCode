/*************************************************************************
	> File Name: 80.小明看电影.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 19 10:59:48 2020
	> Source: 
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, step;
};


int n, m, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 }; 
char mp[510][510];
queue<node> que;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 's') {
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
            if (mp[x][y] == 'g') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mp[x][y] == '.') {
                mp[x][y] = '#';
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
