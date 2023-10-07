#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
# define Maxlength 9999
using namespace std;
typedef struct {
    int ma[50][50];
    int nodenum, edgenum;
}Map;
void InitialMap(Map &map) {
    for (int i = 1; i <= map.nodenum; i++) {
        for (int j = 1; j <= map.nodenum; j++)
        {
            if (i != j)map.ma[i][j] = Maxlength;
            else map.ma[i][j] = 0;
        }
    }
    for (int i = 1; i <= map.edgenum; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        map.ma[from][to] = weight;
        map.ma[to][from] = weight;
    }
}
void Floyd(Map& map,int D[50][50], int P[50][50]) {
    //初始化
    for (int i = 1; i <= map.nodenum; i++) {
        for (int j = 1; j <= map.nodenum; j++)
        {
            D[i][j] = map.ma[i][j];
            P[i][j] = j;
        }
    }
    //查找最短路，更新D和P
    for (int i = 1; i <= map.nodenum; i++) {
        for (int j = 1; j <= map.nodenum; j++) {
            for (int k = 1; k <= map.nodenum; k++) {
                if (D[j][i] + D[i][k] < D[j][k]) {
                    D[j][k] = D[j][i] + D[i][k];
                    P[j][k] = P[j][i];
                }
            }
        }
    }
}
//打印个点间的路径和长度
void Path(int P[50][50],int D[50][50],int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int k=i;
            cout << i << "->" << j << "的路径为：";
            while (k != j) {
                cout << k << ' ';
                k = P[k][j];
            }
            cout <<j<< "\t长度为："<<D[i][j] << endl;
        }
    }
}
int main() {
    Map map;
    cin >> map.nodenum >> map.edgenum;
    InitialMap(map);
    cout << "邻接矩阵为：" << endl;
    for (int i = 1; i <= map.nodenum; i++) {
        for (int j = 1; j <= map.nodenum; j++)
            cout<<map.ma[i][j]<<' ';
        cout << endl;
    }
    int D[50][50], P[50][50];
    Floyd(map, D, P);
    cout << "D：" << endl;
    for (int i = 1; i <= map.nodenum; i++) {
        for (int j = 1; j <= map.nodenum; j++)
            cout << D[i][j] << ' ';
        cout << endl;
    }
    cout << "P：" << endl;
    for (int i = 1; i <= map.nodenum; i++) {
        for (int j = 1; j <= map.nodenum; j++)
            cout << P[i][j] << ' ';
        cout << endl;
    }
    cout << "最短路径：" << endl;
    Path(P,D, map.nodenum);
    return 0;
}
//测试数据
//6 7
//1 2 2
//1 3 4
//1 5 6
//3 6 3
//2 4 1
//4 5 2
//4 6 1
