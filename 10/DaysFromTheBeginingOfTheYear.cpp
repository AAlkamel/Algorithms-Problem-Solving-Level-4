#include <string>
#include <iostream>
using namespace std;

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
int main()
{
  short Day = ReadDay();
  short Month = ReadMonth();
  short Year = ReadYear();
  cout << "\nNumber of Days from the begining of the year is " << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
  system("pause>0");
  return 0;
}