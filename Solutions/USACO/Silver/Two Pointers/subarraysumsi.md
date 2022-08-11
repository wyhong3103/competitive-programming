Solving with binary search and prefix sum
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
    cin>> n >> x;
    
    vi a(n);
    for(auto& i : a) cin >> i;

    vector<ll> prefix_sum(n);
    prefix_sum[0] = a[0];

    for(int i{1}; i < n; i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }

    int ans = 0;
    for(int i{}; i < n; i++){
        int lo = i+1, hi = n-1;
        bool found = false;
        if (a[i] == x){
            ans++;
            continue;
        }
        while (hi >= lo){
            int mid = lo + (hi-lo)/2;
            if (prefix_sum[mid] - (i == 0 ? 0 : prefix_sum[i-1]) == x){
                found = true;
                break;
            }
            else if (prefix_sum[mid] - (i == 0 ? 0 : prefix_sum[i-1]) > x){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        if (found) ans++;
    }
    cout << ans;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```

Two pointers
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

    
    int count = 0;
    int l = 0, r = 0;
    ll sm = a[0];
    while (r != n-1 || l != n-1){
        if (sm == x) count++;
        if (sm < x){
            if (r == n-1) break;
            r++;
            sm += a[r];
        }else{
            sm -= a[l];
            l++;
        }
    }
    if (sm == x) count++;
    cout << count;



}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```