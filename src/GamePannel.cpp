#include "GamePannel.h"

#include "./ui_GamePannel.h"

GamePannel::GamePannel(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GamePannel) {
  ui->setupUi(this);
}

GamePannel::~GamePannel() { delete ui; }