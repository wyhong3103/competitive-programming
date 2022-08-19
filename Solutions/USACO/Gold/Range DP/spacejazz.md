```

So we're given a string, and we are to find the number of missing letters in that string.

A string is only valid iff, in each insertion of letters, each letter is inserted twice & adjacent to each other.

N <= 500, which signaled us that this could be O(N^3) algorithm


So we're going to perform Range DP on the subarray to solve this problem.


dp[l,r] = the minimum letters left out in subarray [l,r]
dp transition = 

for each character from l to r, 
	if (s[l] == s[j] and l != j)
		dp[l][j] = min(dp[l][j], dp[l+1][j-1] + dp[j+1][r])
	else
		dp[l][j] = min(dp[l][j], dp[l][j] + dp[j+1][r])

Base case is dp[i][i] = 1, as every one character left out another character,

DP order is from smaller size of subarray to the bigger subarray, this is to ensure the dp state we need during ever state has already been processed.

If the characters are the same, we can simply pair them up, and if we are to pair them up, we just have to consider the subarray between them and the outer one. We only need to match it with s[l], the reason is that only with s[l], we do not repeat some dp transitions & states. You might be tempted to pair up every character in that subarray but that is unnecessary, say you want to match s[l+1] and s[r-1], notice that this subarray has already been processed, so there is no need.

If the characters do not match up, then just simply split the subarray into half and combine them at that point.

Notable Things
- There is no need to worry about accesing a dp state such that dp[i,j] i > j, because it's just simply 0
- Greedy doesn't work, so we have to do DP.
```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    string s;
    cin >> s;

    //Allocated one more index for the end, to avoid accesing index that is out of the array causing RE
    vector<vi> dp(sz(s)+1, vi (sz(s)+1));
    for(int i{}; i < sz(s); i++) dp[i][i] = 1;

    for(int i{2}; i <= sz(s); i++){
        for(int j{}; j <= sz(s)-i; j++){
            dp[j][j+i-1] = INT_MAX;
            for(int k{j}; k < j+i; k++){
                if (j != k && s[j] == s[k]){
                    dp[j][j+i-1] = min(dp[j][j+i-1], dp[j+1][k-1] + dp[k+1][j+i-1]);
                }else{
                    dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1]);
                }
            }
        } 
    }

    cout << dp[0][sz(s)-1];
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