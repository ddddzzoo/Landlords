#include <QApplication>

#include "GamePannel.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  GamePannel w;
  w.show();
  return a.exec();
}