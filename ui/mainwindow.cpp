#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rtklib.h"
#include <QFileDialog>
#include <locale.h>
#include <QDebug>
#include <string>
#include <iomanip>
#include <iostream>
#include <mars.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setNativeMenuBar(false);
    m_portNameList =getPortNameList();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionserial_triggered()
{
    QStringList files =QFileDialog::getOpenFileNames(this,tr("Open Obs/Nav Data"),
                                          QString(),
                                          tr("RINEX OBS (*.obs *.nav *.*o *.*d *.*o.gz *.*o.Z *.d.gz *.d.Z);;All (*.*)"));
    obs_t obs ={0,0,NULL};
    nav_t nav;
    sta_t sta;
    int nobs;

    gtime_t ts,te ={0,0};
    double tint =0.0;
    int i,n;
    char obsfile[1024],navfile[1024]="",*p,*q,opt[2048];

    strcpy(opt,qPrintable("plot/rnxopts"));
    setlocale(LC_NUMERIC,"C"); // use point as decimal separator in formated output

    memset(&nav,0,sizeof(nav_t));
    memset(&sta,0,sizeof(sta_t));

    if  (files.size()==0)return;

    for (i=0;i<files.count();i++) {
           strcpy(obsfile,qPrintable(QDir::toNativeSeparators(files.at(i))));
           if (readrnxt(obsfile,1,ts,te,tint,opt,&obs,&nav,&sta)<0) {
               qDebug()<<"return"<<endl;
               return ;
           }

       }

    double *rov =new double(3);

    if(obs.n>0 && nav.n>0){
        int n = obs.n;
        snoise_t *snoise =(snoise_t *)malloc(sizeof (snoise_t)*60);

        gtime_t gtime = obs.data[0].time;
        double *rs = new double[6 * n];
        double *dts = new double[2 *n];
        double *var = new double[n];
        int *svh = new int[n];

        satpossp(gtime,obs.data,obs.n,&nav,EPHOPT_BRDC,rs,dts,var,svh);
        for (int num =0;num<n;num++) {
            std::cout <<std::fixed << std::setprecision(6)<< rs[0+num*6] <<"  " << rs[1+num*6] << " "<<rs[2+num*6]<<std::endl;

            for (;;) {

            }
        }
    }

    /*distance eph2rov */

//    snoise_t snoise ={0,NULL};

}


void MainWindow::dataReceive()
{

}


QStringList MainWindow::getPortNameList()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName<<info.portName();
        qDebug()<<"serialPortName:"<<info.portName();

    }
    return m_serialPortName;
}


void ReadObs(const QStringList &files){


//    if (nobs =ReadObsRnx())

}



void MainWindow::on_actionAnalysis_triggered()
{
    obsDialog =new ObsDialog(this);
    obsDialog->show();
    int ret =obsDialog->exec();
    if (ret == QDialog::Accepted){

    }

    delete obsDialog;

}
