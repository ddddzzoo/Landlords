#pragma once

#include <QObject>

#include "Cards.h"

class Player : public QObject {
  Q_OBJECT

 public:
  enum Role { Lord, Farmer };         // 角色
  enum Sex { Man, Woman };            // 性别
  enum Direction { Left, Right };     // 头像的显示方向
  enum Type { Robot, User, UnKnow };  // 玩家类型
  Player(QObject *parent);
  explicit Player(QString &name, QObject *parent = nullptr);
  ~Player();

  // 名字
  void setName(QString &name);
  QString getName() const;

  // 角色
  void setRole(Role role);
  Role getRole() const;

  // 性别
  void setSex(Sex sex);
  Sex getSex() const;

  // 头像显示方位
  void setDirection(Direction direction);
  Direction getDirection() const;

  // 玩家类型
  void setType(Type type);
  Type getType() const;

  // 玩家分数
  void setScore(int score);
  int getScore() const;

  // 游戏输赢
  void setWin(bool flag);
  bool isWin() const;

  // 当前对象的上/下家
  void setPrevPlayer(Player *player);
  void setNextPlayer(Player *player);
  Player *getPrevPlayer() const;
  Player *getNextPlayer() const;

  // 叫地主/抢地主
  void grabLordBet(int point);

  // 发牌时拿到的牌
  void storeDispatchCard(const Card &card);
  void storeDispatchCard(const Cards &cards);

  // 获取玩家所有的牌（展示）
  Cards getCards();

  // 清空玩家手里的牌
  void clearCards();

  // 出牌
  void playCard(Cards &cards);

  // 获取待出牌玩家对象以及玩家打出的牌
  Player *getPendPlayer();
  Cards getPendCards() const;

  // 储存待出牌玩家对象和打出的牌
  void storePendingInfo(Player *player, Cards &cards);

  // 叫地主
  virtual void prepareCallLord();
  // 准备出牌
  virtual void preparePlayCard();

 protected:
  QString _name{};
  Role _role{};
  Sex _sex{};
  Direction _direction{};
  Type _type{};
  int _score{0};
  bool _isWin{false};
  Player *_prev{nullptr};  // 上家
  Player *_next{nullptr};  // 下家
  Cards _cards;            // 玩家手牌
  Player *_pend{nullptr};  // 待出牌玩家
  Cards _pendCards;        // 待出牌
};