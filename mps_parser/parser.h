#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QVector>
#include "inst.h"
class parser
{
    //Q_OBJECT
    int lineNumber; //keeps track of the line numbering in the file being parsed.
    bool checkReg(int); //checks if the register index is valid or not.
public:
    parser();                          //regular constructor, defaults lineNumber to 0
    QVector<inst> parseFile(QFile&); //accepts a file as input and start parsing it line by line, fill in the instruction type and feilds,
                                    //and push it inside the instruction vector, return the instructor vector after done parsing.
};

#endif // PARSER_H

