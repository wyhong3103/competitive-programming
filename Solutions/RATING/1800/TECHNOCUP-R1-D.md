```

for every number starting from n-1

we do 

0 0 0 0 .... 1 tells us where is x+1

1 1 1 1 1 ...0 tells us where is x-1

^ we have to do it both way because sometime when we do a query we will get back to our self

If we get 0 doing the first type of query, that means we found the largest element

If we get 0 doing the second type of query, that means we found the smallest element

Make it a DAG, every element x points to the one that is larger, x+1

Finally do a DFS starting from the smallest

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void dfs(int node, vi& order, vi& to){
    order.pb(node);

    if (to[node] == -1) return;
    dfs(to[node],order, to);

}

void solve(){
    int n;
    cin >> n;

    vi to(n, -1);
    
    int start = -1;

    for(int i{n-1}; i >= 0; i--){
        cout << "? ";
        for(int j{}; j < n; j++){
            cout << (j == i ? 2 : 1) << ' '; 
        }
        cout << '\n';

        cout.flush();

        //if 0 here, largest
        int x;
        cin >> x;
        
        if (x && x-1 != i){
            to[i] = x-1;
        }

        cout << "? ";
        for(int j{}; j < n; j++){
            cout << (j == i ? 1 : 2) << ' '; 
        }
        cout << '\n';
        cout.flush();

        //if 0 here, smallest
        cin >> x;

        if (!x) start = i;
        else if (x && x-1 != i){
            to[x-1] = i;
        }
    }


    vi order;
    dfs(start,order, to);

    vi res(n);
    for(int i{}; i <n ; i++){
        res[order[i]] = i+1;
    }
    cout << "! ";
    for(auto& i :res) cout << i << ' ';

}
    
int main(){
 //   ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```