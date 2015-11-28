#ifndef SAVEANDQUITDIALOG_H
#define SAVEANDQUITDIALOG_H

#include <QDialog>

#ifndef FIXTUREDATA_H
#include "fixturedata.h"
#endif //FIXTUREDATA_H


namespace Ui {
class SaveAndQuitDialog;
}

class SaveAndQuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveAndQuitDialog(QWidget *parent = 0, AllData *cData = 0);
    ~SaveAndQuitDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SaveAndQuitDialog *ui;
    AllData *m_cData;
};

#endif // SAVEANDQUITDIALOG_H
