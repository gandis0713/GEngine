#ifndef COPERSPECTIVECAMERA_H
#define COPERSPECTIVECAMERA_H

#include "cocamera.h"
#include "coenginedefine.h"

class GANDISENGINE CoPerspectiveCamera : public CoCamera
{
public:
    explicit CoPerspectiveCamera();
    virtual ~CoPerspectiveCamera();

    void update() override;
};

#endif // COPERSPECTIVECAMERA_H
