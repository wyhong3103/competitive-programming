```

Simply binary search and take care of some edge cases

y axis goes from top to bottom

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

struct Sofa{
    int a, b, c, d;
};

int bs(int target, vi& a){
    int lo = 0, hi = sz(a)-1;
    while(hi > lo){
        int mid = lo + (hi-lo)/2;
        if (a[mid] >= target) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

void solve(){
    int d, n, m;
    cin >> d >> n >> m;

    vector<Sofa> a(d);

    vi horl;
    vi horr;
    vi vert;
    vi verb;

    for(auto& i : a){
        cin >> i.a >> i.b >> i.c >> i.d;
        if (i.a > i.c) swap(i.a, i.c);
        if (i.b > i.d) swap(i.b, i.d);

        horl.pb(i.a);
        horr.pb(i.c);
        vert.pb(i.b);
        verb.pb(i.d);
    }

    sort(all(horl));
    sort(all(horr));
    sort(all(verb));
    sort(all(vert));

    int l, r, t, b;
    cin >> l >> r >> t >> b;

    int cnt = 0;
    for(auto& i : a){
        cnt++;
        int tl, tr, tt, tb;
        tl = bs(i.c, horl)+(horl[bs(i.c, horl)] < i.c)-(i.a != i.c);
        tr = d-bs(i.a+1, horr)-(horr[bs(i.a+1, horr)] < i.a+1) - (i.a != i.c);
        tt = bs(i.d, vert)+(vert[bs(i.d, vert)] < i.d)-(i.b != i.d);
        tb = d-bs(i.b+1, verb)-(verb[bs(i.b+1, verb)] < i.b+1) - (i.b != i.d);

        if (tl == l && tr == r && tt == t && tb == b){
            cout << cnt << '\n';
            return;
        }
    }
    cout << -1;
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