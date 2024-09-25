#include <string>
#include <iostream>
using namespace std;
bool IsLeapYear(short year)
{
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
  // if (year % 400 == 0)
  // {
  //   return true;
  // }
  // if (year % 4 == 0 && year % 100 != 0)
  // {
  //   return true;
  // }
  // else
  // {
  //   return false;
  // }
}
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
  if (IsLeapYear(Year))
    cout << "\nYes, Year [" << Year << "] is a leap year.\n";
  else
    cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";
  system("pause>0");
  return 0;
}