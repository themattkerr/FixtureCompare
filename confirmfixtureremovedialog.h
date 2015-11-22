#ifndef CONFIRMFIXTUREREMOVEDIALOG_H
#define CONFIRMFIXTUREREMOVEDIALOG_H

#include <QDialog>

#ifndef FIXTUREDATA_H
#include "fixturedata.h"
#endif // FIXTUREDATA_H


namespace Ui {
class ConfirmFixtureRemoveDialog;
}

class ConfirmFixtureRemoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmFixtureRemoveDialog(QWidget *parent = 0, AllData *cData = 0);

    ~ConfirmFixtureRemoveDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ConfirmFixtureRemoveDialog *ui;
    AllData *m_cData;
};

#endif // CONFIRMFIXTUREREMOVEDIALOG_H
