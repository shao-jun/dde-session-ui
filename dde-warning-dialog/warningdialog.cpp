/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
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

#include "warningdialog.h"
#include <QApplication>
#include <QIcon>

WarningDialog::WarningDialog(QWidget *parent)
    : DDialog(parent)
{
    setAccessibleName("WarningDialog");
    const auto ratio = devicePixelRatioF();
    QPixmap icon = QIcon::fromTheme("dialog-warning").pixmap(int(48 * ratio), int(48 * ratio));
    icon.setDevicePixelRatio(ratio);

    const QString title = tr("Kindly Reminder");
    const QString body = tr("This application cannot run without window effect");
    setTitle(title);
    setMessage(body);
    setIcon(icon);
    addButton(tr("OK"), true);
}

WarningDialog::~WarningDialog()
{
}
