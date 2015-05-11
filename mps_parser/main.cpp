#include <QtCore/QCoreApplication>
#include "parser.h"
#include "inst.h"
#include <QFile>
#include <QVector>
#include <iostream>
#include <ctime>
#include <QtDebug>
#include "DataMem.h"
#include "regfile.h"
using namespace std;

int main(int argc, char *argv[])
{
    srand ((unsigned)time(NULL));
    QCoreApplication a(argc, argv);
    QFile testFile;
    QVector <inst> vec;
    testFile.setFileName("/home/ola/Documents/Study\ Documents/Computer\ Architecture/Project/MPS/mps_parser/test.txt");
    parser fileParser;
    try{
        vec = fileParser.parseFile(testFile);
        for(int i=0;i<vec.size();i++) {
            qDebug()<<vec[i].instruction<<"  rd:  "<<vec[i].rd<<"  rt: "<<vec[i].rt<<"  rs: "<<vec[i].rs<<"  imm: "<<vec[i].imm<<"  jAdd: "<<vec[i].jAddress<<endl;
        }
        regfile dm,dm2;
        for (int i=0;i<regfile::regSize;i++){
            dm[i] = rand() % 10;
            //qDebug() << dm[i]<<endl;
        }
        dm2 = dm;
        for (int i=0;i<regfile::regSize;i++){

            qDebug() << dm2[i]<<endl;
        }

    } catch (QString error) {
         qDebug()<<error;
    }

    return a.exec();
}
