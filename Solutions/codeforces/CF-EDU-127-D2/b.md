It's only possible to do it , if the number of times where adjacent elements which has a difference of 2 is <= 2 / the number of times where the difference of adjacnet element is 3 , is == 1. Notice that , we cannot have both of these at the same time. Figured it out through expriments.
```
Cases such as

-----
1 3 5

Possible

2 3 4

-------
1 3 5 7

Impossible

Best we could do = 2 3 4 6
-------

1 4

Possible

2 3 

--------

1 4 6

Impossible

2 3 5
```

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
 
        bool ok = true;
        pi count{};
        for(int i{1}; i < n; i++){
            if (a[i] - a[i-1] > 3){
                ok = false;
                break;
            }
            else if (a[i] - a[i-1] == 3){
                count.fir++;
                if (count.fir == 2 || count.sec){
                    ok = false;
                    break;
                }
            }else if (a[i] - a[i-1] == 2){
                count.sec++;
                if (count.fir || count.sec > 2){
                    ok = false;
                    break;
                }
            }
        }
 
        if (ok) cout << "YES";
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