/*************************************************************************
	> File Name: 527.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 17时34分16秒
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step, d;
};

int m, n, D;
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int check[105][105][105];

int main() {
    cin >> n >> m >> D;
    for(int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push({1, 1, 0, D});
    for(int i = 0; i <= D; i++) {
        check[1][1][i] = 1;
    }

    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            for(int j = 2; j <= temp.d; j++) {
                int x = temp.x + j * dir[i][0];
                int y = temp.y + j * dir[i][1];
                if(x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                if(mmap[x][y] == 0) break;
                if(mmap[x][y] == 'P' &&  check[x][y][temp.d - j] == 0) {
                    check[x][y][temp.d - j] = 1;
                    que.push({x, y, temp.step + 1, temp.d - j});
                }
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if(mmap[x][y] == 'P' && check[x][y][temp.d] == 0) {
                check[x][y][temp.d] = 1;
                que.push({x, y, temp.step + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
