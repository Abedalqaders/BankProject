#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

using namespace std;
class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short counter = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                counter--;
                cout << "\nInvlaid Username/Password!\n";
                cout << "You Have " << counter << " Trials to login.\n";
            }
            if (counter == 0) {
                cout << "Your Locked After 3 Faild Trials.\n";
                return false;
            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
      return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t   Login Screen");
       return _Login();

    }
  

};

