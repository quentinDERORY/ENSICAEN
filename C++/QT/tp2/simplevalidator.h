#ifndef SIMPLEVALIDATOR_H
#define SIMPLEVALIDATOR_H

#include <QRegExpValidator>
#include <QRegExp>

class SimpleValidator : public QRegExpValidator
{
    Q_OBJECT
public:
    SimpleValidator(QObject* parent = 0);
     QValidator::State validate(QString & chaine,int & i);

signals:
        void invalidInput() const;
public slots:

};

#endif // SIMPLEVALIDATOR_H
