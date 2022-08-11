So, for this problem. We're given 2 numbers, and we're only allowed to do 3 type of operations, a += 1, b += 1, a \|= b, the goal is to find the minimum number of operations to make a == b
<br>
Explanation:
- The key observation is that, everytime we do the third operation, the OR operation, our a either equal to b or goes larger than b. And we're only required to do it once for an optimal solution.
- For the case, where you apply an OR operation, that instantly make a == b, are below
```
	1111
OR	0111
	1111

Notice that the case below is not a valid case

	1100
OR	0011
	1111

Based on these cases, we can say that if every i-th bit of a , which is equal to 1, i-th of b has to equal to 1 as well. There are 4 combinations of bit, which is when a , b = 0 0, 0 1, 1 0, 1 1 
The only invalid case is when a = 1, b = 0
```
- With this observation, we can kind of brute force it, we're going to add 1 to a until it became a valid case of an instant OR operation. And every time we add 1 to a, we're going to OR the new a, since a is going to go over b, and the value is uncertain, so we can compute the value after OR operation, subtract by b, because there are cases where you added a certain values, OR it, and b add a certain value, to be equal. Repeat the same operation with b. Get the minimum answer.

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
 
 
bool valid(int a, int b){
    for(int i{}; i <= (int)log2(a); i++){
        if (((a >> i) & 1) && !((b >> i) & 1)){
            return false; 
        }
    }
    return true;
}
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = b-a;
 
 		//temp a
        int ta = a;
 
        int count1 = 0;
 
 		//count1 or count2 + 1, because of the OR operation
        while(!valid(ta,b)){
            int temp = ta | b;
            //after doing OR operation, temp grows larger than b, so temp - b is the number we need to add to b
            ans = min(temp-b+count1+1, ans);
            ta++;
            count1++;
        }
        ans = min(ans, count1+1);
 
 		//same thing, but on b
        int count2 = 0;
        while(!valid(a, b)){
            int temp = a | b;
            ans = min(temp-b+count2+1, ans);
            b++;
            count2++;
        }
        ans = min(count2+1, ans);
 
        cout << ans << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```