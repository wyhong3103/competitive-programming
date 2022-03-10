I would've solve this problem in a faster pace, here are why I couldn't:<br>
- I misunderstood the question in the first place, I didn't know that there is "unpainted element", which wasted my time in thinking of a soltuion
- This is the most frustrating one, because I coded the solution in the last hour, but I'm getting WA, because I wasn't using correct conditional statement, I've missed out a = sign, also I thought we won't be using ll, so I've decide to change it back to int, but it turned out, it overflowed (I only realised it in the last 5 minutes), and finally solved it.
<br>
<br>

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
 
 
using ll = long long;
using namespace std;
 

void solve(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> a(n);

		for(auto& i : a){
			cin >> i;
			}

		sort(all(a));

		ll bs{};ll rs{};
		int bc{}; int rc{};
		bool valid{false};
		int pl{0}, pr{n-1};


		while (pl <= pr){
			if (bs >= rs && bc-1 > rc){
				rs += a[pr];
				rc++;
				pr--;
				if (bc > rc && bs < rs) {
					valid = true;
					break;
				}
			}
			bs += a[pl];
			bc++;
			pl++;
			}
		cout <<(valid ? "YES" : "NO")  <<'\n';
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}



```