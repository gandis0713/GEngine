#include "copolygoncore.h"
#include "copolygon.h"

CoPolygonCore::CoPolygonCore()
{

}

CoPolygonCore::CoPolygonCore(CoNode* pNode, CoCamera *pCamera)
    : CoShapeCore(pNode, pCamera)
{
}


CoPolygonCore::~CoPolygonCore()
{

}

void CoPolygonCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();
    m_pNBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/polygon_frag.glsl");
//    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/polygon_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/polygon_vert.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");
    m_nMID = m_pShaderProgram->getUniformLocation("m");
    m_nVID = m_pShaderProgram->getUniformLocation("v");
    m_nCameraID = m_pShaderProgram->getUniformLocation("cameraPosition");

    CoPolygon *pPolygon = static_cast<CoPolygon*>(m_pNode);

    m_pVBO->gen();
    m_pVBO->bind();
    m_pVBO->allocate(&pPolygon->getPoints()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pCBO->gen();
    m_pCBO->bind();
    m_pCBO->allocate(&pPolygon->getColors()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pNBO->gen();
    m_pNBO->bind();
    m_pNBO->allocate(&pPolygon->getNormals()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pVAO->gen();
    m_pVAO->bind();

    m_pVBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(COLOR_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(COLOR_IN_LAYOUT, 3, 0);

    m_pNBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(2);
    m_pShaderProgram->setVertexAttribPointer(2, 3, 0);

    m_pVAO->release();
}

void CoPolygonCore::paint()
{
    CoPolygon *pPolygon = static_cast<CoPolygon*>(m_pNode);

    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat());
    m_pShaderProgram->setUniformMatrix4fv(m_nMID, pPolygon->getMatModel());
    m_pShaderProgram->setUniformMatrix4fv(m_nVID, m_pCamera->getViewMat());
    CoVec3 vCameraPosition = m_pCamera->getPosition();
    glUniform3f(m_nCameraID, vCameraPosition[0], vCameraPosition[1], vCameraPosition[2]);

    m_pVAO->bind();

    glDrawArrays(GL_TRIANGLES, 0, pPolygon->getSize());
}
