/*!
 * \file
 * \brief A header file the Model class.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 *
 * File contains Model declarations.
 */

#ifndef MODEL_H
#define MODEL_H

#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QList>

/*!
 * \defgroup model Model
 * \brief This group defines an classes that is used
 * by views to access data.
 */

/*!
 * \brief Access to database and fetch data from there at startup.
 * \warning Read only mode. Editing is not suggested.
 * \warning No tracking database changes during application running.
 *
 * The Model class derived public Inheritance from QStandardItemModel
 * implements an interface for interacting with Views classes.
 * Unlike QAbstractItemModel it has defined methods
 * index(), data(), rowCount(), columnCount()
 * for View interaction with a hierarchical (2-level in this case) structure.
 *
 * \ingroup model Model
 */
class Model : public QStandardItemModel
{
public:
    /*!
     * \brief Constructor that initiat from Sqlite database.
     *
     * Initiates QStandardItem instance by read database at startup.
     * Required column names of tables is hard coded in sql query.
     * \warning No tracking database changes during application running.
     *
     * \include model.cpp
     */
    Model(QObject *parent = 0);

     //! Destroy model.
    virtual ~Model();
};

#endif // MODEL_H
