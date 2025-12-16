#include <iostream>
using namespace std;

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

int validate_day(int day)
{
  while (day < 1 || day > 31)
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

int main()
{
  cout << "Program to set time for car" << endl;
  cout << "Enter following information" << endl;

  int day, month, year, hour, minute;
  cout << "   Day: ";
  cin >> day;
  day = validate_day(day);

  cout << "   Month: ";
  cin >> month;
  month = validate_month(month);

  cout << "   Year: ";
  cin >> year;
  year = validate_year(year);
  
  cout << "   Hour: ";
  cin >> hour;
  hour = validate_hour(hour);

  cout << "   Minute: ";
  cin >> minute;
  minute = validate_minute(minute);

  return 0;
};
