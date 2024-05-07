#pragma once

#include <QWidget>

#include "Card.h"
#include "Player.h"

class CardPanel : public QWidget {
  Q_OBJECT

 public:
  explicit CardPanel(QWidget *parent = nullptr);
  ~CardPanel();

  // 设置获取图片函数
  void setImage(QPixmap &front, QPixmap &back);
  QPixmap getImage();

  // 扑克牌显示哪一面
  void setFrontSide(bool flag);
  bool isFrontSide() const;

  // 记录该卡片是否被选中
  void setSelected(bool flag);
  bool isSelected() const;

  // 扑克牌的花色和点数
  void setCard(const Card &card);
  Card getCard() const;

  // 扑克牌所有者
  void setOwner(Player *player);
  Player *getOwner();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

 private:
  QPixmap _front{};         // 扑克牌正面显示图案
  QPixmap _back{};          // 扑克牌反面显示图案
  bool _isFront{true};      // 是否是正面显示
  bool _isSelected{false};  // 是否被选中
  Card _card{};             // 扑克牌花色和点数
  Player *_owner{};         // 扑克牌拥有者
};