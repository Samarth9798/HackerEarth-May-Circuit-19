#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n;
ll MAXW;
map<ll,ll> m;
const ll mod = 987654319;
ll size[300005];
int parent[300005];

struct edges
{
    ll w;
    int x,y;
}e[300005];

bool comp(edges a, edges b)
{
    return a.w < b.w;
}

void init()
{
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int root(int i)
{
    while(i != parent[i])
    {
        parent[i] = parent[ parent[i] ];
        i = parent[i];
    }
    return i;
}

void weighted_union(int x,int y)
{
    int rootx = root(x);
    int rooty = root(y);
    
    if(size[rootx] < size[rooty])
    {
        parent[rootx] = parent[rooty];
        size[rooty] += size[rootx];
        return;
    }
    
    parent[rooty] = parent[rootx];
    size[rootx] += size[rooty];
    return;
}

void kruskal()
{
    init();
    
    sort(e,e+n-1,comp);
    
    for(int i = 0; i < n-1; i++)
    {
        ll x = size[ root(e[i].x) ] - 1;
        ll y = size[ root(e[i].y) ] - 1;
        
        ll temp = ((x*y) + x + y);
        
        if(temp > 0)
            m[e[i].w] += temp;
            
        weighted_union(e[i].x,e[i].y);
    }
}

ll power(ll x, ll y)
{
    ll res = 1;
    
    while(y > 0)
    {
        if(y&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return res;
}

void solve()
{
    ll ans = 1;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        ll temp = MAXW - (it->first) + 1;
        if(temp < 0)
        {
            cout << 0;
            return;
        }
        temp = ( power(temp+1, it->second) )%mod;
        ans = (ans * temp)%mod;
    }
    
    cout << ans;
}

void input()
{
    cin >> n >> MAXW;
    for(int i = 0; i < n-1; i++)
        cin >> e[i].x >> e[i].y >> e[i].w;
}

int main()
{
    fast
    
    input();
    
    kruskal();
    
    solve();
}
