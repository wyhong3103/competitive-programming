```
It is pretty obvious that the below cannot happen

1 2 1 2

(I kinda looked at the editorial, cus I have to, I do not understand what the heck the second part was talking about)

Basically we can see it as a bracket sequence!

Start and end of the letter as it's opening and closing bracket!

By using stack, we can make sure if this is a valid sequence or not!

One thing I did add is to add two 0 at both ends, bc that guarantee us 0 as the outest layer, so that the below case won't mistakenly identify as a true case.

1 0 1

The answer is simply the maximum depth of the bracket sequence.

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
using db = double;
using ldb = long double;
using pldb = pair<ldb, ldb>;
using pdb = pair<db,db>;
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

    vi a(n+2);
    for(int i{1}; i <= n; i++) cin >> a[i];

    vector<pi> at(n+1, {INT_MAX, 0});

    vi bracket(n+2, INT_MAX);
    for(int i{}; i <= n+1; i++) {
        at[a[i]].fir = min(at[a[i]].fir, i);
        at[a[i]].sec = max(at[a[i]].sec, i);
    }

    for(int i{}; i <= n; i++){
        if (at[i].fir == INT_MAX) continue;
        else if (at[i].fir == at[i].sec) bracket[at[i].fir] = -INT_MAX;
        else{
            bracket[at[i].fir] = i;
            bracket[at[i].sec] = -i;
        }
    }

    stack<int> s;

    int mx = 0;
    bool ok = 1;
    for(int i{}; i <= n+1; i++){
        if (bracket[i] == INT_MAX) continue;

        if (bracket[i] == -INT_MAX) mx = max(mx, (int)sz(s)+1);
        else if (bracket[i] >= 0) s.push(bracket[i]);
        else if (bracket[i] < 0){
            if (!s.empty() && s.top() == abs(bracket[i])){
                s.pop();
            }else ok = 0;
        }
        mx = max(mx, (int)sz(s));
    }

    if (ok){
        cout << mx-1;
    }else{
        cout << -1;
    }
}

int main(){
    setio("art2");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}



```