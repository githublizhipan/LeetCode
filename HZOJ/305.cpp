/*************************************************************************
	> File Name: 305.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 22时49分45秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;  
};

int X, Y, Mx, My;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[105][105];

int main() {
    cin >> X >> Y >> My >> Mx;
    queue<node> que;
    for(int i = 1; i <= Y; i++) {
        cin >> &mmap[i][1];
    }
    que.push({Y - Mx + 1, My, 0});
    mmap[Y - Mx + 1][My] = '*';
    int ans;
    while(!que.empty()) {
        node temp = que.front();
        ans = temp.step;
        que.pop();
        for(int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] == '.') {
                mmap[x][y] = '*', 
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
