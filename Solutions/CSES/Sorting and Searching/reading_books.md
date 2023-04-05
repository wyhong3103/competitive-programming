```

Greedy

Sort the book in reading time


If the longest reading book is greater than all other book combined, total time to read is total reading time + diff of longest reading and every other book

else just total reading time


Proof for second case:

Let's have two array, these two array needs to consist of every books.

Let the first array to have every books in order.

The second array can start from the last book, and then the first book to the second to last book.

This would guarantee them to not read the same book at the same time because

let the largest book be lenght of x, and the reading time of the current book first reader is reading be y, reading time from the first book to the current book be z

first reader takes z to read until the current book,

second reader takes x + z to reach the current book,

They will not collide because, first reader will finish the the book in z + y,

z + x >= z + y, so obviously, they will not be reading at the same time, worst case is when x == y, and in that case, first reader will already have finish the book and second reader would just be starting to read it.

Proof for first case:

It is impossible to have them finish all the books in total reading time, because to read the last book alone, the other guy would have finished all the book, so the answer is just total reading time + diff between largest and the rest


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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n;
    cin >> n;
    
    vll a(n);
    for(auto& i : a) cin >> i;

    sort(all(a));

    ll sm = 0;
    for(int i{}; i < n-1; i++){
        sm += a[i];
    }

    if (a.back() > sm){
        cout << sm + a.back() + (a.back()-sm);
    }else{
        cout << sm + a.back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```