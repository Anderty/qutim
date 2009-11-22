/****************************************************************************
 *  plugin.h
 *
 *  Copyright (c) 2009 by Nigmatullin Ruslan <euroelessar@gmail.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*****************************************************************************/

#ifndef PLUGIN_H
#define PLUGIN_H

#include "extensioninfo.h"
#include <QtCore/QtPlugin>
#include <QtCore/QObject>
#include <QtCore/QSharedDataPointer>

#define PLUGIN_VERSION(major, minor, secminor, patch) QUTIM_VERSION_CHECK(major, minor, secminor, patch)

namespace qutim_sdk_0_3
{
	class ModuleManager;
	class PluginInfoData;
	struct PluginPrivate;

	class LIBQUTIM_EXPORT PluginInfo
	{
	public:
		PluginInfo(const char *name = 0, const char *description = 0,
				   quint32 version = 0, ExtensionIcon icon = ExtensionIcon());
		PluginInfo(const PluginInfo &other);
		~PluginInfo();
		PluginInfo &operator =(const PluginInfo &other);
		PluginInfo &addAuthor(const PersonInfo &author);
		PluginInfo &addAuthor(const char *name, const char *task,
							  const QString &email = QString(), const QString &web = QString());
		PluginInfo &setName(const char *name);
		PluginInfo &setDescription(const char *description);
		PluginInfo &setIcon(const ExtensionIcon &icon);
		PluginInfo &setVersion(quint32 version);
		QList<PersonInfo> authors() const;
		LocalizedString name() const;
		LocalizedString description() const;
		quint32 version() const;
		ExtensionIcon icon() const;
	private:
		QSharedDataPointer<PluginInfoData> d;
	public:
		typedef PluginInfoData Data;
		Data *data();
	};

	typedef void ( /*QObject::*/ *ModuleInit)();

	class LIBQUTIM_EXPORT Plugin : public QObject
	{
		Q_OBJECT
		Q_DISABLE_COPY(Plugin)
	public:
		Plugin();
		virtual ~Plugin();
		PluginInfo info() const;
		ExtensionInfoList avaiableExtensions() const;
		virtual void init() = 0;
		virtual bool load() = 0;
		virtual bool unload() = 0;
	protected:
		// Should be called at init
		void addAuthor(const char *name, const char *task, const QString &email = QString(), const QString &web = QString());
		void setInfo(const char *name, const char *description, quint32 version = 0, QIcon icon = QIcon());
		void addExtension(const char *name, const char *description, const ObjectGenerator *generator,
						  ExtensionIcon icon = ExtensionIcon());
		template<typename T>
		void addExtension(const char *name, const char *description, ExtensionIcon icon = ExtensionIcon())
		{ addExtension(name, description, new GeneralGenerator<T>(), icon); }
		template<typename T, typename I0>
		void addExtension(const char *name, const char *description, ExtensionIcon icon = ExtensionIcon())
		{ addExtension(name, description, new GeneralGenerator<T, I0>(), icon); }
		template<typename T, typename I0, typename I1>
		void addExtension(const char *name, const char *description, ExtensionIcon icon = ExtensionIcon())
		{ addExtension(name, description, new GeneralGenerator<T, I0, I1>(), icon); }
	private:
		QScopedPointer<PluginPrivate> p;
		friend class ModuleManager;
	};

#define QUTIM_EXPORT_PLUGIN(Plugin) \
	Q_EXPORT_PLUGIN(Plugin) \
	static const char *qutim_plugin_verification_data = \
	"pattern=""QUTIM_PLUGIN_VERIFICATION_DATA""\n" \
	"libqutim="QUTIM_VERSION_STR"\0"; \
	Q_EXTERN_C Q_DECL_EXPORT \
	const char * Q_STANDARD_CALL qutim_plugin_query_verification_data() \
	{ return qutim_plugin_verification_data; }
}


#endif // PLUGIN_H
