#include "gamesettingwidget.h"
#include "ui_gamesettingwidget.h"
#include <QString>
#include <QDir>
#include <QDebug>

GameSettingWidget::GameSettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSettingWidget)
{
    ui->setupUi(this);
    /* fill combobox */
    QString stylesPaths = qgetenv("__STYLES_PATH");
    if (stylesPaths.isEmpty())
        stylesPaths = QString(DEFAULT_STYLE_PATH);
    foreach (QString stylesPath, stylesPaths.split(';')) {
        QDir stylesDir(stylesPath, "",
                      QDir::SortFlags(QDir::Name | QDir::IgnoreCase),
                      QDir::Filters(
                          QDir::AllDirs | QDir::NoDotAndDotDot));
        foreach (QFileInfo styleDirInfo, stylesDir.entryInfoList()) {
            ui->chooseStyleBox->addItem(styleDirInfo.fileName(),
                                        styleDirInfo.filePath());
        }
    }
}

GameSettingWidget::~GameSettingWidget()
{
    delete ui;
}

void GameSettingWidget::on_chooseStyleBox_currentIndexChanged(int index)
{
    QString name = ui->chooseStyleBox->itemText(index);
    QString path = ui->chooseStyleBox->itemData(index).toString();
    QString styleUrl = "file:///" + path + "/" + name + ".qss";
    dynamic_cast<QApplication*>(QCoreApplication::instance())->setStyleSheet(styleUrl);
    qDebug() << styleUrl;
}




















