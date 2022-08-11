A very standard 2 pointers problem.
```cpp
include <bits/stdc++.h>
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
        int n, s;
        cin >> n >> s;
 
        vi a(n);
        for(auto& i : a) cin >> i;
 
        int p1 = 0, p2 = 0;
        int res = INT_MAX;
        int cur = 0;
        while (p2 < n){
            if (cur + a[p2] <= s){
                cur += a[p2];
                if (cur == s){
                    res = min(res, n-(p2-p1+1));
                }
                p2++;
            }else{
                cur -= a[p1];
                p1++;
            }
        }
 
        cout << (res == INT_MAX ? -1 : res) << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```