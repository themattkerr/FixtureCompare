#ifndef FIXTUREEDITDIALOG_H
#define FIXTUREEDITDIALOG_H

#include <QDialog>

#ifndef FIXTUREDATA_H
#include "fixturedata.h"
#endif

namespace Ui {
class FixtureEditDialog;
}

class FixtureEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit
    FixtureEditDialog(QWidget *parent = 0, AllData *cData = 0);
    ~FixtureEditDialog();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    //void on_DistMetersSpinBox_valueChanged(double arg1);

    void on_CandelaBox_editingFinished();

    //void on_LuxSpinBox_valueChanged(double arg1);

    //void on_FootCandleSpinBox_valueChanged(double arg1);

    //void on_BeamSizeMetersSpinBox_2_valueChanged(double arg1);

    //void on_BeamSizeFeetSpinBox_3_valueChanged(double arg1);

    //void on_FieldAngleSpinBox_valueChanged(double arg1);

    void on_Lumens_editingFinished();

    //void on_DistFeetSpinBox_2_valueChanged(double arg1);

    void on_FixtureName_editingFinished();

    void on_NavigationButtons_accepted();

    void on_DistMetersSpinBox_editingFinished();

    void on_DistFeetSpinBox_2_editingFinished();

    void on_LuxSpinBox_editingFinished();

    void on_FootCandleSpinBox_editingFinished();

    void on_BeamSizeMetersSpinBox_2_editingFinished();

    void on_BeamSizeFeetSpinBox_3_editingFinished();

    void on_FieldAngleSpinBox_editingFinished();

    void on_RemoveFixture_clicked();

private:
    Ui::FixtureEditDialog *ui;
    void setEditFieldsToCurrentState();

    AllData *m_cData;
};

#endif // FIXTUREEDITDIALOG_H
