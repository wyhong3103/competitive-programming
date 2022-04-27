Prefix sum basically. Took me a while to figure out the solution.
```
Say the test case is

3 7
2 1 2

First we can sort it

1 2 2 

Then we prefix sum it

1 3 5

Notice that, 1 is the amount of money we need to buy 1 pack of sugar, 3 is the amount we need for 2, 5 is the amount we need for 3

So through experimenting , I found out that we can do this,

So we always prioritize, element on the right, because it got us the most sugar 

1 3 5

For 5, we could only do it for 1 day, because the next day the price would become 8, (5 + 3), 3 because 3 pack of sugars

There's a way to find how many days can we keep buying the same amount of sugar, before it reaches out of the budgets, which is

prefix[i] + (i * number of days) = budget

Floor of number of days is the number of days we could keep buying it

So we simply need to use the number of days * i, which is the number of pack of sugars.

And iterate through the next element, before we do anything to it, we need to do prefix[i] * days, because of the days that we bought sugars previously, we need to make sure the amount is up to date. And we do the same thing
```
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){ 
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;

        vector<ll> a(n);
        for(auto& i : a) cin >> i;

        sort(all(a));
        
        for(int i{1}; i < n; i++){
            a[i] = a[i-1] + a[i];
        }
       
        ll ans = 0;
        ll day = 0;
        for(int i{n-1}; i >= 0; i--){
            a[i] += (i+1) * day;
            if (a[i] <= x){
                ll days_able = ((x - a[i])/(i+1))+1;
                ans += days_able * (i+1);
                day += days_able;
            }
        }

        cout << ans << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```