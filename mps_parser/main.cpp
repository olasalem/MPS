#include <QtCore/QCoreApplication>
#include "parser.h"
#include "inst.h"
#include <QFile>
#include <QVector>
#include <iostream>

#include <QtDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile testFile;
    QVector <inst> vec;
    testFile.setFileName("/home/ola/Desktop/mps_parser/test.txt");
    parser fileParser;
    try{
        vec = fileParser.parseFile(testFile);
        for(int i=0;i<vec.size();i++) {
            qDebug()<<vec[i].instruction<<"  rd:  "<<vec[i].rd<<"  rt: "<<vec[i].rt<<"  rs: "<<vec[i].rs<<"  imm: "<<vec[i].imm<<"  jAdd: "<<vec[i].jAddress<<endl;
        }
    } catch (QString error) {
         qDebug()<<error;
    }

    return a.exec();
}
