Working solution, but MLE + TLE.
12+ seconds to compute worst possible case.
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MXN = 1e5;
const int MXP = 7;

//{strength, selected}
pair<ll,vi> dp[1 << MXP][MXN];

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    
    vector<pair<int,vi>> members(n);

    for(int i{}; i < n; i++){
        cin >> members[i].fir;
    }

    for(int i{}; i < n; i++){
        members[i].sec.resize(p);
        for(int j{}; j < p; j++){
            cin >> members[i].sec[j];
        }
    }
    
    sort(all(members), [](auto& a, auto& b){
        return a.fir > b.fir;
    });


    ll initial = 0;
    for(int i{}; i < k; i++){
        initial += members[i].fir;
    }
    
    for(int i{1}; i < (1 << p); i++){
        //starts from number of 1 used
        int bit_count = __builtin_popcount(i);
        for(int j{bit_count-1}; j < n; j++){
            for(int l{}; l < p; l++){
                if (i & (1 << l)){
                    ll cur_strength = initial;
                    ll k_need = 0;
                    
                    vi prev;
                    if (bit_count > 1){
                        prev = dp[i ^ (1 << l)][j-1].sec;
                    }else{
                        prev.resize(p);
                        fill(all(prev), -1);
                    }
                    prev[l] = j;

                    set<int> used;
                    for(int m{}; m < p; m++){
                        if (prev[m] == -1) continue;

                        if (prev[m] < k){
                            k_need++;
                            cur_strength -= members[prev[m]].fir;
                            used.insert(prev[m]);
                        }
                        cur_strength += members[prev[m]].sec[m];
                    }

                    int at = k;
                    while (k_need){
                        if (!used.count(at)){
                            cur_strength += members[at].fir;
                            k_need--;
                        }
                        at++;
                    }

                    if (cur_strength > dp[i][j].fir){
                        dp[i][j].fir = cur_strength;
                        dp[i][j].sec = prev;
                    }
                    //if j >= 1, refer to j-1
                    if (j >= 1 && dp[i][j-1].fir > dp[i][j].fir){
                        dp[i][j].fir = dp[i][j-1].fir;
                        dp[i][j].sec = dp[i][j-1].sec;
                    }
                }
            }
        }
    }

    cout << dp[(1 << p)-1][n-1].fir;
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

AC, finally!
```
Almost the same idea with the first solution, but with a smarter way to calculate strength for k.

Anyways, let's forget about the audience part first, and let's try to figure out how to calculate the best strength we could get for a team, such that a team must be formed from the n people.

Normally, we would encounter a problem to count such a thing, but n is equal to the length of the subset. This question is different, instead of having the same size, we have a relatively small size for the subset and a much greater size for n.

The idea is almost the same, but for each transition instead of only considering the i-th person, such that the i-th person is the number of bits, we need to consider from the i-th person to the n-th person, as the lower bound for a team of i person is first i people, but j-th person, (j > i) could also be in the team.

That leads us to the transition below.

dp[s][i] = max(dp[s][i], dp[s^(1 << j)][i-1] + val[i][j], dp[s][i-1]), number of 1 in the subset-1 <= i < n

In short, either we take the j-th person, or we don't, or we remain taking the k-th person (j >= number of bits, number of bits <= k < j)

Now to consider the audience.

Our initial approach is to literally keep track of every person we used for each dp[s][i], so that the strength is simply greatest k-th audience, excluding the i-th person used as a position in a team

While that works, but it's very slow, and make our program very memory inefficient

##########################################################################################

Now comes the observation/solution to this problem.

Note that instead of storing the entire array used, we could instead store the last person used. And before that we need to sort the members array, from greatest k to smallest k, (k = audience strength), so that the below would work.

For each dp[s][i]'s transition from dp[s^(1<<j)][i-1], if the last person used on dp[s^(1<<j)][i-1] is >= i, that means (the last person or i-th person) is used in the audience strength, (because only the person that is before i or equal to i, is used in the team) in order to use it in this transition, we can subtract the last person's audience strength from the strength of dp[s][i-1], and because of that, our audience is lack of one person, so we simply need to add (last person+1)-th audience strength and set the new last person as last person+1. And then simply add i-th person strength as position j, to the new strength.

By doing this, we got our new strength, and we can simply do the rest of the transition.

Although I couldn't prove it yet, there seems to be some flaws behind this solution, but surprisingly, it worked just fine.

##########################################################################################

Visualization, I guess

Say we got 7 members, and k = 3, p = 2

initially, when s = 0 (empty team)

o o o x x x x

o = audience, x = not selected

The first 3 members are selected as an audience.

Starting from the first s, s = 001

The first member (i = 0) will now be considered into the team, and the last person used in (001 ^ 001 = 000)has the index 2 (first 3 were used as an audience). So we will have consider the next one as an audience and the first one as the team member.

p o o o x x x

p = team member

This guaranteed the optimal answer, because members were sorted in a non-increasing order according to their audience strength.

Each dp value is the optimal value that is with k audience exactly, and p team members exactly (p = number of bits that are 1)
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


const int MXP = 7;
const int MXN = 1e5;
pll dp[1 << MXP][MXN];

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    
    vector<pair<int,vi>> members(n);

    for(int i{}; i < n; i++){
        cin >> members[i].fir;
    }

    for(int i{}; i < n; i++){
        members[i].sec.resize(p);
        for(int j{}; j < p; j++){
            cin >> members[i].sec[j];
        }
    }
    
    sort(all(members), [](auto& a, auto& b){
        return a.fir > b.fir;
    }); 

    
    ll initial = 0;
    for(int i{}; i < k; i++){
        initial += members[i].fir;
    }
    

    for(int s{1}; s < (1 << p); s++){
        int bit_count = __builtin_popcount(s);
        for(int i{bit_count-1}; i < n; i++){
            for(int j{}; j < p; j++){
                if (s & (1 << j)){
                    pll state = dp[s][i];
                    if (bit_count > 1){
                        state = dp[s ^ (1 << j)][i-1];
                    }else{
                        state = {initial,k-1};
                    }
                    
                    if (state.sec >= i){
                        state.fir -= members[i].fir;
                        state.fir += members[state.sec+1].fir;
                        state.sec++;
                    }

                    state.fir += members[i].sec[j];
                    state.sec = max(state.sec, (ll)i);

                    if (state.fir > dp[s][i].fir) dp[s][i] = state;

                    if (i >= 1 && dp[s][i-1].fir > dp[s][i].fir){
                        dp[s][i] = dp[s][i-1];
                    }
                }
            }
        }
    }

    
    cout << dp[(1<<p)-1][n-1].fir;
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
A more intuitive solution, i guess, from the editorial. [Editorial](https://codeforces.com/blog/entry/74493).
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


const int MXP = 7;
const int MXN = 1e5+5;
ll dp[MXN][1 << MXP];

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    
    vector<pair<int,vi>> members(n);

    for(int i{}; i < n; i++){
        cin >> members[i].fir;
    }

    for(int i{}; i < n; i++){
        members[i].sec.resize(p);
        for(int j{}; j < p; j++){
            cin >> members[i].sec[j];
        }
    }
    
    sort(all(members), [](auto& a, auto& b){
        return a.fir > b.fir;
    }); 

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i{1}; i <= n; i++){
        for(int mask{}; mask < (1 << p); mask++){
            //there is still remaining audience space, if i-bitcount < k
            int c = (i-1)-(__builtin_popcount(mask));
            if (c < k){
                if (dp[i-1][mask] != -1){
                    dp[i][mask] = dp[i-1][mask] + members[i-1].fir;
                }
            }else{
                if (dp[i-1][mask] != -1){
                    dp[i][mask] = dp[i-1][mask];
                }

            }

            for(int j{}; j < p; j++){
                if ((mask & (1 << j)) && dp[i-1][mask ^ (1 << j)] != -1){
                    ll temp = dp[i-1][mask ^ (1 << j)] + members[i-1].sec[j];
                    if (temp > dp[i][mask]) dp[i][mask] = temp;
                }
            }
        }
    }

    cout << dp[n][(1 << p)-1];
    
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