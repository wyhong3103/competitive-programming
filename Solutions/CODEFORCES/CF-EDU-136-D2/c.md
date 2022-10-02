```

For every round i, player who goes first and had the strongest card wins.

For example, in first round, if player A has card N, he won the game. (Optimally)

There's only one possibility for drawing. 


n-1 - n (A - B)
n-3 - n-2 (B - A)
n-5 - n-4 (A - B)
.
.
.
1 2 (1 go first, then 2 defends it)


Now we can imagine the deck of card in such sequence (BIG -> SMALL)


A B A B A B

any permutation of n/2 A, and n/2 B consider a sequence

Notice in the first round, if A has the first card (biggest)

A x x x x x

doesn't matter what goes next, he always win


In order to play the second round, the sequence has to be like this

B A x x x x x

In order to win the second round, it can geos like this (B's Turn)

B B A x x x x x

B B B A x x x x

.
.
.

B B B B A A A A

OR

B A B 

There has got to be a B right after an A, or there's more than 1 B (1 used to defend the first A) in the prefix before the first A

In order for to play the third round (A's Turn, again)

B A A B x x x x 

In order to win the third round

Same thing, but , ignore the first round (B A)

[B A] A A A A B x x x x

or

[B A] A B A x x x

more than 1 A before the second B, or one A right after the second B, 

these sequences guaranteed player i to win in the round.

so the idea is


for each round i (n to 1)

We need to consider two cases, first is more than 1 x before y, second is one x right after y (x is the current player's card)

Basically, we need to fixed those number of cards and then choose the remaining card from the deck.

[B A] A A A A B x x x x

We fixed 7 cards, say there is j cards of A, so we need to pick n/2 - j cards from the remainig deck (n-7), 

B A A B A x x x

We fixed 5 cards, 3 cards of A, we need to choose n/2 - 3 from (n-5)

For the first case, we kind of need a loop for that, to get cases where there is i+1 more x before the targeted y, until we run out of cards (i+1+previous cards reached n/2) 

This is basically the solution.

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
 
 
const int MOD = 998244353;
long long C[100][1000];
 
void build_pascal(){
    for(int i{}; i < 100; i++){
        for(int j{}; j < 1000; j++){
            if (i == 0){
                C[i][j] = 1;
                break;
            }else{
                C[i][j] = (j == 0 ? 1 : (C[i-1][j] + C[i-1][j-1]) % MOD);
            }
        }
    }
}
 
void solve(){
    int n;
    cin >> n;
    
    pll ans{0,0};
    for(int i{}; i < n/2; i++){
        if (i){
            for(int j{1}; j <= (n/2)-(i); j++){
                if (i % 2){
                    ans.sec = (ans.sec + C[n-((i-1)*2)-(j+2)][(n/2)-(i+j)]) % MOD;
                }else{
                    ans.fir = (ans.fir + C[n-((i-1)*2)-(j+2)][(n/2)-(i+j)]) % MOD;
                }
            }
        }
        if (i % 2){
            ans.sec = (ans.sec + C[n-(i*2)-1][(n/2)-i-1]) % MOD;
        }else{
            ans.fir = (ans.fir + C[n-(i*2)-1][(n/2)-i-1]) % MOD;
        }
    }
    cout << ans.fir << ' ' << ans.sec << ' ' << 1 << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    build_pascal();
    while(t--){
        solve();
    }
    return 0;
}
```