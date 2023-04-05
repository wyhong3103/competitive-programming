```

Okay apparently, we could just store the distance up to 1e9, which takes only ~2^30.

My dumbass went to optimize it with DSU and try to determine whether its in a cycle or no, maybe got even worse time complexity.

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

const int MX = 2e5 + 5;
const int ME = __lg(MX) + 5;
int nxt[MX];
int up[MX][ME];
//dist to cycle
int dist[MX];
int vis[MX];


int siz[MX];
int parent[MX];
    
int get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : get(parent[a]));
}

bool merge(int a, int b){
    a = get(a);
    b = get(b);
    
    if (a == b) return false;

    if (siz[a] > siz[b]){
        siz[a] += siz[b];
        parent[b] = a;
    }else{
        siz[b] += siz[a];
        parent[a] = b;
    }
    return true;
}

void dfs(int node, int& found, int& incycle){
    if (dist[nxt[node]] != -1){
        dist[node] = dist[nxt[node]] + 1;
        return;
    }
    if (vis[node]){
        found = node; 
        incycle = 1;
        return;
    }

    vis[node] = 1;
    dfs(nxt[node], found, incycle);

    if (incycle == 1){
        dist[node] = 0;
        merge(node, found);
    }
    else dist[node] = dist[nxt[node]] + 1;

    if (found == node) incycle = 0;
}


void solve(){
    int n, q;
    cin >> n >> q;

    memset(dist, -1, sizeof(dist));
    memset(up, -1, sizeof(up));
    
    for(int i{}; i < n; i++){
        int to;
        cin >> to;
        to--;
        parent[i] = i;
        siz[i] = 1;
        nxt[i] = to;
        up[i][0] = to;
    }

    for(int i{}; i < n; i++){
        if (!vis[i]){
            int found = -1;
            int incycle = 0;
            dfs(i, found, incycle);
        }
    }

    for(int i{1}; i < ME; i++){
        for(int j{}; j < n; j++){
            if (up[j][i-1] != -1) up[j][i] = up[up[j][i-1]][i-1];
        }    
    }   

    while(q--){
        int x, k;
        cin >> x >> k;
        x--;

        int node = x;
        if (k >= dist[x]){
            //bring it to first cycle node
            int d = dist[x];
            
            for(int i{}; i < ME; i++){
                if (node != -1 && (d & (1 << i))){
                    node = up[node][i];
                }
            }

            k -= d;
            k %= siz[get(node)];
        }

        for(int i{}; i < ME; i++){
            if (node != -1 && (k & (1 << i))){
                node = up[node][i];
            }
        }

        cout << node+1 << '\n';
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