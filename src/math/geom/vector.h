#ifndef ILYOAN_ALGORITHMS_MATH_VECTOR_H
#define ILYOAN_ALGORITHMS_MATH_VECTOR_H

#include <vector>
using namespace std;

namespace math
{
namespace geom
{

class Vector
{
public:
    // construct a n-length Vector with all element initialized by 0.
    explicit Vector(int n);
    // construct a new Vector wich has 2 elements initialized by x and y.
    explicit Vector(double x, double y);
    // construct a new Vector wich has 3 elements initialized by x, y and y.
    explicit Vector(double x, double y, double z);
    // construct a new Vector by given vector.
    explicit Vector(const vector<double>& _v);
    // construct a new Vector by given Vector.
    explicit Vector(const Vector& obj);

    // size
    int size() const;

    // equal?
    bool operator==(const Vector& rhs) const;
    // assign
    Vector& operator=(const Vector& rhs) const;
    // plus
    Vector operator+(const Vector& rhs) const;
    // minus
    Vector operator-(const Vector& rhs) const;
    // scalar multiply
    Vector operator*(double rhs) const;

    // norm
    double norm() const;
    // unit vector
    Vector normalize() const;
    
    // dot
    double dot(const Vector& rhs) const;
    // cross
    double cross2(const Vector& rhs) const;
    Vector cross(const Vector& rhs) const;
    // project
    Vector project(const vector& rhs) const;

private:
    vector<double> v;
};

} // namespace geom
} // namespace math
#endif
