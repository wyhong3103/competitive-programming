We're given a binary string, you can swap the order, the goal is to make it non-palindrome, not even the substring. This is fairly obvious, because if there's more than 2 1's or 2 0's, it's impossible. Below shows some example
```
00000001
Impossible, there will always be 2 0s which is a palindrome

101
Impossible, even though you could make it to 110, but 11 is still a palindrome
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
        pair<int,int> count = {0,0};
        for(auto& i : s){
            if (i == '1') count.fir++;
            else count.sec++;
        }
 
        cout << (count.fir >= 2 || count.sec >= 2 ? "NO" : "YES") << '\n';
    }
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```