/*************************************************************************************
 *  Copyright (C) 2013 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#ifndef KEYRING_PLUGIN_H
#define KEYRING_PLUGIN_H

#include <QObject>
#include <SignOn/ExtensionInterface>

class KeyringPlugin: public QObject, public SignOn::ExtensionInterface3
{
    Q_OBJECT
    Q_INTERFACES(SignOn::ExtensionInterface3)
    Q_PLUGIN_METADATA(IID "com.nokia.SingleSignOn.ExtensionInterface/3.0")

    public:
        KeyringPlugin(QObject *parent = 0) : QObject(parent)
        {
            setObjectName(QStringLiteral("kwallet-keyring"));
        }

    SignOn::AbstractSecretsStorage *secretsStorage(QObject *parent = 0) const Q_DECL_OVERRIDE;
};

#endif // KEYRING_PLUGIN_H

