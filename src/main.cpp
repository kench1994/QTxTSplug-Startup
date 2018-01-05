#include "mainwindow.h"
#include <QApplication>
#include <QLibrary>
#include <QDebug>
#include "tspluglib.h"
#include <windows.h>

int main(int argc, char *argv[]){
    HRESULT hres;
    hres =  OleInitialize(0);

    QLibrary TsLib("TSPlug.dll");
    if (TsLib.load())
        qDebug() << "Load TSPlug Successed!";
    else{
        qDebug()<<"Load TSPlug Failed!";
        return -1;
    }
    TSPlugLib::TSPlugInterFace ts;
    qDebug()<<("Current Version is %d",ts.Ver());



    getchar();
    return 0;
}
