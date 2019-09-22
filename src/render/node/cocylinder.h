#ifndef COCYLINDER_H
#define COCYLINDER_H

#include "coshape.h"

using namespace std;

class GANDISENGINE CoCylinder : public CoShape
{
public:
    CoCylinder();
    CoCylinder(CoVec3 vCenter,
               Gfloat fRadius,
               Gfloat fLength);
    virtual ~CoCylinder();

    void setCenter(CoVec3 vPosition);
    void setRadius(Gfloat fRadius);
    void setLength(Gfloat fLength);

    std::vector<CoVec3> getNormals();
    std::vector<Gint> getVertexIndice();

protected:
    void createCylinder();
    void createIndexedCylinder();

private:
    CoVec3 m_vCenter;
    Gfloat m_fRadius;
    Gfloat m_fLength;

    vector<Gint> m_vecVertexIndices;
    vector<CoVec3> m_vecVertexNormal;

};

#endif // COCYLINDER_H
