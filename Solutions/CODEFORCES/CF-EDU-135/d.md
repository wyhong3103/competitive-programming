```

DP State

dp[l][r] = winning state (1 == Alice, -1 == Bob, 0 == Draw, -2 == Uninitialized)

DP Basecase

For every adjacent letters, if they're different letter then Alice will win for sure. This is because when it's 2 letter remaining, alice could choose whichever letter she wants, so she's winning for sure in that situation.

DP Transition

dp[l][r] = max(
        min(
        1, 
        (dp[l+1][r-1] == 0 ? comp(s[l], s[r]) : dp[l+1][r-1]),
        (dp[l+2][r] == 0 ? comp(s[l], s[l+1]) : dp[l+2][r])
    	),

        min(
        1, 
        (dp[l+1][r-1] == 0 ? comp(s[r], s[l]) : dp[l+1][r-1]),
        (dp[l][r-2] == 0 ? comp(s[r], s[r-1]) : dp[l][r-2])
        )
);

We played each round for both players simultaneously, this is more convinent for comparing Alice's & Bob's letter.

The idea is

If alice was to take the left character, bob could take either left or right! Vice versa.

If the result of the next round (after bob and alice have taken their letters) is a draw, then bob would choose the round that produce the most favored result for him, which is when the next is drawed, bob will compare his letter and alice's and he will take the round where he got lexicographically smaller letter. Among all of the possible round, he will choose the round that's a win for him, if there isn't any, then alice's is winning regardless.

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

int comp(char a, char b){
    //alice = a
    //bob = b
    if (a == b) return 0;
    if (a > b) return 1;
    else return -1;
}

void recur(int l, int r, auto& dp, string& s){
    if (r-l == 1){
        dp[l][r] = s[l] != s[r];
        return;
    }
    
    if (dp[l][r] != -2) return;

    recur(l+1, r-1, dp, s);
    recur(l, r-2, dp, s);
    recur(l+2, r, dp, s);

    //Take left
    dp[l][r] = min({
        1, 
        (dp[l+1][r-1] == 0 ? comp(s[l], s[r]) : dp[l+1][r-1]),
        (dp[l+2][r] == 0 ? comp(s[l], s[l+1]) : dp[l+2][r])
    });

    //Take right
    dp[l][r] = max(
            dp[l][r],
            min({
            1, 
            (dp[l+1][r-1] == 0 ? comp(s[r], s[l]) : dp[l+1][r-1]),
            (dp[l][r-2] == 0 ? comp(s[r], s[r-1]) : dp[l][r-2])
            })
    );
}


void solve(){
    string s;
    cin >> s;

    vector<vi> dp(sz(s), vi(sz(s), -2));
    recur(0, sz(s)-1, dp, s);

    if (dp[0][sz(s)-1] == 1){
        cout << "Alice" << '\n';
    }else if (dp[0][sz(s)-1] == -1){
        cout << "Bob" << '\n';
    }
    else cout << "Draw" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


```