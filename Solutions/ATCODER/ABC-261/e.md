Took a little inspiration from the editorial.
```
Basically the idea is to deal with the bit independently, and note that it's a composite function.

The idea is that for each bit, the only possible input/output is 0 and 1, so we can create function dummy bit at first, and then do the corresponding operation & coresponding bit on the function dummy bit. And if the current bit is 0 and then we point to dummy 0 bit's answer, if current bit is 1 we point to the dummy 1 bit's answer.

C = 10

3 3
2 5
1 12

Take this for example, let's start with the first bit (rightmost)

function = [0,1] ---first operation - XOR 1 (because rightmost bit in 3 is 1)---> [1,0] ---second op - OR 1---> [1,1] ---third op - AND 0 ---> [0,0]

Before first oeration, our bit is 1, so we take the answer after XOR operation at index 1, which is 0, 

After first operation, our current answer is 0, so for the second op, we take the answer after second op at index 0, which is 1

The same thing goes on until we finish the operations.


###Other notable thing

Things to take note here is to take care of integer overflow, and the way we reset the bit and set the bit.

If we are going to AND long long, a & b, a and b both have to be long long, or else undefined behaviour

TO set a bit , simply OR the i-th bit

To reset a bit, (to 0), AND NOT(i-th bit as 1)

```
Explanation i guess
```

The reason we could do this is because of the fact that whatever operations we do, the bit is just 1 and 0,

fi(...f3(f2(f1(x))))

Basically, the composite function, show us the possible result after i-th operation on initial 0 and 1 indexed bit. Whatever answer we got from i-th operation,it's just as if we doing the same operation again from the 0/1 bit. That's the reason we could do that.

It's a bit unclear I get it. Need time to digest it.
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
 
void solve(){
    ll n, c;
    cin >> n >> c;
 
    vector<pll> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    vll ans(n+1);
    ans[0] = c;
    
    for(ll i{}; i <= 32; i++){
        pi func = {0, 1};
        for(ll j{}; j < n; j++){
            ll one = (ll)1;
            if (a[j].fir == 1){
                func.fir &= (a[j].sec >> i) & one;
                func.sec &= (a[j].sec >> i) & one;
            }else if (a[j].fir == 2){
                func.fir |= (a[j].sec >> i) & one;
                func.sec |= (a[j].sec >> i) & one;
            }else{
                func.fir ^= (a[j].sec >> i) & one;
                func.sec ^= (a[j].sec >> i) & one;
            }
 
            ll res = ((ans[j] >> i) & one ? func.sec : func.fir);
 
            if (res){
                ans[j] |= (res << i);
                ans[j+1] |= (res << i);
            }
            else{
                ans[j] &= ~(one << i);
                ans[j+1] &= ~(one << i);
            }
        }
    }
 
    for(int i{}; i < n; i++) cout << ans[i] << '\n';
 
 
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