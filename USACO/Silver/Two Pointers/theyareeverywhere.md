Ad-hoc solutions? I honestly have no idea what solution is this, I just came up with this, and implemented it, the idea is basically count the last occurence of every character, then get the minimum of it. The only reason why this would work is that the number of characters from a-Z, is only 52, so I just think it's feasible to do this.

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
 

int count(map<char,int>& m){
    pi range = {numeric_limits<int>::max(), 0};
    for(auto& i : m){
        range.fir = min(range.fir, i.sec);
        range.sec = max(range.sec, i.sec);
    }
    return range.sec - range.fir + 1;
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_set<char> setofc;
    //Count the number of unique characters
    for(auto& i : s){
        setofc.insert(i); 
    }

    map<char,int> m;

    int ans = numeric_limits<int>::max();
    for(int i{}; i < n; i++){
        m[s[i]] = i; 
        if (sz(m) == sz(setofc)){
            ans = min(ans, count(m));
        }
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

