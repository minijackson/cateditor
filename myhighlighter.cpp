#include "myhighlighter.h"

MyHighlighter::MyHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    /*
     * L'ordre se fait en fonction des priorités : Les moins prioritaires en premiers
     * exemple : les commentaires prévalents sur les mot-clefs donc les commentaires se situent à la fin
     */

    keywordFormat.setForeground(Qt::darkRed);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "^If " << "^Then " << "^Else " << "^IfEnd$"
                    << "^While " << "^WhileEnd$" << "^Do$" << "^LpWhile "
                    << "^For " << " To " << " Step " << "^Next$";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    displayKeywordFormat.setForeground(Qt::darkGray);
    displayKeywordFormat.setFontWeight(QFont::Bold);
    QStringList displayKeywordPatterns;
    displayKeywordPatterns << "\\bLocate " << "\\bText ";
    foreach (const QString &pattern, displayKeywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = displayKeywordFormat;
        highlightingRules.append(rule);
    }

    numberFormat.setForeground(QColor(240, 128, 128));
    rule.pattern = QRegExp("[0-9]");
    rule.format = numberFormat;
    highlightingRules.append(rule);

    stringFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\"[^\n]*\"");
    rule.format = stringFormat;
    highlightingRules.append(rule);

    commentFormat.setForeground(Qt::darkBlue);
    commentFormat.setFontItalic(true);
    rule.pattern = QRegExp("'[^\n]*");
    rule.format = commentFormat;
    highlightingRules.append(rule);
}

void MyHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);

        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);
}
