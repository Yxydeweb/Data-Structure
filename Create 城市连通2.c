#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
bool ans, vis[100];
int head[100],cnt;
struct edge {
    int next, to;
}edges[100];
void add(int from, int to) {
    edges[++cnt].next = head[from];
    edges[cnt].to = to;
    head[from] = cnt;
}
void dfs(int from, int to) {
    if (from == to) {
        ans = true;
        return;
    }
    else {
        for (int i = head[from]; i; i = edges[i].next) {
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
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        add(from, to);
    }
    dfs(4, 1);
    if (ans == true) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
