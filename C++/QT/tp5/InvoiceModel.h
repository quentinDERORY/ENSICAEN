/**
 * @file   InvoiceModel.h
 * @author Sebastien Fourey
 *
 * @brief  Invoice document model declaration.
 */
#ifndef _INVOICEMODEL_H_
#define _INVOICEMODEL_H_

#include <iostream>
#include <QObject>

class InvoiceModel : public QObject {
  
  Q_OBJECT

public:

  const QString & lastname( ) const;

  const QString & firstname( ) const;

  const QString & addressLine1( ) const;

  const QString & addressLine2( ) const;

  const QString & zipcode( ) const;

  const QString & city( ) const;

  const QString & cell( int row, int col ) const;

public slots:

  void setLastname( const QString & lastname );
  
  void setFirstname( const QString & firstname );
  
  void setAddressLine1( const QString & text );
  
  void setAddressLine2( const QString & text );

  void setZipcode( const QString & zipcode );
  
  void setCity( const QString & city );
  
  void setCell( int row, int column, const QString & text );

signals:

  void notify();
  
private:

  QString _lastname;
  QString _firstname;
  QString _addressLine1;
  QString _addressLine2;
  QString _zipcode;
  QString _city;
  QString _cells[15][4];
};

#endif
