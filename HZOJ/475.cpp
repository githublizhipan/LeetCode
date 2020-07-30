/*************************************************************************
	> File Name: 475.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 15时28分08秒
 ************************************************************************/
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n[2000], sum[2000], ans[2000];
char str_n[2000], str_m[2000], temp_sum[2000];



int cmp(char s1[], char s2[]) {
    int l1 = strlen(s1), l2 = strlen(s2);
    if(l1 < l2) return 0;
    else if(l1 == l2) {
        for(int i = 0; i <= l1; i++) {
            if(s1[i] < s2[i]) return 0;
            if(s1[i] > s2[i]) return 1;
        }
    } else return 1;
    return 0;
}



int main() {

    //输入俩数
    cin >> str_n >> str_m;
    int n_len = strlen(str_n), m_len = strlen(str_m);
    
    //将str_n倒着存到n,sum来倒着累加n,初始化为n
    sum[0] = n[0] = n_len;
    for(int i = 0; i < n_len; i++) {
        n[i + 1] = str_n[n_len - i - 1] - '0';
        sum[i + 1] = n[i + 1];
    }
    

    //将累加和sum翻过来变成字符串存到temp_sum中,每次和str_m比较,初始化为str_n;
    strcpy(temp_sum, str_n);
    ans[0] = 1;
    while(!cmp(temp_sum, str_m)) {
        
        //sum累加n;
        for(int i = 1; i <= n[0]; i++) {
            sum[i] += n[i];
        }
        //处理sum的进位
        for(int j = 1; j <= sum[0]; j++) {
            if(sum[j] < 10) continue;
            sum[j + 1] += sum[j] / 10;
            sum[j] %= 10;
            sum[0] += (j == sum[0]);
        }
        //每累加一次n, ans++
        ans[1] += 1;
        for(int k = 1; k <= ans[0]; ++k) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
        //将累加和反过来存字符串里
        for(int i = 1; i <= sum[0]; i++) {
            temp_sum[i - 1] = sum[sum[0] - i + 1] + '0';
        }
        
    }

    for(int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
