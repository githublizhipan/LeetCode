/*************************************************************************
	> File Name: 398.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 22时19分40秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, a, b; 
int ans[500][500];
int dir[8][2] = {1, 2, -1, 2, 1, -2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

int main() {
    cin >> n >> m >> a >> b;
    queue<node> que;
    ans[a][b] = -1;
    que.push({a, b, 0});
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x > n || x < 1 || y > m || y < 1 || ans[x][y]) continue;
            ans[x][y] = temp.step + 1;
            que.push({x, y, ans[x][y]});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j > 1) cout << " ";
            if(ans[i][j] == -1) cout << 0;
            else if(ans[i][j] == 0) cout << -1;
            else cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
