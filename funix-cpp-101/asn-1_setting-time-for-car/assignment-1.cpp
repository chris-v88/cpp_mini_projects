#include <iostream>
using namespace std;

// check if it's leap year based on 
// A year is a leap year if it is divisible by 400
// OR divisible by 4 but not by 100
bool is_leap_year(int year)
{
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Convert month to string
string get_month_name(int month)
{
  switch (month)
  {
  case 1: return "Jan";
  case 2: return "Feb";
  case 3: return "Mar";
  case 4: return "Apr";
  case 5: return "May";
  case 6: return "Jun";
  case 7: return "Jul";
  case 8: return "Aug";
  case 9: return "Sep";
  case 10: return "Oct";
  case 11: return "Nov";
  case 12: return "Dec";
  default: return "";
  }
}

// Get # of days in a month
int get_days_in_mont(int month, int year)
{
  if (month == 2)
  {
    // Feb has 28 days (if it's a leap year, it has 29 days)
    return is_leap_year(year) ? 29 : 28;
  }
  // Months with 31 days are 1, 3, 5, 7, 8, 10, 12
  if ((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
  {
    return 31;
  }
  return 30;
}

// Validate functions for user inputs
int validate_year(int year)
{
  while (year <= 0 || year > 2025)
  {
    cout << "Invalid year. Please enter again: ";
    cin >> year;
  }
  return year;
}

int validate_month(int month)
{
  while (month < 1 || month > 12)
  {
    cout << "Invalid month. Please enter again: ";
    cin >> month;
  }
  return month;
}

int validate_day(int day, int month, int year)
{
  int max_days = get_days_in_mont(month, year);
  while (day < 1 || day > max_days)
  {
    cout << "Invalid day. Please enter again: ";
    cin >> day;
  }
  return day;
}

int validate_hour(int hour)
{
  while (hour < 0 || hour > 23)
  {
    cout << "Invalid hour. Please enter again: ";
    cin >> hour;
  }
  return hour;
}

int validate_minute(int minute)
{
  while (minute < 0 || minute > 59)
  {
    cout << "Invalid minute. Please enter again: ";
    cin >> minute;
  }
  return minute;
}

void display_date_format(int hr, int min, int dd, int mm, int yy)
{
  string month = get_month_name(mm);
  cout << hr << "h:" << min << "m, " << dd << ", " << month << ", " << yy << endl;
}

int main()
{
  cout << "========================================" << endl;
  cout << "Program to set time for car" << endl;
  cout << "========================================" << endl;
  cout << "Enter following information" << endl;

  // init data
  int day, month, year, hour, minute;

  cout << "   Year: ";
  cin >> year;
  year = validate_year(year);

  cout << "   Month: ";
  cin >> month;
  month = validate_month(month);

  cout << "   Day: ";
  cin >> day;
  day = validate_day(month, day, year);

  cout << "   Hour: ";
  cin >> hour;
  hour = validate_hour(hour);

  cout << "   Minute: ";
  cin >> minute;
  minute = validate_minute(minute);

  display_date_format(hour, minute, day, month, year);

  return 0;
};
