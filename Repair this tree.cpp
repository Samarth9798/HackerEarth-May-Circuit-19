#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

ll parent[200005];
ll n,q;
ll ans;
unordered_map<ll, vector< pair<int,int> > > weights;
unordered_map<ll, vector<ll> > store;
int done[1000005];
vector<int> level[200005];
vector<int> adj[200005];
int max_level;
int vertex_level[200005];
int max_level_[200005];

void dfs(int x, int lev)
{
    level[lev].push_back(x);
    if(lev > max_level)
        max_level = lev;
    vertex_level[x] = lev;
    for(int i = 0; i < adj[x].size(); i++)
    {
        dfs(adj[x][i],lev+1);
    }
}

void find_max_level()
{
    for(int i = max_level; i >= 1; i--)
    {
        for(int j = 0; j < level[i].size(); j++)
        {
            int x = level[i][j];
            max_level_[x] = max(max_level_[x], i);
            max_level_[ parent[x] ] = max(max_level_[parent[x]],max_level_[x]);
        }
    }
}

void input()
{
    cin >> n >> q;
    
    for(ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        parent[i] = x;
        adj[x].push_back(i);
    }
    parent[1] = 1;
    
    memset(vertex_level,0,sizeof(vertex_level));
    max_level = 0;
    dfs(1,0);
    
    memset(max_level_,0,sizeof(max_level_));
    find_max_level();
}

void prime(ll x, ll y)
{
    if(x%2 == 0)
    {
        store[2].push_back(y);
    }
    while(x%2 == 0)
        x = x/2;
        
    for(ll i = 3; i <= sqrt(x); i += 2)
    {
        if(x%i == 0) store[i].push_back(y);
        while(x%i == 0) x = x/i;
    }
    if(x > 1)
        store[x].push_back(y);
}

void type1()
{
    ll x,y,w;
    
    cin >> x >> y >> w;
    
    x = (x + ans - 1)%n + 1;
    y = (y + ans - 1)%n + 1;

    if(x == y)
        return;
        
    if(x > y) 
        swap(x,y);
        
    weights[w].push_back({x,y});
    
    if(done[w] == 0)
    {
        prime(w,w);
        done[w] = 1;
    }
}

int root(int i)
{
    int arr = parent[i]; 
    while(arr != i)
    {
        arr = parent[parent[parent[i]]];
        i = arr;
        arr = parent[i]; 
    }
    return i;
}

void type2()
{
    ll v,p;
    
    cin >> v >> p;
    
    v = (v + ans - 1)%(n-1) + 2;

    ans = 0;

    int temp = parent[v];
    parent[v] = v;
    
    for(int i = 0; i < store[p].size(); i++)
    {
        ll it = store[p][i];
        for(int j = 0; j < weights[it].size(); j++)
        {
            pair<ll,ll> pi = weights[it][j];
            int x,y;
            
            if(pi.first != v and vertex_level[pi.first] <= vertex_level[v])
                x = 1;
            else if(pi.first != v and vertex_level[pi.first] > max_level_[v])
                x = 1;
            else if(pi.first != v and level[vertex_level[v]].size() == 1)
                x = v;
            else
                x = root(pi.first);
        
            if(pi.second != v and vertex_level[pi.second] <= vertex_level[v])
                y = 1;  
            else if(pi.second != v and vertex_level[pi.second] > max_level_[v])
                y = 1;
            else if(pi.second != v and level[vertex_level[v]].size() == 1)
                y = v;
            else
                y = root(pi.second);
                
            if(x != y)
                ans += it;
        }
    }
    
    parent[v] = temp;
    cout << ans << "\n";
}

void query()
{
    ans = 0;
    memset(done,0,sizeof(done));
    
    while(q--)
    {
        int ty;
        cin >> ty;
        
        switch(ty)
        {
            case 1: type1(); break;
            case 2: type2(); break;
        }
    }
}

int main()
{
    fast
    
    input();
    
    query();
}
