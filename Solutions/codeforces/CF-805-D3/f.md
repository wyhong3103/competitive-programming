Literally a greedy problem. But quite tricky tho.
```
Anyway, the idea is to size all element of a & b into an odd base

We cannot ruin the odd property of a & b , because it's impossible to go from even to odd, only odd can go odd, and only by division. 

5
2 2 4 4 4
28 46 62 71 98

take this case for example, size them all down to odd base

1 1 1 1 1
7 23 31 71 49

Our goal is to literally make all b equal to a, as long as they got the same base that means it's a yes.

And this is a pretty obvious case, as we can just divide all b by 2, and eventually size them all down to 1.

2 4 5 24

1 4 6 11

Let's take a look at this case

1 1 5 3
1 1 3 11

1 1 3 cancel out each other, so what do we do with 5 and 11?

We will try to divide 11 until we make it into 5, if it's impossible, then it's a NO.

So the greedy goes like this, from smaller element in b to the bigger ones, if the value doesn't exist in a, we floor divide it by 2, until we find one, if we hit 0, then that's a NO. Meanwhile, keep track of what element we already have and what we don't.
```
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n;
    cin >> n;
    
    map<int,int> a;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        while (!(x%2)){
            x /= 2;
        }
        if (!a.count(x)) a[x] = 0;
        a[x]++;
    }

    map<int,int> b;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        while (!(x%2)){
            x /= 2; 
        }
        if (!b.count(x)) b[x] = 0;
        b[x]++;
    }


    auto it = b.begin();
    while (it != b.end()){
        while (true){
            int val = it->fir;
            while (!(a.count(val)) && val){
                val /= 2; 
            }
            if (!val){
                it++;
                break;
            }
            a[val]--;
            if (!a[val]) a.erase(val);
            it->sec--;
            if (!it->sec){
                int temp = it->fir;
                it++;
                b.erase(temp);
                break;
            }
        }
    }

    cout << (!sz(a) && !sz(b) ? "YES" : "NO") << '\n';
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