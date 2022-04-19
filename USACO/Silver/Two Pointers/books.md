Mistakes made:
- Assumed the first element is always going to be included , which is apparently not
- Messed up the sequence a little bit
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


void solve(){
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for(auto& i : a) cin >> i;
    
    int r = 0, l = 0;
    pi sm = {};
    int mx = 0;
    while(r < n){
        mx = max(mx, sm.fir);
        if (sm.sec + a[r] <= x){
            sm.sec += a[r];
            r++;
            sm.fir++;
        }else{
            sm.sec -= a[l];
            sm.fir--;
            l++;
        }
    }
    mx = max(mx, sm.fir);
    cout << mx;
}
    



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```