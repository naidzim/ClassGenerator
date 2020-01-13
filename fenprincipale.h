#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>


class FenPrincipale: public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();

public slots:
    void genererCode();

private:

    void createLayout1();
    void createLayout2();
    void createLayout3();
    void createLayout4();

    QFormLayout *layout1;
    QLineEdit *nom ;
    QLineEdit *classeMere;

    QVBoxLayout *layout2;
    QCheckBox *protection;
    QCheckBox *genererConstructeur;
    QCheckBox *genererDesructeur;
    QGroupBox *optionsGr;

    QGroupBox *comGr;
    QFormLayout *layoutText;
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *role;

    QPushButton *generer;
    QPushButton *quitter;
    QHBoxLayout *layout4;
};

#endif // FENPRINCIPALE_H


