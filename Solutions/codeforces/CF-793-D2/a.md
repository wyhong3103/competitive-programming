Every palindrome has a mirrored half, and we basically have to start looking from the middle to the right and left, find the consecutive same characters.
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = 1;
        for(int i{(n/2)+1}; i < n; i++){
            if (s[i] == s[n/2]) res++;
            else break;
        }
        for(int i{(n/2)-1}; i >= 0; i--){
            if (s[i] == s[n/2]) res++;
            else break;
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