/*************************************************************************
	> File Name: 304.骑士风度的牛.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 19 15:23:22 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int c, r;
int dir[8][2] = { 1, 2, 2, 1, 1, -2, -2, 1, -1, 2, 2, -1, -1, -2, -2, -1 }; 
char mp[200][200];
queue<node> que;

int main() {
    cin >> c >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'K') {
                que.push({i, j, 0});
            }
        }
    }

    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mp[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mp[x][y] == '.') {
                mp[x][y] = '*';
                que.push({x, y, temp.step + 1});  
            }
        }
    }
    return 0;
}


