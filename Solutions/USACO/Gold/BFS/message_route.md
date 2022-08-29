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


const int MX = 1e5;
vi adj[MX];
bool vis[MX];
int parent[MX];

void solve(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    queue<int> q;
    q.push(0);
    vis[0] = 1;
    memset(parent, -1, sizeof(parent));

    while(!q.empty()){
        int cur = q.front();q.pop();
        for(auto& i : adj[cur]){
            if (!vis[i]){
                vis[i] = 1;
                parent[i] =cur;
                q.push(i);
            }
        }
    }

    if (parent[n-1] == -1){
        cout << "IMPOSSIBLE";
    }else{
        vi route;
        int cur = n-1;
        while (cur != -1){
            route.pb(cur);
            cur = parent[cur];
        }

        cout << sz(route) << '\n';
        for(int i{sz(route)-1}; i >= 0; i--){
            cout << route[i]+1 << ' ';
        }
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