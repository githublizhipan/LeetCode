/*************************************************************************
	> File Name: 380.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月10日 星期五 18时40分37秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

struct vote {
    int len;
    int index;
    char str[1100];
};

int cmp(vote a, vote b) {
    if(a.len > b.len) return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vote a[150];
    for(int i = 1; i <= n; i++) {
        cin >> a[i].str;
        a[i].len = strlen(a[i].str);
        a[i].index = i;
    }
    //sort(a + 1, a + n + 1, cmp);
    int l = a[1].len;
    char s[1100];
    strcpy(s, a[1].str);
    int m = 1;
    for(int i = 2; i <= n; ++i) {
        if(a[i].len < l) continue;
        if(a[i].len > l) {
            m = a[i].index;
            l = a[i].len;
            strcpy(s, a[i].str);
        } else {
            for(int j = 0; j < l; j++) {
                if(a[i].str[j] <= s[j]) continue;
                m = i;
                l = a[i].len;
                strcpy(s, a[i].str);
                break;
                //cout <<  a[i].index << endl;
            }
        }
    }
    cout << m << endl;
    cout << s << endl;
    return 0;
}
