
Not a hard problem, but I made an implementation-wise mistake during the contest, and was not able to solve it. I didn't know that we could return true if two elements are equal when using custom comparator. [More in here](https://codeforces.com/blog/entry/70237)
```

Basically only the last character and the first character matters.

All the intermediate letters (it's location) doesn't matter at all. We basically want to travel from first character to last character in a sorted way. For example,

Say first is 'a' and last is 'z', when this happen, we can literally jump through every character in-between (in ascending order). As the total cost of jumping between characters in asecnding order is the same if we jump from a to z.

a->z == a->b->e->f->g->....->y->z

The same goes to the reverse

z->a == z->y->x->...->b->a

so we basically just want to find the total letters that are >= first character (alphabet order) and <= last character, vice versa. And just print the order we want.

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
    string s;
    cin >> s;
 
    int n = sz(s);
 
    vi a;
    for(int i{1}; i < n-1; i++){
        if (s[0] > s[n-1]){
            if (s[i] >= s[n-1] && s[i] <= s[0]) a.pb(i);
        }else{
            if (s[i] <= s[n-1] && s[i] >= s[0]) a.pb(i);
        }
    }
 
    if (s[0] > s[n-1]){
        sort(all(a), [&](int c, int b){
            return s[b] < s[c];
        });
    }else {
       sort(all(a), [&](int c, int b){
            return s[b] > s[c];
       });
    }
 
    vi b;
    b.pb(0);
    for(auto& i : a) b.pb(i);
    b.pb(n-1);
    a = b;
    
    int cost = 0;
    for(int i{1}; i < sz(a); i++){
        cost += abs(((int)s[a[i]]) - ((int)s[a[i-1]]));
    }
    cout << cost << ' ' << sz(a) << '\n';
    for(auto& i : a) cout << i+1 << ' ';
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