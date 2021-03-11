#ifndef Evenement_H
#define Evenement_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class Evenement
{public:
    Evenement();
    Evenement(int,QDate,QString,QString,QString);
    QDate getDate();
    QString get_type();
    QString get_lieu();
    QString get_avis();


    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString type,lieu,avis;
    int id;
    QDate date;
};

#endif // Evenement_H
