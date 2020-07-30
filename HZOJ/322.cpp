/*************************************************************************
	> File Name: 322.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月23日 星期六 10时28分06秒
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;
#define MAX_N 1000000
map<int, int> ind;
int n, a, b, c;

struct Date {
    int i, j, e;
} arr[MAX_N + 5];

struct UnionSet {
    int fa[2 * MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int a) {
        return (fa[a] = (a - fa[a] ? get(fa[a]) : a));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};


void solve() {
    ind.clear();
    cin >> n;
    UnionSet u;
    u.init(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].i >> arr[i].j >> arr[i].e;
        if (ind.find(arr[i].i) == ind.end()) ind[arr[i].i] = ++ind[0];
        if (ind.find(arr[i].j) == ind.end()) ind[arr[i].j] = ++ind[0];
        arr[i].i = ind[arr[i].i];
        arr[i].j = ind[arr[i].j];
        if (arr[i].e) u.merge(arr[i].i, arr[i].j);
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i].e == 0) {
            if (u.get(arr[i].i) != u.get(arr[i].j)) continue;
            flag = 0;
            break;
        }  
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
