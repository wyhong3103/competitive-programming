Although this method computes in O(N), but we have to use another N length array to stop us from visiting a visited component. We use floyd algorithm to detect a cycle and to find the first node.  It's overkilled for that problem. But hey it worked out
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
bool vis[1000];
int ans[1000];
int a[1000];

void floyd(int i){
	//Finding cycle
    int p1 = a[i-1];
    int p2 = a[a[i-1]-1];
    while (p1 != p2){
        p1 = a[p1-1];
        p2 = a[a[p2-1]-1];
    }

    //Finding beginning node
    p1 = i;
    while (p1 != p2){
        p1 = a[p1-1];
        p2 = a[p2-1];
    }

    //Before Cycle
    vis[i-1] = 1;
    p1 = i;
    while (p1 != p2){
        vis[p1-1] = 1;
        ans[p1-1] = p2;
        p1 = a[p1-1];
    }

    //In cycle
    vis[p2-1] = 1;
    ans[p2-1] = p2;
    p1 = a[p2-1];
    while (p1 != p2){
        vis[p1-1] = 1;
        ans[p1-1] = p1;
        p1 = a[p1-1];
    }
}


void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++) cin >> a[i];

    for(int i{}; i < n; i++){
        if (!vis[i]){
            floyd(i+1);
        }
    }

    for(int i{}; i < n; i++){
        cout << ans[i] << ' ';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```
A recursive way from USACO, more on [Solution](https://usaco.guide/silver/func-graphs?lang=cpp)
```cpp

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> P,ans;
bool in_cycle;

void gen(int x) {
	if (ans[x] != -2) {
		if (ans[x] == -1) ans[x] = x, in_cycle = 1; // found a cycle!
		return;
	}
	ans[x] = -1;
	gen(P[x]);
	if (ans[x] != -1) { in_cycle = 0; return; }
	//If it's in a cycle, then we assign itself, else the beginning node
	ans[x] = in_cycle ? x : ans[P[x]];
}

int main() {
	cin >> N;
	P.assign(N, 0);
	for(int& x:P) cin >> x, --x;
	ans.assign(N, -2);
	for(int i=0;i<N;++i) gen(i); // in_cycle is always reset to 0
	for(int t:ans) cout << t+1 << " ";
}
```