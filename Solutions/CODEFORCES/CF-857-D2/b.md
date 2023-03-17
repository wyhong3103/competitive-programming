```

Everytime we examine with doctor, we can assume we reorganize every pigs before including those hasve already been examined.

Everytime we examine with doctor, if the current number of pigs we have is an even number.

Then, we will always assume the worse case scenario, where we have 1 + (pigs -2 / 2) male and the same for female.

(*WORST CASE SCENARIO!!!)

For odd number, worse case scenario is when we just have an odd number of males/femal and an even number of the other.

So the number of cage we need is simply ceil(pigs/2)


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
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    int total = 0;
    int remain = 0;
    int pigs = 0;
    for(int i{}; i < n; i++){
        if (a[i] == 1){
            if (!remain) total++;
            else remain--;
            pigs++;
        }else{
            if (pigs) remain = total - (pigs % 2 ? pigs/2 + (pigs % 2) : (pigs-2)/2 + 2);
        }
    }
    cout << total << '\n';
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