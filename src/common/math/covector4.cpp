#include "covector4.h"

void CoVec4::set(Gfloat x, Gfloat y, Gfloat z, Gfloat w)
{
    x = x;
    y = y;
    z = z;
}

void CoVec4::set(const CoVec4& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

Gfloat CoVec4::dot(const CoVec4& vec)
{
    return x * vec.x + y * vec.y + z * vec.z;
}

CoVec3 CoVec4::cross(const CoVec4& vec)
{
    return CoVec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}


Gfloat CoVec4::length()
{
    return sqrtf(x * x + y * y + z * z);
}

Gfloat CoVec4::distance(const CoVec4& vec)
{
    return sqrtf((x - vec.x) * (x - vec.x)
                 + (y - vec.y) * (y - vec.y)
                 + (z - vec.z) * (z - vec.z)
                 + (w - vec.w) * (w - vec.w));
}

CoVec4& CoVec4::normalize()
{
    Gfloat normalizeFactor = 1.0f / std::sqrtf(x * x + y * y + z * z);

    x *= normalizeFactor;
    y *= normalizeFactor;
    z *= normalizeFactor;

    return *this;
}

CoVec4 CoVec4::operator-()
{
    return CoVec4(-x, -y, -z, -w);
}

CoVec4 CoVec4::operator+()
{
    return CoVec4(+x, +y, +z, +w);
}

CoVec4 CoVec4::operator-(const CoVec4& vec)
{
    return CoVec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

CoVec4 CoVec4::operator+(const CoVec4& vec)
{
    return CoVec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

CoVec4 CoVec4::operator*(const CoVec4& vec)
{
    return CoVec4(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}

CoVec4 CoVec4::operator/(const CoVec4& vec)
{
    return CoVec4(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}

CoVec4& CoVec4::operator-=(const CoVec4& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    w -= vec.w;

    return *this;
}

CoVec4& CoVec4::operator+=(const CoVec4& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;

    return *this;
}

CoVec4& CoVec4::operator*=(const Gfloat& value)
{
    x *= value;
    y *= value;
    z *= value;
    w *= value;

    return *this;
}

CoVec4& CoVec4::operator/=(const Gfloat& value)
{
    x /= value;
    y /= value;
    z /= value;
    w /= value;

    return *this;
}

Gbool CoVec4::operator==(const CoVec4& vec)
{
    return (x == vec.x) &&
           (y == vec.y) &&
           (z == vec.z) &&
           (w == vec.w);
}

Gfloat CoVec4::operator[](Gint index) const
{
    return (&x)[index];
}

Gfloat& CoVec4::operator[](Gint index)
{
    return (&x)[index];
}
