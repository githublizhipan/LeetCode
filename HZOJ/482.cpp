/*************************************************************************
	> File Name: 482.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 12时55分33秒
 ************************************************************************/
#include <vector>
#include<iostream>
using namespace std;
int main() {
    char s[100000 + 5];
    vector<char> v;
    int n;
    char c;
    cin >> s >> n;
    for(int i = 0; s[i]; ++i) {
        v.push_back(s[i]);
    }

    int pos = v.size() + 1;

    //cout << pos << endl;

    while(n--) {
        cin >> c;
        if(c == 'L') {
            if(pos == 1) continue;
            pos--;
        } else if(c == 'D') {
            if(pos == v.size() + 1) continue;
            pos++;
        } else if(c == 'B') {
            if(pos == 1) continue;
            v.erase(v.begin() + (pos - 2));
            pos--;
        } else if(c == 'P') {
            char temp;
            cin >> temp;
            v.insert(v.begin() + (pos - 1), temp);
            pos++;
        }
    }
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}
