#include "evenement.h"
#include <QDebug>
#include "connexion.h"
Evenement::Evenement()
{
id=0;
type="";
lieu="";
avis="";
}
Evenement::Evenement(int id,QDate date,QString type,QString lieu,QString avis)
{
  this->id=id;
  this->type=type;
  this->lieu=lieu;
    this->avis=avis;
    this->date=date;

}
QString Evenement::get_type(){return  type;}
QString Evenement::get_lieu(){return  lieu;}
QString Evenement::get_avis(){return  avis;}
QDate Evenement::getDate(){return date;}
int Evenement::get_id(){return  id;}

bool Evenement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO EVENEMENT (ID, DATEE,TYPE,LIEU,AVIS) "
                    "VALUES (:id, :date, :type,:lieu,:avis)");
query.bindValue(":id", res);
query.bindValue(":date", date);
query.bindValue(":type", type);
query.bindValue(":lieu", lieu);
query.bindValue(":avis", lieu);


return    query.exec();
}

QSqlQueryModel * Evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from EVENEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("avis"));

    return model;
}

bool Evenement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from EVENEMENT where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

