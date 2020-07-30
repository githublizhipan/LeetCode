/*************************************************************************
	> File Name: 509.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 21时14分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int t, w;
};

int m, n, maxt, check[505];
node game[505];
int cmp(node a, node b) {
    return a.w > b.w;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> game[i].t;
       // maxt = max(maxt, game[i].t);
    }
    for (int i = 0; i < n; i++) {
        cin >> game[i].w;
    }
    sort(game, game + n, cmp);
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = game[i].t; j >= 1; j--) {
            if (check[j]) continue;
            check[j] = 1;
            flag = 1;
            break;
        }
        if (!flag) m -= game[i].w;
    }
    cout << m << endl;
    return 0;
}
