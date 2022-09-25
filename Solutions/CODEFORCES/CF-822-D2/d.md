```

Do two pointers.

Starting from both L & R, keep absorbing the slime, until either you got a positive delta or a negative delta on your overall health.

If both side you got negative delta, that means it's impossible to get out, bc it doesn't whether where you go, your health will be lesser than original, and there is no way you could get out with positive health. A simple fact, you got i health initially, but now you got j, i > j, you can't get out with i, how can you get out with j?

And if one of the side has positive delta, then you should definitely take it, because it's always optimal, to take a positive side. Ofc, if both side has positive delta, take the bigger one. It is optimal to do that.

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
    int n, k;
    cin >> n >> k;
    k--;

    vll a(n);
    for(auto& i : a) cin >> i;

    bool ok = 1;
    pll val{0, 0};
    int l = k-1, r = k+1;
    ll cur = a[k];
    while (l >= 0 && r < n){
        bool reach = 0;

        if (val.sec < 0) val.sec -= a[r];
        ll temp = cur+val.sec;
        for(int i{r}; i < n; i++){
            if (val.sec > 0) break;
            temp += a[r];
            val.sec += a[r];
            if (temp >= 0 && r == n-1) reach = 1;
            if (temp >= 0){
                r++;
            }else break;
        }
        if (reach) break;

        if (val.fir < 0) val.fir -= a[l];
        temp = cur+val.fir;
        for(int i{l}; i >= 0; i--){
            if (val.fir > 0) break;
            temp += a[l];
            val.fir += a[l];
            if (temp >= 0 && l == 0) reach = 1;
            if (temp >= 0){
                l--;
            }else break;
        }
        if (reach) break;

        if (val.fir >= 0 && val.sec >= 0){
            if (val.fir > val.sec){
                cur += val.fir;
                val.fir = 0;
            }else{
                cur += val.sec;
                val.sec = 0;
            }
        }else if (val.fir >= 0){
            cur += val.fir;
            val.fir = 0;
        }else if (val.sec >= 0){
            cur += val.sec;
            val.sec = 0;
        }else {
            ok = 0;
            break;
        }
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