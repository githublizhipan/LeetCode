/*************************************************************************
	> File Name: 73.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月22日 星期五 23时28分46秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000
#define ind(a, b) ((a) * (m) + (b) + 1) //从一编号
int n, m; 
char mp[MAX_N + 5][MAX_N + 5];

struct UnionSet {
    int fa[MAX_N * MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'X') continue;
            if (i && mp[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if (j && mp[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'X') continue;
            if (u.get(ind(i, j)) - u.get(0)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
