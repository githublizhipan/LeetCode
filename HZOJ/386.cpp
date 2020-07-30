/*************************************************************************
	> File Name: 387.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 17时16分44秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
using namespace std;

struct GUA {
    long long num;
    int index;
};

int cmp(GUA a, GUA b) {
    return a.num < b.num;
}


int main() {
    GUA gua[100000];
    int M, N;
    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        cin >> gua[i].num;
        gua[i].index = i;
    }

    sort(gua + 1, gua + M + 1, cmp);
    
    long long y;
    for(int i = 1; i <= N; i++) {
        cin >> y;
        int l = 1, r = M, mid;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(gua[mid].num == y) {
                cout << gua[mid].index << endl;
                break;
            } else if(gua[mid].num > y) {
                r = mid - 1;
            }else l = mid + 1;
        }
        if(l > r) cout << 0 << endl;
    }
    return 0;
}
