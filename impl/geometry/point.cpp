const double PI = acos(-1);
constexpr double EPS = 1e-6; 
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<typename T>
struct Point{
    T x, y;
    Point(T x=0, T y=0) : x(x),y(y){}
    bool operator < (Point o) const { return tie(x,y) < tie(o.x,o.y); }
    bool operator == (Point o) const { return tie(x,y) == tie(o.x,o.y); }
    Point operator + (Point o) const { return Point(x+o.x,y+o.y); }
    Point operator - (Point o) const { return Point(x-o.x,y-o.y); }
    Point operator * (T k) const { return Point(x*k,y*k); }
    Point operator / (T k) const { return Point(x/k,y/k); }
    double cross(Point o) const { return x*o.y - y*o.x; }
    double cross(Point a, Point b) const { return (a-*this).cross(b-*this); }
    double dot(Point o) const { return x*o.x + y*o.y; }
    double dist() const { return std::sqrt(x*x + y*y); }
    double dist(Point a) const { return std::sqrt((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y)); }
    double dist2() const { return x*x + y*y; }
    double len() const { return hypot(x,y); }
    Point perp() const { return Point(-y,x); }
    Point rotate(double a) const { return Point(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
    int quad() { return (x<0)^3*(y<0); }
    bool ccw(Point<T> q, Point<T> r){ return (q-*this).cross(r-q) > 0;}
};

template<typename T>
Point<T> projPointLine(Point<T> a, Point<T> b, Point<T> c) { // ponto c na linha a - b, a.b = |a| cost * |b|
    return a + (b-a) * (b-a).dot(c-a) / (b-a).dot(b-a);
}

template<typename T>
double distancePointLine(Point<T> a, Point<T> b, Point<T> c) { // distancia do ponto c a linha a - b
    return c.dist(projPointLine(a, b, c));
}

template<typename T>
bool ptInSegment (Point<T> a, Point<T> b, Point<T> c) { // ponto c esta em um segmento a - b
    if (a == b) return a == c;
    a = a-c, b = b-c;
    return cmp(cross(a, b)) == 0 && cmp(dot(a, b)) <= 0;
}