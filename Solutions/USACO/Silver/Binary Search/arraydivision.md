The idea is to basically find the maximum number for a box. A few things that we need to take note of are integer overflow, and some special cases. 
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


bool valid(vi& a, ll lim, int k){
    ll cur = 0;
    ll count = 0;
    for(auto& i : a){
        if (i > lim) return false;
        //If i > lim, this limit simply cannot be used, so we need a new one
        if (cur + i <= lim){
            cur += i; 
        }else{
            cur = i;
            count++;
        }
    }
    if (cur) count++;
    return (count <= k);
}


void solve(){
    int n, k;
    cin >> n >> k;
    
    ll total = 0;

    vi a(n);
    for(auto& i : a){
        cin >> i;
        total+=i;
    }


    ll lo = 1, hi = total;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;
        if (valid(a, mid, k)){
            hi = mid;
        }else{
            lo = mid +1;
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