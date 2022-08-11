This is really implementation heavy, and honestly, I felt like my implementation skill has improved!
<br>
Anyways, this problem is about finding the number of times we have to use two hand, which means, when the distance between shift key and the key we want to capitalized strictly bigger than x, > x.
<br>
Explanation:
- So basically, first we store, each letters location in a hash-map, because there could be a lot of reptitive letter, we know this from observation, keyboard size could goes up to 30x30, so obviously, there will be repetitive letters.
- Second, get the string, and iterate through each and every letter, if the letter doesn't exist on our keyboard, or if the letter is a Upper letter, and we don't have a shift key, return -1
- else, we're going to iterate through each and every shift key, and the letter key, if it's an upper case letter(Basically the combination of them), then store the minimum distance we could get. If the distance > x, then we will have to move 1 time. One key observation is that, since there are like only 26 letters exist in the alphabet, one thing we can do to save more time is to use memoization, because imagine if you have a case where it's 30x30, and there are half S, and half a, and you want to produce a string of A that goes up to 10^5, it's basically impossible to make it in time. So with memoization, we don't need to do that.

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


int dist(pi c1, pi c2){
    return (((c1.fir - c2.fir)*(c1.fir - c2.fir)) + ((c1.sec - c2.sec)*(c1.sec - c2.sec)));
}

void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    //x = maximum distance to reach within one hand

    map<char,vector<pi>> kb;

    //store it in a hash map
    for(int i{}; i < n; i++){
        string s;
        cin >> s;
        for(int j{}; j < m; j++){
            kb[s[j]].pb({i, j});
        }
    }

    int q;
    cin >> q;
    string s;
    cin >> s;

    //hash map for memoization
    map<char,bool> mm;
    
    int ans = 0;
    for(auto& c : s){
    	//ASCII Number goes from A-z, if letter is below 'a', that means is an upper case letter
        if (c - 'a' < 0){
            if (kb.count('S') && kb.count(tolower(c))){
                //memoization
                if (mm.count(c)){
                    if (!mm[c]){
                        ans++;
                    }
                    continue;
                }

                int mn = numeric_limits<int>::max();
                for(auto& k : kb['S']){
                    for(auto& l : kb[tolower(c)]){
                        mn = min(mn, dist(k, l));
                    }
                    if (mn <= (x*x)) break;
                }
                if (mn > (x*x)){
                    ans++;
                    mm[c] = false;
                }else{
                    mm[c] = true;
                }
            }else{
                cout << -1;
                return;
            }
        }else{
            if (!kb.count(c)){
                cout << -1;
                return;
            }
        }
    }

    cout << ans;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```