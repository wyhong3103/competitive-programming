Kind of solved this problem with lucks, apparently it's impossible to make every element the same, if you cannot do it with just one operation. 
```
Now let's talk about some proof, if we have 

4
4 3 2 1

If we mask the first element

4 5/3 5/3 5/3

Second element

7/3 3 7/3 7/3

Third element

8/3 3 8/3 8/3

Last element

9/3 9/3 9/3 1

Notice that, if you mask the same element again , you're going to get the same value.

And if you decided to mask the different element, (after first operation), it's impossible to make all element equal, the reason is that

For eaxmple 

9/3 9/3 9/3 1

3 3 3 1

if you chose 3 on the second operation, notice that it's impossible to make all element equal to 3, because you already have n-2 of 3s and in order to make all element equal to 3, the 1 has to be 3 as well, which if it's a three it would've been it in the first operation, but it's not.
```
```cpp
#include <bits/stdc++.h>
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
        int n;
        cin >> n;
    
        int total = 0;
 
        vi a(n);
        for(auto& i : a){
            cin >> i;
            total += i;
        }
 
        bool ok = 0;
        for(auto& i : a){
            double mean = (total-i)/(double)(n-1);
            if (abs(mean - i) < EPS) ok = 1;
        }
 
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}

```