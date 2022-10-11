```

A really cool problems!

First off, in what situation 2 ballons will touch each other? It's when the distance of their radius <= sum of both radius

Notice that, we inflate the balloon from left to right, so basically, we only need to check those that has already completed on the left!

In fact, we do not even need to check all on the left, but those on a monotonic order! (Big -> Small), any smaller ballon between two big ballon should be ignored, because we will never touch that ballon before we touch the bigger ballon after it.

So the idea is simply, from L to R, try to append the current ballon to the stack, make sure it is the smallest in the stack!

First, remove the ballons on the stack that has smaller radius than us (before colliding). We can check the maximal radius we can do before collide with the ballon before, by binary searching on real number (~ 50 times with for loop anything more than that (60) will get TLE) with 1e-3 precision. If the previous ballon has bigger radius then we should just stop, (there is no way we could get to the next ballon, if we've been stopped by the previous)

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

ldb dist(pldb a, pldb b){
    return hypot(abs(a.fir-b.fir), abs(a.sec-b.sec));
}

void solve(){
    int n;
    cin >> n;

    vector<pldb> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;

    vector<ldb> res(n);

    //{loc, radius}, monotonic radius
    stack<pldb> s;
    

    for(int i{}; i < n; i++){
        ldb cur_hi = a[i].sec;
        while (!s.empty()){
            ldb lo = 0, hi = cur_hi;
            for(int j{}; j < 50; j++){
                ldb mid = lo + (hi-lo)/2; 
                if (dist(s.top(), {a[i].fir, mid}) > mid+s.top().sec) lo = mid;
                else hi = mid;
            }
            cur_hi = lo;
            if (lo > s.top().sec){
                s.pop(); 
            }else break;
        }

        res[i] = cur_hi;
        s.push({a[i].fir, cur_hi});
    }
    cout << setprecision(8) << fixed;
    for(auto& i : res) cout << i << '\n';
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