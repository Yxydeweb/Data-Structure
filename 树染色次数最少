#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<int>map[20];
int step,color[20];
void dfs(int num, int frontcol) {//frontcol为父节点的颜色
    if (color[num] != frontcol)step++;//当父节点颜色与当前节点的颜色不同时step++
    for (int i : map[num]) dfs(i, color[num]);
}
int main() {
    int n;cin >> n;
    for (int i = 2; i <= n; i++) {//读入除根节点外的其他节点的父节点
        int from; cin >> from;
        map[from].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> color[i];//读入每个节点的颜色，颜色代码1,2
    dfs(1, 0);
    cout << step << endl;
    return 0;
}//将一个树染为目的状态，每次染树父节点的子树和父节点颜色相同
