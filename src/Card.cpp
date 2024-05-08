#include "Card.h"

Card::Card() {}

Card::~Card() {}

Card::Card(CardPoint point, CardSuit suit) {
  _point = point;
  _suit = suit;
}

Card::CardSuit Card::getSuit() const { return _suit; }

Card::CardPoint Card::getPoint() const { return _point; }

void Card::setSuit(CardSuit& suit) { _suit = suit; }

void Card::setPoint(CardPoint& point) { _point = point; }

bool lessSort(const Card& c1, const Card& c2) {
  if (c1.getPoint() == c2.getPoint()) {
    return c1.getSuit() < c2.getSuit();
  }
  else {
    return c1.getPoint() < c2.getPoint();
  }
}

bool greaterSort(const Card& c1, const Card& c2) {
  if (c1.getPoint() == c2.getPoint()) {
    return c1.getSuit() > c2.getSuit();
  }
  else {
    return c1.getPoint() > c2.getPoint();
  }
}

bool operator<(const Card& c1, const Card& c2) { return lessSort(c1, c2); }

bool operator==(const Card& left, const Card& right) {
  return (left.getPoint() == right.getPoint() &&
          left.getSuit() == right.getSuit());
}

uint qHash(const Card& card) { return card.getPoint() * 100 + card.getSuit(); }