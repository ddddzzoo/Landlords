#ifndef GAMEPANNEL_H
#define GAMEPANNEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GamePannel;
}
QT_END_NAMESPACE

class GamePannel : public QMainWindow {
  Q_OBJECT

 public:
  GamePannel(QWidget *parent = nullptr);
  ~GamePannel();

 private:
  Ui::GamePannel *ui;
};
#endif  // GAMEPANNEL_H