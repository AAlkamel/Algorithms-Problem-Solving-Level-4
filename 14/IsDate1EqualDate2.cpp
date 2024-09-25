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
sDate ReadDate()
{
  sDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
  return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
}
int main()
{
  sDate Date1 = ReadDate();
  sDate Date2 = ReadDate();
  if (IsDate1EqualDate2(Date1, Date2))
    cout << "\nYes, Date1 is Equal Date2.";
  else
    cout << "\nNo, Date1 is NOT Equal Date2.";
  system("pause > 0");
  return 0;
}