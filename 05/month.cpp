#include <string>
#include <iostream>
using namespace std;
bool IsLeapYear(short year)
{
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
short NumberOfDaysInAMonth(short year, short month)
{
  int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return month < 1 || month > 12 ? 0 : (month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1]);
}
short NumberOfHoursInAMonth(short year, short month) { return NumberOfDaysInAMonth(year, month) * 24; }
int NumberOfMinutesInAMonth(short year, short month) { return NumberOfHoursInAMonth(year, month) * 60; }
int NumberOfSecondsInAMonth(short year, short month) { return NumberOfMinutesInAMonth(year, month) * 60; }
short ReadYear()
{
  short Year;
  cout << "\nPlease enter a year to check? ";
  cin >> Year;
  return Year;
}
short ReadMonth()
{
  short Month;
  cout << "\nPlease enter a month to check? ";
  cin >> Month;
  return Month;
}
int main()
{
  short Year = ReadYear();
  short Month = ReadMonth();
  cout << "\nNumber of Days    in Month [" << Year << " >>" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);
  cout << "\nNumber of Hours   in Month [" << Year << " >>" << Month << "] is " << NumberOfHoursInAMonth(Year, Month);
  cout << "\nNumber of Minutes in Month [" << Year << " >>" << Month << "] is " << NumberOfMinutesInAMonth(Year, Month);
  cout << "\nNumber of Seconds in Month [" << Year << " >>" << Month << "] is " << NumberOfSecondsInAMonth(Year, Month);
  system("pause>0");
  return 0;
}