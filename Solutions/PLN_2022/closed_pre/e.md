```

Had to use python with BigInteger.

```
```py
def ncr(n, r):
    nom = 1
    for i in range((n-r)+1, n+1):
        nom *= i
    
    denom = 1
    for i in range(1, r+1):
        denom *= i
    
    return int(nom//denom)
 
 
t = int(input())
for i in range(t):
    n, r = input().split()
    n = int(n)
    r = int(r)
    print(ncr(n+r-1, r))
```