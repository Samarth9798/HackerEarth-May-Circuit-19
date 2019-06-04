#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n;
int ans[300005];
int start[300005];
int finish[300005];
int timer;

void dfs(int parent)
{
    int node = start[timer];
    
    ans[node] = parent;
    
    timer++;
    
    while(finish[node] > timer)
        dfs(node);
}

int main()
{
    fast
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int x;
        
        cin >> x;
        
        start[x] = i;
    }
    
    for(int i = 1; i <= n; i++)
        cin >> finish[i];
        
    timer = 0;
    dfs(0);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
