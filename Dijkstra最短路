#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
# define Maxlength 1e10
using namespace std;
int n, m, s,from,to,weight;//n为点的个数，m为边的个数，s为起点，from为边起点，to为边终点，weight为边权
typedef struct {
    int to, weight;
}Edge;
vector<Edge>map[100001];
int minlength[100001];
bool vis[100001];
void Dijkstra(int s) {
    //初始化
    for (int i = 1; i <= n; i++)minlength[i] = Maxlength;
    minlength[s] = 0;
    for (Edge i : map[s]) {
        minlength[i.to] = i.weight;
    }
    vis[s] = 1;
    
    for (int i = 1; i <= n;i++) {
        int min = Maxlength, k=s;
        if (i != s) {
            //寻找权重最小的
            for (int i = 1; i <= n;i++) {
            if (minlength[i]<min && !vis[i]) {
                min = minlength[i];
                k = i;
            }
        }
        vis[k] = 1;
        //更新
        for (Edge i:map[k]) {
            if (min + i.weight < minlength[i.to]) {
                minlength[i.to] = min + i.weight;
            }
        }
        }
        
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        Edge edge;
        scanf("%d%d%d", &from, &to, &weight);
        edge = { to,weight };
        map[from].push_back(edge);
    }
    Dijkstra(2);
    for (int i = 1; i <= n; i++)printf("%d ", minlength[i]);
    return 0;
}
//测试数据
//5 7 1
//1 2 1
//1 5 7
//2 4 2
//4 1 1
//4 5 2
//2 3 4
//5 3 3
