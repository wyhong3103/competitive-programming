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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vi a(n);
        for(auto& i : a) cin >> i;
        
        int count = 0;
        int l = 0, r = n-1;
        pi weight;
        int mx = 0;
        while (l <= r){
            if (weight.sec > weight.fir){
                weight.fir += a[l];
                l++;
                count++;
            }else{
                weight.sec += a[r];
                r--;
                count++;
            }
            if (weight.fir == weight.sec){
                mx = count;
            }
        }
        cout << mx << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```