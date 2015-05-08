#include "highlighter.h"
#include <QDebug>
/*
 * Class Highlighter
 * args: parent* (QTextDocument)
 * Description: It highlights the syntax in the code editor
 */
Highlighter::Highlighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{
    SyntaxRule syntaxRule;

    commentFormat.setForeground(Qt::darkGreen);
    commentExpression = QRegExp("#[^\n]*");
    syntaxRule.format = commentFormat;
    syntaxRule.pattern = commentExpression;
    rules.append(syntaxRule);

    labelFormat.setFontItalic(true);
    labelExpression = QRegExp("[a-z][a-z0-9]+ ?:");
    labelExpression.setCaseSensitivity(Qt::CaseInsensitive);
    syntaxRule.format = labelFormat;
    syntaxRule.pattern = labelExpression;
    rules.append(syntaxRule);

    QStringList instructions;
    instructionFormat.setForeground(Qt::blue);
    instructionFormat.setFontKerning(true);
    instructions << "\\badd\\b" << "\\baddi\\b" << "\\bsub\\b"
                 << "\\bxor\\b" << "\\blw\\b" << "\\bsw\\b"
                 << "\\bble\\b" << "\\bj\\b" << "\\bslt\\b"
                 << "\\bjal\\b" << "\\bjr\\b";
    foreach(const QString &instruction, instructions){
        syntaxRule.pattern = QRegExp(instruction);
        syntaxRule.pattern.setCaseSensitivity(Qt::CaseInsensitive);
        syntaxRule.format = instructionFormat;
        rules.append(syntaxRule);
    }
    invalidFormat.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
    invalidFormat.setUnderlineColor(Qt::red);
}

Highlighter::~Highlighter()
{
}

void Highlighter::highlightBlock(const QString &text)
{
    char invalid = 0;
    foreach(const SyntaxRule &rule, rules){
        int index = rule.pattern.indexIn(text);
        invalid |= (index != -1);
        while(index >= 0){
            setFormat(index, rule.pattern.matchedLength(), rule.format);
            index = rule.pattern.indexIn(text, index + rule.pattern.matchedLength());
        }
    }
   if (invalid == 0)
       setFormat(0, text.size(), invalidFormat);

}
