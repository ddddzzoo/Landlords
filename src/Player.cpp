#include "Player.h"

Player::Player(QObject *parent) : QObject(parent) {}

Player::Player(QString &name, QObject *parent) : QObject(parent) {
  _name = name;
}

Player::~Player() {}

void Player::setName(QString &name) { _name = name; }

QString Player::getName() const { return _name; }

void Player::setRole(Role role) { _role = role; }

Player::Role Player::getRole() const { return _role; }

void Player::setSex(Sex sex) { _sex = sex; }

Player::Sex Player::getSex() const { return _sex; }

void Player::setDirection(Direction direction) { _direction = direction; }

Player::Direction Player::getDirection() const { return _direction; }

void Player::setType(Type type) { _type = type; }

Player::Type Player::getType() const { return _type; }

void Player::setScore(int score) { _score = score; }

int Player::getScore() const { return _score; }

void Player::setWin(bool flag) { _isWin = flag; }

bool Player::isWin() const { return _isWin; }