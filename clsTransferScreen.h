#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"Global.h"
class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";
        cout << Message;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }
public:
    static void ShowTransferScreen()
    {


        _DrawScreenHeader("\tTransfer Screen");
        

        clsBankClient  SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer from: "));
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer: "));
        _PrintClient(DestinationClient);
        
        cout << "\nenter Transfer Amount: ";
        float Amount = clsInputValidate::ReadFloatNumberBetween(0, SourceClient.AccountBalance, "Acount " + SourceClient.AccountNumber() + " does not have enough Balance, Enter another Amount less Than (" + to_string(SourceClient.AccountBalance)+") :");

        char Answer='n';
        cout << "\nAre You Sure you Want To perform This operation?y/n: ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
       {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nTransfer Seccessfully\n";
            }
            else
            {
                cout << "\nTransfer Faild\n";
            }
       }

    }
};
