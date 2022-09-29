```

First, let's prove that we can go from any number to any number that is bigger and that has the same number of bit set


say we have 

0111

We can go to 1011 -> 10011 -> 100011, OR 1011 -> 1101

Now with the above proof, we know that we can literally move to any subset of the same numer of bit set, that is bigger ofc.

And let's prove that we can go to any number to any number that is bigger and has lesser bit set

Back to our previous example,

0111 -> 1000 

From 1000, we can go to any number with 1 bit set (10000, 1000000....)

Same goes to 2 bit set, basically, at any point, we can merge both bits, and then just keep on merging to bit (by moving it foward, until it bumped into another 1 in front), to a number that has lesser number of bit set.

But there is a caveat! 

Notice that everytime we move the bit, we can only move forward, but not backward, so it is only possible if at any prefix the nunmber of bit of u is bigger or equal to v's.

It turned out that we can generalize it, if v > u && bit that is set of v <= bit that is set of u && at any prefix (from 2^0 -> 2^1 -> 2^2) bit that is set of u >= v's  

Also you might be tempted to think that we can straight up find the closest number that has the same number of bits of v (i.e by merging the smallest bits to make them the same number of bits). But this is wrong, doing this in some cases, will takeaway the 1s needed at the early prefix, to generalize it, we can go to any number bigger than u with same or lesser number of bit set and at each prefix, has same or lesser 1s than u
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
    int q;
    cin >> q;

    auto possible = [](ll a, ll b){
        //make sure at any prefix, a has more 1 than b
        int cnt_a = 0;
        int cnt_b = 0;
        for(int i{}; i <= 30; i++){
            if (a & (1LL << i)){
                cnt_a++;
            }
            if (b & (1LL << i)){
                cnt_b++;
            }
            if (cnt_b > cnt_a) return false;
        }
        return true;
    };

    while(q--){
        ll a, b;
        cin >> a >> b;

        if (a > b) cout << "NO";
        else{
            ll cnt_a = __builtin_popcountll(a);
            ll cnt_b = __builtin_popcountll(b);
            if (cnt_b > cnt_a){
                cout << "NO";
            }else if (cnt_b <= cnt_a && possible(a, b)){
                cout << "YES";
            }else cout << "NO";
        }

        cout << '\n';
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