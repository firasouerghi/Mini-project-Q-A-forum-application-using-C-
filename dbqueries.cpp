#include "dbqueries.h"


void initUsersList()
{
    //connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("us-cdbr-iron-east-05.cleardb.net");
    db.setDatabaseName("heroku_90f5a4881d13b5e");
    db.setPort(3306);
    db.setUserName("bbb060321ad72d");
    db.setPassword("c7f99f67");
    bool status = db.open();

    if(status == false)
    {
        db.close();
    }

    else
    {
       QSqlQuery query1;
       query1.exec("SELECT * FROM users");
       while(query1.next())
       {
           QString username = query1.value(0).toString();
           QString email = query1.value(1).toString();
           QString password = query1.value(2).toString();
           QString creationdate = query1.value(3).toString();
           int isactive = query1.value(4).toInt();
           QString name = query1.value(5).toString();
           QString surname = query1.value(6).toString();
           QString birthday = query1.value(7).toString();
           QString signature = query1.value(8).toString();
           QString occupation = query1.value(9).toString();
           int role = query1.value(10).toInt();

           userProfile up;
           up.account.setEmail(email.toStdString());
           up.account.setPassword(password.toStdString());
           up.account.setUsername(username.toStdString());
           up.account.setCreationDate(creationdate.toStdString());
           up.account.setStatus(isactive);
           up.setBirthday(birthday.toStdString());
           up.setName(name.toStdString());
           up.setOccupation(occupation.toStdString());
           up.setRole(role);
           up.setSignature(signature.toStdString());
           up.setSurname(surname.toStdString());

           myPlatformFull.addUser(up);
       }

       QSqlQuery query2;
       query2.exec("SELECT * FROM admins");
       while (query2.next())
       {
           QString username = query2.value(0).toString();
           QString email = query2.value(1).toString();
           QString password = query2.value(2).toString();
           QString creationdate = query2.value(3).toString();
           int isactive = query2.value(4).toInt();
           QString name = query2.value(5).toString();
           QString surname = query2.value(6).toString();
           QString birthday = query2.value(7).toString();
           QString signature = query2.value(8).toString();
           QString occupation = query2.value(9).toString();
           int role = query2.value(10).toInt();

           Admin admintemp;
           admintemp.account.setEmail(email.toStdString());
           admintemp.account.setPassword(password.toStdString());
           admintemp.account.setUsername(username.toStdString());
           admintemp.account.setCreationDate(creationdate.toStdString());
           admintemp.account.setStatus(isactive);
           admintemp.setBirthday(birthday.toStdString());
           admintemp.setName(name.toStdString());
           admintemp.setOccupation(occupation.toStdString());
           admintemp.setRole(role);
           admintemp.setSignature(signature.toStdString());
           admintemp.setSurname(surname.toStdString());

           myPlatformFull.addAdmin(admintemp);
       }
    db.close();
    }

}

void initCatsList()
{
    //connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("us-cdbr-iron-east-05.cleardb.net");
    db.setDatabaseName("heroku_90f5a4881d13b5e");
    db.setPort(3306);
    db.setUserName("bbb060321ad72d");
    db.setPassword("c7f99f67");
    bool status = db.open();

    //Echec de connexion
    if(status == false)
    {
        db.close();
    }

    //Connexion réussie
    else
    {
       QSqlQuery query1;
       query1.exec("SELECT * FROM categories");
       while(query1.next())
       {
           int id = query1.value(0).toInt();
           QString title = query1.value(1).toString();
           QString description = query1.value(2).toString();
           int isvisible = query1.value(3).toInt();

           Category tempcat;
           tempcat.setDescription(description.toStdString());
           tempcat.setTitle(title.toStdString());
           tempcat.setID(id);
           tempcat.setStatus(isvisible);
           myPlatformFull.addCategory(tempcat);
       }
       db.close();
    }
}

void initTopicsList()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("us-cdbr-iron-east-05.cleardb.net");
    db.setDatabaseName("heroku_90f5a4881d13b5e");
    db.setPort(3306);
    db.setUserName("bbb060321ad72d");
    db.setPassword("c7f99f67");
    bool status = db.open();

    if(status == false)
    {
        db.close();
    }

    else
    {
        for(unsigned i = 0 ; i < myPlatformFull.categories.size() ; i++)
        {
            QSqlQuery query;
            query.prepare("SELECT * FROM topics WHERE catID = ?");
            query.addBindValue(myPlatformFull.categories[i].getID());
            query.exec();
            while(query.next())
            {
                int id = query.value(0).toInt();
                QString title = query.value(1).toString();
                QString body = query.value(2).toString();
                QString author = query.value(3).toString();
                QString date = query.value(4).toString();
                int isvisible = query.value(5).toInt();
                int catID = query.value(6).toInt();

                Topic temptopic;
                temptopic.setAuthor(author.toStdString());
                temptopic.setBody(body.toStdString());
                temptopic.setID(id);
                temptopic.setStatus(isvisible);
                temptopic.setTitle(title.toStdString());
                temptopic.setDate(date.toStdString());
                temptopic.setCatID(catID);
                myPlatformFull.categories[i].addTopic(temptopic);
            }

        }
       db.close();
    }
}

void initRepliesList()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("us-cdbr-iron-east-05.cleardb.net");
    db.setDatabaseName("heroku_90f5a4881d13b5e");
    db.setPort(3306);
    db.setUserName("bbb060321ad72d");
    db.setPassword("c7f99f67");
    bool status = db.open();

    if(status == false)
    {
        db.close();
    }

    else
    {
        for(unsigned i = 0; i < myPlatformFull.categories.size();i++)
        {
            for(unsigned j = 0; j < myPlatformFull.categories[i].topics.size();j++)
            {
                QSqlQuery query;
                query.prepare("SELECT * FROM replies WHERE topicID = ? ");
                query.addBindValue(myPlatformFull.categories[i].topics[j].getID());
                query.exec();
                while (query.next())
                {
                    int id = query.value(0).toInt();
                    QString body = query.value(1).toString();
                    QString author = query.value(2).toString();
                    QString date = query.value(3).toString();
                    int isVisible =  query.value(4).toInt();
                    int topicID = query.value(5).toInt();

                    Reply tempreply;

                    tempreply.setAuthor(author.toStdString());
                    tempreply.setBody(body.toStdString());
                    tempreply.setID(id);
                    tempreply.setStatus(isVisible);
                    tempreply.setDate(date.toStdString());
                    tempreply.setTopicID(topicID);

                    myPlatformFull.categories[i].topics[j].addReply(tempreply);

                }
            }
        }


       db.close();
    }
}

void initPMsList()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("us-cdbr-iron-east-05.cleardb.net");
    db.setDatabaseName("heroku_90f5a4881d13b5e");
    db.setPort(3306);
    db.setUserName("bbb060321ad72d");
    db.setPassword("c7f99f67");
    bool status = db.open();

    if(status == false)
    {
        db.close();
    }

    else
    {
        for(unsigned i = 0; i < myPlatformFull.users.size();i++)
        {
            QSqlQuery query;
            query.prepare("SELECT * FROM privatemessages WHERE sender = ? OR receiver = ?");
            QString qstr = QString::fromStdString(myPlatformFull.users[i].account.getUsername());
            query.addBindValue(qstr);
            query.addBindValue(qstr);
            query.exec();
            while(query.next())
            {
                PrivateMessage pm;
                int id = query.value(0).toInt();
                int isvisibleforreceiver = query.value(1).toInt();
                QString sender = query.value(2).toString();
                QString receiver = query.value(3).toString();
                QString title = query.value(4).toString();
                QString body = query.value(5).toString();
                QString date = query.value(6).toString();
                int isvisibleforsender = query.value(7).toInt();
                pm.setBody(body.toStdString());
                pm.setDate(date.toStdString());
                pm.setID(id);
                pm.setReceiver(receiver.toStdString());
                pm.setSender(sender.toStdString());
                pm.setTitle(title.toStdString());
                pm.setVisR(isvisibleforreceiver);
                pm.setVisS(isvisibleforsender);
                myPlatformFull.users[i].addPM(pm);
            }
        }
        for(unsigned i = 0; i < myPlatformFull.admins.size();i++)
        {
            QSqlQuery query;
            query.prepare("SELECT * FROM privatemessages WHERE sender = ? OR receiver = ?");
            QString qstr = QString::fromStdString(myPlatformFull.admins[i].account.getUsername());
            query.addBindValue(qstr);
            query.addBindValue(qstr);
            query.exec();
            while(query.next())
            {
                PrivateMessage pm;
                int id = query.value(0).toInt();
                int isvisibleforreceiver = query.value(1).toInt();
                QString sender = query.value(2).toString();
                QString receiver = query.value(3).toString();
                QString title = query.value(4).toString();
                QString body = query.value(5).toString();
                QString date = query.value(6).toString();
                int isvisibleforsender = query.value(7).toInt();
                pm.setBody(body.toStdString());
                pm.setDate(date.toStdString());
                pm.setID(id);
                pm.setReceiver(receiver.toStdString());
                pm.setSender(sender.toStdString());
                pm.setTitle(title.toStdString());
                pm.setVisR(isvisibleforreceiver);
                pm.setVisS(isvisibleforsender);
                myPlatformFull.admins[i].addPM(pm);
            }
        }

       db.close();
    }
}
