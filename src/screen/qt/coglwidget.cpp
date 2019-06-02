#include "coglwidget.h"

CoGLWidget::CoGLWidget(QWidget *parent) : QGLWidget(parent)
{
    qDebug() << __FUNCTION__;
}

CoGLWidget::~CoGLWidget()
{

}


void CoGLWidget::resizeGL(int nWidth, int nHeight)
{
    emit signalResizeGL(nWidth, nHeight);
    qDebug() << __FUNCTION__;

}

void CoGLWidget::initializeGL()
{
    emit signalInitializeGL();
    qDebug() << __FUNCTION__;
}

void CoGLWidget::paintGL()
{
    emit signalPaintGL();
    qDebug() << __FUNCTION__;
}

