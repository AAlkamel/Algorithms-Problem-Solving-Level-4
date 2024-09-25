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
short ReadDays()
{
  short Days;
  cout << "\nPlease enter number of Days to add?";
  cin >> Days;
  return Days;
}
bool IsLeapYear(short Year) { return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); }
short NumberOfDaysInAMonth(short Year, short Month)
{
  int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return Month < 1 || Month > 12 ? 0 : (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1]);
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
  short TotalDays = 0;
  for (short i = 1; i < Month; i++)
  {
    TotalDays += NumberOfDaysInAMonth(Year, i);
  }
  return TotalDays + Day;
}
sDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
{
  sDate D;

  for (short i = 1; i <= 12; i++)
  {
    if (DaysOrderInYear > NumberOfDaysInAMonth(Year, i))
    {
      DaysOrderInYear -= NumberOfDaysInAMonth(Year, i);
    }
    else
    {
      D.Day = DaysOrderInYear;
      D.Month = i;
      D.Year = Year;
      return D;
    }
  }
}
sDate DateAddDays(int Days, sDate Date)
{

  Days += Date.Day;
  while (Days > NumberOfDaysInAMonth(Date.Year, Date.Month))
  {
    Days -= NumberOfDaysInAMonth(Date.Year, Date.Month);
    if (Date.Month >= 12)
    {
      Date.Month = 1;
      Date.Year++;
    }
    else
    {
      Date.Month++;
    }
  }
  Date.Day = Days;
  return Date;
};
int main()
{
  sDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  short Days = ReadDays();
  Date = DateAddDays(Days, Date);
  cout << "\nDate after adding [" << Days << "] days is: ";
  cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
  system("pause>0");
  return 0;
}