This is a weird problem, I was so lucky!!! So basically this question is about looking for the maximum even odd group that can be formed with the cows(every cow needed to be in a particular group)
<br>
Explanation:
- Alright, so, the way I solved this problem is by calculating the number of odd cow and even cow, and I realised one property of those cow which is , odd + odd = even, even +even = even, etc etc. 
- Using this property, you will get the optimal grouping numbers. But there's one exception, (seems like it is the only one exception, xD), when cow number = 5 , and there's no even number element, we will always group them into 3 and 2, so that we could form odd and even group. (Based on example 1).

```cpp
#include <bits/stdc++.h>
#include <limits>
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
map<char, int> elements{
{'o',0},
{'e',0}
};


void solve(){
	int n;
	cin >> n;

	for(int i{}; i < n; i++){
		int x;
		cin >> x;
		if (x % 2 == 0) elements['e']++;
		else elements['o']++;
	}
	
	int i{};
	int ans{};
	while(true){
		bool exist{false};
		if (i % 2 == 0){
			if (elements['e'] > 0){
				elements['e']--;
				exist = true;
				}
			else if(elements['o'] >= 2){
				elements['o'] -=2;
				exist = true;
				}
			}
		else{
			if (elements['o'] == 5 && elements['e'] == 0){
				elements['o'] -= 3;
				exist=true;
				}
			else if (elements['o'] > 0){
				elements['o']--;
				exist = true;
				}
			}

		if (!exist){
			break;
			}
		else{
			ans++;
			}
		i++;
		}

	
	cout << ans;
}
 
int main(){
	//setIO("");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}



```

Alright, I've just read the editorial, I felt so dumb.
<br>So ,the idea is to make the ratio of even and odd, 1 : 1, because that would guarantee the optimal number of group formed. How ? if O > E , O-=2, and E++, beacuse odd + odd = evene, if E > O+1, E = O+1, because we could pair all the even element to odd element, to form an odd element. since , odd + (n * even) = odd.

```cpp
#include <iostream>
using namespace std;
 
int main(void)
{
  int O=0, E=0, N, x;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> x;
    if (x % 2 == 0) E++; else O++;
  }
  while (O > E) { O=O-2; E++; }
  if (E > O+1) E = O+1;
  cout << E + O << "\n";
}
```