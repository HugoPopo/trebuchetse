#ifndef FIELD_H
#define FIELD_H


#include <QGLWidget>

class Field : public QGLWidget
{
    Q_OBJECT
public:
    explicit Field(QWidget *parent = 0);
    ~Field();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
private:
    void draw();

    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;
};

#endif // FIELD_H
