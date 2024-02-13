#include "widget.h"

GlWidget::GlWidget(QWidget *parent)
: QGLWidget(QGLFormat(/* Additional format options */), parent)
{
    alpha = 25;
    beta = -25;
    distance = 2.5;
}

GlWidget::~GlWidget()
{
}

QSize GlWidget::sizeHint() const
{
    return QSize(640, 480);
}


void GlWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/fragmentShader.fsh");
    shaderProgram.link();
    m_colAttr = shaderProgram.attributeLocation("colAttr");
    //vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2) << QVector3D(-1, 0, -2);
    vertices << QVector3D(-0.5, -0.5, 0.5)  << QVector3D( 0.5, -0.5, 0.5)  << QVector3D(-0.5, 0.5, 0.5)   << // front
                QVector3D( 0.5, 0.5, 0.5)   << QVector3D(-0.5, 0.5, 0.5)   << QVector3D(0.5, -0.5, 0.5)   <<

                QVector3D( 0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, 0.5, -0.5)  << // back
                QVector3D(-0.5, 0.5, -0.5)  << QVector3D( 0.5, 0.5, -0.5)  << QVector3D(0.5, -0.5, -0.5)  <<

                QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, 0.5)  << QVector3D(-0.5, 0.5, 0.5)   << //left
                QVector3D(-0.5, 0.5, 0.5)   << QVector3D(-0.5, 0.5, -0.5)  << QVector3D(-0.5, -0.5, -0.5) <<

                QVector3D( 0.5, -0.5, 0.5)  << QVector3D( 0.5, -0.5, -0.5) << QVector3D(0.5, 0.5, -0.5)   << // right
                QVector3D( 0.5, 0.5, -0.5)  << QVector3D( 0.5, 0.5, 0.5)   << QVector3D(0.5, -0.5, 0.5)   <<

                QVector3D(-0.5, 0.5, 0.5)   << QVector3D( 0.5, 0.5, 0.5)   << QVector3D(0.5, 0.5, -0.5)   << // up
                QVector3D( 0.5, 0.5, -0.5)  << QVector3D(-0.5, 0.5, -0.5)  << QVector3D(-0.5, 0.5, 0.5)   <<

                QVector3D(-0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, 0.5)  << // down
                QVector3D( 0.5, -0.5, 0.5)  << QVector3D(-0.5, -0.5, 0.5)  << QVector3D(-0.5, -0.5, -0.5);

    colors << QVector4D(1.0, 1.0, 0.0, 1.0) << QVector4D(0.0, 1.0, 0.0, 1.0) << QVector4D(0.0, 0.0, 1.0, 1.0) <<
              QVector4D(1.0, 0.0, 0.0, 1.0) << QVector4D(0.0, 0.0, 1.0, 1.0) << QVector4D(0.0, 1.0, 0.0, 1.0) <<
              QVector4D(0.0, 1.0, 1.0, 1.0) << QVector4D(0.0, 0.0, 0.0, 1.0) << QVector4D(1.0, 0.0, 1.0, 1.0) <<
              QVector4D(1.0, 0.0, 1.0, 1.0) << QVector4D(1.0, 1.0, 1.0, 1.0) << QVector4D(0.0, 1.0, 1.0, 1.0) <<
              QVector4D(0.0, 0.0, 0.0, 1.0) << QVector4D(1.0, 1.0, 0.0, 1.0) << QVector4D(0.0, 0.0, 1.0, 1.0) <<
              QVector4D(0.0, 0.0, 1.0, 1.0) << QVector4D(1.0, 0.0, 1.0, 1.0) << QVector4D(0.0, 0.0, 0.0, 1.0) <<
              QVector4D(0.0, 1.0, 0.0, 1.0) << QVector4D(0.0, 1.0, 1.0, 1.0) << QVector4D(1.0, 1.0, 1.0, 1.0) <<
              QVector4D(1.0, 1.0, 1.0, 1.0) << QVector4D(1.0, 0.0, 0.0, 1.0) << QVector4D(0.0, 1.0, 0.0, 1.0) <<
              QVector4D(0.0, 0.0, 1.0, 1.0) << QVector4D(1.0, 0.0, 0.0, 1.0) << QVector4D(1.0, 1.0, 1.0, 1.0) <<
              QVector4D(1.0, 1.0, 1.0, 1.0) << QVector4D(1.0, 0.0, 1.0, 1.0) << QVector4D(0.0, 0.0, 1.0, 1.0) <<
              QVector4D(0.0, 0.0, 0.0, 1.0) << QVector4D(0.0, 1.0, 1.0, 1.0) << QVector4D(0.0, 1.0, 0.0, 1.0) <<
              QVector4D(0.0, 1.0, 0.0, 1.0) << QVector4D(1.0, 1.0, 0.0, 1.0) << QVector4D(0.0, 0.0, 0.0, 1.0);
}


void GlWidget::resizeGL(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);
    glViewport(0, 0, width, height);
}


void GlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;
    shaderProgram.bind();

    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 1, 0, 0);
    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);
    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

    shaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);
    //shaderProgram.setUniformValue("color", QColor(Qt::green));
    shaderProgram.setAttributeArray("vertex", vertices.constData());
    shaderProgram.enableAttributeArray("vertex");

    shaderProgram.setAttributeArray("colAttr", colors.constData());
    shaderProgram.enableAttributeArray("colAttr");

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    shaderProgram.disableAttributeArray("vertex");
    shaderProgram.release();
}

void GlWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        lastMousePosition = event->pos();
        event->accept();
    }
}

void GlWidget::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton)
    {
        alpha -= deltaX;
        while (alpha < 0)
        {
            alpha += 360;
        }

        while (alpha >= 360)
        {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90)
        {
            beta = -90;
        }

        if (beta > 90)
        {
            beta = 90;
        }

        updateGL();
    }

    lastMousePosition = event->pos();
    event->accept();
}

void GlWidget::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();
    if (event->orientation() == Qt::Vertical)
    {
        if (delta < 0)
        {
            distance *= 1.1;
        } else if (delta > 0)
        {
            distance *= 0.9;
        }

        updateGL();
    }

    event->accept();
}
