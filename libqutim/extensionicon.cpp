#include "extensionicon.h"
#include "icon.h"

namespace qutim_sdk_0_3
{
	class ExtensionIconData : public QSharedData
	{
	public:
		ExtensionIconData() {}
		ExtensionIconData(const ExtensionIconData &o) : name(o.name), icon(o.icon) {}
		mutable QString name;
		mutable QIcon icon;
	};

	ExtensionIcon::ExtensionIcon(const QString &name) : p(new ExtensionIconData)
	{
		p->name = name;
	}

	ExtensionIcon::ExtensionIcon(const QIcon &icon) : p(new ExtensionIconData)
	{
		p->icon = icon;
	}

	ExtensionIcon::ExtensionIcon(const ExtensionIcon &other) : p(other.p)
	{
	}

	ExtensionIcon::~ExtensionIcon()
	{
	}

	ExtensionIcon &ExtensionIcon::operator =(const ExtensionIcon &other)
	{
		p = other.p;
		return *this;
	}

	QIcon ExtensionIcon::toIcon() const
	{
		if (!p->name.isEmpty() && isCoreInited()) {
			p->icon = Icon(p->name);
			p->name.clear();
		}
		return p->icon;
	}
}
