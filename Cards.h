#pragma once

#include <QSet>
#include <QVector>

#include "Card.h"

class Cards {
 public:
  enum SortType { Asc, Desc, NoSort };

  Cards();
  ~Cards();

  explicit Cards(const Card& card);

  // 添加扑克牌
  void add(const Card& card);
  void add(const Cards& cards);
  void add(const QVector<Cards>& cards);

  // 重载 << 一次性插入多个数据
  Cards& operator<<(const Card& card);
  Cards& operator<<(const Cards& cards);

  // 删除扑克牌
  void remove(const Card& card);
  void remove(const Cards& cards);
  void remove(const QVector<Cards>& cards);

  // 扑克牌数量
  int cardCount();

  // 是否为空
  bool isEmpty();

  // 清空卡牌
  void clear();

  // 最大点数
  Card::CardPoint maxPoint();

  // 最小点数
  Card::CardPoint minPoint();

  // 指定点数的牌的数量
  int pointCount(const Card::CardPoint& point);

  // 某张牌是否在集合中
  bool contains(const Card& card);
  bool contains(const Cards& cards);

 private:
  QSet<Card> _cards;
};