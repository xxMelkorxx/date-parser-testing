#pragma once

#include <iostream>
#include <map>

namespace Parser
{
	enum ParseErr
	{
		WRONG_DAY,
		WRONG_DAY_FORMAT,
		WRONG_MONTH,
		WRONG_MONTH_FORMAT,
		WRONG_FULLDATE,
		WRONG_DELIMETER,
		OK
	};
	class DateParser
	{
	public:
		DateParser();
		ParseErr GetDatePlus3DaysStr(std::string date, std::string& date_str);

		std::string GetDayString();
		std::string GetMonthString();
		void GetDayFromString(std::string);
		void GetMonthFromString(std::string);

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