This problem is really straightfoward, it's literally about finding a maximum subarray with size of k, it's kinda like sliding windows. Basically just get the sum of the window using prefix sum.
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
    int n, k, b;
    cin >> n >> k >> b;

    vi a(n);
    fill(all(a),1);
    for(int i{}; i < b; i++){
        int x;
        cin >> x;
        x--;
        a[x]--;
    }
    
    vi pref(n);
    pref[0] = a[0];
    for(int i{1}; i < n; i++){
        pref[i] = pref[i-1] + a[i];
    }

    int mx = pref[k-1];
    for(int i{1}; i <= n-k; i++){
        mx = max(mx, pref[i+k-1]-pref[i-1]);
    }

    cout << k-mx;
}

int main(){
    setio("maxcross");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```