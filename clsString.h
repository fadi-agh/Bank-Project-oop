#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <ctime>
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;
class clsString
{
private:
	string _Value;
public:
	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;




	//letter

	static short Length(string S1)
	{
		return S1.length();
	};
	short Length()
	{
		return _Value.length();
	};

	static void PrintFirstLetterOfEachWord(string S1)
	{
		//cin : Fadi Ahmed Alaghwani
		//cout : F A A
		bool IsFirstLetter = true;

		for (int i = 0;i < S1.length();i++)
		{
			if (IsFirstLetter && S1[i] != ' ')
			{
				cout << S1[i] << endl;

			}
			IsFirstLetter = ((S1[i] == ' ') ? true : false);
		}

	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEchWord(string S1)
	{
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	string UpperFirstLetterOfEchWord()
	{
		return UpperFirstLetterOfEchWord(_Value);
	}

	static string lowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	string lowerFirstLetterOfEachWord()
	{
		return lowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = toupper(S1[i]);

		}

		return S1;

	}
	string UpperAllString()
	{
		return  UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;

	}
	string LowerAllString()
	{
		return LowerAllString(_Value);
	}

	static char InvertLetter(char Char1)
	{

		return (isupper(Char1)) ? tolower(Char1) : toupper(Char1);


	}

	static string InvertAllLetterInString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetter(S1[i]);
		}
		return S1;
	}
	string InvertAllLetterInString()
	{
		return InvertAllLetterInString(_Value);
	}

	enum enTypeLetter { SmallLetter = 1, CapitalLetter = 2, SpacelLetter = 3, All = 4 };
	static short CountAllTypeLetter(string s1, enTypeLetter TypeLetter= enTypeLetter::All)
	{

		short Counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (TypeLetter == enTypeLetter::SmallLetter && islower(s1[i]))
			{

				Counter++;

			}
			else if (TypeLetter == enTypeLetter::CapitalLetter && isupper(s1[i]))
			{

				Counter++;

			}

			else if (TypeLetter == enTypeLetter::SpacelLetter && char(s1[i]) == ' ')
			{


				Counter++;

			}

			else if (TypeLetter == enTypeLetter::All)
			{

				return s1.length();

			}
			else
			{
				return Counter;
			}

		}
		return Counter;
	}

	static short CountSmallLetter(string s1)
	{
		short Counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (islower(s1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLetter()
	{
		return CountSmallLetter(_Value);
	}

	static short CountCapitalLetter(string s1)
	{
		short Counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (isupper(s1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	static short CountSpacelLetter(string s1)
	{
		short Counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (char(s1[i]) == ' ')
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSpacelLetter()
	{
		return  CountSpacelLetter(_Value);
	}

	static short CountLetter(string S1, char Char1, bool MachCase = false)
	{
		int Counter = 0;
		if (MachCase)
		{
			for (int i = 0; i < S1.length(); i++)
			{
				if (tolower(Char1) == tolower(S1[i]))
				{
					Counter++;
				}

			}
			return Counter;
		}
		else
			for (int i = 0; i < S1.length(); i++)
			{
				if (Char1 == S1[i])
				{
					Counter++;
				}

			}
		return Counter;


	}
	
	static bool IsVowel(char Char1)
	{
		Char1 = tolower(Char1);
		return ((Char1 == 'a') || (Char1 == 'o') || (Char1 == 'i') || (Char1 == 'e') || (Char1 == 'y'));
	}

	static short CountVawels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountVawels()
	{
		return CountVawels(_Value);
	}

	//string

	static void PrintEachWordInString(string S1)
	{
		string delim = " ";
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord;
		while ((pos = S1.find(delim)) != S1.npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + (delim.length()));
		}
		if (S1 != "")
		{
			cout << S1 << endl;
		}

	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static short CountWords(string S1)
	{
		// fade fade fade
		//  3

		string Delim = " ";
		string SWord;
		short Pos = 0;
		short Counter = 0;
		while ((Pos = S1.find(Delim)) != S1.npos)
		{
			SWord = S1.substr(0, Pos);
			if (SWord != "")
			{
				Counter++;
			}
			S1.erase(0, Pos + (Delim.length()));

		}
		if (S1 != "")
		{
			Counter++;
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);

	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);    
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  
		}

		if (S1 != "")
		{
			vString.push_back(S1); 
		}

		return vString;

	}

	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}


	static string JoinString(string Delim, vector <string> vString)
	{
		// {aa,bb}
		//  aa bb
		string StringWithDelim = "";
		for (string& i : vString)
		{
			StringWithDelim = StringWithDelim + i + Delim;
		}
		return StringWithDelim.substr(0, StringWithDelim.length() - Delim.length());
	}

	static string TrimRight(string S1)
	{
		// "  fffff  "
		// "  fffff"
		for (int i = 0;i < S1.length();i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, S1.length() - i);
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string TrimLeft(string S1)
	{
		// "  fffff  "
		// "fffff  "
		for (int i = 0;i < S1.length();i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string Trim(string S1)
	{
		// "  fffff  "
		// "fffff"
		return TrimLeft(TrimRight(S1));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string ReverseWordInString(string Delim, string S1)
	{
		vector <string> vString = Split(Delim, S1);
		vector <string>::iterator iter = vString.end();
		string RWord;
		while (iter != vString.begin())
		{
			--iter;
			RWord += *iter + "_";
		}
		RWord = RWord.substr(0, RWord.length() - Delim.length());
		return RWord;

	}

	static string ReplaceWordInString(string S1, string StringToReplace, string StringReplaceTo)
	{
		

		int Pos = S1.find(StringToReplace);

		while (Pos != std::string::npos)
		{
			S1.replace(Pos, StringToReplace.length(), StringReplaceTo);
			Pos = S1.find(StringToReplace);
		}

		return S1;
	}
};

