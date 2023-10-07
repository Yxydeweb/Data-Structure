#include<iostream>
using namespace std;
int lie[200], zd[200], fd[100],n,a[200];
bool check(int i, int j) {
    if (!lie[j] && !zd[i - j + 100] && !fd[i + j]) return true;
    else return false;
}
void dfs(int hang) {
    if (hang == n + 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] == j)cout << 1<<" ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
        cout << "------------------------------------"<<endl;
    }
    else {
        for (int j = 1; j <= n; j++) {
            if (check(hang, j)) {
                lie[j] = 1;
                zd[hang - j + 100] = 1;
                fd[hang + j] = 1;
                a[hang] = j;
                dfs(hang + 1);
                lie[j] = 0;
                zd[hang - j + 100] = 0;
                fd[hang + j] = 0;
            }
        }
    }
}
int main() {
    cout << "请输入皇后个数：";
    cin >> n;
    dfs(1);
}
