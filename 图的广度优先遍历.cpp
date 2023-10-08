#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>map[20];
queue<int>q;
int vis[30];
void bfs() {
    while (!empty(q)) {
        cout << q.front() << ' ';
        vis[q.front()] = 1;
        for (int i : map[q.front()]) {
            if(!vis[i])q.push(i),vis[i]=1;
        }
        q.pop();
    }
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 1; i <= edge; i++) {
        int from, to;
        cin >> from >> to;
        map[from].push_back(to);
    }
    q.push(1);
    bfs();
}
