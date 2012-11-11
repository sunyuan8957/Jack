#include <QtGui>
#include <cmath>
#include<ctime>

  
#include "plotter.h"  
  
using namespace std;  
  
Plotter::Plotter(QWidget *parent)  
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Light);
    //setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  
    setFocusPolicy(Qt::StrongFocus);  
    rubberBandIsShown = false;  
  
    zoomInButton = new QToolButton(this);  
    zoomInButton->setIcon(QIcon(":/images/zoomin.png"));
    zoomInButton->adjustSize();  
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));  
  
    zoomOutButton = new QToolButton(this);  
    zoomOutButton->setIcon(QIcon(":/images/zoomout.png"));
    zoomOutButton->adjustSize();  
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));  
  
    setPlotSettings(PlotSettings());  
    klw=0;
    pop=0;
    jx=0;
    xq=0;
    kd=0;
    tf=1;
    tk=(1/tf);
    tx=1;
    xz=1;
    change=1;

    start();

    //extern QVector<QPointF>data2[6];
   QTimer *timer1 = new QTimer(this);


     timer1->setSingleShot(1);

     timer1->start(10000);

   // connect(timer1, SIGNAL(timeout()),this, SLOT(savenumbershow()));

    //QGroupBox *groupbox=new QGroupBox;
   // groupbox->setStyleSheet("background-color:blue;color:white");
    QLabel *label = new QLabel(this);
    label->setText("Model-6601 SHOWA");

    label->setAlignment(Qt::AlignTop|Qt::AlignCenter);
    label->setStyleSheet("background-color:blue;color:white");
    label->setGeometry(QRect(0, 0, 315, 20));  //四倍行距


    //label->setWordWrap(true);


    QLabel *labe2 = new QLabel(this);
    labe2->setText("MEASURE MODE");
    labe2->setAlignment(Qt::AlignCenter);
    labe2->setStyleSheet("background-color:blue;color:white");
    labe2->setGeometry(QRect(0, 20, 315, 20));

   QLabel *labe3=new QLabel(this/*tr("鈫愨啋: Select Digit\n鈫撯啈: Select Charactor\n\nEnter(Set & Next)    CAN(Return)")*/);
    labe3->setText("鈫愨啋: CH 鈫撯啈: Select Charactor\nCAN(Return)");
    labe3->setAlignment(Qt::AlignHCenter);
    labe3->setStyleSheet("background-color:blue;color:white");
    labe3->setGeometry(QRect(0,166,315,40));


   // QHBoxLayout *grid1=new QHBoxLayout;

   // grid1->addWidget(label);
    //groupbox->setLayout(grid1);
   // groupbox->setGeometry(10,0,50,50);

    //QLabel *label1=new QLabel(this);
   // label1->setText("MODEL");
   // label1->setGeometry();
  // timer1->setInterval(1000);
     //QTimer *timer2 = new QTimer(this);

      //timer2->setSingleShot(1);


     // QTimer *timer3 = new QTimer(this);
     // timer3->start(0);

      //connect(timer3, SIGNAL(timeout()),this, SLOT(fuckon()));
      //connect(timer3, SIGNAL(timeout()),this, SLOT(fuckon2()));
      //timer2->setInterval(4);



    //for (int i=0;i<100;i++)
    //{





   // getnumber();


//    for(int i=0;i<1000;i++)
//    {
//        refreshPixmap();
//    }

    //curveMap[0] = data2[0];

    //startTimer(1000);
   // refreshPixmap();

    /*getnumber();
    curveMap[0] = data2[0];
    curveMap[1]=data2[1];
    refreshPixmap();*/
  //  }


    //flushbuffer();


      //startTimer(1000);
    //startTimer(1000);
  //QTimer *timer = new QTimer(this);

  // timer->setSingleShot(1);

  // timer->start(100);

//connect(timer, SIGNAL(timeout()),this, SLOT(flushbuffer()));
//  QTimer *timer1 = new QTimer(this);

//  timer1->setSingleShot(1);

//  timer1->start(1000);

//connect(timer1, SIGNAL(timeout()),this, SLOT(zoomfuck2()));

//  setCurveData(0, data2[0]);
//  setCurveData(3, data2[1]);
//  setCurveData(1, data2[2]);
//  setCurveData(4,data2[3]);

}

void Plotter::start()
{
    timer2=new QTimer;
    timer2->start(0);
    timer2->setInterval(200);
    connect(timer2, SIGNAL(timeout()),this, SLOT(fuckon()));
    connect(timer2, SIGNAL(timeout()),this, SLOT(fuckon2()));
    //timer2->killTimer();
}
  
//void Plotter::flushbuffer()
//{
//    float kk;

//    kk=buffer[199];

//    int i;

//    for( i=199; i>=1; i--)
//    {
//    buffer[i] = buffer[i-1];

//    }
//    buffer[0]=kk;
//    float rd;
//    for( int i=0; i<199; i++ )

//    {    rd=100*i;
//        data2[0].append(QPointF(20*i+900,buffer[i]*10 +1200 ));

//        float kk;

//        kk=buffer[199];

//        int k;

//        for( k=199; k>=1; k--)
//        {
//        buffer[k] = buffer[k-1];

//        }
//        buffer[0]=kk;



    //beginPoint.setX( 2*i+90 );
   // beginPoint.setY( buffer[i] +120 );
   // endPoint.setX( 2*i+1+90);
   // endPoint.setY( buffer[i+1] +120 );
   // painter1.drawLine( beginPoint, endPoint );
//       }



//}


void Plotter::changeup()
{   //tf=1;

    timer2->stop();
    data2[0].clear();
    data2[1].clear();
    beforecurveMap.clear();
    curveMap[0]=data2[0];
    curveMap[1]=data2[1];
    refreshPixmap();
    tf=tf*2;
    if(tf>32)
    {
        tf=1;
    }
    change=tf;
    kd=0;
    xq=0;
    start();
    //fuckon3();
   // fuckon3();

    //timer2->start();
    //data2[0].clear();
    //beforecurveMap.clear();
    //curveMap.clear();
    //refreshPixmap();
    //data2[0].clear();
   // beforecurveMap.clear();

    //laiba();
}
void Plotter::changedown()
{   //tf=1;

    timer2->stop();
    data2[0].clear();
    data2[1].clear();
    beforecurveMap.clear();
    curveMap[0]=data2[0];
    curveMap[1]=data2[1];
    refreshPixmap();
    tf=tf/2;
    if(tf<1)
    {
        tf=32;
    }
  change=tf;
    kd=0;
    xq=0;
    start();

}
void Plotter::lower()
{

    timer2->stop();
    data2[0].clear();
    data2[1].clear();
    beforecurveMap.clear();
    curveMap[0]=data2[0];
    curveMap[1]=data2[1];
    refreshPixmap();
    tf=change;
    kd=0;
    xq=0;
    jx=0;
    xz=xz*2;
    start();
//    xz=xz*2;
//    tf=change;
//    kd=0;
//    start();
}
void Plotter::upper()
{

    timer2->stop();
    data2[0].clear();
    data2[1].clear();
    beforecurveMap.clear();
    curveMap[0]=data2[0];
    curveMap[1]=data2[1];
    refreshPixmap();
    tf=change;
    kd=0;
    xq=0;
    jx=0;
    xz=xz/2;

    start();
}



void Plotter::laiba()
{   QTimer *timer5 = new QTimer(this);
    timer5->start(10000);
    timer5->setInterval(200);
    connect(timer5, SIGNAL(timeout()),this, SLOT(fuckon()));
    connect(timer5, SIGNAL(timeout()),this, SLOT(fuckon2()));
}




void Plotter::fuckoff()

{   double dx,dy;
    //data2[0].remove(0,2);
    beforecurveMap[0]=data2[0];

    QMapIterator<int, QVector<QPointF> > i(beforecurveMap);
  while (i.hasNext())
  {
       i.next();

        //int id = i.key();
        const QVector<QPointF> &data = i.value();
       // QPolygonF polyline(data.count());

        for (int j = 0; j < data.count(); ++j)
        {
            dx = data[j].x()+1  ;
            dy = data[j].y()  ;

            data2[0].append(QPointF(dx,dy));
        }
  }







     curveMap[0] = data2[0];
    refreshPixmap();
}


void Plotter::savenumbershow()
{
     savecurveMap[0]=data2[2];
     data2[2].clear();
     double dx,dy;
     QMapIterator<int, QVector<QPointF> > i(savecurveMap);
   while (i.hasNext()) {
        i.next();

         //int id = i.key();
         const QVector<QPointF> &data = i.value();
        // QPolygonF polyline(data.count());

         for (int j = 0; j < data.count(); ++j)
         {
             dx = data[j].x()+0.04*(j) ;
             dy = data[j].y()  ;


             data2[2].append(QPointF(dx,dy));
         }

     }
   curveMap[2] = data2[2];

   refreshPixmap();


}






void Plotter::fuckon()
{
    //for (int i=0;i<100;i++)
  //  {
    //int t;
     double dx,dy;
    if(kd<(5*tf))
    {
    getnumber();


    double tx;
    tx=50*(xq+1)*(0.04/tf);
    data2[1].append(QPointF(tx,0));
    data2[1].append(QPointF(tx,10));

    curveMap[0] = data2[0];
    curveMap[1]=data2[1];
    refreshPixmap();
    data2[1].clear();
     xq++;


 if(kd<(5*tf-1)){
        //
        beforecurveMap[0]=data2[0];
        //int fff=data2[0].count();

        data2[0].clear();
       // data2[0].remove(0,fff);



    QMapIterator<int, QVector<QPointF> > i(beforecurveMap);
  while (i.hasNext()) {
       i.next();

        //int id = i.key();
        const QVector<QPointF> &data = i.value();
       // QPolygonF polyline(data.count());

        for (int j = 0; j < data.count(); ++j)
        {
            if (32==tf){
               dx = data[j].x()+0.0625;}

         if (16==tf){
            dx = data[j].x()+0.125;}
         if (8==tf){
             dx = data[j].x()+0.25;}
         if (4==tf){
             dx = data[j].x()+0.5;}
         if (2==tf){
             dx = data[j].x()+1;}
         if (1==tf){
             dx = data[j].x()+2;}

            dy = data[j].y()  ;

      data2[0].append(QPointF(dx,dy));}


  }}


    }
    kd++;


}


void Plotter::fuckon2()
{   /*kd++;
    if (kd==9)
    {
        pop=pop+0.1;
    }*/



    if (kd>=(5*tf))
    {     //data2[0].remove(9);
          beforecurveMap[0]=data2[0];
          //int t=data2[0].count();
          //double kk= t;

          //data2[0].clear();
          data2[0].remove(((250*tf)-(jx+1)*50),((jx+1)*50));
         // data2[0].squeeze();

          //data2[0].clear();
   // getnumber();
   //curveMap[0] = data2[0];

   // refreshPixmap();




//        //data2[0].remove(0,2);


//        //data2[0].clear();


             //float tk=1/tf;

                    double dx,dy;
                  if(jx>=1)
                  {
                    QMapIterator<int, QVector<QPointF> > i(beforecurveMap);
                  while (i.hasNext()) {
                       i.next();


                        const QVector<QPointF> &data = i.value();


                        for (int j = ((250*tf)-(jx*50)); j <=(250*tf-1); ++j)
                        {   if (32==tf){
                                dx = data[j].x()+0.0625;}

                          if (16==tf){
                             dx = data[j].x()+0.125;}
                          if (8==tf){
                              dx = data[j].x()+0.25;}
                          if (4==tf){
                              dx = data[j].x()+0.5;}
                          if (2==tf){
                              dx = data[j].x()+1;}
                          if (1==tf){
                              dx = data[j].x()+2;}


                            dy = data[j].y() ;


                            data2[0].append(QPointF(dx,dy));
                        }
                        //beforecurveMap.clear();
                  }
                  }

                        getnumber2();
                        curveMap[0] = data2[0];

                        double tx;
                        tx=50*(jx+1)*(0.04/tf);
                        data2[1].append(QPointF(tx,0));
                        data2[1].append(QPointF(tx,10));

                         curveMap[1]=data2[1];

                        refreshPixmap();

                        data2[1].clear();


                        jx++;
                        if(jx>=(5*tf))
                        {
                            jx=0;
                        }





    }
}





void Plotter::getnumber()
{   //float kkk=100;
   // float kkk=10;

   // srand((unsigned)time(0));



//    jx++;
//    if (jx>9)
//    {
//        fuckon2();
//        jx=0;
//    }
    if(xz<1)
    {
        xz=1;
    }
    float rd,rd2;

    float pp=(1.96/tf);
    for (int j = 0; j < 50; ++j)
    {



        //rd=pop;
        //pop=pop-0.1;
        rd=pp;
        pp=pp-(0.04/tf);
        rd2=((rand()%10)/tx)/xz;

//        rd=pop;
//        pop=pop-0.02;
//        rd2=(rand()%10);



        data2[0].append(QPointF(rd,rd2));
        data2[2].append(QPointF(0,rd2));


        //data2[1].append(QPointF(rd-180*j,rd-160*j));
        //data2[1].append(QPointF(rd,rd+30*j+klw));
       // data2[2].append(QPointF(rd,rd+45*j));
        //data2[3].append(QPointF(rd,rd+60*j));



    }

}

void Plotter::getnumber2()
{
    if(xz<1)
    {
        xz=1;
    }

    float rd,rd2;
    float pp=(1.96/tf);
    //kk=(-0.7);


    for (int j = 0; j < 50; ++j)
    {
        rd=(0.04/tf)+pp;
        pp=pp-(0.04/tf);
        rd2=((rand()%10)/tx)/xz;
        data2[0].append(QPointF(rd,rd2));
        data2[2].append(QPointF(0,rd2));
    }
}






void Plotter::setPlotSettings(const PlotSettings &settings)  
{  
    zoomStack.clear();  
    zoomStack.append(settings);  
    curZoom = 0;  
    zoomInButton->hide();  
    zoomOutButton->hide();  
    refreshPixmap();  
}  
  
void Plotter::zoomOut()  
{  
    if (curZoom > 0) {  
        --curZoom;  
        zoomOutButton->setEnabled(curZoom > 0);  
        zoomInButton->setEnabled(true);  
        zoomInButton->show();  
        refreshPixmap();  
    }  
}  
  
void Plotter::zoomIn()  
{  
    if (curZoom < zoomStack.count() - 1) {  
        ++curZoom;  
        zoomInButton->setEnabled(curZoom < zoomStack.count() - 1);
        zoomOutButton->setEnabled(true);  
        zoomOutButton->show();  
        refreshPixmap();  
    }  
}  
  
void Plotter::setCurveData(int id, const QVector<QPointF> &data)  
{  
    curveMap[id] = data;  
    refreshPixmap();  
}  
  
void Plotter::clearCurve(int id)  
{  
    curveMap.remove(id);  
    refreshPixmap();  
}  
  
QSize Plotter::minimumSizeHint() const  
{  
    return QSize(6 * Margin, 4 * Margin);  
}  
  
QSize Plotter::sizeHint() const  
{  
    return QSize(12 * Margin, 8 * Margin);  
}  
  
void Plotter::paintEvent(QPaintEvent * /* event */)  
{  
    QStylePainter painter(this);
    //QRectF target(10.0, 20.0, 80.0, 60.0);
    QPoint centerPoint(0,0);

       // Scale new image which size is widgetSize
    //QSize sizeoff(100,15);

         QPixmap scaledPixmap = pixmap.scaled(widgetSize, Qt::KeepAspectRatio);

      // Calculate image center position into screen

      centerPoint.setX((widgetSize.width()-scaledPixmap.width())/2);

      centerPoint.setY((widgetSize.height()-scaledPixmap.height())*2);

     // Draw image

          painter.drawPixmap(centerPoint,scaledPixmap);



  //  painter.drawPixmap(0, 0, pixmap);
    //painter.drawPixmap(0, 0, pixmap);
  
    if (rubberBandIsShown) {  
        painter.setPen(palette().light().color());  
        painter.drawRect(rubberBandRect.normalized()  
                                       .adjusted(0, 0, -1, -1));  
    }  
  
    if (hasFocus()) {  
        QStyleOptionFocusRect option;  
        option.initFrom(this);  
        option.backgroundColor = palette().dark().color();  
        painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);  
    }  
}  
  
void Plotter::resizeEvent(QResizeEvent *  event )
{  
    int x = width() - (zoomInButton->width()  
                       + zoomOutButton->width() + 10);  
    zoomInButton->move(x, 5);  
    zoomOutButton->move(x + zoomInButton->width() + 5, 5);
    widgetSize = event->size();
    QWidget::resizeEvent(event);
    refreshPixmap();  
}  
  
void Plotter::mousePressEvent(QMouseEvent *event)  
{  
    QRect rect(Margin, Margin,  
               width() - 2 * Margin, height() - 2 * Margin);  
  
    if (event->button() == Qt::LeftButton) {  
        if (rect.contains(event->pos())) {  
            rubberBandIsShown = true;  
            rubberBandRect.setTopLeft(event->pos());  
            rubberBandRect.setBottomRight(event->pos());  
            updateRubberBandRegion();  
            setCursor(Qt::CrossCursor);  
        }  
    }  
}  
  
void Plotter::mouseMoveEvent(QMouseEvent *event)  
{  
    if (rubberBandIsShown) {  
        updateRubberBandRegion();  
        rubberBandRect.setBottomRight(event->pos());  
        updateRubberBandRegion();  
    }  
}  
//void Plotter::timerEvent(QTimerEvent *t) //定时器事件

//{


//switch(t->timerId()) //判断定时器的句柄

//{

//case 1 : //zoomfuck();
//   // killTimer(1);
//    break;

////case 2 : zoomfuck2() ;
// //   break;

////case 3 : qApp->quit();break; //退出系统

//}

//}

//void Plotter::zoomfuck()

//{


//    curveMap.remove(1);
//    refreshPixmap();

//     //killTimer(1);

//}
//void Plotter::zoomfuck2()

//{


//    curveMap.remove(0);
//    refreshPixmap();
//     //killTimer(1);
//    //getnumber();

//}


void Plotter::mouseReleaseEvent(QMouseEvent *event)  
{  
    if ((event->button() == Qt::LeftButton) && rubberBandIsShown) {  
        rubberBandIsShown = false;  
        updateRubberBandRegion();  
        unsetCursor();  
  
        QRect rect = rubberBandRect.normalized();  
        if (rect.width() < 4 || rect.height() < 4)
            return;  
        rect.translate(-Margin, -Margin);  
  
        PlotSettings prevSettings = zoomStack[curZoom];  
        PlotSettings settings;  
        double dx = prevSettings.spanX() / (width() - 2 * Margin);  
        double dy = prevSettings.spanY() / (height() - 2 * Margin);  
        settings.minX = prevSettings.minX + dx * rect.left();  
        settings.maxX = prevSettings.minX + dx * rect.right();  
        settings.minY = prevSettings.maxY - dy * rect.bottom();  
        settings.maxY = prevSettings.maxY - dy * rect.top();  
        settings.adjust();  
  
        zoomStack.resize(curZoom + 1);  
        zoomStack.append(settings);  
        zoomIn();  
    }  
}  



  
void Plotter::keyPressEvent(QKeyEvent *event)  
{  
    switch (event->key()) {  
    case Qt::Key_Plus:  
        zoomIn();  
        break;  
    case Qt::Key_Minus:  
        zoomOut();  
        break;  
    case Qt::Key_Left:  
        //zoomStack[curZoom].scroll(-1, 0);
        //refreshPixmap();
        changedown();
        break;  
    case Qt::Key_Right:  
        //zoomStack[curZoom].scroll(+1, 0);
        changeup();

        //laiba();
        //refreshPixmap();
        break;  
    case Qt::Key_Down:  
       // zoomStack[curZoom].scroll(0, -1);
        //refreshPixmap();
        lower();
        break;  
    case Qt::Key_Up:  
        //zoomStack[curZoom].scroll(0, +1);
        //refreshPixmap();
        upper();
        break;  
    default:  
        QWidget::keyPressEvent(event);  
    }  
}  
  
void Plotter::wheelEvent(QWheelEvent *event)  
{  
    int numDegrees = event->delta() / 8;  
    int numTicks = numDegrees / 15;  
  
    if (event->orientation() == Qt::Horizontal) {  
        zoomStack[curZoom].scroll(numTicks, 0);  
    } else {  
        zoomStack[curZoom].scroll(0, numTicks);  
    }  
    refreshPixmap();  
}  
  
void Plotter::updateRubberBandRegion()  
{  
    QRect rect = rubberBandRect.normalized();  
    update(rect.left(), rect.top(), rect.width(), 1);  
    update(rect.left(), rect.top(), 1, rect.height());  
    update(rect.left(), rect.bottom(), rect.width(), 1);  
    update(rect.right(), rect.top(), 1, rect.height());  
}  
  
void Plotter::refreshPixmap()  
{
    pixmap = QPixmap(size());

//    QPixmap pixmap;

//    qreal width = pixmap1.width(); //获得以前图片的宽和高
//    qreal height = pixmap1.height();
//    pixmap = pixmap.scaled(width*1,height*1,Qt::KeepAspectRatio);
    pixmap.fill(this, 0, 0);
  
    QPainter painter(&pixmap);  
    painter.initFrom(this);  
    drawGrid(&painter);  
    drawCurves(&painter);  
    update();  
}  
  
void Plotter::drawGrid(QPainter *painter)  
{   QRect rect(15, Margin+5,
               width()-15, height() - 2 * Margin-10);
    if (!rect.isValid())  
        return;  
  
    PlotSettings settings = zoomStack[curZoom];  
    QPen quiteDark = palette().dark().color().light();  
    QPen light = palette().light().color();  
  
    for (int i = 0; i <= settings.numXTicks; ++i) {
        int x = rect.left() + (i * (rect.width() - 1)  
                                 / settings.numXTicks);  
        double label = settings.minX + (i * settings.spanX()  
                                         / settings.numXTicks);
        double label1=label*tf;
        painter->setPen(Qt::black);
        painter->drawLine(x, rect.top(), x, rect.bottom());  
       // painter->setPen();
        painter->drawLine(x, rect.bottom(), x, rect.bottom() + 5);  
        painter->drawText(x - 50, rect.bottom() + 5, 100, 15,
                          Qt::AlignHCenter | Qt::AlignTop,  
                          QString::number((label1)/10));
    }  
    for (int j = 0; j <= settings.numYTicks; ++j) {
        int y = rect.bottom() - (j * (rect.height() - 1)  
                                   / settings.numYTicks);  
        double label = settings.minY + (j * settings.spanY()  
                                          / settings.numYTicks);  
       // painter->setPen(quiteDark);
        painter->drawLine(rect.left(), y, rect.right(), y);  
       // painter->setPen(/*light*/quiteDark);
        painter->drawLine(rect.left() - 5, y, rect.left(), y);  
        painter->drawText(rect.left() - Margin, y - 10, Margin - 5, 20,  
                          Qt::AlignRight | Qt::AlignVCenter,  
                          QString::number(label));  
    }  
    painter->drawRect(rect.adjusted(0, 0, -1, -1));  
}  
  
void Plotter::drawCurves(QPainter *painter)  
{  
    static const QColor colorForIds[6] = {  
        Qt::blue, Qt::red, Qt::blue, Qt::cyan, Qt::green, Qt::yellow
    };  
    PlotSettings settings = zoomStack[curZoom];  
    QRect rect(15, Margin+5,
                  width()-15, height() - 2 * Margin-10);
    if (!rect.isValid())  
        return;  
  
    painter->setClipRect(rect.adjusted(+1, +1, -1, -1));  
  
    QMapIterator<int, QVector<QPointF> > i(curveMap);  
    while (i.hasNext()) {  
        i.next();  
  
        int id = i.key();  
        const QVector<QPointF> &data = i.value();  
        QPolygonF polyline(data.count());  
  
        for (int j = 0; j < data.count(); ++j) {
            double dx = data[j].x() - settings.minX;  
            double dy = data[j].y() - settings.minY;  
            double x = rect.left() + (dx * (rect.width() - 1)  
                                         / settings.spanX());  
            double y = rect.bottom() - (dy * (rect.height() - 1)  
                                           / settings.spanY());  
            polyline[j] = QPointF(x, y);  
        }  
        painter->setPen(colorForIds[uint(id) % 6]);  
        painter->drawPolyline(polyline);
       //curveMap.erase(i);
    }  
}  
  
PlotSettings::PlotSettings()  
{  
    minX = 0.0;  
    //maxX = 10.0;
    maxX = 10.0;
    numXTicks = 5;  
  
    minY = 0.0;
    maxY = 10.0;  
    numYTicks = 5;
}  
  
void PlotSettings::scroll(int dx, int dy)  
{  
    double stepX = spanX() / numXTicks;  
    minX += dx * stepX;  
    maxX += dx * stepX;  
  
    double stepY = spanY() / numYTicks;  
    minY += dy * stepY;  
    maxY += dy * stepY;  
}  
  
void PlotSettings::adjust()  
{  
    adjustAxis(minX, maxX, numXTicks);  
    adjustAxis(minY, maxY, numYTicks);  
}  
  
void PlotSettings::adjustAxis(double &min, double &max,  
                              int &numTicks)  
{  
    const int MinTicks = 4;  
    double grossStep = (max - min) / MinTicks;  
    double step = pow(10.0, floor(log10(grossStep)));  
  
    if (5 * step < grossStep) {
        step *= 5;  
    } else if (2 * step < grossStep) {
        step *= 2;  
    }  
  
    numTicks = int(ceil(max / step) - floor(min / step));  
    if (numTicks < MinTicks)
        numTicks = MinTicks;  
    min = floor(min / step) * step;  
    max = ceil(max / step) * step;  
}  


