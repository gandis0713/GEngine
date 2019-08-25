#ifndef COPOLYGON_H
#define COPOLYGON_H

#include "coshape.h"
#include "cofaceindex.h"

class GANDISENGINE CoPolygon : public CoShape
{
public:
    CoPolygon();
    CoPolygon(const std::vector<CoVec3> &vecPoints,
              const std::vector<CoVec3> &vecNormals,
              const std::vector<CoVec2> &vecTextureCoords,
              const CoFaceIndex &faceIndices);
    ~CoPolygon();

    void setPoints(const std::vector<CoVec3> &vecPoints);
    void setNormals(const std::vector<CoVec3> &vecNormals);
    void setTextureCoords(const std::vector<CoVec2> &vecUICoords);
    void setFaceIndex(const CoFaceIndex &faceIndices);

    std::vector<CoVec3> getPoints();
    std::vector<CoVec3> getNormals();
    std::vector<CoVec2> getTextureCoords();
    CoFaceIndex getFaceIndex();

private:
    std::vector<CoVec2> m_vecTextureCoords;
    std::vector<CoVec3> m_vecVertexNormals;
    CoFaceIndex         m_faceIndices;
};

#endif // COPOLYGON_H