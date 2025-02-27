/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     chenwei <chenwei_cm@deepin.com>
 *
 * Maintainer: chenwei <chenwei_cm@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NOTIFYLISTVIEW_H
#define NOTIFYLISTVIEW_H

#include "notification/constants.h"
#include "notifymodel.h"

#include <DListView>

#include <QPoint>

class QPropertyAnimation;
class QScrollBar;
class QTimer;
class BubbleItem;

DWIDGET_USE_NAMESPACE

class NotifyListView : public DListView
{
    Q_OBJECT
public:
    explicit NotifyListView(QWidget *parent = nullptr);
    ~NotifyListView() override;

public:
    void createAddedAnimation(EntityPtr entity, const ListItem appItem);
    void createRemoveAnimation(BubbleItem *item);
    void createExpandAnimation(int idx, const ListItem appItem);
    bool aniState() { return m_aniState; }
    void setCurrentRow(int row);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *object, QEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    bool tabKeyEvent(QObject *object, QKeyEvent *event);   //处理键盘TAB键按下的事件,QListView过滤了TAB按键事件
    void wheelEvent(QWheelEvent *event) override;

private:
    bool canShow(EntityPtr ptr); // 判断消息是否应该层叠[即超过4小时]
    void handleScrollValueChanged();
    void handleScrollFinished();

signals:
    void removeAniFinished(EntityPtr ptr);
    void expandAniFinished(QString appName);
    void addedAniFinished(EntityPtr entity);
    void refreshItemTime();
    void focusOnButton();

private:
    bool m_aniState = false;
    int m_currentIndex = 0;
    double m_speedTime = 2.0;
    QPropertyAnimation *m_scrollAni;
    QPointer<QWidget> m_prevElement = nullptr;
    QPointer<QWidget> m_currentElement = nullptr;
    QTimer *m_refreshTimer = nullptr;
};

#endif // NOTIFYLISTVIEW_H
