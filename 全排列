#include<iostream>
using namespace std;
int vis[100],pl[100],n;
void DFS(int step) {
    if(step==n+1)
    {
        for(int i=1; i<=n; i++)
            cout << pl[i] << ' ';
        cout<< endl;
        return;
    }
    else {
        for(int i=1; i<=n; i++) {
            if(!vis[i])
            {
                vis[i]=1;
                pl[step]=i;
                DFS(step+1);
                vis[i]=0;
            }
        }
    }

}
int main() {
cin >> n;
    DFS(1);
    return 0;
}
