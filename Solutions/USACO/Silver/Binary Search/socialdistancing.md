NO COMMENT, THE TRICKY PART IS THE TESTER FUNCTION
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

bool valid(vector<pair<ll,ll>>& a, ll d, int n){
    ll cur = a[0].fir;
    ll count = 1;
    for(int i{}; i < sz(a); i++){
        while(cur + d <= a[i].sec){
            cur = (cur+d < a[i].fir ? a[i].fir : cur+d);
            count++; 
            if (count >= n) return true;
        }
    }
    return false;
}


void solve(){ 
    int n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> a(m);
    for(auto& i : a) cin >>i.fir >> i.sec;
    
    sort(all(a));

    ll lo = 1, hi = a[m-1].sec - a[0].fir;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (valid(a, mid, n)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    cout << lo;
}
 
int main(){
    setio("socdist");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```