#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include "clsString.h"
using namespace std;
class clsDate
{

	short _Year  ;
	short _Month;
	short _Day  ;
public:
	
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}
	clsDate(string sDate)
	{
		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[2]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[0]);
	}
	clsDate(short _Year, short _Month, short _Day)
	{
		
		this->_Year = _Year;
		this->_Month = _Month;
		this->_Day = _Day;
	}
	clsDate(short Year, short AllDaysFromBegining)
	{
		clsDate Date = GetDateFromDays(Year, AllDaysFromBegining);
		_Year = Date.Year;
		_Month = Date.Month;
		_Day = Date.Day;

	}


	void Print()
	{
		cout<< DateToString(*this) <<endl;
	}

	void SetDay(short Day) {
		_Day = Day;
	}
	short GetDay() {
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}
	short GetMonth() {
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year) {
		_Year = Year;
	}
	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;


	static string NumberToTxt(long long Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string Arr[] = { "","One",  "Tow" ,"Three","Four","Five","Six" ,"Seven" ,"Eight","Nine", "Ten"
				,"Eleven","Twelve","Thirteen", "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return Arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty"
				,"Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToTxt(Number % 10);
		}
		if (Number >= 100 && Number <= 999)
		{
			return NumberToTxt(Number / 100) + "Hundred " + NumberToTxt(Number % 100);
		}
		if (Number >= 1000 && Number <= 999999)
		{
			return NumberToTxt(Number / 1000) + "Thousand " + NumberToTxt(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 999999999)
		{
			return NumberToTxt(Number / 1000000) + "Million " + NumberToTxt(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 9999999999999)
		{
			return NumberToTxt(Number / 1000000) + "Billion " + NumberToTxt(Number % 1000000);
		}
		else
			return "";
	}
	static bool IsLeapYear(short Year)
	{

		return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	static short NumberOfDaysInAMonth(short Year, short Month)
	{
		return (Month < 1 || Month > 12) ? 0 : (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
	}
	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}
	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}
	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	static short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short D, Y, M, A;
		A = ((14 - Month) / 12);
		Y = Year - A;
		M = Month + (12 * A) - 2;
		D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
		return D;
	}

	static string MonthShortName(short Month)
	{
		string Months[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return Months[Month];
	}
	static string DayShortName(short DaysOfWeekOrder)
	{
		string DayOfWeek[7] = { "Sun","Mon","Tue","Win","Thu","Fri","Sat" };
		return DayOfWeek[DaysOfWeekOrder];
	}

	static void PrintMonthCalindar(short Year, short Month)
	{

		{
			cout << endl;
			string DayOfWeek[] = { "Sun","Mon","Tue","Win","Thu","Fri","Sat" };
			printf("--------------_%s_--------------\n\n", MonthShortName(Month).c_str());
			for (string i : DayOfWeek)
			{
				printf("%3s  ", i.c_str());
			}
			cout << endl << endl;
		}

		short NumberOfDays = NumberOfDaysInAMonth(Year, Month);
		short DaysOfWeekOrder = DayOfWeekOrder(Year, Month, 1);
		int j;
		for (j = 0;j < DaysOfWeekOrder;j++)
		{
			printf("     ");

		}
		for (int i = 1; i <= NumberOfDays;i++)
		{
			printf("%3d  ", i);

			if (++j == 7)
			{
				j = 0;
				printf("\n\n");
			}

		}
		printf("\n---------------------------------\n");
	}
	static void PrintYearCalindar(short Year)
	{
		printf("\n---------------------------------\n");
		printf("\tCalindar - %d", Year);
		printf("\n---------------------------------\n");
		for (int i = 1; i <= 12;i++)
		{
			PrintMonthCalindar(Year, i);
		}
	}

	static 	short NumberDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
	{

		short TotalDays = 0;
		for (int i = 1;i < Month;i++)
		{
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}
		return TotalDays + Day;
	}
	


	//

	static clsDate AddAndGetDateFromDays(short Year, short AllDaysFromBegining, short AddDays)
	{
		clsDate date;
		short monthdays;
		date.Month = 1;
		short days = AllDaysFromBegining + AddDays;
		date.Year = Year;

		while (true)
		{

			monthdays = NumberOfDaysInAMonth(date.Year, date.Month);
			if (days > monthdays)
			{
				days -= monthdays;
				date.Month++;

				if (date.Month > 12)
				{
					date.Year++;
					date.Month = 1;
				}
			}
			else
			{
				date.Day = days;
				break;
			}


		}

		return date;
	}
	static clsDate GetDateFromDays(short Year, short AllDaysFromBegining)
	{
		clsDate Date;
		short MonthDays;
		Date.Month = 1;
		Date.Year = Year;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Year, Date.Month);
			if ((AllDaysFromBegining > MonthDays))
			{
				AllDaysFromBegining -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = AllDaysFromBegining;
				break;
			}
		}

		return Date;
	}
	static clsDate ReadDate(short Year, short Month, short Day)
	{
		clsDate Date;
		Date.Year = Year;
		Date.Month = Month;
		Date.Day = Day;
		return Date;
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)) : false);

	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{

		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	 enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompareResult2Dates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
		{
			return enDateCompare::Before;
		}
		if (IsDate1EqualDate2(Date1, Date2))
		{
			return enDateCompare::Equal;
		}
		else
			return enDateCompare::After;

	}
	static bool IsLastMonthInYear(clsDate Date)
	{
		return (Date.Month == 12);
	}
	static bool IsLastDayInMonth(clsDate Date)
	{
		return 	 (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
	}
	static clsDate SystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}
	static string GetSystemDateTimeString()
	{
		short Day, Year, Month, Hour, Minute, Second;
		time_t t = time(0);
		tm* now = localtime(&t);
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;
		if (Hour > 12)
		{
			Hour -= 12;
		}


		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	//// Add

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date.Year++;
				Date.Month = 1;
				Date.Day = 1;
			}
			else
			{
				Date.Month++;
				Date.Day = 1;
			}

		}

		else
		{
			Date.Day++;
		}
		return Date;

	}
	static clsDate IncreaseDateByXDays(clsDate Date, short AddDays)
	{
		for (short i = 1;i <= AddDays;i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;

	}
	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 1;i <= 7;i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	static clsDate IncreaseDateByXWeeks(clsDate Date, short AddWeeks)
	{
		for (short i = 1;i <= AddWeeks;i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	static clsDate IncreaseDateByXMonths(clsDate Date, short AddMonths)
	{
		for (short i = 1;i <= AddMonths;i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	static clsDate IncreaseDateByOneYear(clsDate Date)
	{

		Date.Year++;
		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	static clsDate IncreaseDateByXYears(clsDate Date, short AddYears)
	{
		for (short i = 1;i <= AddYears;i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	static clsDate IncreaseDateByXYearsFaster(clsDate Date, short AddYears)
	{

		Date.Year += AddYears;

		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{


		Date.Year += 10;


		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;

	}
	static clsDate IncreaseDateByXDecades(clsDate Date, short AddDecades)
	{

		for (short i = 1;i <= AddDecades;i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}
		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	static clsDate IncreaseDateByXDecadesFaster(clsDate Date, short AddDecades)
	{

		Date.Year += AddDecades * 10;

		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{

		Date.Year += 100;
		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year += 1000;

		short AllDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysOfMonth)
		{
			Date.Day = AllDaysOfMonth;
		}

		return Date;
	}
	  
	//sub

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{

			if (Date.Month == 1)
			{
				Date.Year--;
				Date.Month = 12;
			}
			else
			{
				Date.Month--;
			}
			Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}
	static clsDate DecreaseDateByXDays(clsDate Date, short SubDays)
	{
		for (int i = 1;i <= SubDays;i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1;i <= 7;i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	static clsDate DecreaseDateByXWeeks(clsDate Date, short SubWeeks)
	{
		for (int i = 1;i <= SubWeeks;i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	static clsDate DecreaseDateByXMonths(clsDate Date, short SubMonths)
	{
		for (int i = 1;i <= SubMonths;i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year--;
		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	static clsDate DecreaseDateByXYears(clsDate Date, short SubYears)
	{
		for (int i = 1;i <= SubYears;i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	static clsDate DecreaseDateByXYearsFaster(clsDate Date, short SubYears)
	{
		Date.Year -= SubYears;
		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date.Year -= 10;
		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	static clsDate DecreaseDateByXDecades(clsDate Date, short SubDecades)
	{
		for (int i = 1;i <= SubDecades;i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}
	static clsDate DecreaseDateByXDecadesFaster(clsDate Date, short SubDecades)
	{
		Date.Year -= (SubDecades * 10);
		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date.Year -= 100;
		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year -= 1000;

		short AllDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > AllDaysInMonth)
		{
			Date.Day = AllDaysInMonth;
		}
		return Date;
	}
	

	////Until The end

	static short DayOfWeekOrder(clsDate Date)
	{

		short D, Y, M, A;
		A = ((14 - Date.Month) / 12);
		Y = Date.Year - A;
		M = Date.Month + (12 * A) - 2;
		D = (Date.Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
		return D;
	}
	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}
	static bool IsWeekend(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 5;
	}
	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekend(Date);
	}
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date)
	{

		return NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day;
	}
	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		return NumberOfDaysInAYear(Date.Year) - NumberDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
	}
	static int DiffrencesBetwenTowDate(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int DiffrencesDays = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DiffrencesDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay) ? ++DiffrencesDays : DiffrencesDays;

	}
	static int DiffrencesBetwenTowDate2(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{

		int DiffrencesDays = 0;
		int OperationType = +1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			OperationType = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DiffrencesDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}


		return (IncludeEndDay) ? ++DiffrencesDays * OperationType : DiffrencesDays * OperationType;

	}
	static int CalculateVacationDays(clsDate StartDate, clsDate EndDate)
	{
		int DaysCount = 0;
		while (IsDate1BeforeDate2(StartDate, EndDate))
		{

			if (!IsWeekend(StartDate))
			{
				DaysCount++;

			}
			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return DaysCount;

	}
	static clsDate  CalculateVacationReturnDate(clsDate StartDate, short WorkDays)
	{
		int WorkDaysWithWeekEnd = WorkDays;
		for (int i = 0;i < WorkDaysWithWeekEnd;i++)
		{
			if (IsWeekend(StartDate))
			{
				WorkDaysWithWeekEnd++;
			}
			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return StartDate;
	}

	//
	static clsDate GetMaxDate(clsDate Date1, clsDate Date2)
	{
		return (IsDate1AfterDate2(Date1, Date2)) ? Date1 : Date2;
	}
	static clsDate GetMinDate(clsDate Date1, clsDate Date2)
	{
		return (IsDate1BeforeDate2(Date1, Date2)) ? Date1 : Date2;
	}
	static bool IsValidDate(clsDate Date)
	{
		return (Date.Month <= 12 && Date.Month >= 1) && (Date.Day <= NumberOfDaysInAMonth(Date.Year, Date.Month) && Date.Day >= 1) && (Date.Year >= 1);

	}
	static clsDate stringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate = clsString::Split(DateString, "/");
		Date.Year = stoi(vDate[2]);
		Date.Month = stoi(vDate[1]);
		Date.Day = stoi(vDate[0]);
		return Date;
	}
	static string DateToString(clsDate Date)
	{
		return to_string(Date.Year) + "/" + to_string(Date.Month) + "/" + to_string(Date.Day);
	}
	enum enFormatTypes { Format1 = 1, Format2 = 2, Format3 = 3, Format4 = 4, Format5 = 5, Format6 = 6 };
	static string FormatString(clsDate Date, enFormatTypes FormatType = enFormatTypes::Format1)
	{
		switch (FormatType)
		{
		case enFormatTypes::Format1:
			return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
		case enFormatTypes::Format2:
			return  to_string(Date.Year) + "/" + to_string(Date.Month) + "/" + to_string(Date.Day);
		case enFormatTypes::Format3:
			return to_string(Date.Month) + "/" + to_string(Date.Day) + "/" + to_string(Date.Year);
		case enFormatTypes::Format4:
			return to_string(Date.Day) + "-" + to_string(Date.Month) + "-" + to_string(Date.Year);
		case enFormatTypes::Format5:
			return to_string(Date.Month) + "-" + to_string(Date.Day) + "-" + to_string(Date.Year);
		case enFormatTypes::Format6:
			return "Day:" + to_string(Date.Day) + ", Month:" + to_string(Date.Month) + ", Year:" + to_string(Date.Year);

		}
	}



};

