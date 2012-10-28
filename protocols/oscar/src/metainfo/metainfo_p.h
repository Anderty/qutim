/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2011 Alexey Prokhin <alexey.prokhin@yandex.ru>
**
*****************************************************************************
**
** $QUTIM_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QUTIM_END_LICENSE$
**
****************************************************************************/

#ifndef METAINFO_P_H
#define METAINFO_P_H

#include "../icqaccount.h"
#include <QTimer>
#include "abstractmetarequest_p.h"
#include "../snachandler.h"

namespace Ureen {

namespace oscar {

class MetaInfo: public QObject, public SNACHandler
{
	Q_OBJECT
	Q_INTERFACES(Ureen::oscar::SNACHandler)
	Q_CLASSINFO("DependsOn", "Ureen::oscar::IcqProtocol")
public:
	MetaInfo();
	static MetaInfo &instance() { Q_ASSERT(self); return *self; }
	void handleSNAC(AbstractConnection *conn, const SNAC &snac);
	void addRequest(AbstractMetaRequest *request);
	bool removeRequest(AbstractMetaRequest *request);
	quint16 nextId() { return ++m_sequence; }
private slots:
	void onNewAccount(Ureen::Account *account);
	void onAccountStatusChanged(const Ureen::Status &status);
private:
	quint16 m_sequence;
	QHash<quint16, AbstractMetaRequest*> m_requests;
	static MetaInfo *self;
};

} } // namespace Ureen::oscar

#endif // METAINFO_P_H

