#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<int>map[100];
bool ans, vis[100];
void dfs(int from, int to) {
    if (from == to) {
        ans = true;
        return;
    }
    else {
        for (int i : map[from]) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(i, to);
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        map[from].push_back(to);
    }
    dfs(2, 1);
    if (ans == true)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
