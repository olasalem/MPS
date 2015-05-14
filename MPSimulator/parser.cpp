#include "parser.h"

bool Parser::checkReg(int index)
{
    if(index < 0 || index > 31) return false;
        return true;
}

Parser::Parser()
{
    lineNumber = 0;
}

Parser::~Parser()
{

}

QVector<Instruction> Parser::parseFile(QFile &instFile)
{
    QVector <Instruction> instMem; //to be returned
    Instruction temp; //current instruction that is being formed
    QString line; //current line being proccessed
    QTextStream  fileStream(&instFile); //the stream of the file

    QRegExp inst_3Op("\\s*(ADD|ADDI|XOR|SLT|BLE)\\s+\\$(\\d+)\\s*,\\s*\\$(\\d+)\\s*,\\s*(\\$?\\d+)\\s*"); //to check for instruction with three operands
    QRegExp inst_2Op("\\s*(LW|SW)\\s+\\$(\\d+)\\s*,\\s*(\\d+)\\s*\\(\\s*\\$(\\d+)\\s*\\)\\s*"); //to check for instructions with two operands
    QRegExp inst_1Op ("\\s*(J|JAL|JR|JUMP_PROCEDURE)\\s+(\\$?\\d+)\\s*"); //to check for instruction with 1 operand
    QRegExp inst_0Op ("^\\s*(RETURN_PROCEDURE)\\s*$");
    QRegExp empty("^(\\s*)$");  //to check for any white char
    QString fileError = "An Error Occurred, Problem with the File"; //to be thrown if an error occurred when openning the file
    QString invalidSyntaxError = "An Error Occurred, Invalid Instruction Syntax at Line: "; //to be thrown if invalid syntax found
    QString RegIndexError = "An Error Occurred, Register Index Out of Bounds at Line: "; //to be thrown if register index is out of bound

    if(instFile.open(QFile::ReadOnly)) { //todo : open file in read only format

        while(!fileStream.atEnd()) {
            line = fileStream.readLine();
            lineNumber++;

            if(inst_3Op.indexIn(line) != -1) { //match 3operands instruction
                temp.inst = inst_3Op.cap(0);
                temp.instType = inst_3Op.cap(1);
                temp.jAddress = 0;


                if (temp.instType == "ADDI" || temp.instType == "BLE" ){ // I-Format
                    if (inst_3Op.cap(4).at(0) == '$') throw (invalidSyntaxError + QString::number(lineNumber));
                    temp.rd = 0;
                    temp.rt = atoi( inst_3Op.cap(2).toStdString().c_str() );
                    temp.rs = atoi( inst_3Op.cap(3).toStdString().c_str() );
                    temp.imm = atoi( inst_3Op.cap(4).toStdString().c_str() );

                    if ( !checkReg(temp.rs) || !checkReg(temp.rt) ) throw (RegIndexError + QString::number(lineNumber));

                } else { //R-Format
                    if (inst_3Op.cap(4).at(0) != '$') throw (invalidSyntaxError + QString::number(lineNumber));
                    temp.imm = 0;
                    temp.rd = atoi( inst_3Op.cap(2).toStdString().c_str() );
                    temp.rs = atoi( inst_3Op.cap(3).toStdString().c_str() );
                    temp.rt = atoi( inst_3Op.cap(4).toStdString().substr(1).c_str() );



                    if (!checkReg(temp.rs) || !checkReg(temp.rt) || !checkReg(temp.rd) ) throw (RegIndexError + QString::number(lineNumber));
                }

            } else if(inst_2Op.indexIn(line) != -1) { //match 2operands instructtion
                temp.inst = inst_2Op.cap(0);
                temp.instType = inst_2Op.cap(1);
                temp.rd = 0;
                temp.jAddress = 0;
                temp.rt = atoi( inst_2Op.cap(2).toStdString().c_str() );
                temp.imm = atoi( inst_2Op.cap(3).toStdString().c_str() );
                temp.rs = atoi( inst_2Op.cap(4).toStdString().c_str() );


                if ( !checkReg(temp.rs) || !checkReg(temp.rt) ) throw (RegIndexError + QString::number(lineNumber));


            } else if (inst_1Op.indexIn(line) != -1) { //match 1operand instruction
                temp.inst = inst_1Op.cap(0);
                temp.instType = inst_1Op.cap(1);
                temp.rt = 0;
                temp.rd = 0;
                temp.imm = 0;

                if(temp.instType == "JR") { //JR
                    if (inst_1Op.cap(2).at(0) != '$') throw (invalidSyntaxError + QString::number(lineNumber));
                    temp.jAddress = 0;
                    temp.rs = atoi( inst_1Op.cap(2).toStdString().substr(1).c_str() );

                    if ( !checkReg(temp.rs) ) throw (RegIndexError + QString::number(lineNumber));


                } else { // J/JAL/JUMP_PROCEDURE
                    if (inst_1Op.cap(2).at(0) == '$') throw (invalidSyntaxError + QString::number(lineNumber));
                    temp.rs = 0;
                    temp.jAddress = atoi( inst_1Op.cap(2).toStdString().c_str() );

                }

            } else if(inst_0Op.indexIn(line) != -1) { //RETURN_PROCEDURE
                temp.inst = inst_0Op.cap(0);
                temp.instType = inst_1Op.cap(1);
                temp.rs = temp.rt = temp.rd = temp.imm = temp.jAddress = 0;


            } else if (empty.indexIn(line) != -1) { //match white char

                continue;

            } else { //invalid instruction
                throw (invalidSyntaxError + QString::number(lineNumber));

            }

            instMem.push_back(temp); //end of line parsing
        }

        instFile.close();
    } else throw (fileError); //QString Error

    return instMem;  //end of parsing file

}
