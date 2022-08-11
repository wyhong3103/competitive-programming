We're given an integer number N, we need to form an array of permutations from 1 to N-1, where the maximum of XOR of all adjacent pairs is the minimum.
```
Observation:

Let's say N = 8, the number we have are 0,1,2,3,4,5,6,7

In bits,

0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1

Notice that, if we were to apply XOR on numbers such as 4 to numbers < 4, such as 4, 2
 
	1 0 0
XOR	0 1 0
 	1 1 0 = 5

And 4 to 0

	1 0 0
XOR	0 0 0
	1 0 0 = 4


And 4 to 5

	1 0 0
XOR	1 0 1
	0 0 1 = 1

From this observation, we know that the largest bit is always unavoidable, We can XOR it with 5 or 6, we will get a smaller value, but it's adjacent pair, there will always be a number which is smaller than the largest bit be adjacent to it. 

So the key observation is that we can always place number > largest bit, after the largest bit, put a 0 before that largest bit, and the rest can be placed randomly.

For simplicty, for N = 8, 3 bits maxium, since it's 0 - 7, the best order is 

1, 2, 3, 0, 4, 5, 6, 7

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
        
        //Getting the largest bit we could get
        int largest = 1 << (int)floor(log2(n-1));
     
        for(int i{1}; i < n; i++){
            if (i == largest){
                cout << 0 << ' ';
            }
            cout << i << ' ';
        }
        cout << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```