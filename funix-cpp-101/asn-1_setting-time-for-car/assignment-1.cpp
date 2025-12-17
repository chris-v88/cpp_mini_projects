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

// 


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
