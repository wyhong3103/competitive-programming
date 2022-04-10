#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define M_PI 3.14159265358979323846

using namespace std;
using vi = vector<int>;
using ll = long long;
const double EPS = 1e-9;


//struct point_i stands for point struct for integer
struct point_i{
    int x,y;
    //default constructor
    point_i(){
        x = y = 0;
    }
    //user defined
    point_i (int _x, int _y) : x(_x), y(_y){};

};

//only used if more precision is needed
struct point{
    double x,y;
    point() {
        x = y = 0.0;
    }
    point(double _x, double _y) : x(_x), y(_y) {} 
    bool operator < (point other) const{
        //first criteria, by x-coordinate
        if (fabs(x - other.x) > EPS){
            return x < other.x;
        }
        //second criteria, by y-coodinate
        return y < other.y;
    }

    bool operator == (point other) const{
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

};

double dist(point p1, point p2){
    return hypot(p1.x - p2.x , p1.y - p2.y);
}

double DEG_to_RAD(double theta){
    return (theta * (M_PI / 180));
}

point rotate(point p, double theta){
    double rad = DEG_to_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

struct line{
    double a, b, c;
    // ax + by  + c;
    // a = gradient, c = y-intercept, b is either 1 or 0, just like when we did y = mx + c, coefficient of y is always 0 or 1, depends on whether its a vertical line or non-vertical line
};

//answer is stored in the third parameter
void pointsToLine(point p1, point p2, line& l){
    if (fabs(p1.x - p2.x) < EPS){
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
        //b = 0, because it's a vertical line
    }else{
        l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2){
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2){
    return areParallel(l1,l1) && (fabs(l1.c - l2.c) < EPS);
}

//return true (+ intersection point), if two lines are intersect
bool areIntersect(line l1, line l2, point& p){
    if (areParallel(l1,l2)) return false;

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // > Eps = non-zero
    // We normally do < Eps if it's zero
    if (fabs(l1.b) > EPS){
        p.y = -(l1.a * p.x + l1.c);
    }else{
        p.y = -(l2.a  * p.x + l2.c);
    }
    return true;
}

struct vec{
    double x, y;
    vec(double _x, double _y) : x(_x) , y(_y) {};
};

//Convert 2 points to vector a -> b
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s){
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}



double distToLine(point p, point a, point b, point& c){
    vec ap = toVec(a, p), ab = toVec(a,b);
    double u = dot(ap,ab)/norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSeg(point p, point a, point b, point& c){
    vec ap = toVec(a,p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0){
        c = point(a.x , a.y);
        return dist(p, a);
    }
    if (u > 1.0){
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, b, a, c);
}

//compute angle between aob
double angle(point a, point o, point b){
    vec oa = toVec(o, a), ob = toVec(o,b);
    return acos(dot(oa, ob)/(sqrt(norm_sq(oa) * norm_sq(ob))) );
}

double cross(vec a, vec b){
    return (a.x * b.y - a.y * b.x);
}

//Finding distance using cross product
double distToLineC(point p, point a, point b){
    vec ap = toVec(a, p), ab = toVec(a,b);
    double area = cross(ap, ab);
    return area / sqrt(norm_sq(ab));
}

//Counter Clockwise Test - Left turn test
//return true if point r is on the left side of line pq
bool ccw(point p, point q, point r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}

//returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
