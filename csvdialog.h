#ifndef CSVDIALOG_H
#define CSVDIALOG_H

#include <QDialog>

namespace Ui {
class CSVDialog;
}

class CSVDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CSVDialog(QWidget *parent = 0, bool *ok = 0);
    ~CSVDialog();

private slots:
    void on_CloseCSVdialog_clicked();

private:
    Ui::CSVDialog *ui;
};

#endif // CSVDIALOG_H
