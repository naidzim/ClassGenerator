#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QtWidgets>
#include <QApplication>

class FenCodeGenere : public QDialog
{
public:
    FenCodeGenere(QString &code, QWidget *parent);

private:
    QTextEdit *codeGenere;
    QPushButton *fermer;

};

#endif // FENCODEGENERE_H
