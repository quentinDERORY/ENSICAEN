/**
 * @file   InvoiceModel.cpp
 * @author Sebastien Fourey
 *
 * @brief  Invoice document model declaration.
 */

#include "InvoiceModel.h"

void
InvoiceModel::setLastname(const QString & lastname) {
   _lastname = lastname;
   emit notify();
}

void
InvoiceModel::setFirstname(const QString & firstname) {
   _firstname = firstname;
   emit notify();
}

void
InvoiceModel::setAddressLine1(const QString & text) {
   _addressLine1 = text;
   emit notify();
}

void
InvoiceModel::setAddressLine2(const QString & text) {
   _addressLine2 = text;
   emit notify();
}

void
InvoiceModel::setZipcode(const QString & zipcode) {
   _zipcode = zipcode;
   emit notify();
}

void
InvoiceModel::setCity(const QString & city) {
   _city = city;
   emit notify();
}

void
InvoiceModel::setCell(int row, int column, const QString & text) {
   _cells[row][column] = text;
   emit notify();
}

const QString &
InvoiceModel::lastname() const {
   return _lastname;
}

const QString &
InvoiceModel::firstname() const {
   return _firstname;
}

const QString &
InvoiceModel::addressLine1() const {
   return _addressLine1;
}

const QString &
InvoiceModel::addressLine2() const {
   return _addressLine2;
}

const QString &
InvoiceModel::zipcode() const {
   return _zipcode;
}

const QString &
InvoiceModel::city() const {
   return _city;
}

const QString &
InvoiceModel::cell(int row, int column) const {

   return _cells[row][column];
}


