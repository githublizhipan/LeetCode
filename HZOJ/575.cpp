/*************************************************************************
	> File Name: 575.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 18时37分57秒
 ************************************************************************/
#include <map>
#include<iostream>
using namespace std;
int main() {
    map<string, int> words;
    int n, m;
    char str[110];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int page;
        cin >> str >> page;
        words[str] = page;
    }
    
    cin >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> str;
        cout << words[str] << endl;;
    }

    return 0;
}
