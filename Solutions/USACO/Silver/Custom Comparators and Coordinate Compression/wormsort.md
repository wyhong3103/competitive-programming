Unsolved solution
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
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

 
vector<pi> adj[100001];
bool visc[100001];


void dfs(vi& cows, int i, int& mx, int tmx, int lastw){
    if (cows[i] == i){
        mx = max(tmx, mx);
        return;
    }

    if (visc[i]){
        return;
    }

    tmx = max(tmx, lastw);
    visc[i] = true;

    for(auto& w : adj[i]){
        swap(cows[i], cows[w.fir]);
        dfs(cows, w.fir, mx, tmx, w.sec);
        swap(cows[i], cows[w.fir]);
    }
}


void solve(){   
    int n, m;
    cin >> n >> m;

    map<int,int> lo;

    vi cows(n+1);
    for(int i{1}; i  <= n; i++) {
        cin >> cows[i];
        lo[cows[i]] = i;
    }

    for(int i{}; i < m; i++){
        int en1, en2, wgh;
        cin >> en1 >> en2 >> wgh;
        adj[en1].pb({en2, wgh});
        adj[en2].pb({en1, wgh});
    }

    bool found = false;
    int ans = numeric_limits<int>::max();
    for(int i{1}; i <= n; i++){
        if (lo[i] != i){
            int mx = 0;
            int tmx = 0;
            found = true;
            dfs(cows, i, mx, tmx, 0);
            memset(visc, 0, sizeof(visc));
            ans = min(ans, mx);
        }     
    }


    if (!found){
        cout << -1;
        return;
    } 
    cout << ans;

    
}
 
int main(){
    setio("wormsort");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```