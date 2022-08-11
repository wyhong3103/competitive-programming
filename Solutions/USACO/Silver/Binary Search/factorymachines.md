Took me a while to figure out how to binary search this problem, but the idea is pretty simple indeed, it's just to test on how many items can a machine make at certain time, and sum them up, and see if they make n in time, and we simply get the smallest. Integer overflow in this problem had me going crazy!
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}


bool valid(vector<ll>& a, ll t, ll n){
    ll total = 0;
    for(auto& i : a){
        total += t/i;
        if (total >= n) return true;
    }
    return false;
}

void solve(){
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for(auto& i : a) cin >> i;

    ll lo = 1, hi = (*max_element(all(a))) * t;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;
        if (valid(a,mid,t)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    cout << lo;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```