#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "clsCurrency.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;

class clsListCurrency : public clsScreen
{
    static void _PrintCurrenciesRecordLine(clsCurrency CurrencyRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(28) << left << CurrencyRecord.Country();
        cout << "| " << setw(8) << left << CurrencyRecord.CurrencyCode();
        cout << "| " << setw(42) << left << CurrencyRecord.CurrencyName();
        cout << "| " << setw(10) << left << to_string(CurrencyRecord.Rate()) << endl;
    }

public:

    static void ShowListCurrency()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t List Currency Screen";
        string SubTitle = "\t(" + to_string(vCurrencies.size()) + ") Currencies";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << "" << "| " << left << setw(28) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(42) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        cout << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        if (vCurrencies.size() == 0)
            cout << clsUtil::Tabs(4) << "No Currencies available In this System \n";

        else
            for (clsCurrency CurrenciesRecord : vCurrencies)
                _PrintCurrenciesRecordLine(CurrenciesRecord);
    }
};