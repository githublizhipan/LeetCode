/*************************************************************************
	> File Name: 9.大整数加法.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Oct  3 21:29:10 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1000
char stra[maxn], strb[maxn];
int a[maxn], b[maxn], ans[maxn];

int main() {
    cin >> stra >> strb;
    int lena = strlen(stra), lenb = strlen(strb);
    ans[0] = lena > lenb ? lena : lenb; //ans[0]存结果的位数

    

    return 0;
}
