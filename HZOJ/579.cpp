/*************************************************************************
	> File Name: 579.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 14时58分29秒
 ************************************************************************/
#include <set>
#include <cstdio>
#include<iostream>
using namespace std;
struct num {
    int m;
    set<int> s;
};

int main() {
    int n;
    num nums[60];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        cin >> nums[i].m;
        for(int j = 1; j <= nums[i].m; ++j) {
            int t;
            scanf("%d", &t);
            nums[i].s.insert(t);
        }
    }
    int k, x, y;
    scanf("%d", &k);
    for(int i = 1; i <= k; ++i) {
        scanf("%d%d", &x, &y);
        //set<int> unions;
        int lx = nums[x].s.size(), ly = nums[y].s.size(); //l = unions.size();
        int same = 0;
        
        if(lx > ly) {
            for(set<int>::iterator it = nums[y].s.begin(); it != nums[y].s.end(); it++) {
                if(!nums[x].s.count(*it)) continue;
                same++;
            } 
        } else {
            for(set<int>::iterator it = nums[x].s.begin(); it != nums[x].s.end(); it++) {
                if(!nums[y].s.count(*it)) continue;
                same++;
            }
        }
        /*
        for (set<int>::iterator it = nums[x].s.begin(); it != nums[x].s.end(); ++it) { 
            unions.insert(*it);
        }
        for (set<int>::iterator it = nums[y].s.begin(); it != nums[y].s.end(); ++it) {
            unions.insert(*it);
        }
        */
        double ans = same * 100.0 / (lx + ly - same);
        printf("%.1lf\%\n", ans);
    }
    return 0;
}
