/*!
 * \file
 * \brief Source code for the Addressbook class.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 *
 * File contains an Addressbook class definitions.
 */

#include "addressbook.h"

Addressbook::Addressbook(QWidget *parent) : QWidget(parent)
{
    pComboBox = new QComboBox;
    pNameList = new NameListView;
    pvbxLayout = new QVBoxLayout;

    pvbxLayout->addWidget(pComboBox);
    pvbxLayout->addWidget(pNameList);

    setLayout(pvbxLayout);

    QObject::connect(pComboBox, SIGNAL(activated(int)),
                     pNameList, SLOT(setRootIndex(int))
                    );

    setWindowTitle(tr("Addressbook"));
}

void Addressbook::setModel(QAbstractItemModel *model)
{
    pComboBox->setModel(model);
    pNameList->setModel(model);
    //Descend to sublevel of model NameListView object
    emit pComboBox->activated(0);
}

Addressbook::~Addressbook()
{
}

