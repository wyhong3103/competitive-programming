Okay this is a pretty straightfoward problem, all you need to do is make sure the number of chairs is enough, and order does matter! So the idea is to basically sort it, for optimal arrangement, and make sure the overlapping chairs between people, is always the biggest between them, and sum them up. And if the sum > m, then it's impossible, one key point is that the last chair has to overlap with the first chair, so we will have to take care of the case as well.
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
        int n, m;
        cin >> n >> m;
        
        vi a(n);
        for(auto& i : a) cin >> i;
        
        sort(all(a));
        
        int prev = a[0];
        ll total = 0;
        for(int i{0}; i < n; i++){
            total += prev; 
            total++;
            if (i != n-1){
                prev = max(a[i+1], a[i]);
            }else{
                //last chair connects up with the first chair
                total += a[n-1] - a[0];
            }
        }
        if (total <= m) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```