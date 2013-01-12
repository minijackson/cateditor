#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegExp>
#include <QTextEdit>

class MyHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    MyHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat commentFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat displayKeywordFormat;
    QTextCharFormat stringFormat;
    QTextCharFormat numberFormat;
};

#endif // MYHIGHLIGHTER_H
