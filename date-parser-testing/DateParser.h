#pragma once

#include <iostream>
#include <map>

namespace Parser
{	
	/// <summary>
	/// Коды ошибок
	/// </summary>
	enum ParseErr
	{
		WRONG_DAY,	//Когда введён неправильный день или вместо него не цифры
		
		WRONG_MONTH,	//Когда введён неправильный месяц или вместо него не цифры   
		
		WRONG_FULLDATE,	   //Когда введён неправильный месяц и неправильный день или вместо них не цифры
		
		WRONG_DELIMETER,   //Когда введён неправильный разделитель

		OK	//Когда все прошло успешно
	};
	class DateParser
	{
	public:
		DateParser();

		//Метод для парсиинга в строку введеной даты
		ParseErr GetDatePlus3DaysStr(std::string date, std::string& date_str);

		std::string GetDayString();
		std::string GetMonthString();

		std::string GetDate() { return Date; }
		int GetDay() { return Day; }
		int GetMonth() { return Month; }
	private:
		std::string Date;
		int Day;
		int Month;
	};
	class NumberParser
	{
	public:
		std::map<int, std::string> GetDays() { return daysDict_; }
		std::map<int, std::string> GetMonths() { return monthsDict_; }
		void SetDays();
		void SetMonths();
	private:
		std::map<int, std::string> daysDict_;
		std::map<int, std::string> monthsDict_;
	};
}