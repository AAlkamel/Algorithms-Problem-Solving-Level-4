#include <iostream>
using namespace std;
struct stDate
{
  short Year;
  short Month;
  short Day;
};
bool isLeapYear(short Year) { return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0); }
short NumberOfDaysInAMonth(short Month, short Year)
{
  if (Month < 1 || Month > 12)
    return 0;
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short NumberOfDaysInAMonth(stDate Date)
{
  if (Date.Month < 1 || Date.Month > 12)
    return 0;
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (Date.Month == 2) ? (isLeapYear(Date.Year) ? 29 : 28) : days[Date.Month - 1];
}
bool IsLastDayInMonth(stDate Date) { return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year)); }
bool IsLastMonthInYear(short Month) { return (Month == 12); }
short ReadDay()
{
  short Day;
  cout << "\nPlease enter a Day? ";
  cin >> Day;
  return Day;
}
short ReadMonth()
{
  short Month;
  cout << "Please enter a Month? ";
  cin >> Month;
  return Month;
}
short ReadYear()
{
  short Year;
  cout << "Please enter a Year? ";
  cin >> Year;
  return Year;
}
stDate ReadFullDate()
{
  stDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
  short a, y, m;
  a = (14 - Month) / 12;
  y = Year - a;
  m = Month + (12 * a) - 2;
  // Gregorian://0:sun, 1:Mon, 2:Tue...etcreturn
  return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(stDate Date)
{
  return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(short DayOfWeekOrder)
{
  string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return arrDayNames[DayOfWeekOrder];
}
stDate GetSystemDate()
{
  stDate Date;
  time_t t = time(0);
  tm *now = localtime(&t);
  Date.Day = now->tm_mday;
  Date.Month = now->tm_mon + 1;
  Date.Year = now->tm_year + 1900;
  return Date;
}
bool IsEndOfWeek(stDate Date)
{
  return DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(stDate Date)
{
  return (DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 5);
}
bool IsBusinessDay(stDate Date)
{
  return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(stDate Date)
{
  return (6 - DayOfWeekOrder(Date));
}
short DaysUntilTheEndOfMonth(stDate Date)
{
  return (NumberOfDaysInAMonth(Date) - Date.Day);
}
short DaysUntilTheEndOfYear(stDate Date)
{
  short Days = 0;
  while (Date.Month <= 12)
  {
    Days += NumberOfDaysInAMonth(Date);
    Date.Month++;
  }
  Days -= Date.Day;
  return Days;
}
int main()
{
  stDate Date1 = GetSystemDate();
  cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1))
       << " , "
       << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
  //---------------------
  cout << "\nIs it End of Week?\n";
  if (IsEndOfWeek(Date1))
    cout << "Yes it is Saturday, it's of Week.";
  else
    cout << "No it's Not end of week.";
  //---------------------
  cout << "\n\nIs it Weekend?\n";
  if (IsWeekEnd(Date1))
    cout << "Yes it is a week end.";
  else
    cout << "No today is " << DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";
  //---------------------
  cout << "\n\nIs it Business Day?\n";
  if (IsBusinessDay(Date1))
    cout << "Yes it is a business day.";
  else
    cout << "No it is NOT a business day.";
  //---------------------
  cout << "\n\nDays until end of week : "
       << DaysUntilTheEndOfWeek(Date1) << " Day(s).";
  //---------------------
  cout << "\nDays until end of month : "
       << DaysUntilTheEndOfMonth(Date1) << " Day(s).";
  //---------------------
  cout << "\nDays until end of year : "
       << DaysUntilTheEndOfYear(Date1) << " Day(s).";
  system("pause>0");
  return 0;
}