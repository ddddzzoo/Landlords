#include "Robot.h"

Robot::Robot(QObject *parent) : Player(parent) { _type = Player::Robot; }

Robot::~Robot() {}

void Robot::prepareCallLord() {}

void Robot::preparePlayCard() {}