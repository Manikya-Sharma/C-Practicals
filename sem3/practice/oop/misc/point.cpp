#include <iostream>
#include <math.h>
using namespace std;

class Line;

class Point {
  private:
    double x;
    double y;

  public:
    friend ostream &operator<<(ostream &, const Point &);
    friend double distance(const Point &, const Point &);
    Point(double x = 0, double y = 0);
    bool operator>(const Point &pt2)
    {
        Point origin;
        return distance(*this, origin) > distance(pt2, origin);
    }
    bool operator<(const Point &pt2)
    {
        Point origin;
        return distance(*this, origin) < distance(pt2, origin);
    }
    Point operator+(const Point &pt2) { return Point(x + pt2.x, y + pt2.y); }
    friend Line;
    friend ostream &operator<<(ostream &, const Line &);
};

Point::Point(double x, double y) : x(x), y(y) {}

ostream &operator<<(ostream &os, const Point &pt)
{
    os << "(" << pt.x << "," << pt.y << ")";
    return os;
}

double distance(const Point &pt1, const Point &pt2)
{
    return sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2));
}

class Line {
    Point pt1;
    Point pt2;

  public:
    Line() {}
    Line(Point pt1, Point pt2) : pt1(pt1), pt2(pt2) {}
    double slope() const { return (pt2.y - pt1.y) / (pt2.x - pt1.x); }
    double magnitude() const { return distance(pt1, pt2); };
    friend bool operator>(const Line &, const Line &);
    friend bool operator<(const Line &, const Line &);
    friend ostream &operator<<(ostream &, const Line &);
};

bool operator>(Line &l1, Line &l2) { return l1.slope() > l2.slope(); }

bool operator<(const Line &l1, const Line &l2)
{
    return l1.slope() < l2.slope();
}

ostream &operator<<(ostream &os, const Line &l)
{
    double m = l.slope();
    double c = (l.pt2.x * l.pt1.y - l.pt1.x * l.pt2.y) / (l.pt2.x - l.pt1.x);
    os << "y = " << m << " x + " << c;
    return os;
}

class Vector2D {
    union U {
        constexpr U() : form(0) {}
        int form;
        class {
          public:
            Line l;
            int direction;
        } linear;
        Point unit;
    } representation;

  public:
    void convert_to_unit()
    {
        if (this->representation.form == 1) {
            return;
        }
        double magnitude = this->representation.linear.l.magnitude();
        double slope = this->representation.linear.l.slope();
        double theta = atan(slope);
        double x = magnitude * sin(theta);
        double y = magnitude * cos(theta);
        this->representation.form = 1;
        this->representation.unit = Point(x, y);
    }

    void convert_to_linear()
    {
        if (this->representation.form == 0) {
            return;
        }
        Point origin;
        Line l(origin, this->representation.unit);
        this->representation.linear.l = l;
        this->representation.linear.direction = 1;
    }

    Vector2D() {}

    Vector2D(Point pt)
    {
        this->representation.unit = pt;
        this->representation.form = 1;
    }

    Vector2D(Line l, int direction = 1)
    {
        this->representation.linear.direction = direction;
        this->representation.linear.l = l;
        this->representation.form = 0;
    }
    Vector2D operator+(Vector2D &vec2)
    {
        if (this->representation.form != 1) {
            this->convert_to_unit();
        }
        if (vec2.representation.form != 1) {
            vec2.convert_to_unit();
        }
        Point newUnit = this->representation.unit + vec2.representation.unit;
        Vector2D vec(newUnit);
        return vec;
    }
    void reverse()
    {
        if (this->representation.form == 1) {
            this->convert_to_linear();
            this->representation.linear.direction = 1;
        }
        this->representation.linear.direction =
            -this->representation.linear.direction;
    }
    friend ostream &operator<<(ostream &, Vector2D &);
};

ostream &operator<<(ostream &os, Vector2D &vec)
{
    if (vec.representation.form == 0) {
        os << "Line: " << vec.representation.linear.l << endl;
        os << "Direction: " << vec.representation.linear.direction << endl;
    }
    else {
        os << "Unit vector: " << vec.representation.unit << endl;
    }
    return os;
}

int main()
{
    Point pt(5, 6);
    Vector2D vec(pt);
    cout << vec;
    vec.convert_to_linear();
    vec.convert_to_unit();
    cout << vec;
}