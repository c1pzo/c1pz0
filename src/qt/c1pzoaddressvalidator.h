// Copyright (c) 2011-2020 The C1pzo Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef C1PZO_QT_C1PZOADDRESSVALIDATOR_H
#define C1PZO_QT_C1PZOADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class C1pzoAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit C1pzoAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** C1pzo address widget validator, checks for a valid c1pzo address.
 */
class C1pzoAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit C1pzoAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // C1PZO_QT_C1PZOADDRESSVALIDATOR_H
