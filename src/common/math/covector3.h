#ifndef COVECTOR3_H
#define COVECTOR3_H

#include "dedatatype.h"
#include "deengine.h"

class GANDISENGINE CoVec3
{
public:
    CoVec3() : x(0.f), y(0.f), z(0.f) {};
    CoVec3(Gfloat x, Gfloat y, Gfloat z) : x(x), y(y), z(z) {};

    void set(Gfloat x, Gfloat y, Gfloat z);
    void set(const CoVec3& vec);
    Gfloat dot(const CoVec3& vec);
    CoVec3 cross(const CoVec3& vec);
    Gfloat length();
    Gfloat distance(const CoVec3& vec);
    CoVec3& normalize();

    CoVec3 operator-() const;
    CoVec3 operator+() const;

    CoVec3 operator-(const CoVec3& vec) const;
    CoVec3 operator+(const CoVec3& vec) const;
    CoVec3 operator*(const CoVec3& vec) const;
    CoVec3 operator/(const CoVec3& vec) const;
    CoVec3 operator-(const Gfloat& vec) const;
    CoVec3 operator+(const Gfloat& vec) const;
    CoVec3 operator*(const Gfloat& vec) const;
    CoVec3 operator/(const Gfloat& vec) const;

    CoVec3& operator-=(const CoVec3& vec);
    CoVec3& operator+=(const CoVec3& vec);

    CoVec3& operator*=(const Gfloat& value);
    CoVec3& operator/=(const Gfloat& value);

    Gbool operator==(const CoVec3& vec);
    Gfloat operator[](Gint index) const;
    Gfloat& operator[](Gint index);


private:
    Gfloat x;
    Gfloat y;
    Gfloat z;
};

#endif // COVECTOR3_H
