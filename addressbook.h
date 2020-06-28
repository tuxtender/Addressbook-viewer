/*!
 * \file
 * \brief A header file an Addressbook class.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 *
 * File contains Addressbook class declarations
 * a main window application.
 */

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "namelistview.h"
#include <QtWidgets>

/*!
 * \defgroup view View
 *
 * \brief View classes.
 *
 * This group defines an classes
 * that is used by the view
 * obtains items of data from
 * the model and presents them to the user.
*/

/*!
 * \brief Container for ComboBox and ListWidget items.
 *
 * Common application class that is container
 * and layout manager for other QWidget objects
 * like QComboBox, NameListView.
 *
 * \ingroup view View
 */
class Addressbook : public QWidget
{
    Q_OBJECT

public:

     //! Constructs a combobox with the given parent.

    Addressbook(QWidget *parent = nullptr);

    /*!
     * \brief Destroy addressbook.
     *
     * It's not necessary. Relying on Qt memory management
     * the parent QObject class will delete
     * all the objects in its child list
     * when the parent take destroyed at first.
     */
    virtual ~Addressbook();

    /*!
     * \brief Sets the model.
     *
     * Set appropriate model to a class
     * private members derivatives from QWidget.
     */
    void setModel(QAbstractItemModel *model);

private:

    QComboBox *pComboBox;
    NameListView *pNameList;
    QVBoxLayout *pvbxLayout;

};

#endif // ADDRESSBOOK_H
