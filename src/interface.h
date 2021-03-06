/*
 * Copyright (C) 2015  Vishesh Handa <vhanda@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef KDE_WHATSTHAT_INTERFACE_H
#define KDE_WHATSTHAT_INTERFACE_H

#include "whatsthat_export.h"
#include <QObject>
#include <QString>

namespace WhatsThat {

class ChatListJob;

class WHATSTHAT_EXPORT Interface : public QObject
{
    Q_OBJECT
public:
    explicit Interface(QObject* parent = 0);
    ~Interface();

    ChatListJob* generateChatList();

public Q_SLOTS:
    void show();
    void hide();

Q_SIGNALS:
    void loaded();
    void authRequired(const QString& imgUrl);

private:
    Interface(const Interface& rhs) = delete;
    Interface& operator=(const Interface& rhs) = delete;

    class Private;
    Private* d;
};

}

#endif // WHATSTHATINTERFACE_H
