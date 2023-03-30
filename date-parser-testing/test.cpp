#include "gtest/gtest.h"
#include "DateParser.h"
using namespace std;
using namespace Parser;

DateParser dp = DateParser();
ParseErr err;
string date_str;

TEST(TestDaysMonth, DaysJanuary)
{
	err = dp.GetDatePlus3DaysStr("31.01", date_str);
	ASSERT_EQ(date_str, "Третье февраля");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestDaysMonth, DaysFebruary)
{
	err = dp.GetDatePlus3DaysStr("28.02", date_str);
	ASSERT_EQ(date_str, "Третье марта");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("29.02", date_str);
	ASSERT_EQ(date_str, "");
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestDaysMonth, DaysMarch)
{
	err = dp.GetDatePlus3DaysStr("31.03", date_str);
	ASSERT_EQ(date_str, "Третье апреля");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestDaysMonth, DaysApril)
{
	err = dp.GetDatePlus3DaysStr("30.04", date_str);
	ASSERT_EQ(date_str, "Третье мая");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("31.04", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestDaysMonth, DaysMay)
{
	err = dp.GetDatePlus3DaysStr("31.05", date_str);
	ASSERT_EQ(date_str, "Третье июня");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestDaysMonth, DaysJuny)
{
	err = dp.GetDatePlus3DaysStr("30.06", date_str);
	ASSERT_EQ(date_str, "Третье июля");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("31.06", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestDaysMonth, DaysJuly)
{
	err = dp.GetDatePlus3DaysStr("31.07", date_str);
	ASSERT_EQ(date_str, "Третье августа");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestDaysMonth, DISABLED_DaysAugust)
{
	err = dp.GetDatePlus3DaysStr("31.08", date_str);
	ASSERT_EQ(date_str, "Третье сентября");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestDaysMonth, DaysSeptember)
{
	err = dp.GetDatePlus3DaysStr("30.09", date_str);
	ASSERT_EQ(date_str, "Третье октября");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("31.09", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestDaysMonth, DaysOctober)
{
	err = dp.GetDatePlus3DaysStr("31.10", date_str);
	ASSERT_EQ(date_str, "Третье ноября");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestDaysMonth, DaysNovember)
{
	err = dp.GetDatePlus3DaysStr("30.11", date_str);
	ASSERT_EQ(date_str, "Третье декабря");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("31.11", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestDaysMonth, DaysDecember)
{
	err = dp.GetDatePlus3DaysStr("31.12", date_str);
	ASSERT_EQ(date_str, "Третье января");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestInputArgument, Spaces)
{
	err = dp.GetDatePlus3DaysStr("   01.01   ", date_str);
	ASSERT_EQ(date_str, "Четвёртое января");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("01.01   ", date_str);
	ASSERT_EQ(date_str, "Четвёртое января");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("   01.01", date_str);
	ASSERT_EQ(date_str, "Четвёртое января");
	ASSERT_EQ(err, OK);
	date_str = "";
}

TEST(TestErr, WrongDelimeter)
{
	err = dp.GetDatePlus3DaysStr("01.01", date_str);
	ASSERT_EQ(date_str, "Четвёртое января");
	ASSERT_EQ(err, OK);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("01/01", date_str);
	ASSERT_EQ(err, WRONG_DELIMETER);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("01:01", date_str);
	ASSERT_EQ(err, WRONG_DELIMETER);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("01 01", date_str);
	ASSERT_EQ(err, WRONG_DELIMETER);
	date_str = "";
}

TEST(TestErr, WrongDay)
{
	err = dp.GetDatePlus3DaysStr("00.01", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("32.01", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestErr, WrongDayFormat)
{
	err = dp.GetDatePlus3DaysStr("ff.01", date_str);
	ASSERT_EQ(err, WRONG_DAY);
	date_str = "";
}

TEST(TestErr, WrongMonth)
{
	err = dp.GetDatePlus3DaysStr("01.00", date_str);
	ASSERT_EQ(err, WRONG_MONTH);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("01.13", date_str);
	ASSERT_EQ(err, WRONG_MONTH);
	date_str = "";
}

TEST(TestErr, WrongMonthFormat)
{
	err = dp.GetDatePlus3DaysStr("01.ff", date_str);
	ASSERT_EQ(err, WRONG_MONTH);
	date_str = "";
}

TEST(TestErr, WrongFullDate)
{
	err = dp.GetDatePlus3DaysStr("00.00", date_str);
	ASSERT_EQ(err, WRONG_FULLDATE);
	date_str = "";
	err = dp.GetDatePlus3DaysStr("32.13", date_str);
	ASSERT_EQ(err, WRONG_FULLDATE);
	date_str = "";
}