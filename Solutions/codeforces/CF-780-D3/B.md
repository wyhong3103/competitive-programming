This problem is about not eating the same maximum frequency element twice in a row. 
<br>
Initial Solution, it was totally unnecessary! This approach is to test if the previous element can be eaten legally (do no violate the twice in a row), if it is that means the next element could also be eaten, regardless of its number.
```cpp

#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto& i: a) cin >> i;
 
        if (a.size() == 1){
            if (a[0] == 1){
                cout << "YES";
            }else{
                cout << "NO";
            }
            cout << '\n';
            continue;
        }
    
 
        sort(all(a), [](int a, int b){
            return a > b;
        });
 
        
        vector<bool> b(n);
        bool found = false;
        for(int i{1}; i < n; i++){
            if (abs(a[i-1] - a[i]) > 1){
                if (b[i-1]){
                    b[i] = true;
                }else{
                    found = true;
                    break;
                }
            }else{
                b[i] = true;
            }
        }
 
        cout << (!found ? "YES" : "NO") << '\n';
    }
}
 
 
int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```
Upsolving
<br>
A better solution is to just check the frequency of the maximum element and the one after that. Because if the difference between them is < 1, that means we can pretty much each every other candies, why is that?
```
5 5 3 1

After consuming type 1 candy

4 5 3 1

We consume the second, and it goes on and on

4 4 3 1

3 4 3 1

3 3 3 1

2 3 3 1

2 2 3 1

2 2 2 1

1 2 2 1

1 1 2 1

1 1 1 1 

...

0 0 0 0
```

Code:

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto& i : a) cin >> i;

        sort(all(a), [](int a, int b){
            return a > b;
        });

        if (a.size() == 1){
            cout << (a[0] == 1 ? "YES" : "NO") << '\n';
        }else{
            cout << (a[0]-a[1] <= 1? "YES" : "NO") << '\n';
        }

    }
}

int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```