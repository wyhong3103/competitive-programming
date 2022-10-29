```cpp
#include <bits/stdc++.h>
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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    int cur = 0;
    vi pref(n);
    for(int i{}; i < n; i++){
        cur += s[i] == '0';
        pref[i] = cur;
    }

    auto valid = [&](int dist){
        for(int i{}; i < n; i++){
            if (s[i] == '0'){
                int left = (!i ? 0 : pref[i-1] - (i-dist-1 >= 0 ? (i-dist == 0 ? 0 : pref[i-dist-1]) : 0));
                int right = (i+dist >= n ? pref[n-1] - pref[i] : pref[i+dist] - pref[i]);
                if (left + right + 1 >= k+1) return true;   
            }
        }
        return false;
    };

    int lo = 1, hi = n-1;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        if (valid(mid)){
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