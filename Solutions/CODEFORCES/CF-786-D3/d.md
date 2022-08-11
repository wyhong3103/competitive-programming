This problem took me a long while to figure it out. It's about the observation and guesses. We don't have to actually move it to b then to c and check if it's sorted. We just have to check on A, there's a certain pattern that A must fulfill in order to get sorted on C. Anyways here is the solution
```
When the number of element is even,
_ _ _ _ _ _
___ ___ ___

_ = one element
___ = a group of elements

It can only be switched up between the adjacent element, which is in the same group (___), so we can just get a new array and sort it, and check if it's in the position. For example


2 1 4 3 6 5
___ ___ ___ 

Is valid

The smallest group has to be on the left most, because during the assignment to B, the last group is the group that we put in the middle which is the first one we put into C, so it has to be the smallest.

I am guessing that it's because of the even property that allow it being switch up only between one adjacent element that is in the same group, this is because when the number of element is even in b, we can always select either left element of right element and assign it to C.  

When the number of element is odd,

It's similar to even-length array, only that the first element has to be the smallest and it's non switchable, so it has to be like this

_ _ _ _ _
_ ___ ___

1 3 2 5 4

is valid

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
        int n;
        cin >> n;
        vi a(n);
        vi sorted(n);
        for(int i{}; i < n; i++){
            cin >> a[i];
            sorted[i] = a[i];
        }
 
        sort(all(sorted));
        
        bool ok = true;
        if (n % 2 == 1 && sorted[0] != a[0]){
            ok = false;
        }else{
            for(int i{n % 2}; i < n-1; i+=2){
                if (!((sorted[i] == a[i] && sorted[i+1] == a[i+1]) || (sorted[i] == a[i+1] && sorted[i+1] == a[i]))){
                    ok = false; 
                }
            }
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