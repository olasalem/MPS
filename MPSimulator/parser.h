#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QRegExp>
#include "instruction.h"

class Parser
{
    int lineNumber; //keeps track of the line numbering in the file being parsed.
    bool checkReg(int index); //checks if the register index is valid or not.
public:

    Parser();                          //regular constructor, defaults lineNumber to 0
    ~Parser();
    QVector<Instruction> parseFile(QFile&); //accepts a file as input and start parsing it line by line, fill in the instruction type and feilds,
                                            //and push it inside the instruction vector, return the instructor vector after done parsing.
};

#endif // PARSER_H

