We can only compute the inverse when gcd(a,b) == 1
```cpp
ll ex_gcd(ll a, ll b, ll& x, ll& y){
    if (!b){
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = ex_gcd(b, a % b, x1, y1);

    x = y1, y = x1 - (y1 * (a/b));
    return d;
}

ll inv(ll a, ll b){
    ll x, y;
    ex_gcd(a, b, x, y);
    return ((x % b) + b) % b;
}

```