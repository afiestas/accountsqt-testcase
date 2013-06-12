#include "accountsqt-testcase.h"

#include <QtCore/QDebug>

#include <Accounts/Manager>
#include <Accounts/Account>

accountsqt_testcase::accountsqt_testcase()
{
    m_manager = new Accounts::Manager(this);
    connect(m_manager, SIGNAL(accountCreated(Accounts::AccountId)), SLOT(monitorAccount(Accounts::AccountId)));

    Accounts::AccountIdList accList = m_manager->accountList();
    Q_FOREACH(const Accounts::AccountId &id, accList) {
        monitorAccount(id);
    }
}

accountsqt_testcase::~accountsqt_testcase()
{}

void accountsqt_testcase::monitorAccount(Accounts::AccountId id)
{
    qDebug() << "Monitor account: " << id;
    Accounts::Account *acc =  m_manager->account(id);
    connect(acc, SIGNAL(enabledChanged(QString,bool)), SLOT(enabledChanged(QString,bool)));
}

void accountsqt_testcase::enabledChanged(QString service, bool enabled)
{
    qDebug() << "enableChanged: " << service << enabled;
}


#include "accountsqt-testcase.moc"
