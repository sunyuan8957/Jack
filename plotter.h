#ifndef PLOTTER_H
#define PLOTTER_H

#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QWidget>

class QToolButton;
class PlotSettings;

class Plotter : public QWidget
{
    Q_OBJECT

public:
    Plotter(QWidget *parent = 0);

    void setPlotSettings(const PlotSettings &settings);
    void setCurveData(int id, const QVector<QPointF> &data);
    void clearCurve(int id);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    QSize widgetSize;

    QVector<QPointF>data2[6];
  void getnumber();
  void getnumber2();
    void flushbuffer();
    void changeup();
    void changedown();
    void lower();
    void upper();
    void laiba();
    QTimer *timer2;


public slots:
    void zoomIn();
    void zoomOut();
  //  void zoomfuck();
   // void zoomfuck2();
  //  void getnumber();
    void fuckoff();
    void fuckon();
     void fuckon2();
     //void fuckon3();
     void savenumbershow();
     void start();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
  //  void timerEvent(QTimerEvent *);


private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter *painter);
    void drawCurves(QPainter *painter);
    int buffer[200];
    int buffer1[200];
    int jx,kd;
    int klw;
    float pop;
    double tk;
    int tf;
    int tx;
    int xz;
    int change;
    int xq;

    enum { Margin = 50 };

    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QMap<int, QVector<QPointF> > curveMap;
    QMap<int, QVector<QPointF> > beforecurveMap;
    QMap<int, QVector<QPointF> > savecurveMap;

    QVector<PlotSettings> zoomStack;
    int curZoom;
    bool rubberBandIsShown;
    QRect rubberBandRect;
    QPixmap pixmap;
    int fuck,fuck2,timerId;
};

class PlotSettings
{
public:
    PlotSettings();

    void scroll(int dx, int dy);
    void adjust();
    double spanX() const { return maxX - minX; }
    double spanY() const { return maxY - minY; }

    double minX;
    double maxX;
    int numXTicks;
    double minY;
    double maxY;
    int numYTicks;

private:
    static void adjustAxis(double &min, double &max, int &numTicks);
};

#endif
