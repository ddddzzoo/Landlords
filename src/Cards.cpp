#include "Cards.h"

#include <QRandomGenerator>

Cards::Cards() {}

Cards::~Cards() {}

Cards::Cards(const Card &card) {}

void Cards::add(const Card &card) { _cards.insert(card); }

void Cards::add(const Cards &cards) { _cards.unite(cards._cards); }

void Cards::add(const QVector<Cards> &cards) {
  for (auto &i : cards) {
    add(i);
  }
}

Cards &Cards::operator<<(const Card &card) {
  add(card);
  return *this;
}

Cards &Cards::operator<<(const Cards &cards) {
  add(cards);
  return *this;
}

void Cards::remove(const Card &card) { _cards.remove(card); }

void Cards::remove(const Cards &cards) { _cards.subtract(cards._cards); }

void Cards::remove(const QVector<Cards> &cards) {
  for (auto &i : cards) {
    remove(i);
  }
}

int Cards::cardCount() { return _cards.size(); }

bool Cards::isEmpty() { return _cards.isEmpty(); }

void Cards::clear() { _cards.clear(); }

Card::CardPoint Cards::maxPoint() {
  Card::CardPoint max = Card::Card_Begin;
  if (!_cards.isEmpty()) {
    for (auto &i : _cards) {
      if (i.getPoint() > max) {
        max = i.getPoint();
      }
    }
  }
  return max;
}

Card::CardPoint Cards::minPoint() {
  Card::CardPoint min = Card::Card_End;
  if (!_cards.isEmpty()) {
    for (auto &i : _cards) {
      if (i.getPoint() < min) {
        min = i.getPoint();
      }
    }
  }
  return min;
}

int Cards::pointCount(const Card::CardPoint &point) {
  int count = 0;
  for (auto &i : _cards) {
    if (i.getPoint() == point) {
      count++;
    }
  }
  return count;
}

bool Cards::contains(const Card &card) { return _cards.contains(card); }

bool Cards::contains(const Cards &cards) {
  return _cards.contains(cards._cards);
}

Card Cards::takeRandomCard() {
  // 生成随机数
  int num = QRandomGenerator::global()->bounded(_cards.size());
  QSet<Card>::const_iterator it = _cards.constBegin();
  for (int i = 0; i < num; ++i, ++it)
    ;
  Card card = *it;
  _cards.erase(it);
  return card;
}

CardList Cards::toCardList(SortType type) {
  CardList list;
  for (auto &i : _cards) {
    list << i;
  }
  if (type == Asc) {
    std::sort(list.begin(), list.end(), lessSort);
  }
  else if (type == Desc) {
    std::sort(list.begin(), list.end(), greaterSort);
  }
  return list;
}