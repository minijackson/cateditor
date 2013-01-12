#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    zoneCentrale = new QMdiArea;

    keywordPatterns << "^If " << "^Then " << "^Else " << "^IfEnd$"
                    << "^While " << "^WhileEnd$" << "^Do$" << "^LpWhile "
                    << "^For " << " To " << " Step " << "^Next$"
                    << "\\bLocate " << "\\bText " << "\\bList " << "\\bMat ";

    specialCharsPatterns << "\\\\sin " << "sin "
                         << "\\\\micro" << "µ"
                         << "\\\\pi" << "??"
                         << "\\\\sqrt" << "?";

    // ==========
    // == MENU ==
    // ==========

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        QAction *actionNouveauProjet = new QAction(QIcon::fromTheme("document-new"), "Nouveau &Projet", this);
        menuFichier->addAction(actionNouveauProjet);
        actionNouveauProjet->setShortcut(QKeySequence("Ctrl+Shift+N"));

        QAction *actionNouveauProgramme = new QAction(QIcon::fromTheme("document-new"), "&Nouveau Programme", this);
        menuFichier->addAction(actionNouveauProgramme);
        actionNouveauProgramme->setDisabled(true);
        actionNouveauProgramme->setShortcut(QKeySequence("Ctrl+N"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionNouveauProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionFermerProjet = new QAction(QIcon::fromTheme("window-close"), "Fermer le Projet", this);
        menuFichier->addAction(actionFermerProjet);
        actionFermerProjet->setDisabled(true);
        actionFermerProjet->setShortcut(QKeySequence("Ctrl+Shift+W"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionFermerProjet, SLOT(setEnabled(bool)));

        QAction *actionFermerProgramme = new QAction(QIcon::fromTheme("window-close"), "Fermer le Programme", this);
        menuFichier->addAction(actionFermerProgramme);
        actionFermerProgramme->setDisabled(true);
        actionFermerProgramme->setShortcut(QKeySequence("Ctrl+W"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionFermerProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionEnregistrerProjet = new QAction(QIcon::fromTheme("document-save"), "&Enregistrer le Projet", this);
        menuFichier->addAction(actionEnregistrerProjet);
        actionEnregistrerProjet->setDisabled(true);
        actionEnregistrerProjet->setShortcut(QKeySequence("Ctrl+Shift+S"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionEnregistrerProjet, SLOT(setEnabled(bool)));

        QAction *actionEnregistrerProgramme = new QAction(QIcon::fromTheme("document-save"), "En&registrer un Programme", this);
        menuFichier->addAction(actionEnregistrerProgramme);
        actionEnregistrerProgramme->setDisabled(true);
        actionEnregistrerProgramme->setShortcut(QKeySequence("Ctrl+S"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionEnregistrerProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionSupprmierProjet = new QAction(QIcon::fromTheme("edit-delete"), "Supprimer le Projet", this);
        menuFichier->addAction(actionSupprmierProjet);
        actionSupprmierProjet->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionSupprmierProjet, SLOT(setEnabled(bool)));

        QAction *actionSupprmierProgramme = new QAction(QIcon::fromTheme("edit-delete"), "Supprimer le Programme", this);
        menuFichier->addAction(actionSupprmierProgramme);
        actionSupprmierProgramme->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionSupprmierProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionOuvrirProjet = new QAction(QIcon::fromTheme("document-open"), "&Ouvrir un projet", this);
        menuFichier->addAction(actionOuvrirProjet);
        actionOuvrirProjet->setShortcut(QKeySequence("Ctrl+Shift+O"));

        QAction *actionOuvrirProgramme = new QAction(QIcon::fromTheme("document-open"), "O&uvrir un programme", this);
        menuFichier->addAction(actionOuvrirProgramme);
        actionOuvrirProgramme->setDisabled(true);
        actionOuvrirProgramme->setShortcut(QKeySequence("Ctrl+O"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionOuvrirProgramme, SLOT(setEnabled(bool)));

        QMenu *sous_menuProjetsRecents = new QMenu("Fichiers &Récents");
        menuFichier->addMenu(sous_menuProjetsRecents);

        menuFichier->addSeparator();
        QAction *actionQuitter = new QAction(QIcon::fromTheme("application-exit"), "&Quitter", this);
        menuFichier->addAction(actionQuitter);
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));


    QMenu *menuEdition = menuBar()->addMenu("&Edition");
        QAction *actionAnnuler = new QAction(QIcon::fromTheme("edit-undo"), "&Annuler", this);
        menuEdition->addAction(actionAnnuler);
        actionAnnuler->setDisabled(true);
        actionAnnuler->setShortcut(QKeySequence("Ctrl+Z"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionAnnuler, SLOT(setEnabled(bool)));

        QAction *actionRefaire = new QAction(QIcon::fromTheme("edit-redo"), "&Refaire", this);
        menuEdition->addAction(actionRefaire);
        actionRefaire->setDisabled(true);
        actionRefaire->setShortcut(QKeySequence("Ctrl+Shift+Z"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionRefaire, SLOT(setEnabled(bool)));

        menuEdition->addSeparator();

        QAction *actionCouper = new QAction(QIcon::fromTheme("edit-cut"), "Co&uper", this);
        menuEdition->addAction(actionCouper);
        actionCouper->setDisabled(true);
        actionCouper->setShortcut(QKeySequence("Ctrl+X"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionCouper, SLOT(setEnabled(bool)));

        QAction *actionCopier = new QAction(QIcon::fromTheme("edit-copy"), "Cop&ier", this);
        menuEdition->addAction(actionCopier);
        actionCopier->setDisabled(true);
        actionCopier->setShortcut(QKeySequence("Ctrl+C"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionCopier, SLOT(setEnabled(bool)));

        QAction *actionColler = new QAction(QIcon::fromTheme("edit-paste"), "C&oller", this);
        menuEdition->addAction(actionColler);
        actionColler->setDisabled(true);
        actionColler->setShortcut(QKeySequence("Ctrl+V"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionColler, SLOT(setEnabled(bool)));

        menuEdition->addSeparator();

        QAction *actionToutSelectionner = new QAction(QIcon::fromTheme("edit-select-all"), "Tout &sélectionner", this);
        menuEdition->addAction(actionToutSelectionner);
        actionToutSelectionner->setDisabled(true);
        actionToutSelectionner->setShortcut(QKeySequence("Ctrl+A"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionToutSelectionner, SLOT(setEnabled(bool)));

        menuEdition->addSeparator();

        QAction *actionRechercher = new QAction(QIcon::fromTheme("edit-find"), "&Rechercher", this);
        menuEdition->addAction(actionRechercher);
        actionRechercher->setDisabled(true);
        actionRechercher->setShortcut(QKeySequence("Ctrl+F"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionRechercher, SLOT(setEnabled(bool)));

        QAction *actionRechercherRemplacer = new QAction(QIcon::fromTheme("edit-find-replace"), "Rechercher et Remplacer", this);
        menuEdition->addAction(actionRechercherRemplacer);
        actionRechercherRemplacer->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionRechercherRemplacer, SLOT(setEnabled(bool)));

    QMenu *menuInsertion = menuBar()->addMenu("&Insertion");
        QMenu *menuInsertionCOM = menuInsertion->addMenu("&Boucles et Structures Conditionnelles");
            QAction *actionInsertionStructureIf = new QAction("Structure conditionnelle If", this);
            menuInsertionCOM->addAction(actionInsertionStructureIf);
            connect(actionInsertionStructureIf, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionIf = new QAction("&If", this);
            menuInsertionCOM->addAction(actionInsertionIf);
            connect(actionInsertionIf, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionThen = new QAction("&Then", this);
            menuInsertionCOM->addAction(actionInsertionThen);
            connect(actionInsertionThen, SIGNAL(triggered()), this, SLOT(insertionTexte()));


            QAction *actionInsertionElse = new QAction("&Else", this);
            menuInsertionCOM->addAction(actionInsertionElse);
            connect(actionInsertionElse, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionIfEnd = new QAction("I&fEnd", this);
            menuInsertionCOM->addAction(actionInsertionIfEnd);
            connect(actionInsertionIfEnd, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionCOM->addSeparator();

            QAction *actionInsertionBoucleWhile = new QAction("Boucle While", this);
            menuInsertionCOM->addAction(actionInsertionBoucleWhile);
            connect(actionInsertionBoucleWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionWhile = new QAction("&While", this);
            menuInsertionCOM->addAction(actionInsertionWhile);
            connect(actionInsertionWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionWhileEnd = new QAction("WhileE&nd", this);
            menuInsertionCOM->addAction(actionInsertionWhileEnd);
            connect(actionInsertionWhileEnd, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionCOM->addSeparator();

            QAction *actionInsertionBoucleDoLpWhile = new QAction("Boucle Do LpWhile", this);
            menuInsertionCOM->addAction(actionInsertionBoucleDoLpWhile);
            connect(actionInsertionBoucleDoLpWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionDo = new QAction("&Do", this);
            menuInsertionCOM->addAction(actionInsertionDo);
            connect(actionInsertionDo, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionLpWhile = new QAction("&LpWhile", this);
            menuInsertionCOM->addAction(actionInsertionLpWhile);
            connect(actionInsertionLpWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionCOM->addSeparator();

            QAction *actionInsertionBoucleFor = new QAction("Boucle For", this);
            menuInsertionCOM->addAction(actionInsertionBoucleFor);
            connect(actionInsertionBoucleFor, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionFor = new QAction("&For", this);
            menuInsertionCOM->addAction(actionInsertionFor);
            connect(actionInsertionFor, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionTo = new QAction("T&o", this);
            menuInsertionCOM->addAction(actionInsertionTo);
            connect(actionInsertionTo, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionStep = new QAction("&Step", this);
            menuInsertionCOM->addAction(actionInsertionStep);
            connect(actionInsertionStep, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionNext = new QAction("Ne&xt", this);
            menuInsertionCOM->addAction(actionInsertionNext);
            connect(actionInsertionNext, SIGNAL(triggered()), this, SLOT(insertionTexte()));

        QMenu *menuInsertionListMat = menuInsertion->addMenu("&Listes et Matrices");
            QAction *actionInsertionList = new QAction("&List", this);
            menuInsertionListMat->addAction(actionInsertionList);
            connect(actionInsertionList, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionListVersMat = new QAction("List -> Mat", this);
            menuInsertionListMat->addAction(actionInsertionListVersMat);
            connect(actionInsertionListVersMat, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListGeneration = menuInsertionListMat->addMenu("Générations de Listes");
                QAction *actionInsertionDim = new QAction("Dim", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionDim);
                connect(actionInsertionDim, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionFill = new QAction("Fill", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionFill);
                connect(actionInsertionFill, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionSeq = new QAction("Seq", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionSeq);
                connect(actionInsertionSeq, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionAugment = new QAction("Augment", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionAugment);
                connect(actionInsertionAugment, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListSelection = menuInsertionListMat->addMenu("Sélection d'élements sur les Listes");
                QAction *actionInsertionMin = new QAction("Min", this);
                menuInsertionListMatListSelection->addAction(actionInsertionMin);
                connect(actionInsertionMin, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionMax = new QAction("Max", this);
                menuInsertionListMatListSelection->addAction(actionInsertionMax);
                connect(actionInsertionMax, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionMedian = new QAction("Median", this);
                menuInsertionListMatListSelection->addAction(actionInsertionMedian);
                connect(actionInsertionMedian, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListModifications = menuInsertionListMat->addMenu("Modifications sur les Listes");
                QAction *actionInsertionSortA = new QAction("SortA", this);
                menuInsertionListMatListModifications->addAction(actionInsertionSortA);
                connect(actionInsertionSortA, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionSortD = new QAction("SortD", this);
                menuInsertionListMatListModifications->addAction(actionInsertionSortD);
                connect(actionInsertionSortD, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListCalculs = menuInsertionListMat->addMenu("Calculs sur les Listes");
                QAction *actionInsertionMean = new QAction("Mean", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionMean);
                connect(actionInsertionMean, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionSum = new QAction("Sum", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionSum);
                connect(actionInsertionSum, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionProd = new QAction("Prod", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionProd);
                connect(actionInsertionProd, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionCuml = new QAction("Cuml", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionCuml);
                connect(actionInsertionCuml, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionPercent = new QAction("Percent", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionPercent);
                connect(actionInsertionPercent, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionListMat->addSeparator();

            QAction *actionInsertionMat = new QAction("&Mat", this);
            menuInsertionListMat->addAction(actionInsertionMat);
            connect(actionInsertionMat, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionMatVersList = new QAction("&Mat -> List", this);
            menuInsertionListMat->addAction(actionInsertionMatVersList);
            connect(actionInsertionMatVersList, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatMatGeneration = menuInsertionListMat->addMenu("Génération de Matrices");
                menuInsertionListMatMatGeneration->addAction(actionInsertionDim);
                menuInsertionListMatMatGeneration->addAction(actionInsertionFill);

            QMenu *menuInsertionListMatMatCalculs = menuInsertionListMat->addMenu("Calculs sur les matrices");
                QAction *actionInsertionDet = new QAction("Det", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionDet);
                connect(actionInsertionDet, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionTrn = new QAction("Trn", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionTrn);
                connect(actionInsertionTrn, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                menuInsertionListMatMatCalculs->addAction(actionInsertionAugment);

                QAction *actionInsertionIden = new QAction("Identity", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionIden);
                connect(actionInsertionIden, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionRef = new QAction("Ref", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionRef);
                connect(actionInsertionRef, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionRref = new QAction("Rref", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionRref);
                connect(actionInsertionRref, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionSwap = new QAction("Swap", this);
            menuInsertionListMat->addAction(actionInsertionSwap);
            connect(actionInsertionSwap, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionTimesRow = new QAction("*Row", this);
            menuInsertionListMat->addAction(actionInsertionTimesRow);
            connect(actionInsertionTimesRow, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionTimesRowPlus = new QAction("*Row+", this);
            menuInsertionListMat->addAction(actionInsertionTimesRowPlus);
            connect(actionInsertionTimesRowPlus, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionRowPlus = new QAction("Row+", this);
            menuInsertionListMat->addAction(actionInsertionRowPlus);
            connect(actionInsertionRowPlus, SIGNAL(triggered()), this, SLOT(insertionTexte()));

    menuInsertion->setDisabled(true);
    connect(this, SIGNAL(activerMenusProjet(bool)), menuInsertion, SLOT(setEnabled(bool)));

    QMenu *menuOutils = menuBar()->addMenu("&Outils");
        QAction *actionVueOnglet = new QAction("Vue en onglets", this);
        menuOutils->addAction(actionVueOnglet);
        actionVueOnglet->setCheckable(true);
        actionVueOnglet->setChecked(true);

        menuOutils->addSeparator();

        QAction *actionOptionsProjet = new QAction("Options du Projet", this);
        menuOutils->addAction(actionOptionsProjet);
        actionOptionsProjet->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionOptionsProjet, SLOT(setEnabled(bool)));


        QAction *actionOptionsProgramme = new QAction("Options du programme", this);
        menuOutils->addAction(actionOptionsProgramme);
        actionOptionsProgramme->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionOptionsProgramme, SLOT(setEnabled(bool)));

        menuOutils->addSeparator();

        QAction *actionFenetrePreferences = new QAction(QIcon::fromTheme("preferences-other"), "&Préférences...", this);
        menuOutils->addAction(actionFenetrePreferences);

    QMenu *menuAide = menuBar()->addMenu("&Aide");
        QAction *actionAideSommaire = new QAction("Sommaire...", this);
        menuAide->addAction(actionAideSommaire);
        actionAideSommaire->setShortcut(QKeySequence("F1"));

        menuAide->addSeparator();

        QAction *actionAPropos = new QAction("À Propos", this);
        menuAide->addAction(actionAPropos);

        QAction *actionAProposQt = new QAction("À Propos de Qt", this);
        menuAide->addAction(actionAProposQt);

    // ==============
    // == FIN MENU ==
    // ==============

    // =============
    // == TOOLBAR ==
    // =============

    QToolBar *toolBarMain = addToolBar("Fichier");
    toolBarMain->addAction(actionQuitter);
    toolBarMain->addAction(actionNouveauProgramme);
    toolBarMain->addAction(actionEnregistrerProgramme);
    toolBarMain->addAction(actionOuvrirProgramme);
    toolBarMain->addAction(actionFermerProgramme);
    toolBarMain->addSeparator();
    toolBarMain->addAction(actionFenetrePreferences);


    // =================
    // == FIN TOOLBAR ==
    // =================

    // =================
    // == DOCK WIDGET ==
    // =================

    treeView = new QTreeWidget;
    treeView->setColumnCount(2);
    QStringList *treeViewHeaders = new QStringList(QString("Nom"));
    treeViewHeaders->append(QString("Taille"));
    treeView->setHeaderLabels(*treeViewHeaders);

    QDockWidget *dockWidget = new QDockWidget("Gestionnaire de Projet", this);
    dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget->setWidget(treeView);
    dockWidget->setMinimumWidth(175);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
connect(this, SIGNAL(activerMenusProjet(bool)), actionNouveauProgramme, SLOT(setEnabled(bool)));
    // =====================
    // == FIN DOCK WIDGET ==
    // =====================

    // =============
    // == FENETRE ==
    // =============

    // Rien à déclarer

    // =================
    // == FIN FENETRE ==
    // =================

    connect(treeView, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(treeWidgetItemDoubleClicked(QTreeWidgetItem*,int)));

    connect(actionNouveauProjet, SIGNAL(triggered()), this,SLOT(nouveauProjet()));
    connect(actionNouveauProgramme, SIGNAL(triggered()), this, SLOT(nouveauProgramme()));

    connect(actionFermerProjet, SIGNAL(triggered()), this, SLOT(fermerProjet()));
    connect(actionFermerProgramme, SIGNAL(triggered()), this, SLOT(fermerProgramme()));

    connect(actionEnregistrerProjet, SIGNAL(triggered()), this, SLOT(enregistrerProjet()));
    connect(actionEnregistrerProgramme, SIGNAL(triggered()), this, SLOT(enregistrerProgramme()));

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(actionVueOnglet, SIGNAL(toggled(bool)), this, SLOT(changerVueOnglet(bool)));

    connect(actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    zoneCentrale->setViewMode(QMdiArea::TabbedView);

    setCentralWidget(zoneCentrale);

    this->setWindowTitle("Cat Editor");

    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{

}

void MainWindow::treeWidgetItemDoubleClicked(QTreeWidgetItem* treeWidgetItemClicked, int columnClicked)
{
    bool trouve(false);
    QList<QMdiSubWindow*>::Iterator it;
    // Itération sur la liste des subWindow de la MdiArea
    for (it = zoneCentrale->subWindowList().begin(); it != zoneCentrale->subWindowList().end(); ++it) {
        if ((*it)->windowTitle() == treeWidgetItemClicked->text(0)) { // Si Le titre de la fenetre est le meme que celui du treeWidgetItemClicked
            zoneCentrale->setActiveSubWindow(*it);
            trouve = true;
            break;
        }
    }

    if (!trouve) {
        QTextEdit *zoneTexte = new QTextEdit;
        QMdiSubWindow *subWindow = zoneCentrale->addSubWindow(zoneTexte, Qt::CustomizeWindowHint); // Qt::CustomizeWindowHint pour pouvoir redéfinir les raccourcis prédéfinis par QT
        subWindow->setWindowTitle(treeWidgetItemClicked->text(0));
        subWindow->show();
    }

}

QString MainWindow::catParser(const QString &contenu) const
{
    QString texteEnregistrement("");

    QStringList lignesTexte = contenu.split("\n"); // Traitement du texte par lignes

    foreach (QString ligne, lignesTexte) {
        foreach (const QString &pattern, keywordPatterns) {
            QRegExp expression(pattern);
            int index = expression.indexIn(ligne);

            while (index >= 0) {
                int length = expression.matchedLength();
                ligne.insert(index, QString("\\"));
                index = expression.indexIn(ligne, index + length);
            }
        }
        texteEnregistrement.append(ligne + "\n");
    }
    texteEnregistrement.remove(texteEnregistrement.length() - 1, 1); // Enleve le dernier retour à la ligne ajouté

    return texteEnregistrement;
}

QString MainWindow::genCatFile(const QMap<QString, Programme> &programmes) const
{
    QString catFile;
    foreach (Programme programmeEnCours, programmes) {
        QString contenuCatFile = catParser(programmeEnCours.contenu);
        int capacity = countCatFile(contenuCatFile);

        catFile += "%Header Record\n";
        catFile += "Format:TXT\n";
        catFile += "Communication SW:0\n";
        catFile += "Data Type:PG\n";
        catFile += "Capacity:" + (QString)capacity + "\n";
        catFile += "File Name:" + programmeEnCours.nomPourCalculatrice + "\n";
        catFile += "Group Name:\n";
        catFile += "Password:" + programmeEnCours.motDePasse + "\n";
        catFile += "Option1:NL\n";
        catFile += "Option2:\n";
        catFile += "Option3:\n";
        catFile += "%Data Record\n";
        catFile += contenuCatFile + "\n";
        catFile += "%End";
    }

    return catFile;
}

int MainWindow::countCatFile(const QString &contenuCatFile) const
{
    int count(0);
    for (int i = 0; i < contenuCatFile.length(); ++i) {
        if (contenuCatFile[i] == '\\') {
            //Count la commande en format RAW
        }
        else {
            count++;
        }
    }

    return count;
}

QDomDocument MainWindow::genFichierProjet(const Projet &projet) const
{
    /*
     * QDomImplementation imp = QDomDocument().implementation();
     * QDomDocument document(imp.createDocumentType(projetEnCours.name, QString("publicId"), QString("systemId")));
     */
    QDomDocument document(projet.name);
    QDomElement domElementProject = document.createElement("project");

    QDomElement domElementProjectName = document.createElement("name");
    domElementProjectName.appendChild(document.createTextNode(projet.name));
    domElementProject.appendChild(domElementProjectName);

    QDomElement domElementPrograms = document.createElement("programs");
    foreach(const Programme &programmeEnCours, projet.programmes) {
        QDomElement domElementCurrentProgram = document.createElement("program");

        QDomElement domElementProgramName = document.createElement("name");
        domElementProgramName.appendChild(document.createTextNode(programmeEnCours.name));
        domElementCurrentProgram.appendChild(domElementProgramName);

        QDomElement domElementCalculatorProgramName = document.createElement("calculator_name");
        domElementCalculatorProgramName.appendChild(document.createTextNode(programmeEnCours.nomPourCalculatrice));
        domElementCurrentProgram.appendChild(domElementCalculatorProgramName);

        domElementPrograms.appendChild(domElementCurrentProgram);
    }

    domElementProject.appendChild(domElementPrograms);

    document.appendChild(domElementProject);

    return document;
}

void MainWindow::ecrireProgramme(QString nomFichier, const QString &contenu) const
{
    QFile fichier(nomFichier);
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error("Impossible d'ouvrir / écrire dans le fichier. Vérifier l'emplacement de celui-ci.");
        return;
    }

    QTextStream fluxFichierProgramme(&fichier);
    fluxFichierProgramme << contenu;
}

QWidget* MainWindow::nouvelleFenetre(QString const& contenu) const
{
    QTextEdit *editeurTexte = new QTextEdit(contenu);
    editeurTexte->setFont(QFont("Monospace"));
    editeurTexte->setStyleSheet("background-color:white;");
    MyHighlighter *highlighter = new MyHighlighter(editeurTexte->document());
    return editeurTexte;
}

QString MainWindow::clearInsertText(QString texte) const
{
    texte.remove("&");

    if (texte == "Structure conditionnelle If")
        return "If I>=42\nThen \nElse \nIfEnd";

    else if (texte == "Boucle While")
        return "While I>=42\n\nWhileEnd";

    else if (texte == "Boucle Do LpWhile")
        return "Do\n\nLpWhile I>=42";

    else if (texte == "Boucle For")
        return "For 1->I To 42 Step 1\n\nNext";

    else if (texte == "List -> Mat")
        return "List->Mat(";

    else if (texte == "Mat -> List")
        return "Mat->List(";

    else if (texte == "To" || texte == "Step")
        return texte.append(" ").prepend(" ");

    else if (texte == "IfEnd" || texte == "WhileEnd" || texte == "Do" || texte == "Next")
        return texte;

    else if (texte == "If" || texte == "Then" || texte == "Else" || texte == "While" || texte == "LpWhile" || texte == "For"
             || texte == "List" || texte == "Dim" || texte == "Sum" || texte == "Prod" || texte == "Cuml" || texte == "Percent"
             || texte == "Mat" || texte == "Det" || texte == "Trn" || texte == "Identity" || texte == "Ref" || texte == "Rref" || texte == "Swap" || texte == "*Row" || texte == "*Row+" || texte == "Row+")
        return texte.append(" ");

    else if (texte == "Fill" || texte == "Seq" || texte == "Augment" || texte == "Min" || texte == "Max" || texte == "Median" || texte == "SortA" || texte == "SortD" || texte == "Mean")
        return texte.append("(");

    else
        return texte;
}

void MainWindow::nouveauProjet()
{
    bool okProjet = false;
    QString nomProjet = QInputDialog::getText(this, "Nouveau Projet", "Quel est le nom de votre projet ?", QLineEdit::Normal, QString(), &okProjet);

    if (okProjet && !nomProjet.isEmpty()) {
        bool ok = false;
        QString nomProgramme = QInputDialog::getText(this, "Nouveau Projet", "Quel est le nom de votre premier programme ?", QLineEdit::Normal, QString(), &ok);

        if (ok && !nomProgramme.isEmpty()) {
            zoneCentrale->closeAllSubWindows();
            QMdiSubWindow *newSubWindow = zoneCentrale->addSubWindow(nouvelleFenetre(), Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint); // Qt::CustomizeWindowHint pour pouvoir redéfinir les raccourcis prédéfinis par QT
            newSubWindow->setWindowTitle(nomProgramme);
            newSubWindow->show();

            QStringList *nouveauProgrammeHeader = new  QStringList(QString(nomProgramme));
            nouveauProgrammeHeader->append(QString("Non enregistré"));
            QTreeWidgetItem *treeWidgetNewItem = new QTreeWidgetItem(*nouveauProgrammeHeader);
            treeView->insertTopLevelItem(0, treeWidgetNewItem);

            Programme nouvProgramme;
            nouvProgramme.name = nomProgramme;

            emit activerMenusProjet(true);
            projetEnCours.name = nomProjet;
            projetEnCours.programmes.insert(nomProgramme, nouvProgramme);
            projetEnCours.dir = QDir();
        }
    }
}

void MainWindow::nouveauProgramme()
{
    bool ok = false;
    QString nomProgramme = QInputDialog::getText(this, "Nouveau Programme", "Quel est le nom de votre nouveau programme ?", QLineEdit::Normal, QString(), &ok);

    if (ok && !nomProgramme.isEmpty()) {
        QMdiSubWindow *subWindow = zoneCentrale->addSubWindow(nouvelleFenetre(), Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint);
        subWindow->setWindowTitle(nomProgramme);
        subWindow->show();

        QStringList *nouveauProgrammeHeader = new QStringList(QString(nomProgramme));
        nouveauProgrammeHeader->append(QString("Non enregistré"));
        QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(*nouveauProgrammeHeader);
        treeView->insertTopLevelItem(treeView->topLevelItemCount(), treeWidgetItem);

        Programme nouvProgramme;
        nouvProgramme.name = nomProgramme;

        projetEnCours.programmes.insert(nomProgramme, nouvProgramme);
    }
}

void MainWindow::fermerProjet()
{
    zoneCentrale->closeAllSubWindows();

    for (int i = treeView->topLevelItemCount()-1; i >= 0; --i) {
        treeView->takeTopLevelItem(i);
    }

    emit activerMenusProjet(false);
}

void MainWindow::fermerProgramme()
{
    zoneCentrale->closeActiveSubWindow();
}

void MainWindow::enregistrerProjet()
{
    if(projetEnCours.dir.path() == ".") {
        QString stringDirProjet = QFileDialog::getExistingDirectory(this, "Enregistrer le Projet");
        QDir dirProjet(stringDirProjet);

        if(dirProjet.exists() && dirProjet.path() != ".") {
            projetEnCours.dir = dirProjet;
        } else {
            return;
        }
    }

    QList<QMdiSubWindow*> programmesAEnregistrer = zoneCentrale->subWindowList();

    foreach (QMdiSubWindow* programme, programmesAEnregistrer) {
        QString texteAEnregistrer = catParser(((QTextEdit*)programme->widget())->toPlainText());
        projetEnCours.programmes[((QTextEdit*)programme->widget())->windowTitle()].contenu = texteAEnregistrer;

        /*
        try {
            ecrireProgramme(projetEnCours.fichierProgramme[programme->windowTitle()], texteAEnregistrer);
        } catch (std::exception const& e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
        */
    }

    QString contenuCatFile = genCatFile(projetEnCours.programmes);

    QDomDocument domDocumentProjet = genFichierProjet(projetEnCours);

    try {
        ecrireProgramme(projetEnCours.dir.path() + "/project.cated", domDocumentProjet.toString());
    } catch (std::exception const& e) {
            QMessageBox::critical(this, "Erreur", e.what());
    }
}

void MainWindow::enregistrerProgramme()
{
    QString nomProgramme = zoneCentrale->activeSubWindow()->windowTitle();
    QTextEdit *zoneTexteProgramme = (QTextEdit*)zoneCentrale->activeSubWindow()->widget();

    if (projetEnCours.dir.path() == ".") {
        QString stringDirProjet = QFileDialog::getExistingDirectory(this, "Enregistrer le Projet");
        QDir dirProjet(stringDirProjet);

        if(dirProjet.exists() && dirProjet.path() != ".") {
            projetEnCours.dir = dirProjet;
        } else {
            return;
        }
    }

    QString texteEnregistrement = catParser(zoneTexteProgramme->toPlainText());
    projetEnCours.programmes[nomProgramme].contenu = texteEnregistrement;

    /*
    try {
        ecrireProgramme(projetEnCours.fichierProgramme[nomProgramme], texteEnregistrement);
    } catch (std::exception const& e) {
        QMessageBox::critical(this, "Erreur", e.what());
    }
    */
}

void MainWindow::supprimerProgramme()
{
    QString nomProgramme = zoneCentrale->currentSubWindow()->windowTitle();
    for (int i = 0; i < treeView->topLevelItemCount(); ++i) {
        if(treeView->topLevelItem(i)->text(0) == nomProgramme) {
            treeView->takeTopLevelItem(i);
            break;
        }
    }

    projetEnCours.programmes.remove(nomProgramme);

    zoneCentrale->closeActiveSubWindow();
}

void MainWindow::insertionTexte()
{
    QAction *actionSender = (QAction*)sender(); // Action ayant envoyé le signal
    // Le qobject_cast<QTextEdit*> convertit le QWidget* retourné par ->widget() en QTextEdit*
    qobject_cast<QTextEdit*>(zoneCentrale->currentSubWindow()->widget())->insertPlainText(clearInsertText(actionSender->text()));
}

void MainWindow::changerVueOnglet(bool vueOnglet)
{
    if(vueOnglet)
        zoneCentrale->setViewMode(QMdiArea::TabbedView);
    else
        zoneCentrale->setViewMode(QMdiArea::SubWindowView);
}
