#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QTabWidget>

#include <QMdiArea>
#include <QMdiSubWindow>

#include <QMenu>
#include <QMenuBar>
#include <QMenuItem>
#include <QToolBar>
#include <QDockWidget>
#include <QAction>
#include <QKeySequence>

#include <QIcon>
#include <QStyle>

#include <QVBoxLayout>
#include <QFormLayout>
#include <QTextEdit>
#include <QTextDocument>
#include <QLineEdit>
#include <QPushButton>

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>

#include <QFile>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QDir>

#include <QRegExp>
#include <QMap>

#include <QThread>

#include <list>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include "myhighlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void treeWidgetItemDoubleClicked(QTreeWidgetItem *treeWidgetItemClicked, int columnClicked);

    void nouveauProjet();
    void nouveauProgramme();

    void fermerProjet();
    void fermerProgramme();

    void enregistrerProjet();
    void enregistrerProgramme();

    void supprimerProgramme();

    void insertionTexte();

    void changerVueOnglet(bool vueOnglet);

signals:
    void activerMenusProjet(bool);

private:
    struct Programme {
        QString name;
        QString nomPourCalculatrice;
        QString motDePasse;
        QString description;
        QString contenu;
        double version;
    };

    struct Projet {
        QString name;
        QDir dir;
        QString nomFichierProjet;
        QString nomFichierProgrammes;
        QMap<QString, Programme> programmes;
    };

    QWidget *nouvelleFenetre(const QString &contenu = "") const;
    QString clearInsertText(QString texte) const;
    QString catParser(const QString &contenu) const;
    QString genCatFile(const QMap<QString, Programme> &programmes) const;
    QString convToRawFormat(const QString &contenu) const;
    int countCatFile(const QString &contenuCatFile) const;
    QDomDocument genFichierProjet(const Projet & projet) const;
    void ecrireProgramme(QString nomFichier, const QString &contenu) const;

    Projet projetEnCours;

    QMdiArea *zoneCentrale;
    QTreeWidget *treeView;
    QTabWidget *onglets;

    QMap<QString, QString> rawEquiv;
    QStringList keywordPatterns;
    QStringList specialCharsPatterns;
};

#endif // MAINWINDOW_H
