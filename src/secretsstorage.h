/* -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the GNOME-keyring signond extension
 *
 * Copyright (C) 2011 Canonical Ltd.
 *
 * Contact: Alberto Mardegan <alberto.mardegan@canonical.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef KEYRING_SECRETS_STORAGE_H
#define KEYRING_SECRETS_STORAGE_H

#include <SignOn/AbstractSecretsStorage>

#include <QByteArray>
#include <QObject>

namespace KWallet {
    class Wallet;
}
class SecretsStorage: public SignOn::AbstractSecretsStorage
{
    Q_OBJECT

public:
    SecretsStorage(QObject *parent = 0);
    ~SecretsStorage();

    virtual bool initialize(const QVariantMap& configuration);
    virtual bool close();
    virtual bool clear();

    virtual bool updateCredentials(const quint32 id, const QString& username, const QString& password);
    virtual bool removeCredentials(const quint32 id);
    virtual bool loadCredentials(const quint32 id, QString& username, QString& password);

    virtual QVariantMap loadData(quint32 id, quint32 method);
    virtual bool storeData(quint32 id, quint32 method, const QVariantMap& data);
    virtual bool removeData(quint32 id, quint32 method);


    QByteArray m_keyringName;
    KWallet::Wallet* m_wallet;
};

#endif // KEYRING_SECRETS_STORAGE_H
