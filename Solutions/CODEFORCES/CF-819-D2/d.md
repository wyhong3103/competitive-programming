```
Ideas

Proof by induction

Theorem

The sum of red & blue cc is always N+1 in a tree.

Base case, when non is colored red

Yes it is N+1

Assume P(Z) is correct, Z colored red,

Prove P(Z+1) is also correct

If you color another edge between a and b, initially a and b was two different component, if you colored the edge between them it joins the red component

red component - 1 (because before a and b was connected in red, b was an individual component but now joined to red)
blue component + 1 (because before a and b as connected in red, a was still connected by b, but when colored, a was isolated)

A cycle edge let you connects up red without losing an individual node

find the edge that makes up a cycle and connect to new nodes

we need to find m - (n-1) edges that is part of a cycle and connects to different nodes



```