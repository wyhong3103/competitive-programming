The tricky part about this problem is that, we know there's this lower_bound, upper_bound operation, which all gets you the pointer to the element that is greater than x, or equal to x. But there's never this operation that points to one before it, which is what we can do with binary search, but the problem arises when we're trying to remove ticket that has been used up, which will mess our binary search up. So the approach to this problem is that, we can use lower_bound , and do extra checkings on it, lower_bound is either pointing to the element that is bigger or equal to x, so if it's equal to x, we can just print x, and deduct it from the map, if the amount of x's ticket became 0, we erase it. If the value of the pointer of lower_bound is pointing to is greater than x, then we will do a pointer arithmetic , which is deduct it by 1, get the pointer before it, but we're only allowed to do that if the pointer != the beginning pointer! So that's one part we have to take into account. Also we have to check if the map has been emptied, if it's empty we cannot do those operations because it will cause an RE.

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
    int n, m;
    cin >> n >> m;

    map<int,int> ma;

    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        if (!ma.count(x)){
            ma[x] = 0;
        }
        ma[x]++;
    }

    for(int i{}; i < m; i++){
        int x;
        cin >> x;
        if (ma.empty()){
            cout << -1 << '\n';
            //if it's empty , we continue, so it doesn't evaluate the code below
            continue;
        }
        
        auto it = ma.lower_bound(x); 
        if (it == ma.begin() && it->fir > x){
            cout << -1 << '\n';
        }else{
        	// short circuit evaluation, if the first statemnet is false, we will run the second conditonal statment, which will cause our pointer to be deducted by 1
            if (it->fir == x || (--it)->fir <= x){
                cout << it->fir << '\n';
                it->sec--;    
                if (it->sec <= 0) ma.erase(it->fir);
            }else{
                cout << -1 << '\n';
            }
        }

    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```