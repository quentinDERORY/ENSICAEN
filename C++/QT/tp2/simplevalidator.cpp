#include "simplevalidator.h"



SimpleValidator::SimpleValidator(QObject* parent): QRegExpValidator(parent){
    QRegExp reg("^[0-9]{1,10}[a-z]$");
    setRegExp(reg);

};


 QValidator::State SimpleValidator::validate(QString & chaine,int & i)
    {

     QRegExpValidator* this_root = this;
     QValidator::State tmp_res = this_root->validate(chaine,i);
    if (tmp_res == QValidator::Acceptable )
    {
        int mod=0,tmp;
        for(int j = 0;j<chaine.size()-1;j++)
        {
           tmp=chaine[j].digitValue();
           mod+=tmp%26;
        }
        tmp = chaine[chaine.size()-1].unicode()-97;
        if(mod == tmp)
            return QValidator::Acceptable;
        emit invalidInput();
        return QValidator::Invalid;
    }

    return tmp_res;


    }

