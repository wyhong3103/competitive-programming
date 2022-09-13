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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MX = 26;
vi adj[MX];
bool vis[MX];
bool processing[MX];

void dfs(int node, deque<int>& order, bool& ok){
    if (vis[node]){
        ok &= !processing[node];
        return;
    }
    processing[node] = 1;
    vis[node] = 1;
    for(auto& i : adj[node]){
        dfs(i, order,ok);
    }
    processing[node] = 0;
    order.push_front(node);
}

void solve(){
    int n;
    cin >> n;
    
    if (n == 1){
    	//a random permutation of a-z
        cout << "acbdefhijklmnogpqrstuvwxyz";
        return;
    }

    vector<string> a(n);
    for(auto& i : a){
        cin >> i;
    }

    bool ok = 1;
    for(int i{}; i < n-1; i++){
        bool found = 0;
        for(int j{}; j < min(sz(a[i]), sz(a[i+1])); j++){
            if (a[i][j] != a[i+1][j]){
                adj[a[i][j]-'a'].pb(a[i+1][j]-'a');
                found = 1;
                break;
            }
        }
        if (!found && sz(a[i]) > sz(a[i+1])) ok = 0;
    }

    deque<int> order;
    for(int i{}; i < 26; i++){
        if (!vis[i]){
            dfs(i, order, ok);
        }
    }

    if (!ok){
        cout << "Impossible";
    }else{
        for(auto& i : order) cout << (char)(i+'a');
    }
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