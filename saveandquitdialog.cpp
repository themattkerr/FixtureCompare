#include "saveandquitdialog.h"
#include "ui_saveandquitdialog.h"
#include <QFileDialog>
#include "fixturedata.h"
#include "csvdialog.h"
#include "constsants.h"

SaveAndQuitDialog::SaveAndQuitDialog(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::SaveAndQuitDialog)
{
    m_cData = cData;
    ui->setupUi(this);
    setFixedSize(SAVE_AND_QUIT_SIZE);
}

SaveAndQuitDialog::~SaveAndQuitDialog()
{
    delete ui;
}

void SaveAndQuitDialog::on_buttonBox_accepted()
{
    bool ok;
    QString filename =  QFileDialog::getSaveFileName(this, tr("Save as FixtureFile"),  "" ,tr("FixtureFile (*.fxt)"));
    ok = m_cData->saveAsFxt(filename);
    CSVDialog *CSV = new CSVDialog (this, &ok);
    CSV->exec();

    close();
}

void SaveAndQuitDialog::on_buttonBox_rejected()
{
    close();
}
