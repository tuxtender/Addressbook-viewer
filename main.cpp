/*!
 * \file
 * \brief The main() function file.
 * \author Denis Vasilenko <tuxtender@gmail.com>
 * \date June 2020
 * \copyright (C) 2020 Denis Vasilenko
 */

#include "addressbook.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Addressbook w;
    Model m;
    w.setModel(&m);
    w.show();
    return a.exec();
}
