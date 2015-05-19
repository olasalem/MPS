#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QVector>
#include <QRegExp>
#include <QTextCharFormat>

class Highlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    Highlighter(QTextDocument *parent = 0);
    ~Highlighter();
protected:
    void highlightBlock(const QString &text);
 private:
    struct SyntaxRule {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector <SyntaxRule> rules;


    QRegExp commentExpression;
    QRegExp labelExpression;

    QTextCharFormat instructionFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat labelFormat;
    QTextCharFormat invalidFormat;
};

#endif // HIGHLIGHTER_H
