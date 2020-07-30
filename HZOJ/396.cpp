/*************************************************************************
	> File Name: 396.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 21时22分18秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y;
};

int n;
int mmap[35][35]; 
int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};

int main() {
    cin >> n;
    mmap[0][0] = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    queue<node> que;
    que.push({0, 0});
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x < 0 || y < 0 || x > n + 1 || y > n + 1|| mmap[x][y] == 1) continue;
            if(mmap[x][y] == 0) {
                mmap[x][y] = 3;
                que.push({x, y});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j > 1) cout << " ";
            if(mmap[i][j] == 3) cout << 0;
            else if(mmap[i][j] == 1) cout << 1;
            else cout << 2;
        }
        cout << endl;
    }
    return 0;
}
