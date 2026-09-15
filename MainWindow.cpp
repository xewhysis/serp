#include "MainWindow.h"
#include "KochWidget.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->nSpinBox->setMinimum(0);
    ui->nSpinBox->setMaximum(10);
    ui->nSpinBox->setValue(5);

    ui->iterationSlider->setMinimum(0);
    ui->iterationSlider->setMaximum(10);
    ui->iterationSlider->setValue(0);

    ui->iterationLabel->setText("Итерация: 0");

    connect(ui->buildButton, &QPushButton::clicked, this, &MainWindow::buildSnowflake);

    connect(ui->iterationSlider, &QSlider::valueChanged, this, &MainWindow::sliderChanged);

    ui->kochWidget->setIteration(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::buildSnowflake() {
    int n = ui->nSpinBox->value();

    ui->iterationSlider->setMaximum(n);
    ui->iterationSlider->setValue(0);

    ui->iterationLabel->setText("Итерация: 0");

    ui->kochWidget->setIteration(0);
}

void MainWindow::sliderChanged(int value) {
    ui->iterationLabel->setText(QString("Итерация: %1").arg(value));

    ui->kochWidget->setIteration(value);
}