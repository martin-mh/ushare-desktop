/* Welcome in USquare !! I'm really happy to see you here :-)
 * Don't be scary about comment or edit the code :-P
 * I hope you a good journey in this code :-) *
*/

/**
 * This file (c) by : - Martin Hammerchmidt alias Imote
 *
 * This file is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0
 * International License.
 *
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 *
 * If you have contributed to this file, add your name to authors list.
*/

#include <QApplication>
#include <QtQml>
#include "uplimg.h"

//#include "core/settings.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //app.setQuitOnLastWindowClosed(false);

    QCoreApplication::setOrganizationName("USquare");
    QCoreApplication::setOrganizationDomain("usquare.io");
    QCoreApplication::setApplicationName("U²");

    Uplimg uplimg;
    uplimg.start();



    return app.exec();
}
