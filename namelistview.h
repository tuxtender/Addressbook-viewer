/*!
 * \file
 * \brief A header file the NameListView class.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 *
 * File contains NameListView declarations.
 */

#ifndef NAMELISTVIEW_H
#define NAMELISTVIEW_H

#include <QtWidgets>
#include <QListView>

/*!
 * \brief The list with model/view architecture support.
 *
 * A NameListView is derived from the QListView class
 * presents items stored in a model
 * looks as a simple non-hierarchical list.
 *
 * \ingroup view View
 */

class NameListView : public QListView
{
    Q_OBJECT

public:

    //! Constructs a list with the given parent.
    NameListView(QWidget *parent = 0);

    //! Destroy list.
    virtual ~NameListView();

public slots:
    /*!
     * \brief Match between integer index and a model index item.
     * \param integer index is emitted by QComboBox signal
     * \return none
     *
     * Changes QModelIndex parent item in NameListView's model.
     * Overrides QAbstractItemView slot method:
     * \code
     *      void setRootIndex(const QModelIndex &index)
     * \endcode
     * It match integer index of QComboBox item
     * to a model index of NameListView object.
     *
     * \code
     *  void NameListView::setRootIndex(int row)
     *  {
     *      QModelIndex idx = model()->index(row, 0);
     *       QListView::setRootIndex(idx);
     *  }
     * \endcode
     */
    void setRootIndex(int index);

};

#endif // NAMELISTVIEW_H
