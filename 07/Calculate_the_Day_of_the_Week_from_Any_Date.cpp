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
short DayOfWeekOrder(short Day, short Month, short Year)
{
  short a, y, m;
  a = (14 - Month) / 12;
  y = Year - a;
  m = Month + (12 * a) - 2;
  // Gregorian://0:sun, 1:Mon, 2:Tue...etcreturn
  return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
  string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return arrDayNames[DayOfWeekOrder];
}
int main()
{
  cout << "\n"
       << DayShortName(DayOfWeekOrder(ReadDay(), ReadMonth(), ReadYear()));
  system("pause>0");
  return 0;
}