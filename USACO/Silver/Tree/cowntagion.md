```cpp
#include <bits/stdc++.h>
#include <limits>
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

const int MAX = 1e5 + 5;
vi adj[MAX];
int ans = 0;

void dfs(int node, int prev){
    int cows = 1;
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node);
            //number of days + 1
            ans++;
            //keep tracks of number of cows
            cows++; 
        }
    }
    //log2(cows) = number of days we need to double it up
    ans += ceil((double)log2(cows));
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    dfs(0,-1);
    cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```