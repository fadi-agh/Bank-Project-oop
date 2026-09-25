#include<iostream>
#include"clsLoginScreen.h"
#include "Global.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;






int main()
{

	while(true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	return 0;
}