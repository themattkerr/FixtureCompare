#include "csvdialog.h"
#include "ui_csvdialog.h"
#include "constsants.h"

CSVDialog::CSVDialog(QWidget *parent, bool *ok) :
    QDialog(parent),
    ui(new Ui::CSVDialog)
{
    ui->setupUi(this);
    //setFixedSize(CSV_DIALOG_SIZE);
    adjustSize();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    if(!(*ok))
    {
        ui->label_2->setText("File WAS NOT created!!!");
    }
}

CSVDialog::~CSVDialog()
{
    delete ui;
}

void CSVDialog::on_CloseCSVdialog_clicked()
{
    close();
}
