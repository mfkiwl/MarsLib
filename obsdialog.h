#ifndef OBSDIALOG_H
#define OBSDIALOG_H

#include <QDialog>
#include <QLineEdit>
namespace Ui {
class ObsDialog;
}

class ObsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ObsDialog(QWidget *parent = nullptr);
    ~ObsDialog();

private slots:

    void on_search1_clicked();
    void on_search2_clicked();

    void on_analysisButton_clicked();

private:
    Ui::ObsDialog *ui;
    void analysis_file();
    QStringList fileNameListFirst;
    QStringList fileNameListSecond;
    double *ecef;
    double *pos;
};

#endif // OBSDIALOG_H
