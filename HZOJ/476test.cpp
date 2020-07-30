/*************************************************************************
	> File Name: 476test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 09时30分09秒
 ************************************************************************/
#include <string>
#include<iostream>
using namespace std;
int main() {
    string M;
    cin >> M;
    cout << M << endl;
    cout << "M.size:" << M.size() << endl;
    M.clear();


    cout << M << endl;
    cout << "M.size:" << M.size() << endl;
    
    for(int i = 0; i < 5; ++i){
        M.push_back(i+'0');
    }
    cout << "M:" << M << endl;
    cout << "M.size:" << M.size() << endl;
    return 0;
}
