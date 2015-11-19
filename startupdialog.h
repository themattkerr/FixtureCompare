#ifndef STARTUPDIALOG_H
#define STARTUPDIALOG_H

#include <QDialog>

#ifndef FIXTUREDATA_H
#include "fixturedata.h"
#endif //fixturedata.h


namespace Ui {
class startUpDialog;
}

class startUpDialog : public QDialog
{
    Q_OBJECT

public:
    //explicit
    startUpDialog(QWidget *parent = 0, AllData *cData = 0);
    ~startUpDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();



private:
    Ui::startUpDialog *ui;
    AllData *m_cData;
};

#endif // STARTUPDIALOG_H
