```

I do not solve this problem during contest, I also do not solve it on my own, but I'd like to learn it. (It's pretty math heavy.)

We're given a, b, d.

We need to find an x

0 <= x < 2^60

such that

(a | x) % d == 0
(b | x) % d == 0

Or report that x doesn't exist!

Let's focus on the part where x doesn't exist first!

X doesn't exist iff a or b has smaller lsb than d.

lsb - least significant bit

Why is that?

Let's take a look back at multiplication of binary numbers.

  1001
x  101
_______
  1001
 00000
100100
______
101101

The above is 9 * 5 = 45

Notice that, there is (no way) never a 1 could come earlier than the original number!



```
```cpp

```