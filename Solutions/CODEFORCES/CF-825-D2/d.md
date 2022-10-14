```

I didn't solve it, because I was focusing on the wrong part of the problem.

I kept my focus on how to determine if the sequences can be partition into two disjoint equal subsequences.

But completely forgot about the operation!

I do aware that we'll only be doing the operation with an even number length! and the indices selected will be alternating (i.e 1 0 1 0 1 0), because it makes no sense to rotate 2 consecutive and same character! And it's not hard to see that when you performed that operation every 0 got flipped to 1 ,vice versa. 

Anyway the key idea is, it's always possible to do it if the number 1 is even!

Why?

Let us divide the sequences of 2*n length, into n pairs, such that {2*i, 2*i+1}, i <= n are together as a pair

The pair is either the same or no!

Let's declare x as the pairs that aren't the same.

It can be proven that x will always be even. Let y be the total number of 1 in the pairs that are same. So in total there will be x + 2*y 1s in the sequence and it's an even number, so x has to be even.

And with this, the answer is quite obvious now.

We have even pairs of different number, and with that operation we can flip some bits! So the idea is to simply choose 0/1 in the current pair and then choose the different one on the next pair. (flipping the bits on both the pairs to make them the same.)

So at the end we will only have equal pairs!

Then the answer is simply the odd indices of the sequences. (because every pair is the same we can either take odd/even).

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
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;

    pi cnt;
    for(auto& i : s){
        if (i == '1') cnt.sec++;
        else cnt.fir++;
    }
    if (cnt.fir % 2 || cnt.sec % 2) cout << -1 <<  '\n';
    else{
        vi change;
        int cur = 0;
        for(int i{}; i < n; i+=2){
            if (s[i] != s[i+1]) {
                if (cur){
                    if (s[i] == '1'){
                        change.pb(i);
                        s[i] = '0';
                    }else{
                        change.pb(i+1);
                        s[i+1] = '0';
                    }
                    cur = 0; 
                }else{
                    if (s[i] == '0'){
                        change.pb(i);
                        s[i] = '1';
                    }else{
                        change.pb(i+1);
                        s[i+1] = '1';
                    }
                    cur = 1; 
                }
            }
        }
        cout << sz(change) << '\n';
        for(auto& i : change) cout << i+1 << ' ';
        cout << '\n';
        for(int i{}; i < n; i+=2){
            cout << i+1 << ' ';
        }
        cout << '\n';
    }
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