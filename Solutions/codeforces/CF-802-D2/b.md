```
If the first digit do not start with 9

We can simply, do this

3 0 3 2 3

Match the first digit with the last digit,

Because we aren't allowed to start with leading zero, so what can we do is , if first digit >= last digit, the only extra step is we need to add 1 to the first digit,

After that, for every digit and it's mirrored digit , has to be the same , so the lower one simply need to add some number.

In the case where the first digit is 9

we can simply, get a palindromic number that has a length of n+1, then set all the digit as 1, then do manual subtraction, it's guaranteed that we will get a number that has the length of n
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
 
        string s;
        cin >> s;
        
        string res = s;
        if (s[0] != '9'){
            if (n%2) res[n/2] = '0';
 
            if (s[0] >= s[n-1]){
                res[0] = '1';
                res[n-1] = ((s[0]+1)-s[n-1]) + '0';
            }else{
                res[0] = (s[n-1]-s[0]) + '0';
                res[n-1] = '0';
            }
 
            for(int i{1}; i < n/2; i++){
                if (s[i] >= s[(n-1)-i]){
                    res[i] = '0';
                    res[(n-1)-i] = (s[i] - s[(n-1)-i]) + '0';
                }else{
                    res[(n-1)-i] = '0';
                    res[i] = (s[(n-1)-i] - s[i]) + '0';
                }
            } 
        }else{
            vi remainder(n+1);
            for(auto& i : remainder) i = 1;
 
            for(int i{n-1}; i >= 0; i--){
                if (remainder[i+1] >= (s[i]-'0')){
                    res[i] = (remainder[i+1] - (s[i]-'0')) + '0';
                }else{
                    remainder[i]--;
                    remainder[i+1] += 10;
                    res[i] = (remainder[i+1] - (s[i]-'0')) + '0';
                }
            }
        }
 
        cout << res << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```