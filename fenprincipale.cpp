#include "fenprincipale.h"
#include "fencodegenere.h"

FenPrincipale::FenPrincipale()
{

    // Layout principale
    QVBoxLayout *layoutPrincipale = new QVBoxLayout;

    //Partie 1 : nom et classe mere
    createLayout1();

    //Partie 2 : layout des CheckBox
    createLayout2();

    //Partie 3 : layout des commentaires
    createLayout3();

    //Partie 4 : layout des commentaires
    createLayout4();

    //Ajout des layouts au layout principal
    layoutPrincipale->addLayout(layout1);
    layoutPrincipale->addWidget(optionsGr);
    layoutPrincipale->addWidget(comGr);
    layoutPrincipale -> addLayout(layout4);

    setLayout(layoutPrincipale);


    // LES SLOTS
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()) );
    connect(generer, SIGNAL(clicked()), this, SLOT(genererCode()));
}

void FenPrincipale::createLayout1()
{
    layout1 = new QFormLayout; // layout contenant le nom et la classe mere
    nom = new QLineEdit;
    classeMere = new QLineEdit;
    layout1 -> addRow("Nom de la classe",nom);
    layout1 -> addRow("Classe mere",classeMere);

}

void FenPrincipale::createLayout2()
{
    protection = new QCheckBox("ajouter une protection");
    genererConstructeur = new QCheckBox("Generer un constructeur");
    genererDesructeur = new QCheckBox("Generer un destructeur");

    layout2 = new QVBoxLayout;
    layout2 -> addWidget(protection);
    layout2 -> addWidget(genererConstructeur);
    layout2 -> addWidget(genererDesructeur);

    optionsGr = new QGroupBox("Options");
    optionsGr->setLayout(layout2);
}

void FenPrincipale::createLayout3()
{
    auteur = new QLineEdit;
    date = new QDateEdit;
    date-> setDate(QDate::currentDate());
    date -> setMaximumDate(QDate::currentDate());
    role = new QTextEdit;

    layoutText = new QFormLayout;
    layoutText -> addRow("Auteur :",auteur);
    layoutText -> addRow("Date de creation :",date);
    layoutText -> addRow("Role de la classe :",role);

    comGr = new QGroupBox("Ajouter des commentaires");
    comGr -> setCheckable(true);
    comGr -> setChecked(false);
    comGr->setLayout(layoutText);
}

void FenPrincipale::createLayout4()
{
    generer = new QPushButton("Generer",this);
    quitter = new QPushButton("Quitter",this);
    layout4 = new QHBoxLayout;

    layout4 -> addWidget(generer);
    layout4 -> addWidget(quitter);
    layout4 -> setAlignment(Qt::AlignRight);
}

void FenPrincipale::genererCode()
{
    if (nom ->text().isEmpty() )
    {
        QMessageBox::critical(this,"Erreur","Veillez entrer au moins un nom de classe");
        return; //arret de la methode (void)
    }

    QString code;

    // generation du code a partir des infos saisies

    if ( !(auteur->text().isEmpty()) ||  ! (role->toPlainText().isEmpty()) )
    {
        code +="/* \nAuteur : ";
        code += auteur->text();
        code += "\nDate de création : ";
        code += date->date().toString();
        code +="\nRole: \n";
        code += role->toPlainText();
        code +="\n*/ \n\n\n";
    }

    if (protection->isChecked())
    {
        code += "#ifndef ";
        code += nom->text().toUpper();
        code +="\n";
        code += "#define ";
        code += nom->text().toUpper();
        code +="\n\n";
    }

    code += "class ";
    code += nom->text();
    if ( !(classeMere->text().isEmpty()))
    {
        code +=": public ";
        code += classeMere->text();
        code += "\n";
    }
    code += "{ \n";
    code += "\npublic: \n\n";
    if(genererConstructeur->isChecked())
    {
        code +="    ";
        code += nom->text();
        code +="();\n";
    }
    if (genererDesructeur->isChecked())
    {
        code +="    ";
        code +="~";
        code += nom->text();
        code +="();\n";
    }
    code += "\nprotected:\n\nprivate: \n\n };";
    code += "\n#endif //";
    code += nom->text().toUpper();


    //Creation puis affichage du code generer
    FenCodeGenere *fenetreCode = new FenCodeGenere(code,this);
    fenetreCode->exec();
}
