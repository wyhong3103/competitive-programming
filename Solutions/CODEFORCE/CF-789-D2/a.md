Standard two pointers problem.
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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
 
        string a, b;
        cin >> a >> b;
 
        sort(all(a));
        sort(all(b));
 
        string res = "";
        int p1 = 0, p2 = 0;
        pi cnt{a[p1] > b[p2],1};
        res += (a[p1] > b[p2] ? b[p2++] : a[p1++]);
        while (p1 < n && p2 < m){
            if (a[p1] < b[p2] && !(cnt.fir == 0 && cnt.sec == k)){
                res += a[p1];
                p1++;
                if (cnt.fir != 0) cnt = {0,0};
                cnt.sec++;
            }else if (a[p1] >= b[p2] && !(cnt.fir == 1 && cnt.sec == k)){
                res += b[p2];
                p2++;
                if (cnt.fir != 1) cnt = {1,0};
                cnt.sec++;
            }else{
                if (cnt.fir == 0 && cnt.sec == k){
                    res += b[p2];
                    p2++;
                    cnt = {1, 1};
                }
                else{
                    res += a[p1];
                    p1++;
                    cnt = {0,1};
                }
            }
        }
        cout << res << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```