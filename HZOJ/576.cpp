/*************************************************************************
	> File Name: 576.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 18时51分38秒
 ************************************************************************/
#include <map>
#include<iostream>
using namespace std;

struct news {
    int w, m;
};

int main() {
    map<string, news> goods;

    int n, k;
    long long ans = 0;
    cin >> n >> k;
    
    char names[30];
    for(int i = 1; i <= n; ++i) {
        int a, b;
        cin >> names >> a >> b;
        goods[names].w = a;
        goods[names].m = b;
    }

    for(int i = 1; i <= k; i++) {
        int num;
        cin >> names >> num;
        if(goods[names].m < num) {
            cout << "-" << i;
            return 0;
        }
        ans += goods[names].w * num;
    }
    cout << ans << endl;
    return 0;
}
