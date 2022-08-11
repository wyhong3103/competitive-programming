An interesting problem that I couldn't figure out initially! I kinda have this idea on the other day , but not confidential enough to implement it, but today, I did a little testing and solved it!
```
So the idea is to build all the array at once. Instead of picking it and removing it etc etc, which would ends up in O(N^2).

How??

Well , take this array as an example

1 3 2 5 4

The answer is 

1 3 5
2 4

Now we will show how to construct it from scratch

Okay, first we need an empty multidimensional array, to store each array, and the idea is to search for the first array that has a top which is lower than the element

So in the beginning, we will have bunch of empty arrays(In my solution, I've initialized MAX arrays),

This multidimensional array is going to be the one we're going to perform binary search on.

We're going to shrink down the left pointer if the middle array's top element is bigger than our element, right pointer if the element is smaller than our element

So it goes like this, first iteration , i = 1, there's no element in any arrays, so we will put it in the first array

Current buffer

Array 1 - 1
Array 2 - .
Array 3 - .
...
.
.
.
Array MAX - .

Second iteration, i = 3

Since 1 is smaller than it , so we will simply insert 3 into the array
Current buffer

Array 1 - 1 3 (You can kinda think of it as a stack)
Array 2 - .
Array 3 - .
...
.
.
.
Array MAX - .

Third iteration, i = 2

3 on the first array is bigger than our element, so we will need to find the one that is smaller, which is the next empty array

Array 1 - 1 3
Array 2 - 2

Forth iteration, i = 5

Array 1 - 1 3 5
Array 2 - 2

Fifth iteration, i = 4

Array 1 - 1 3 5
Array 2 - 2 4
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
 

const int MAX = 2e5 + 5;
vi ans[MAX];

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    for(int i{}; i < n; i++){
        int lo = 0, hi = MAX;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (!sz(ans[mid]) || ans[mid][sz(ans[mid])-1] < a[i]){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        ans[lo].pb(a[i]);
    }

    int p1 = 0;
    while (sz(ans[p1])){
        for(auto& j : ans[p1])
            cout << j << ' ';
        cout << '\n';
        p1++;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```