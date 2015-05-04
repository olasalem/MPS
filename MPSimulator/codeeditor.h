#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QWidget>
#include <QTextEdit>

class CodeEditor : public QTextEdit
{
    Q_OBJECT
public:
    CodeEditor();
    ~CodeEditor();
//protected signals:

};

#endif // CODEEDITOR_H
