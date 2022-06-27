We could literally greedy on this problem. Maybe this is not the intended solution, because it seems way too simple.
```

Anyways, the main observation is

- We could only swap each i once, because everytime we swapped i , we're going to get a bigger value, so there's no way we're able to use that position again
- Because we could only swap each position once, so it make sense to literally just put x to where it belongs on the array, because if we don't we would never get it sorted, that's the locally optimal choice we can make. If at the end, we don't get a sorted array then ans = -1

```
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
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

bool issorted(vi& a){
    for(int i{1}; i < sz(a); i++){
        if (a[i] < a[i-1]) return false;
    }
    return true;
}

void solve(){
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    int mx = 0;
    for(int i{}; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int cnt = 0;
    while (!issorted(a) && !(x >= mx)){
        for(int i{}; i < n; i++){
            if (a[i] > x){
                swap(a[i], x);
                break;
            }
        }
        cnt++;
    }


    cout << (issorted(a) ? cnt : -1) << '\n';
    return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```