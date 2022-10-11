My solution is to make sure both ends are the same element (rotate the array).

Keep track of the first element in every ring.

If we at a[i] and a[i] == a[i+1], then it's time to break the current ring. If a[i] == first element in the ring as well, then the answer must be 2. The idea is, in the current ring, there won't be 2 adjacent elements that are the same, because that's how we form the ring in the first place. So that means the element before a[i] in the ring is definitely not the same as a[i] so we could simply break the ring at the last element, and let a[i] be an individual element.

And we do the same at last.


