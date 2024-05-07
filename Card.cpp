#include "Card.h"

Card::Card() {}

Card::~Card() {}

Card::CardSuit Card::getSuit() { return _suit; }

Card::CardPoint Card::getPoint() { return _point; }

void Card::setSuit(CardSuit& suit) { _suit = suit; }

void Card::setPoint(CardPoint& point) { _point = point; }