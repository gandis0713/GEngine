#include "coperspectivecamera.h"

#include "nomath.h"

CoPerspectiveCamera::CoPerspectiveCamera()
{    
    setCamera();
}

CoPerspectiveCamera::~CoPerspectiveCamera()
{

}

void CoPerspectiveCamera::update()
{
    setCamera();

    emit signalCameraUpdated();
}


void CoPerspectiveCamera::setCamera()
{
    CoMat4x4 matPerspective = NoMath::perspective(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    CoMat4x4 matLookAt = lookAt(m_vecPosition,
                                m_vecTarget,
                                m_vecUp);

    m_matCamera = matPerspective * matLookAt;
}
