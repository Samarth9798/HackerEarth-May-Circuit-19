#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

struct point
{
    ll x,y;
}g[200005], s[200005];

int main()
{
    fast

    int n,m;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        cin >> g[i].x >> g[i].y;
    
    for(int i = 1; i <= m; i++)
        cin >> s[i].x >> s[i].y;
      
    int guard[n+5];
    memset(guard,0,sizeof(guard));
    int shops[m+5],id;
    memset(shops,0,sizeof(shops));
    
    for(int j = 1; j <= m; j++)
    {
        int xj,yj;
        yj = s[j].y;
        xj = s[j].x;
        for(int i = n; i >= 1; i--)
        {
            int xi,yi;
            xi = g[i].x;
            yi = g[i].y;
            
            if(abs(yi - yj) <= xj - xi) 
            {
                shops[j]++;
                id = i;
            }
            if(shops[j] > 1)
                break;
        }
        if(shops[j] == 1) guard[id] = 1;
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(guard[i] > 0)
            cnt++;
    }
    
    int ans = n-cnt;
    cout << ans;
}
