C is essentially about flatten all the elment first and then increase them altogether.
```
Through trial and error, we found out that it's always optimal to lower the elements starting from the minimal element.

For example

We need a variable for total subtraction for left and right, and total for answer

-4 2 3 1

First we size down 2 to -4

subtraction = {0, 6}, total = 6

-4 2-6 3-6 1-6

-4 -4 -3 -5

-3 to -3

subtraction = {0, 6+1} total = 6+1
-4 -4 -3-1 -5-1

-4 -4 -4 -6

But now we have an even smaller element which is -6, so we will size down all the element on it's right

subtraction = {2,7} ,total = 9 

-4-2 -4-2 -4-2 -6

And finally we have

-6 -6 -6 -6

And now we simply need to increase them by 6 altogether, and that's the final answer


But what if the minimal element is in the middle, we can start from either left or right, and we have to subtract the each element according to the current subtract count, there could be subtraction count that is inherited from the left operation/right operation. Through trial and error(again), I found out that starting from left/right spits different answer, so we have to choose the minimal of it.
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
using pdb = pair<double,double>;
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

        pair<int, ll> mn_t = {-1, INT_MAX};
        vector<ll> a(n);
        for(int i{}; i < n; i++){
            cin >> a[i];
            if (a[i] < mn_t.sec){
                mn_t.fir = i;
                mn_t.sec = a[i];
            }
        }

        vector<ll> b = a;

        //starting from left first
        pair<int,ll> mn = mn_t;
        pair<ll,ll> sub1 = {};
        ll res1 = 0;
        for(int i{mn.fir+1}; i < n; i++){
            a[i] -= sub1.sec;
            if (a[i] < mn.sec){
                res1 += mn.sec - a[i];
                sub1.fir += mn.sec - a[i];
                mn.sec = a[i];
            }
            res1 += a[i]-mn.sec;
            sub1.sec += a[i]-mn.sec;
        }

        for(int i{mn.fir-1}; i >= 0; i--){
            a[i] -= sub1.fir;
            if (a[i] < mn.sec){
                res1 += mn.sec - a[i];
                mn.sec = a[i];
            }
            res1 += a[i]-mn.sec;
            sub1.fir += a[i]-mn.sec;
        }

        //starting from left first
        mn = mn_t;
        pair<ll,ll> sub2 = {};
        ll res2 = 0;
        for(int i{mn.fir-1}; i >= 0; i--){
            b[i] -= sub2.fir;
            if (b[i] < mn.sec){
                res2 += mn.sec - b[i];
                sub2.sec += mn.sec - b[i];
                mn.sec = b[i];
            }
            res2 += b[i]-mn.sec;
            sub2.fir += b[i]-mn.sec;
        }
        
        for(int i{mn.fir+1}; i < n; i++){
            b[i] -= sub2.sec;
            if (b[i] < mn.sec){
                res2 += mn.sec - b[i];
                mn.sec = b[i];
            }
            res2 += b[i]-mn.sec;
            sub2.sec += b[i]-mn.sec;
        }

        cout << min(res2, res1) + abs(mn.sec) << '\n';

    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```