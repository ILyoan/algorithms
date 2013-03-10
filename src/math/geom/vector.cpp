#include "Vector.h"

#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

namespace math
{
namespace geom
{

Vector::Vector(int n) : v(n) {}

Vector::Vector(double x, double y) : v(2)
{
    v[0] = x;
    v[1] = y;
}

Vector::Vector(double x, double y, double z) : v(3)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

Vector::Vector(const vector<double>& _v) v(_v) {}

Vector::Vector(const Vector& obj) : v(obj.v) {}

int Vector::size() const
{
    return v.size();
}

bool Vector::operator==(const Vector& rhs) const
{
    return size() == rhs.size()
           && std::equal(v.begin(), v.end(), rhs.v.begin());
}

Vector& Vector::operator=(const Vector& rhs) const
{
    v = rhs.v;
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    assert(size() == rhs.size());
    int n = size();
    Vector res(n);
    for (int i = 0; i < n; i++) {
        res[i] = v[i] + rhs.v[i];
    }
    return res;
}

Vector Vector::operator-(const Vector& rhs) const
{
    assert(size() == rhs.size());
    int n = size();
    Vector res(n);
    for (int i = 0; i < n; i++) {
        res[i] = v[i] + rhs.v[i];
    }
    return res;
}

Vector Vector::operator*(double rhs) const
{
    int n = size();
    Vector res(*this);
    for (int i = 0; i < n; i++) {
        res[i] *= rhs;
    }
    return res;
}

double Vector::norm() const
{
    int n = size();
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += v[i] * v[i];
    }
    return sqrt(res);
}

Vector Vector::normailize() const
{
    int n = size();
    double nor = norm();
    Vector res(*this);
    for (int i = 0; i < n; i++) {
        res[i] /= nor;
    }
    return res;
}

double Vector::dot(const Vector& rhs) const
{
    assert(size() == rhs.size());
    int n = size();
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += v[i] * rhs.v[i];
    }
    return res;
}

double Vector::cross2(const Vector& rhs) const
{
    assert(size() == 2 && rhs.size() == 2);
    return v[0] * rhs.v[1] - v[1] * rhs.v[0];
}

Vector Vector::cross(const Vector& rhs) const
{
    assert(size() == rhs.size());
    int n = size();
    Vector res(n);
    if (n == 3) {
        res.v[0] = v[1] * rhs.v[2] - v[2] * rhs.v[1];
        res.v[1] = v[2] * rhs.v[0] - v[0] * rhs.v[2];
        res.v[2] = v[0] * rhs.v[1] - v[1] * rhs.v[0];
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    for (int k = 0; k < n; k++) {
                        if (k != i) {
                            if (k > j) res.v[i] += v[j] * rhs.v[k];
                            if (k < j) res.v[i] -= v[j] * rhs.v[k];
                        }
                    }
                }
            }
        }
    }
    return res;
}

Vector Vector::project(const Vector& rhs) const
{
    assert(size() == rhs.size());
    Vector res = rhs.normalize();
    return res * res.dot(*this);
}

} // namespace geom
} // namespace math
