```
If n is odd, then we leave one odd element be 0


Notice that, in order for XOR of every odd-indexed & even-indexed elements to be the same, the parity on each bit have to be the same.

And every numbers have to be distinct. And it has to be < 2^31

So the idea is

Have every odd & even elements be the same number, and then simply let even/odd number's large bit that will never get used be 1. So that every numbers differ.

But here comes a tiny problem.

If the number of even/odd-indexed numbers is an odd number. That large bit will become an extra bit, and the numbers won't be the same. So in order for it to be the same, we can let the large bit in the opposite parity-indexed number be 1. Although it would still collide (non-distinct). But right now, we can simply pick 2 numbers (including the one that selected), add an even larger bit so that it cancelled out each other and it's different.


0001
0010
0011

1001
1010
1011

XOR of second group have an extra 2^4,


1001
0010
0011

We can simply let any element (for the sake of convinent, we will just use the first element), to have 2^4 = 1, so right now there's 2 ,1001.

Now simply pick 2 numbers on any parity, but including the non-distinct number,

11001
10010
00011

Add ones to them, because it's even number of bits so it got cancelled out.

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
    int cnt = 1;
    for(int i{}; i < n-(n%2); i+=2){
        a[i] = cnt++;
    }
    cnt = 1;
    for(int i{1}; i < n; i+=2){
        a[i] = cnt++;
    }
 
    for(int i{1}; i < n; i+=2){
        a[i] |= 1 << 29;
    }
    if (n % 2 && (n/2) % 2){
        a[n-1] |= 1 << 29;
    }else if (n % 2 == 0 && (n/2) % 2){
        a[0] |= 1 << 29;
        a[1] |= 1 << 30;
        a[3] |= 1 << 30;
    }
 
    for(auto& i : a) cout << i << ' ';
    cout << '\n';
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