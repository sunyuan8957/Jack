    #include <QtGui>
 #include<QTextCodec>
      
    #include "plotter.h"  

 QVector<QPointF>data2[6];

      
    void readFlightCurves(Plotter *plotter, const QString &fileName)  
    {

     // QVector<QPointF>data2[6];

        //float kkk=10;
//        float rd;


//        for (int j = 0; j < 10; ++j)
//        {


//            rd=100*j;


//            data2[0].append(QPointF(rd,rd+15*j));

//            //data2[1].append(QPointF(rd-180*j,rd-160*j));
//            data2[1].append(QPointF(rd,rd+30*j));

//        }


       // plotter->setCurveData(0, data2[0]);
       // plotter->setCurveData(3, data2[1]);



//        QVector<QPointF> data[6];
//        double factX = 0.0013;
//        double factY[6] = { 0.0008, 0.1, 0.2, 0.2, 0.1, 0.8 };
//        double offsY[6] = { +500, -55, +309, +308, 0, 0 };
//        int pos[6] = { 3, 6, 7, 8, 9, 10 };
//        QFile file(fileName);
//        double offsX = 0.0;
      
//        if (file.open(QIODevice::ReadOnly)) {
//            QTextStream in(&file);
//            while (!in.atEnd()) {
//                QString line = in.readLine();
//                QStringList coords = line.split(' ',
//                                                QString::SkipEmptyParts);
//                if (coords.count() >= 6) {
//                    double x = factX * coords[0].toDouble();
//                    if (data[0].isEmpty())
//                        offsX = x;
//                    for (int i = 0; i < 6; ++i) {
//                        double y = coords[pos[i]].toDouble();
//                        data[i].append(QPointF(x - offsX,
//                                               factY[i] * (y - offsY[i])));
//                    }
//                }
//            }
//        }
      
//        plotter->setCurveData(0, data[0]);
//        plotter->setCurveData(1, data[1]);
//        plotter->setCurveData(2, data[2]);
//        plotter->setCurveData(3, data[3]);
//        plotter->setCurveData(4, data[4]);
//        plotter->setCurveData(5, data[5]);
    }  
      
    int main(int argc, char *argv[])  
    {  
        QApplication app(argc, argv);   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        Plotter plotter;
        plotter.setWindowTitle(QObject::tr("Plotter"));  
        readFlightCurves(&plotter, "in1.txt");
         plotter.resize(315,206);

        plotter.show();  
        return app.exec();  
    }  


