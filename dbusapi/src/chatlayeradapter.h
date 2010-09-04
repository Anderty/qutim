/****************************************************************************
 *
 *  This file is part of qutIM
 *
 *  Copyright (c) 2010 by Nigmatullin Ruslan <euroelessar@gmail.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This file is part of free software; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License as        *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 ***************************************************************************
 ****************************************************************************/

#ifndef CHATLAYERADAPTER_H
#define CHATLAYERADAPTER_H

#include <QDBusAbstractAdaptor>
#include <QDBusObjectPath>
#include <QDBusConnection>
#include <qutim/messagesession.h>

using namespace qutim_sdk_0_3;

class ChatLayerAdapter : public QDBusAbstractAdaptor
{
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "org.qutim.ChatLayer")
public:
    explicit ChatLayerAdapter(const QDBusConnection &dbus);
public slots:
	QDBusObjectPath session(const QDBusObjectPath &chatUnit, bool create = true);
	QDBusObjectPath session(const QDBusObjectPath &account, const QString &id, bool create = true);
	QList<QDBusObjectPath> sessions() const;
signals:
	void sessionCreated(const QDBusObjectPath &sessionPath);
private slots:
	void onSessionCreated(qutim_sdk_0_3::ChatSession *session);
private:
	QDBusConnection m_dbus;
	int m_lastId;
};

#endif // CHATLAYERADAPTER_H
