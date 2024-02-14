#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QMatrix4x4>
#include <QGLShaderProgram>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>
#include <QGLBuffer>

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
    QGLShaderProgram coloringShaderProgram;
    int numSpotlightVertices;
    QGLBuffer spotlightBuffer;

    QGLShaderProgram lightingShaderProgram;
    int numCubeVertices;
    QGLBuffer cubeBuffer;
    QMatrix4x4 pMatrix;
    GLuint cubeTexture;

    double lightAngle;
    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;

private Q_SLOTS:
    void timeout();
};
#endif // WIDGET_H

