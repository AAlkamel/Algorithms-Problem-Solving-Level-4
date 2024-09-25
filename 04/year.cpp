#include <string>
#include <iostream>
using namespace std;
bool IsLeapYear(short year)
{
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int NumberOfDaysInAYear(short year) { return IsLeapYear(year) ? 366 : 365; }
short NumberOfHoursInAYear(short year) { return NumberOfDaysInAYear(year) * 24; }
int NumberOfMinutesInAYear(short year) { return NumberOfHoursInAYear(year) * 60; }
int NumberOfSecondsInAYear(short year) { return NumberOfMinutesInAYear(year) * 60; }
short ReadYear()
{
  short Year;
  cout << "\nPlease enter a year to check? ";
  cin >> Year;
  return Year;
}
int main()
{
  short Year = ReadYear();
  cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
  cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
  cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
  cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);
  system("pause>0");
  return 0;
}