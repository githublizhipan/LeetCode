/*************************************************************************
	> File Name: 529.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 18时51分49秒
 ************************************************************************/

#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, a, b, c, d; 
char mmap[150][150];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
int check[150][150];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    while(cin >> a >> b >> c >> d, a) {
        memset(check, 0, sizeof(check));
        for(int i = 0; i < 8; i++) {
            for(int j = 1; ;j++) {
                int x = a + j * dir[i][0];
                int y = b + j * dir[i][1];
                if(mmap[x][y] != 'O') break;
                check[x][y] = 2;
            }
        }
        check[a][b] = 2;
        if(check[c][d] == 2) {
            cout << 0 << endl;
            continue;
        }
        queue<node> que;
        que.push({c, d, 0});
        int flag = 0;
        while(!que.empty()) {
            node temp = que.front();
            que.pop();
            for(int i = 0; i < 4; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if(check[x][y] == 2) {
                    cout << temp.step + 1 << endl;
                    flag = 1;
                    break;
                }
                if(mmap[x][y] == 'O' && !check[x][y]) {
                    check[x][y] = 1;
                    que.push({x, y, temp.step + 1});
                }
            }
            if(flag) break;
        }
        if(!flag) cout << "Impossible!\n";
    }
    return 0;
}
