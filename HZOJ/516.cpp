/*************************************************************************
	> File Name: 516.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 23时09分39秒
 ************************************************************************/

//**************************错误***************
#include<iostream>
using namespace std;
int n, indc[10005], indw[10005], indo[10005], sum1 = 0, sum2 = 0, ans = 0;
char str[10005];
int main() {
    cin >> n >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'C') {
            indc[++indc[0]] = i;
        } else if (str[i] == 'O') {
            indo[++indo[0]] = i;
        } else {
            indw[++indw[0]] = i;
        }
    }
    for (int i = 1; i <= indc[0]; i++) {
        int cnt = 0, tmp = 1;
        for (int j = indc[i] + 1; j <= indo[indo[0]]; j++) {
            if (str[j] == 'C') {
                for (int k = j + 1; k <= indw[indw[0]]; k++) {
                    ++cnt;
                }
                sum1 += cnt;
            }
            sum2 += sum1;
        }
        ans += sum2;
    }
    cout << sum2 << endl;
    return 0;
}
