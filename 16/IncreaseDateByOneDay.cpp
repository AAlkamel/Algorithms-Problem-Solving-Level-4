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
int main()
{
  sDate Date = ReadFullDate();
  Date = IncreaseDateByOneDay(Date);
  cout << "\nDate after adding one day is:" << Date.Day << "/" << Date.Month << "/" << Date.Year;
  system("pause > 0");
  return 0;
}