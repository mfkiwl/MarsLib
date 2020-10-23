#include "obsdialog.h"
#include "ui_obsdialog.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>

ObsDialog::ObsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObsDialog)
{
    ui->setupUi(this);
}

ObsDialog::~ObsDialog()
{
    delete ui;
}

void ObsDialog::on_search1_clicked()
{
    fileNameListFirst =QFileDialog::getOpenFileNames(this,tr("Open Obs/Nav Data"),
                                          QString(),tr("RINEX OBS (*.obs *.*o *.*d *.*o.gz *.*o.Z *.d.gz *.d.Z);;All (*.*)"));

    ui->datafilefirst->setText(fileNameListFirst.join("; "));
    analysis_file();
}

void ObsDialog::on_search2_clicked()
{
    fileNameListSecond =QFileDialog::getOpenFileNames(this,tr("Open Obs/Nav Data"),
                                          QString(),tr("RINEX OBS (*.obs *.*o *.*d *.*o.gz *.*o.Z *.d.gz *.d.Z);;All (*.*)"));

    ui->datafilesecond->setText(fileNameListSecond.join("; "));

}

void ObsDialog::analysis_file(){
    qDebug()<<"it works"<<endl;
    ui->progressBar->setValue(100);
}

void ObsDialog::on_analysisButton_clicked()
{
    if  (fileNameListFirst.size()<=0 || fileNameListSecond.size()<=0){
        return;
    }

    analysis_file();

}
