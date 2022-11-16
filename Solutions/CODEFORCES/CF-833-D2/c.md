```

By choosing a 0 on the left, and by doing some operation on it, we're essentially adding some values to all the prefix sum on the right!

For each 0, it makes sense to gain better score by making some of the prefix on the right = 0, but we need to be careful with this. Everytime we do such an operation, we might affect what's on the right!

For example,

  0           0
2 2 0 0 0 0 1 1 1 1 1

Say we have two 0 at the position above, the optimal move is to do nothing on the first zero, and change the second zero into -1.

So apparently, greedy doesn't work as well! It could get really complicated if we are to greedy on every zero by choosing the one that gives the most gain, because each time we change one zero we could affect everything on the right, including the zero on the right!

Main observation : Doing an operation on a 0 affects everything on the right (altogether), sometime, it might be better to only do the operation at latter 0! That means there are prefix sum on the right that could be affected by multiple zeros! If we are to only deal with number between two zeros for the zero on the left, it would be much better, bc whatever we deal within that range, won't really affect what comes after the range! So basically, the idea is to pick whatever prefix sum that is most frequent between two zeros, by choosing those we won't affect what comes after the second zero, which could be dealt with later!

(Bad explanation, but you got what i mean, only deal with the number that the zero is responsible for, because the latter prefix sums could be dealt with latter 0)

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
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    map<ll, int> freq;
    //freq val
    pll bst{};
    ll res = 0;
    bool in = 0;
    ll cur = 0;
    for(int i{}; i < n; i++){
        if (a[i] == 0) in = 1;
        cur += a[i];
 
        if (!in && cur == 0) res++;
 
        if (a[i] == 0){
            cur -= bst.sec;
            res += bst.fir; 
            freq.clear();
            bst = {};
        }
        if (in){
            freq[cur]++;
            if (freq[cur] >= bst.fir){
                bst = {freq[cur], cur};
            }
        }
    }
    if (in){
        res += bst.fir; 
    }
    cout << res << '\n';
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