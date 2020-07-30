/*************************************************************************
	> File Name: 577.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 11时11分28秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> mp;

int cnt[10000]; //存每个字符串出现的数量(下标是字符串映射值)
int num; //字符串种类数量

int main() {
    string s, ansstr;
    int ans = -1;
    while (cin >> s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (mp[s] == 0) mp[s] = ++num;
        int t = cnt[mp[s]]++;
        if (t > ans) {
            ans = t;
            ansstr = s;
        }
        if (t == ans && s < ansstr) {
            ansstr = s;
        } 
    }
    cout << ansstr << " " << ans + 1 << endl;
    return 0;
}
