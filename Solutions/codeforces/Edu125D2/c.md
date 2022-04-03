Bruh first in-contest div 2 C for me!!! Huge W!!! It was pretty lucky to be honest, because back when I just started CP, I watched this video from Hackerrank learning, how to determine if square brackets were valid! It was to use a stack to keep track of it, if its '(' we push it to the stack, if it isn't we remove it, if ')', comes when there isn't any '(' in the stack, that means it's invalid. For palindrome, instead of constructing a reversed string, I compare it one by one, if it wasn't the same, we break.

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


bool isGood(string& s){
    //regularity check
    stack<char> stck;
    
    bool isRegular = true;
    for(auto& i: s){
        if (i == '('){
            stck.push(i);
        }
        else if (i == ')'){
            if (stck.size()){
                stck.pop();
            }else{
                isRegular = false;
                break;
            }
        }
    }

    //palindrome check
    bool isPalin = true;
    for(int i{s.length()-1}; i >= 0; i--){
        if (s[i] != s[(s.length()-1)- i]){
            isPalin = false;
            break;
        }
    }
    return (isRegular || isPalin);
}


void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        
        int r{},c{n};

        int i{};
        string temp;
        while(i < n){
            temp += s[i];
            if (temp.length() >= 2){
                if (isGood(temp)){
                    r++;
                    c -= temp.length();
                    temp = "";
                }
            }
            i++;
        }
        cout << r << ' ' << c << '\n';
    }
}
int main(){
//   setIO("reduce");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```