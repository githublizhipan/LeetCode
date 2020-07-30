/*************************************************************************
	> File Name: 566.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 09时36分25秒
 ************************************************************************/
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string, int> nameMap; //将名字映射为编号
string page[1005][5005]; //每个人浏览的网页(一维是编号)
string name[1005]; //名字数组
int cnt[1005]; //每个人浏览网页的个数
int num; //记录人数


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        string namestr, s;
        cin >> namestr >> s;

        //这个人如果第一次出现
        if (nameMap[namestr] == 0) {
            nameMap[namestr] = ++num;
            name[num] = namestr;
        }
        int ind = nameMap[namestr]; //这个人之前出现过，找到编号
        page[ind][cnt[ind]++] = s;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << name[i];
        for (int j = 0; j < cnt[i]; j++) {
            cout << " " << page[i][j];
        }
        cout << endl;
    }

    return 0;
}
