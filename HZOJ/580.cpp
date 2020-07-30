/*************************************************************************
	> File Name: 580.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 22时35分49秒
 ************************************************************************/
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    set<int> s;
    int n, t;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << endl;
    int flag = 0;
    for (auto it=s.cbegin(); it!=s.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
