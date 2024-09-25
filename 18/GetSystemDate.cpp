#include <string>
#include <iostream>
using namespace std;
struct sDate
{
  short Day;
  short Month;
  short Year;
};

short ReadYear()
{
  short Year;
  cout << "\nPlease enter a year? ";
  cin >> Year;
  return Year;
}
short ReadMonth()
{
  short Month;
  cout << "\nPlease enter a month? ";
  cin >> Month;
  return Month;
}
short ReadDay()
{
  short Day;
  cout << "\nPlease enter a Day? ";
  cin >> Day;
  return Day;
}
sDate ReadFullDate()
{
  sDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}
bool IsLeapYear(short Year) { return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); }
short NumberOfDaysInAMonth(short Year, short Month)
{
  int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return Month < 1 || Month > 12 ? 0 : (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1]);
}
bool IsLastMonthInYear(short Month) { return Month == 12; }
bool IsLastDayInMonth(short Year, short Month, short Day)
{
  return NumberOfDaysInAMonth(Year, Month) == Day;
}
sDate IncreaseDateByOneDay(sDate Date)
{
  sDate Date1 = Date;
  if (!IsLastDayInMonth(Date.Year, Date.Month, Date.Day))
  {
    Date1.Day += 1;
  }
  else
  {
    Date1.Day = 1;
    if (!IsLastMonthInYear(Date.Month))
    {
      Date1.Month += 1;
    }
    else
    {
      Date1.Month = 1;
      Date1.Year += 1;
    }
  }
  return Date1;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
  if (Date1.Year < Date2.Year)
    return true;
  else if (Date1.Year == Date2.Year)
  {
    if (Date1.Month < Date2.Month)
      return true;
    else if (Date1.Month == Date2.Month)
    {
      if (Date1.Day < Date2.Day)
        return true;
    }
  }
  return false;
}
short GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
  if (!IsDate1BeforeDate2(Date1, Date2))
  {
    cout << "\nDate1 Is Not Before Date2";
    return -1;
  }
  int diff = 0;
  while (IsDate1BeforeDate2(Date1, Date2))
  {
    Date1 = IncreaseDateByOneDay(Date1);
    diff++;
  }
  return IncludeEndDay ? ++diff : diff;
}

sDate GetSystemDate()
{
  sDate Date;
  time_t t = time(0);
  tm *now = localtime(&t);
  Date.Day = now->tm_mday;
  Date.Month = now->tm_mon + 1;
  Date.Year = now->tm_year + 1900;
  return Date;
}
int main()
{
  cout << "\nPlease Enter Your Date of Birth:\n";
  sDate Date1 = ReadFullDate();
  sDate Date2 = GetSystemDate();
  cout << "\nYour Age is : " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";
  system("pause > 0");
  return 0;
}