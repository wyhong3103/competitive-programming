```
First observation, two person will only make eye contact, iff the difference between their angle is exactly 180 degree.

How do we know this?? 

If they are to lined up together, the difference between them will be 180 degree exactly.

The way the angle ie measured is based on the directon the person is looking at, which is atan2(v-y, u-x)

Now, a very important fact, we cannot deal with decimal precision, as it is too hard to compare them.

So whenever it comes to these kind of problems, it's best to deal with integer. But how?

Say if atan2(v1-y1,u1-x1) is exactly 180 degree differ with atan2(v2-y2,u2-x2), that also means

v2-y2/u2-x2 == -(v1-y1)/-(u1-x1)

Now with this we can store the fraction in pair, and to reduce each one of them to their lowest term, we could deal with that with GCD.

Also we have to becareful, directly doing GCD will scrape the negativity of a fraction. 

It's important to know that, (-1/-1)(3rd quater) != (1,1)(1st quater)

So we just have to find the Positive GCD, ignoring the negative sign.

And we can simply store the pair in hashmap, and just iterate through the array and just find the number of people that has the direction (-(v-y),-(u-x))

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


ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}

struct Person{
    ll x, y, u, v;
    
    pll dir(){
        pll temp = {(v-y), (u-x)};
        pll res = {v-y, u-x};
        res.fir /= gcd(abs(temp.fir), abs(temp.sec));
        res.sec /= gcd(abs(temp.fir), abs(temp.sec));
        return res;
    };
};

void solve(){
    int n;
    cin >> n;

    vector<Person> a(n);
    for(auto& i : a) cin >> i.x >> i.y >> i.u >> i.v;

    ll res = 0;
    map<pll,int> mp;
    for(auto& i : a){
        pll dir = i.dir();
        if (mp.count({-dir.fir,-dir.sec})){
            pll temp = {-dir.fir, -dir.sec};
            res += mp[temp];
        }
        if (!mp.count(dir)) mp[dir] = 0;
        mp[dir]++;
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