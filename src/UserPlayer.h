#pragma once

#include "Player.h"

class UserPlayer : public Player {
  Q_OBJECT

 public:
  using Player::Player;
  UserPlayer(QObject *parent);
  ~UserPlayer();

  void prepareCallLord() override;
  void preparePlayCard() override;
};