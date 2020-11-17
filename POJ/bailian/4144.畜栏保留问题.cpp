/*************************************************************************
	> File Name: 4144.畜栏保留问题.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Fri Oct 23 19:05:00 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct COW {
    int start, end;
    int No;
};

struct Stall {
    int end, index;
    bool operator<(const Stall &s) const {
        return end > s.end;
    }
    Stall(int e, int n) : end(e), index(n) {  }
};


int n, sum; //n头牛
COW cows[50050];
priority_queue<Stall> pq;
int pos[50050];

bool cmp(COW a, COW b) { return a.start < b.start; }

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].start >> cows[i].end;
        cows[i].No = i;
    }
    sort(cows, cows + n, cmp); //将牛按开始时间从小到大排序
    for (int i = 0; i < n; i++) {
        if (pq.empty()) { //前面没有畜栏，只能给牛开一个新的
            sum++;
            pq.push(Stall(cows[i].end, sum));
            pos[cows[i].No] = sum;
        } else { 
            //前面有畜栏，此时就要比较时间结束最早的畜栏跟当前牛的开始时间的关系
            Stall temp = pq.top();
            if (temp.end < cows[i].start) {
                //前面时间结束最早的畜栏已经空出来了，给当前牛用
                pq.pop();
                pos[cows[i].No] = temp.index;
                pq.push(Stall(cows[i].end, temp.index));
            } else {
                //前面的畜栏都还在用着，没有结束的，也需要开一个新的
                sum++;
                pq.push(Stall(cows[i].end, sum));
                pos[cows[i].No] = sum;
            }
        }
    }
    cout << sum << endl;
    for (int i = 0; i < n; i++) {
        cout << pos[i] << endl;
    }
    return 0;
}
