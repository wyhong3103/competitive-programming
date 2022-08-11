LUCK
```
In order to fulfil the condition of that array, 

First we can sort the array, 

_ _ _ _ _ _ _

Then place every element in ascending order into the empty array with 1 space between each other


for example, 1 2 3 4 5 6

1 _ 2 _ 3 _ 

Then do it over again for larger element

1 4 2 5 3 6

Notice that it's always optimal to do this, and the only time it wouldn't work is when the number of element is odd, and there's duplication between the larger element and it's adjacent smaller elements

Really not much for a proving , i just have this idea
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

        vi a(n);
        for(auto& i : a) cin >> i;

        if (n % 2 != 0) cout << "NO" << '\n';
        else{
            sort(all(a));
            vi circular(n);

            int cur = 0;
            for(int i{}; i < n; i+=2){
                circular[i] = a[cur];
                cur++;
            }

            bool ok = 1;
            for(int i{1}; i < n; i+=2){
                if (a[cur] == circular[i-1] || (i < n-1 && a[cur] == circular[i+1])) ok = 0;
                circular[i] = a[cur];
                cur++;
            }

            if (!ok) cout << "NO" << '\n';
            else{
                cout << "YES" << '\n';
                for(auto& i : circular) cout << i << ' ';
                cout << '\n';
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