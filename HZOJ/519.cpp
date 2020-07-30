/*************************************************************************
	> File Name: 519.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 10时15分41秒
 ************************************************************************/
//*******************不对********

#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long L, R;

int num[10] = {0};

int is_val(int n) {

    memset(num, 0, sizeof(num));
    int digit = 0, maxl = -1, cnt = 0;
    
    while(n) {
        num[n % 10]++;
        n /= 10;
        digit++;
    }

/*    
    string s = to_string(n);
    for(int i = 0; i < s.size(); ++i) {
        num[s[i] - '0']++;
    } 
    digit = s.size();
*/

    for(int i = 0; i <= 9; i++) {
        maxl = max(maxl, num[i]);
        if(num[i]) cnt++;
    }

    if((cnt - 2) || (maxl + 1) != digit) {
        return 0;
    }
    return 1;
}

int main() {
    long long sum = 0;
    scanf("%lld%lld", &L, &R);
    
    
    for(long long i = L; i <= R; ++i) {
        if(is_val(i)) sum++;
    }
    
    printf("%lld\n", sum);

    return 0;
}
