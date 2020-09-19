/*************************************************************************
	> File Name: 535.2.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 19 14:30:51 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int h, w, cnt, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
queue<node> que;
char mp[55][55];


int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '@') {
                cnt++;
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
            if (mp[x][y] == '.') {
                cnt++;
                mp[x][y] = '#';
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
