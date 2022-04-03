Integer overflow is not fun :\|, i really gotta thik of a way to store the MAX! Anyway, this problem is about finding the connected component, and find its smallest, and largest x,y, in order to find its perimeter!
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


struct Cow{
    int x,y;    
};

bool visited[100000];
vector<Cow> cows;
vector<int> adj[100000];


void dfs(int node, pair<int,int>& x_r , pair<int,int>& y_r){
    if (visited[node]) return;

    x_r.fir = min(x_r.fir, cows[node].x);
    x_r.sec = max(x_r.sec, cows[node].x);
    y_r.fir = min(y_r.fir, cows[node].y);
    y_r.sec = max(y_r.sec, cows[node].y);

    visited[node] = true;
    for(auto& i: adj[node]){
        dfs(i, x_r, y_r);
    }
}


void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < n; i++){
        int x,y;
        cin >> x >> y;
        cows.push_back({x,y});
    }
    
    for(int i{}; i < m; i++){
        int to, end;
        cin >> to >> end;
        to--;end--;
        adj[to].push_back(end);
        adj[end].push_back(to);
    }

    ll ans{1000000000};
    for(int i{}; i < n; i++){
        if (!visited[i]){
            pair<int,int> x{100000000, 0};
            pair<int,int> y{100000000, 0};
            dfs(i,x,y);
            //cout << i << '\n';
            //cout << x.fir << ' ' << x.sec << ' ' << y.fir << ' ' << y.sec << '\n';
            if (((x.sec-x.fir)+(y.sec-y.fir))*2 < ans){
                ans = ((x.sec-x.fir)+(y.sec-y.fir))*2;
            }
        }
    }
    cout << ans;
}

int main(){
    setIO("fenceplan");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}


```
