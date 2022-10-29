I will leave out RMQ segment tree implementation for now, since I know nothing about it and straight up copied it from geeksforgeeks.
```

Anyways, the idea is fairly simple.


We can only travel from one point to another point, iff absolute distance between (x1-x2) and (y1-y2) is divisible by k.

Pure math, if it's not divisible by k, no matter how we move it it's impossible to reach one another.

We can always go to the highest place from starting point, and connects from there, if it's impossible, i.e there are blocks in between the distance.

That's why we need rmq to find the maximum on that range.

One thing to take note when doing query on rmq is that,we must make sure starting point <= ending point
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

 
void solve(){
    int n, m;
    cin >> n >> m;

    auto a = new int [m];
    for(int i{}; i < m; i++) cin >> a[i];

    int* tree = constructST(a, m);
    
    int q;
    cin >> q;
    while(q--){
        pi f, t;
        cin >> f.fir >> f.sec >> t.fir >> t.sec;

        int k;
        cin >> k;
        bool ok = 1;
        if (!(abs(f.fir-t.fir) % k == 0 && abs(f.sec-t.sec) % k == 0)){
            ok = 0;
        }else{
            int mx = f.fir + (((n-f.fir)/k) * k);
            if (f.sec > t.sec){
                swap(f.sec, t.sec);
            }
            ok = getMax(tree,m,f.sec-1,t.sec-1) < mx;
        }

        cout << (ok ? "YES" : "NO") << '\n';
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