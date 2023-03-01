```

DP state

dp[i][0] = maximal length if we are to include node i 
dp[i][1] = maximal length if we are to combine every subtree for children of i


DP transition

dp[i][0] = max(dp[ci][0]+1)

dp[i][1] = sum(max(dp[ci][0], dp[ci][1]))


The idea is 


If we are to include node i in the longest non decreasing subseq that means we can only pick one of the longest in children this is bc, if we are to include node i in the longest non decreasing subseq every other subtree would basically be ignored since node i is going to be the minimal among them all. So we will just choose the longest children and make it the min of that subtree (dont really matter, we aren't asked to construct the tree)

If we are to not include node i, we can simply combine all the longest children


```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 1e5 + 5;
vi adj[MX];
int dp[MX][2];
 
void dfs(int node){
    dp[node][0] = 1;
    
    for(auto& i : adj[node]){
        dfs(i);
    }
 
    for(auto& i : adj[node]){
        dp[node][0] = max(dp[node][0], dp[i][0]+1);
        dp[node][1] += max(dp[i][0],dp[i][1]);
    }
}
 
void solve(){
    int n;
    cin >> n;
    
    for(int i{}; i < n-1; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i+1);
    }
 
    dfs(0);
 
    cout << max(dp[0][0], dp[0][1]);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```