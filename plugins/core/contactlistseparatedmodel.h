/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2013 Ruslan Nigmatullin <euroelessar@yandex.ru>
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

#ifndef CONTACTLISTSEPARATEDMODEL_H
#define CONTACTLISTSEPARATEDMODEL_H

#include "contactlistbasemodel.h"

class ContactListSeparatedModel : public ContactListBaseModel
{
    Q_OBJECT
    Q_CLASSINFO("SettingsDescription", "Show accounts, tags and contacts")
public:
    explicit ContactListSeparatedModel(QObject *parent = 0);

    virtual void updateContactTags(Contact *contact,
                                   const QStringList &current,
                                   const QStringList &previous);
    virtual void addAccount(Account *account);
    virtual void removeAccount(Account *account);
    virtual void addContact(Contact *contact);
    virtual void removeContact(Contact *contact);
};

#endif // CONTACTLISTSEPARATEDMODEL_H
