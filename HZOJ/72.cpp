/*************************************************************************
	> File Name: 72.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月22日 星期五 21时15分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10005
int n, m;
struct UnionSet {
    int fa[MAX_N], val[MAX_N] = {0};
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int a) {
        if (fa[a] == a) return a;
        int root = get(fa[a]);
        val[a] += val[fa[a]];
        val[a] %= 3;
        return fa[a] = root;
    }
    void merge(int a, int b, int x) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = x + val[b] - val[a] + 3;
        val[aa] %= 3;
        return ;
    }
};

UnionSet u;

int main() {
    cin >> n >> m;
    u.init(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) u.merge(b, c, 2);
        else if (a == 2) {
            if (u.get(b) != u.get(c)) cout << "Unknown\n";
            else {
                int x = (u.val[b] - u.val[c] + 3) % 3;
                switch(x) {
                    case 0:
                        cout << "Tie\n";
                        break;
                    case 1:
                        cout << "Loss\n";
                        break;
                    case 2:
                        cout << "Win\n";
                        break;
                }
            }
        }
    }
    return 0;
}
