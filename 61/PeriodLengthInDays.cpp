#include <iostream>
using namespace std;
struct stDate
{
  short Year;
  short Month;
  short Day;
};
struct stPeriod
{
  stDate StartDate;
  stDate EndDate;
};
enum enDateCompare
{
  Before = -1,
  Equal = 0,
  After = 1
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
stDate IncreaseDateByOneDay(stDate Date)
{
  stDate Date1 = Date;
  if (!IsLastDayInMonth(Date))
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
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
  if (Date1.Year < Date2.Year)
    return true;
  else if (Date1.Year == Date2.Year)
  {
    if (Date1.Month < Date2.Month)
      return true;
    else if (Date1.Month == Date2.Month)
    {
      if (Date1.Day < Date2.Day)
        return true;
    }
  }
  return false;
}
void SwapDates(stDate &Date1, stDate &Date2)
{
  stDate TempDate;
  TempDate.Year = Date1.Year;
  TempDate.Month = Date1.Month;
  TempDate.Day = Date1.Day;

  Date1.Year = Date2.Year;
  Date1.Month = Date2.Month;
  Date1.Day = Date2.Day;

  Date2.Year = TempDate.Year;
  Date2.Month = TempDate.Month;
  Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
  int Days = 0;
  short SwapFlagValue = 1;
  if (!IsDate1BeforeDate2(Date1, Date2))
  { // Swap Dates
    SwapDates(Date1, Date2);
    SwapFlagValue = -1;
  }
  while (IsDate1BeforeDate2(Date1, Date2))
  {
    Days++;
    Date1 = IncreaseDateByOneDay(Date1);
  }
  return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
  return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
}
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
  return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
};
stPeriod ReadPeriod()
{
  stPeriod Period;
  cout << "\nEnter Start Date:\n";
  Period.StartDate = ReadFullDate();
  cout << "\nEnter End Date:\n";
  Period.EndDate = ReadFullDate();
  return Period;
}

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
  if (IsDate1BeforeDate2(Date1, Date2))
    return enDateCompare::Before;
  if (IsDate1EqualDate2(Date1, Date2))
    return enDateCompare::Equal;
  return enDateCompare::After;
}
bool isDateInPeriod(stDate Date, stPeriod Period)
{
  return !(CompareDates(Date, Period.StartDate) ==
               enDateCompare::Before ||
           CompareDates(Date, Period.EndDate) ==
               enDateCompare::After);
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
  if (
      CompareDates(Period2.EndDate, Period1.StartDate) ==
          enDateCompare::Before ||
      CompareDates(Period2.StartDate, Period1.EndDate) ==
          enDateCompare::After)
    return false;
  else
    return true;
}
// my answer
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{

  if (IsOverlapPeriods(Period1, Period2))
  {
    if (isDateInPeriod(Period2.StartDate, Period1))
    {
      if (isDateInPeriod(Period2.EndDate, Period1))
      {
        return GetDifferenceInDays(Period2.StartDate, Period2.EndDate);
      }
      else
      {
        return GetDifferenceInDays(Period2.StartDate, Period1.EndDate);
      }
    }
    else
    {
      if (isDateInPeriod(Period1.EndDate, Period2))
      {
        return GetDifferenceInDays(Period1.StartDate, Period1.EndDate);
      }
      return GetDifferenceInDays(Period1.StartDate, Period2.EndDate);
    }
  }

  return 0;
}
// my teacher answer
/*
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
  int Period1Length = PeriodLengthInDays(Period1, true);
  int Period2Length = PeriodLengthInDays(Period2, true);
  int OverlapDays = 0;
  if (!IsOverlapPeriods(Period1, Period2))
    return 0;
  if (Period1Length < Period2Length)
  {
    while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
    {
      if (isDateInPeriod(Period1.StartDate, Period2))
        OverlapDays++;
      Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
    }
  }
  else
  {
    while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
    {
      if (isDateInPeriod(Period2.StartDate, Period1))
        OverlapDays++;
      Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
    }
  }
  return OverlapDays;
}
*/

int main()
{
  cout << "\nEnter Period 1 :";
  stPeriod Period1 = ReadPeriod();
  cout << "\nEnter Period 2 :";
  stPeriod Period2 = ReadPeriod();
  cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2);
  system("pause>0");
  return 0;
}