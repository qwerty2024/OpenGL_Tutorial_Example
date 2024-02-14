#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QMatrix4x4>
#include <QGLShaderProgram>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>


class GlWidget : public QGLWidget
{
    Q_OBJECT
public:
    GlWidget(QWidget *parent = 0);
    ~GlWidget();
    QSize sizeHint() const;

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QGLShaderProgram lightingShaderProgram;
    QVector<QVector3D> spotlightVertices;
    QVector<QVector3D> spotlightColors;
    double lightAngle;

    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> cubeVertices;
    QVector<QVector3D> cubeNormals;
    QVector<QVector2D> cubeTextureCoordinates;
    GLuint cubeTexture;
    QGLShaderProgram coloringShaderProgram;
    //GLuint m_colAttr;
    //QVector<QVector4D> colors;

    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;

private Q_SLOTS:
    void timeout();
};
#endif // WIDGET_H

