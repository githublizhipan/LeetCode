/*************************************************************************
	> File Name: 577.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 18时58分07秒
 ************************************************************************/
#include <cstdio>
#include <map>
#include <cstring>
#include<iostream>
using namespace std;



map<char*, int> m;
int main() {
    char str[10000], ans[10000];
    int max = 0, k = 0;
    while(scanf("%s", str) != EOF) {
        int j = 0;
        char s[10000];
        for(int i = 0; str[i]; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = char(str[i] + 32);
            }
            if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')) {
               // cout << str[i];
                s[j] = str[i];
                j++;
            }
        }
        s[j] = '\0';
        //cout << endl;
        //cout << str << endl;
        //cout << k++ << endl;
        cout << s << endl;

        m[s]++;
        if(m[s] > max) {
            strcpy(ans, s);
            max = m[s];
            cout << m[s] << endl;
        } else if(m[s] == max && strcmp(s, ans) < 0) {
            strcpy(ans, s);
        }
        //cout << ans << endl;
    }
    cout << ans << " " << m[ans] << endl;
    return 0;
}
