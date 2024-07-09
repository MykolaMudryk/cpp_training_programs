#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Завантаження списків кулеметів та калібрів з CSV-файлу
    QFile file(QDir::homePath() + "/Desktop/ballistic_data.csv"); // Змініть шлях до вашого CSV-файлу
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(',');
            ui->weaponComboBox->addItem(parts[0]);
            ui->caliberComboBox->addItem(parts[1]);
        }
        file.close();
    }
    else {
        QMessageBox::warning(this, "Помилка", "Не вдалося завантажити дані з файлу.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    // Отримання значень з віджетів і обчислення поправки
    double distance = ui->distanceLineEdit->text().toDouble();
    QString weapon = ui->weaponComboBox->currentText();
    QString caliber = ui->caliberComboBox->currentText();
    double correction = calculateCorrection(distance, weapon, caliber);

    // Виведення результату у вікно QTextEdit
    ui->resultTextEdit->clear();
    ui->resultTextEdit->append(QString("Поправка нахилу: %1").arg(correction));
}

double MainWindow::calculateCorrection(double distance, const QString &weapon, const QString &caliber)
{
    // Тут ви можете реалізувати свої обчислення поправки нахилу
    // Відповідно до назви кулемета та калібру
    // Поверніть обчислене значення
    // Наприклад:
    // double calculatedCorrection = ...
    // return calculatedCorrection;
    return 0.0;
}
