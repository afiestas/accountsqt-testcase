#include <QCoreApplication>
#include "accountsqt-testcase.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    accountsqt_testcase foo;
    return app.exec();
}
