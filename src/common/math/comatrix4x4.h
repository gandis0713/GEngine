#ifndef COMATRIX4X4_H
#define COMATRIX4X4_H

#include "dedatatype.h"
#include "covector3.h"
#include "deengine.h"

class GANDISENGINE CoMat4x4
{
public:
    CoMat4x4();
    CoMat4x4(const Gfloat mat[16]);
    CoMat4x4(Gfloat mat00, Gfloat mat01, Gfloat mat02, Gfloat mat03,
             Gfloat mat04, Gfloat mat05, Gfloat mat06, Gfloat mat07,
             Gfloat mat08, Gfloat mat09, Gfloat mat10, Gfloat mat11,
             Gfloat mat12, Gfloat mat13, Gfloat mat14, Gfloat mat15);

    CoMat4x4& identity();
    void set(const Gfloat mat[16]);
    void set(Gfloat m00, Gfloat m01, Gfloat m02, Gfloat m03,
             Gfloat m04, Gfloat m05, Gfloat m06, Gfloat m07,
             Gfloat m08, Gfloat m09, Gfloat m10, Gfloat m11,
             Gfloat m12, Gfloat m13, Gfloat m14, Gfloat m15);
    CoMat4x4 getTranspose();
    CoMat4x4& transpose();
    CoMat4x4& invert();
    Gfloat determinant();
    CoVec3 angle();    
    CoMat4x4& rotate(Gfloat angle, const CoVec3& axis);
    CoMat4x4& rotate(Gfloat angle, Gfloat x, Gfloat y, Gfloat z);
    CoMat4x4& rotateX(Gfloat angle);
    CoMat4x4& rotateY(Gfloat angle);
    CoMat4x4& rotateZ(Gfloat angle);

    CoMat4x4 operator+(const CoMat4x4& mat);
    CoMat4x4 operator-(const CoMat4x4& mat);
    CoMat4x4& operator+=(const CoMat4x4& mat);
    CoMat4x4& operator-=(const CoMat4x4& mat);
    CoMat4x4 operator*(const CoMat4x4& mat);
    CoVec3 operator*(const CoVec3& vec) const;
    CoMat4x4& operator*=(const CoMat4x4& mat);

    Gfloat operator[](Gint index) const;
    Gfloat& operator[](Gint index);

private:
    Gfloat mat[16];
};

#endif // COMATRIX4X4_H
