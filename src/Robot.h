#pragma once

#include "Player.h"

class Robot : public Player {
  Q_OBJECT

 public:
  using Player::Player;
  Robot(QObject *parent);
  ~Robot();

  void prepareCallLord() override;
  void preparePlayCard() override;
};