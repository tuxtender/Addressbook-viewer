/*!
 * \file
 * \brief Source code for the Addressbook class.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 *
 * File contains an Addressbook class implementation.
 */

#include "model.h"

Model::Model(QObject *parent) :  QStandardItemModel(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("addrbooks.db");
    db.open();

    QStandardItem *parentItem;
    QSqlQuery queryGroup("SELECT * FROM prj_group");
    QString sql = "SELECT family, first_name, second_name "
                  "FROM prj_group_addrbook "
                  "WHERE prj_group_id = :id";
    QSqlQuery queryName;
    queryName.prepare(sql);

    while (queryGroup.next()) {
        parentItem = invisibleRootItem();
        QStandardItem *item = new QStandardItem(queryGroup.value("name").toString());
        parentItem->appendRow(item);
        parentItem = item;

        QVariant foreignKey = queryGroup.value("prj_group_id");
        queryName.bindValue(":id", foreignKey);
        queryName.exec();

        while (queryName.next()) {
            QStringList names;
            int columnCount = queryName.record().count();

            for (int i=0; i<columnCount; i++)
                names << qvariant_cast<QString>(queryName.value(i));

            QStandardItem *item = new QStandardItem(names.join(" "));
            parentItem->appendRow(item);
        }

    }

    db.close();

}

Model::~Model()
{
}
