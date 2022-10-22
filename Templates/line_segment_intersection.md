[From here](https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/)
```cpp

struct point{
    double x, y;
};

bool onSegment(point p, point q, point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
}

// orientation of p -> q -> r
// collinear = 0
// clockwise = 1
// counterclockwise = 2
int orientation(point p, point q, point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  // collinear
  
    return (val > 0)? 1: 2; 
}

bool doIntersect(point p1, point q1, point p2, point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}


```