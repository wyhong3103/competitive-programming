Both way runs in O(NM), but for some reasons O(NM) space method run extremely slow
```
The idea is to see it as a Knapsack Table


The state is the [x][first k weight], this is the optimal substructure, the number of ways we can construct x using only first k weight

Transition is ,
[x - weight[k]][k] + [x][k-1], [x][k-1] is the number of ways to construct the x with the previous coins which we have to take into account
```
O(NM) space method
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MXX = 1e6+1;
const int MXN = 100;
const int MOD = 1e9 + 7;
int dp[MXX][MXN];
 
void solve(){
    int n, x;
    cin >> n >> x;
 
    vi a(n);
    for(auto& i : a) cin >> i;
    
    
    for(int i{}; i < n; i++){
        dp[0][i] = 1;
    }
 
    for(int i{1}; i <= x; i++){
        for(int c{}; c < n; c++){
            //Consider the number of ways to form x using coins before
            if (c > 0){
                dp[i][c] = dp[i][c-1];
            }
 
            if (i-a[c] >= 0){
                dp[i][c] = (dp[i][c] + dp[i-a[c]][c]) % MOD;
            } 
        }
    }
 
    cout << dp[x][n-1];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}	
```
O(N) space method
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MXX = 1e6+1;
const int MOD = 1e9 + 7;
ll dp[MXX];

void solve(){
    int n, x;
    cin >> n >> x;

    vi a(n);
    for(auto& i : a) cin >> i;
    
    
    dp[0] = 1;

    for(int c{}; c < n; c++){
        for(int i{1}; i <= x; i++){
            if (i - a[c] >= 0){
                dp[i] += dp[i-a[c]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```