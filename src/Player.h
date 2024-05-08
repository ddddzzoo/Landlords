#pragma once

#include <QObject>

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

 private:
  QString _name{};
  Role _role{};
  Sex _sex{};
  Direction _direction{};
  Type _type{};
  int _score{0};
  bool _isWin{false};
};