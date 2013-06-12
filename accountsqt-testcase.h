#ifndef accountsqt_testcase_H
#define accountsqt_testcase_H

#include <QtCore/QObject>

#include <Accounts/Account>
#include <Accounts/Manager>

class accountsqt_testcase : public QObject
{
Q_OBJECT
public:
    accountsqt_testcase();
    virtual ~accountsqt_testcase();

public slots:
    void monitorAccount(Accounts::AccountId);
    void enabledChanged(QString,bool);

private:
    Accounts::Manager *m_manager;
};

#endif // accountsqt_testcase_H
