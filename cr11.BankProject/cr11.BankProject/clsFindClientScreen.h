#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClientScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
   static void ShowFindClientScreen() {
       if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
       {
           return;// this will exit the function and it will not continue
       }

        _DrawScreenHeader("\t  Find Client Screen");
        cout << "\nEnter Account Number To Find It: \n";

        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Client Is Not Exict \n";
            AccountNumber = clsInputValidate::ReadString();
        }
       
        clsBankClient C1 = clsBankClient::Find(AccountNumber);
        if (C1.IsEmpty()) {
            cout << "The Client Is empty :-( \n";
        }
        else {
            cout << "The Client Found :-) \n";
      _PrintClient(C1);
        }
  
    }
};

