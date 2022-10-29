This is an observation heavy problem. And obviously, I did not solve this problem on my own.
```

The idea is figuring what condition would a "beautiful" string be,

Notice that there cannot be a palindrom of length >= 2 in any where of the string

that means

aa, is considered as a palindrome
bab, is considered as a palindrome


So in order to fulfill this condition, there basically cannot be a character where s[i] == s[i-1] , and s[i] == s[i-2], and in order to fulfill this condition, we can generalise this problem to, each s[i] must be equal to s[i+3], this is because there is only 3 characters available for us.

So we would get such a string

abcabcabcabc, or any permutation of a,b,c as long as s[i] == s[i+3] and s[i] != s[i-1] , s[i] != s[i-2]

And finally, we can make a prefix sum array for the characters that needed to change for each permuation of a,b,c, and we can asnwer the query in O(1)

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

void solve(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vi> pref;

    string cur = "abc";
    do{
        vi temp(n);
        temp[0] = s[0] != cur[0];
        for(int i{1}; i < n; i++){
            temp[i] = temp[i-1] + (s[i] != cur[i%3]);
        }
        pref.pb(temp);
    }while (next_permutation(all(cur)));

    
    while(m--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        int res = INT_MAX;
        for(auto& i : pref){
            res = min(i[r]-(!l ? 0 : i[l-1]), res);
        }
        cout << res << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```