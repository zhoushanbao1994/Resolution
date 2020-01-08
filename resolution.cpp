#include "resolution.h"
#include "ui_resolution.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QScreen>

Resolution::Resolution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resolution)
{
    ui->setupUi(this);

    /*设置表格是否充满，即行末不留空*/
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    /*设置tablewidget等宽*/
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 设置表格内容不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 表格使用交替色填充
    ui->tableWidget->setAlternatingRowColors(true);
    // 行选中模式
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 隐藏hang行头、列头
    ui->tableWidget->verticalHeader()->setHidden(true);
    //ui->tableWidget->horizontalHeader()->setHidden(true);

    // 获取系统屏幕分辨率(多块屏幕就显示总分辨率)
    // 例如：2560*1080 + 1920*1080 = 4480*1080
    QDesktopWidget *screen = QApplication::desktop();
    qDebug() << screen->geometry();
    QString str = QString("总分辨率：%1*%2")
            .arg(screen->geometry().width())
            .arg(screen->geometry().height());
    ui->lineEdit->setText(str);

    // 获取屏幕信息，存放到列表中，支持获取多个屏幕
    QList<QScreen*>screens = QGuiApplication::screens();
    ui->tableWidget->setRowCount(screens.size());
    for(int i = 0; i < screens.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(i)));
        qDebug() << screens.at(i)->geometry();          // 屏幕分辨率
        qDebug() << screens.at(i)->availableGeometry(); // 屏幕可用空间
        str = QString("%1*%2")
                    .arg(screens.at(i)->geometry().width())
                    .arg(screens.at(i)->geometry().height());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str));
        str = QString("%1*%2")
                    .arg(screens.at(i)->availableGeometry().width())
                    .arg(screens.at(i)->availableGeometry().height());
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(str));
        ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

Resolution::~Resolution()
{
    delete ui;
}
