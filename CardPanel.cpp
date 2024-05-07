#include "CardPanel.h"

#include <QPainter>

CardPanel::CardPanel(QWidget *parent) : QWidget(parent) {}

CardPanel::~CardPanel() {}

void CardPanel::setImage(QPixmap &front, QPixmap &back) {
  _front = front;
  _back = back;

  setFixedSize(_front.size());

  update();
}

QPixmap CardPanel::getImage() { return _front; }

void CardPanel::setFrontSide(bool flag) { _isFront = flag; }

bool CardPanel::isFrontSide() const { return _isFront; }

void CardPanel::setSelected(bool flag) { _isSelected = flag; }

bool CardPanel::isSelected() const { return _isSelected; }

void CardPanel::setCard(const Card &card) { _card = card; }

Card CardPanel::getCard() const { return _card; }

void CardPanel::setOwner(Player *player) { _owner = player; }

Player *CardPanel::getOwner() { return _owner; }

void CardPanel::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  QPainter p(this);
  if (_isFront) {
    p.drawPixmap(rect(), _front);
  }
  else {
    p.drawPixmap(rect(), _back);
  }
}

void CardPanel::mousePressEvent(QMouseEvent *event) {}