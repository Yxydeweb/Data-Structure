#include<iostream>
using namespace std;
typedef struct edge{
    int next, to, cost;
}Edge;
int head[10];
Edge edges[10];
int i;
void Add(int from, int to, int cost) {
    edges[++i].next = head[from];
    edges[i].to = to;
    edges[i].cost = cost;
    head[from] = i;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int from, to, cost;
        cin >> from >> to >> cost;
        Add(from, to, cost);
    }
    for ( int j = head[1]; j; j = edges[j].next) {
        printf("%d %d\n", edges[j].to, edges[j].cost);
    }
}
