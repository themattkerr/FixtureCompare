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


    void on_CandelaBox_editingFinished();

    void on_Lumens_editingFinished();

    void on_FixtureName_editingFinished();

    void on_NavigationButtons_accepted();

    void on_DistMetersSpinBox_editingFinished();

    void on_DistFeetSpinBox_2_editingFinished();

    void on_LuxSpinBox_editingFinished();

    void on_FootCandleSpinBox_editingFinished();

    void on_FieldSizeMetersSpinBox_editingFinished();

    void on_FieldSizeFeetSpinBox_editingFinished();

    void on_FieldAngleSpinBox_editingFinished();

    void on_RemoveFixture_clicked();

    void on_Next_clicked();

    void on_Last_clicked();

    void on_NavigationButtons_rejected();



    void on_showLessButton_clicked();

    void on_showMoreButton_clicked();

    void on_wattageSpinBox_editingFinished();

    void on_efficacySpinBox_editingFinished();

    void on_colorTempBox_editingFinished();
    void on_cRISpinBox_editingFinished();
    void on_streetPriceBox_editingFinished();

    void on_listPriceBox_editingFinished();

    void on_BeamSizeMetersSpinBox_editingFinished();

    void on_BeamSizeFeetSpinBox_editingFinished();

    void on_BeamAngleSpinBox_editingFinished();



    void on_otherInfoBox_textChanged();

    void on_LEDMixBox_editingFinished();

    void on_copyToNewButton_clicked();

private:
    Ui::FixtureEditDialog *ui;
    void setEditFieldsToCurrentState();

    AllData *m_cData;
    QWidget *m_Parent;

};

#endif // FIXTUREEDITDIALOG_H
