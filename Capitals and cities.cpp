#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
int main()
{
    fast
    
    int n;
    ll k;
    cin >> n >> k;
    
    ll a[n+5];
    map<ll,int> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
    for(int i = n; i >= 1; i--)
        m[a[i]] = i;
    
    sort(a+1,a+n+1);
    
    ll left_dp[n+5]; memset(left_dp,0,sizeof(left_dp));
    ll right_dp[n+5]; memset(right_dp,0,sizeof(right_dp));
    
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        left_dp[i] = sum;
    }
    sum = 0;
    for(int i = n; i >= 1; i--)
    {
        sum += a[i];
        right_dp[i] = sum;
    }
    
    ll ans = LLONG_MAX;
    int cap = 0; 
    for(int i = 1; i <= n; i++)
    {
        ll temp = 0;
        
        ll left,right,left_cnt,right_cnt;
        left = right = left_cnt = right_cnt = 0;
        
        left = left_dp[i-1];
        right = right_dp[i+1];
        
        left_cnt = (i-1)*a[i];
        right_cnt = (n-i)*a[i];
 
        left = abs(left - left_cnt);
        right = abs(right - right_cnt);
            
        temp = left + right;
        
        if(temp < k)
        {
            temp = k - temp;
            temp = (temp&1);
        }
        else
            temp = temp - k;
        
        if(ans > temp)
        {
            ans = temp;
            cap = m[a[i]];
        }
        else if(ans == temp)
        {
            if(cap > m[a[i]])
                cap = m[a[i]];
        }
    }
    cout << cap << ' ' << ans;
}
