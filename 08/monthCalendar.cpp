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
bool IsLeapYear(short Year) { return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); }
short NumberOfDaysInAMonth(short Year, short Month)
{
  int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return Month < 1 || Month > 12 ? 0 : (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1]);
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
string MonthShortName(short MonthNumber)
{
  string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  return (Months[MonthNumber - 1]);
}
void PrintMonthCalendar(short Month, short Year)
{
  short Carrant = DayOfWeekOrder(1, Month, Year);
  cout << "\n________________" << MonthShortName(Month) << "________________\n"
       << endl;
  cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
  short i;
  for (i = 0; i < Carrant; i++)
    cout << "     ";
  for (short j = 1; j <= NumberOfDaysInAMonth(Year, Month); j++)
  {
    printf("%5d", j);
    i++;
    if (i == 7)
    {
      cout << "\n";
      i = 0;
    }
  }
  cout << "\n___________________________________" << endl;
}

int main()
{
  PrintMonthCalendar(ReadMonth(), ReadYear());
  system("pause>0");
  return 0;
}