\*DNS - Did Not Solve
<br>
I am really bad at identifying connected component and all. My initial idea is to actually count the number of cows along the path from the node, and then keep track of the number on each and every node. And I noticed that to go from A to B, the path is simply path from A to root - A lowest common ancestor with B + B to root - B lowest common ancestor with A. But this simply doesn't work because of the memory cosntraint. The way I used to find LCA in this problem might not be efficient I basically store the ancestors of every node, and then during query I simply use Binary Search to look up for their LCA. Anyways it didn't work out well.
```
The explanation to this solution is simply by using connected components.

If A and B are in the same component, that means they are in the same path which has breed I, it's only possible to get the preferable cow's milk if the breed is the corresponding breed.
If A and B are in different component, that means along the way from A to B, we must and we will go through different breeds of cows, so in this situation it's always possible to get the preferable cow.

One connnected component = same breed of cows along one path

```

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
int comp[MAX];
char compbreed[MAX];
string breeds;

void dfs(int node, int prev, int& cur){
    if (!comp[node]){
        comp[node] = cur;
        compbreed[cur] = breeds[node];
        cur++;
    }
    for(auto& i : adj[node]){
        if (i != prev){
            if (breeds[i] == breeds[node]) comp[i] = comp[node];
            dfs(i, node, cur);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    cin >> breeds;

    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    int cur = 1;
    dfs(0, -1, cur);
    
    string res = "";
    for(int i{}; i < q; i++){
        int f,t;
        char c;
        cin >> f >> t >> c;
        f--;t--;
        if (comp[f] != comp[t]) res += '1';
        else if (compbreed[comp[f]] == c) res += '1';
        else res += '0';
    }
    cout << res;
}

int main(){
    setio("milkvisits");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```