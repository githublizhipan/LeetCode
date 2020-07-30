/*************************************************************************
	> File Name: 401.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 17时06分17秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};
int dir[12][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1, 2, 2, 2, -2, -2, 2, -2, -2};
int ans[505][505];

int main() {
    int n;
    cin >> n;
    queue<node> que;
    que.push({1, 1, 0});
    ans[1][1] = -1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x > 500 || y > 500 || x < 1 || y < 1 || ans[x][y]) {
                continue;
            }
            ans[x][y] = temp.step + 1;
            que.push({x, y, ans[x][y]});
        }
    }
    while(n--) {
        int X, Y;
        cin >> X >> Y;
        if(ans[X][Y] == -1) {
            cout << 0 << endl;
        } else {
            cout << ans[X][Y] << endl;
        }
    }
    return 0;
}
