```

abridged statement

original array = a, we want to make a = b

we have m options, each option can only be used once, each operation we can set a segment, for every ai in [l,r] of that segment be min(ai, x)


its impossible if

bi > ai, or there exist a bi != one of the x

if all fulfilled

we need to further check whether what we have is enough!

Good thing about this problem is that we should prioritize using bigger razor then after smaller razor, the reason is that, we cannot use small -> big on an interval.

And if big razor go through hair that has smaller size, it doesnt affect it.

So we can use a monotonic stack to keep track of things.

Everytime an element get pushed, we need one of that elements.

If current element is bigger than top of the stack, we remove it, until it is the smallest.

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
    int n;
    cin >> n;

    vll a(n);
    vll b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    int m;
    cin >> m;
    map<int,int> mp;
    for(int i{}; i < m; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    bool ok = 1;
    for(int i{}; i < n; i++){
        if (b[i] > a[i]) ok = 0;
        if (b[i] != a[i] && !mp.count(b[i])) ok = 0;
    }

    map<ll,int> need;
    stack<int> s;
    for(int i{}; i < n; i++){
        while (!s.empty() && b[i] > s.top()){
            s.pop(); 
        }

        if (s.empty() && b[i] != a[i]){
            s.push(b[i]);
            need[b[i]]++;
        }

        if (!s.empty() && b[i] != s.top() && a[i] != b[i]){
            s.push(b[i]);
            need[b[i]]++;
        }
    }

    for(auto& i : need){
        ok &= mp[i.fir] >= i.sec;
    }

    cout << (ok ? "YES" : "NO") << '\n';
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