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

#include "jsinterface.h"
#include <QDebug>

using namespace WhatsThat;

JsInterface::JsInterface(QObject* parent)
    : QObject(parent)
{
}

void JsInterface::showContactListCallback()
{
    qDebug();
}

void JsInterface::hideContactListCallback()
{
    qDebug();
}

QString JsInterface::currentChat() const
{
    return m_currentChat;
}

void JsInterface::setCurrentChat(const QString& chatId)
{
    m_currentChat = chatId;
    Q_EMIT currentChatChanged();
}

QVariant JsInterface::chatList() const
{
    return m_chatList;
}

QVariant JsInterface::messageList() const
{
    return m_messageList;
}

void JsInterface::setChatList(const QVariant& var)
{
    m_chatList = var;
    Q_EMIT chatListChanged();
}

void JsInterface::setMessageList(const QVariant& var)
{
    m_messageList = var;
    Q_EMIT messageListChanged();
}

void JsInterface::emitLoaded()
{
    Q_EMIT loaded();
}

void JsInterface::jsInjectKeyboardEvent()
{
    Q_EMIT nativeInjectKeyboardEvent();
    Q_EMIT keyboardEventInjected();
}

void JsInterface::emitAuthRequired(const QString& imgSrc)
{
    Q_EMIT authRequired(imgSrc);
}

void JsInterface::jsEmitUnreadMessage(const QString& chatId)
{
    Q_EMIT unreadMessages(chatId);
}

