/*!
 * \file
 * \brief Source code for the NameListView class.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 *
 * File contains NameListView implementation.
 */

#include "namelistview.h"

NameListView::NameListView(QWidget *parent) : QListView(parent)
{
}

NameListView::~NameListView()
{
}

void NameListView::setRootIndex(int row)
{
    QModelIndex idx = model()->index(row, 0);
    QListView::setRootIndex(idx);
}


