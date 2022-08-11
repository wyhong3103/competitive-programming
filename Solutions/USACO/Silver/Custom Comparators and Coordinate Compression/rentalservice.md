This problem is about getting the best profit we could. I wouldn't explain this problem, but here's the link [Rental Service](http://www.usaco.org/index.php?page=viewproblem2&cpid=787).
```
The key observations for this problem is that the amount of milk of a cow can produce is only matter for the store price. For rental service, the amount doesn't matter at all. So from this observation, we can almost start with all cows being rented (of course the maximum price), and then, iterate the cows one by one, get the best price we could if we were to make the cow to produce the milk instead

It's kind of like

XXXXXXX

to

OXXXXXX

OOXXXXX

All produce the milk

Another tricky part of this problem is that, the amount of cow is not always equivalent to the number of store that want to produce the milk, and the number of rental.

So we must take care of that as well.

So the idea is basically, 

Sort all the vectors to our desired form

Get as much as we could from the rental price, it's basically min(number of rental service, number of cows), of course, we're grabbing the biggest as possible

Then we start by iterating the cows, making them to produce the milk

And just get the maximum among every single iteration
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
    int n, m, r;
    cin >> n >> m >> r;

    vi cows(n);
    vector<pi> store(m);
    vi rent(r);

    for(auto& i : cows)cin >> i;

    for(auto& i : store){
        cin >> i.fir >> i.sec;
    }

    for(auto& i : rent){
        cin >> i;
    }

    sort(all(cows), [](int a, int b){
        return a > b;
    });

    sort(all(store), [](pi a, pi b){
        return a.sec > b.sec;
    });
    
    sort(all(rent));

    ll cur = 0;
    int atrent = 0;
    //Store the pointer, for later
    //(r- min(r,n)) makes sure we don't add extra $
    for(int i{r-1}; i >= (r - min(r,n)); i--){
        cur += rent[i];
        atrent = i;
    }

    ll mx = cur;

    int atstore = 0;
    //Pointer for store
    for(int i{}; i < n; i++){
        mx = max(mx, cur);
        //Only start decreasing the rental price, if the number of cows that hasn't been set to produce milk is smaller or equal to the cow we used to rent
        if (n-(i+1) <= (r-(atrent+1))){
            cur -= rent[atrent];
            atrent++;
        }
        //While loop is used , because there are cases where a cow might still ahve remaining milk to produce, also we need to make sure there are stil available store that wants the milk
        while (cows[i] && atstore < m){
            int amt = min(cows[i], store[atstore].fir);
            cur += amt * store[atstore].sec;
            store[atstore].fir -= amt;
            cows[i] -= amt;
            if (!store[atstore].fir) atstore++;
        }
    }
    mx = max(mx, cur);
    cout << mx ;
}
 
int main(){
    setio("rental");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```