#pragma once
#include <qtypes.h>

class Card {
 public:
  // 花色
  enum CardSuit { Suit_Begin, Diamond, Club, Heart, Spade, Suit_End };

  // 点数
  enum CardPoint {
    Card_Begin,
    Card_3,
    Card_4,
    Card_5,
    Card_6,
    Card_7,
    Card_8,
    Card_9,
    Card_10,
    Card_J,
    Card_Q,
    Card_K,
    Card_A,
    Card_2,
    Card_SJ,  // small joker
    Card_BJ,  // big joker
    Card_End
  };

  Card();
  ~Card();

  Card(CardPoint point, CardSuit suit);

  CardSuit getSuit() const;
  CardPoint getPoint() const;

  void setSuit(CardSuit &suit);
  void setPoint(CardPoint &point);

 private:
  CardSuit _suit{};
  CardPoint _point{};
};

// 对象比较
bool lessSort(const Card& c1, const Card& c2);
bool greaterSort(const Card& c1, const Card& c2);
bool operator<(const Card& c1, const Card& c2);

// 操作符重载 ==
bool operator==(const Card& left, const Card& right);

// 重写全局函数 qHash
uint qHash(const Card& card);