#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QWidget>
#include <QPlainTextEdit>

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    CodeEditor();
    ~CodeEditor();
    void lineNumberAreaPaint(QPaintEvent *pevent);
    int  lineNumberWidth();

protected:
    void resize(QResizeEvent *revent);

private slots:
    void updateLine(int lineCount);

private:
    QWidget *lineNumberArea;

};

#endif // CODEEDITOR_H
