/*************************************************************************
	> File Name: 400.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 16时18分10秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int x1, y3, x2, y2;
int dir[12][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1, 2, 2, 2, -2, -2, 2, -2, -2};
int check[505][505];


void func(int a, int b) {
    memset(check, 0, sizeof(check));
    queue<node> que;
    que.push({a, b, 0});
    check[a][b] = 1;
    int ans = 0;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x < 1 || y < 1 || x > 500 || y > 500) continue;
            if(!check[x][y]) {
                que.push({x, y, temp.step + 1}) ;
                check[x][y] = 1;
                if(x == 1 && y == 1) {
                    cout << temp.step + 1 << endl;
                    return ;
                }
            }
        }
    }
    return ;
}


int main() {
    cin >> x1 >> y3 >> x2 >> y2;
    func(x1, y3);
    func(x2, y2);
    return 0;
}
