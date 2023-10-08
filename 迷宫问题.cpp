#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;//红色格子可以走
char map[50][50];
bool vis[50][50];
typedef pair<int, int>point;
queue<point>q;
typedef struct {
    int x, y, num;
}Pos;
Pos pos[100];
int dir[4][2] = { -1,0,1,0,0,-1,0,1 }, ans,step, n, m,a=1,p;
inline bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs() {
    pos[a].x = q.front().first;
    pos[a].y = q.front().second;
    pos[a].num = 0;
    p = a;
    while (!empty(q)) {
        step++;//记录深度（队列的状态/步数）
        int size = q.size();//记录当前队列中点的个数（深度为step的点的个数）
        while(size--)//插入合法的点并删去上一步中队列中的点
        {
            vis[q.front().first][q.front().second] = 1;
            for (int i = 0; i < 4; i++) {
                int xx = dir[i][0] + q.front().first;
                int yy = dir[i][1] + q.front().second;
                if (check(xx, yy) && !vis[xx][yy] && map[xx][yy] == '1') {
                    if (xx == 6 && yy == 5) ans = 1;
                    q.push(make_pair(xx, yy));
                    pos[++a].x = xx;
                    pos[a].y = yy;
                    pos[a].num = p;
                    vis[xx][yy] = 1;
                    if (ans == 1)return;
                }
                
            }
            q.pop(); p++;
        }
    }
}
int Find(int x, int y) {//返回到目的地的pos数组下标
    int i;
    for (i = 1; i < 100; i++)
        if (pos[i].x == x && pos[i].y == y)
            break;
    return i;
}
void Path(int n) {//递归打印路径
    if (pos[n].num == 0) {
        cout << "(" << pos[n].x << "," << pos[n].y << ")" << endl;
        return;
    }
    else {
        Path(pos[n].num);
        cout << "(" << pos[n].x << "," << pos[n].y << ")" << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)scanf("%s", map[i] + 1);
    q.push(make_pair(1, 1));//从左上角开始走迷宫
    bfs();
    cout << ans << endl;
    if (ans == 1)cout << step << endl;
    Path(Find(6, 5));
    return 0;
}
//测试数据
//6 5
//11011
//10111
//10100
//10111
//11101
//11111   起点（1,1）终点（6,5），1可以走，0不可以走，问能否到达？能到达则要几步？路径为？
