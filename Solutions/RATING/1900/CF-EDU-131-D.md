```

Not hard to see that, for each number, the range is [ floor(i/(a[i]+1)), floor(i/a[i]) if a[i] > 0 else N ]

So it is guaranteed that we can definitely construct a solution

But how?

Let's first look at this case

Say we want to fill the number 1, and we have [1, a], [1, b], [1, c] segments

which one should we use? We should use the one that has the smallest end point, because whatever we can achieve in the shortest segment we can also achieve it with others, but not the reverse.

So after 1, what do we do with those segments? Which one do we choose when we  have [2, d] etc

Well turned out all those [1,x] can be seen as [2,x] as 1 is gone, it doesn't matter anymore, so we cna use the same greedy to solve the problem

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

void solve(){
    int n;
    cin >> n;

    vector<vector<pi>> interval(n);
    
    for(int i{}; i < n; i++){
        int x;
        cin >> x;

        int l = ((i+1)/(x+1)) + 1;
        int r = (!x ? n+1 : ((i+1)/x));
        interval[l-1].pb({r-1, i});
    } 

    vi res(n);

    set<pi> s;
    for(int i{}; i < n; i++){
        for(auto& j : interval[i]) s.insert(j);
        res[s.begin()->sec] = i;
        s.erase(s.begin());
    }

    for(auto& i : res){
        cout << i+1 << ' ';
    }
    cout << '\n';

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```