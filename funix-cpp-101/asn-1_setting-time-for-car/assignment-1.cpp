#include <iostream>
#include <string>
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
int get_days_in_month(int month, int year)
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
    cout << " ! ERROR ! Invalid year. Please enter again: " << endl;
    cin >> year;
  }
  return year;
}

int validate_month(int month)
{
  while (month < 1 || month > 12)
  {
    cout << " ! ERROR ! Invalid month. Please enter again: " << endl;
    cin >> month;
  }
  return month;
}

int validate_day(int day, int month, int year)
{
  int max_days = get_days_in_month(month, year);
  cout << "Max days is " << max_days << endl;
  while (day < 1 || day > max_days)
  {
    cout << " ! ERROR ! Invalid day. Please enter again: " << endl;
    cin >> day;
  }
  return day;
}

int validate_hour(int hour)
{
  while (hour < 0 || hour > 23)
  {
    cout << " ! ERROR ! Invalid hour. Please enter again: " << endl;
    cin >> hour;
  }
  return hour;
}

int validate_minute(int minute)
{
  while (minute < 0 || minute > 59)
  {
    cout << " ! ERROR ! Invalid minute. Please enter again: " << endl;
    cin >> minute;
  }
  return minute;
}

int validate_time_format(int user_format)
{
  while (user_format != 12 && user_format != 24)
  {
    cout << " ! ERROR ! Invalid input. Please enter again: " << endl;
    cin >> user_format;
  }
  return user_format;
}

int validate_time_zone_selection(int timezone)
{
  while (timezone < -12 || timezone > 12)
  {
    cout << endl << "! ERROR ! Invalid input. Please try again: ";
    cin >> timezone;
  }
  return timezone;
}

// Display in 24-hour format
void display_date_24format(int hr, int min, int dd, int mm, int yy)
{
  string month = get_month_name(mm);
  cout << hr << "h:" << min << "m, " << dd << " " << month << ", " << yy << endl;
}

// Display in 12-hour format
void display_date_12format(int hr, int min, int dd, int mm, int yy)
{
  string month = get_month_name(mm);
  string meridiem = (hr >= 12) ? "PM" : "AM";
  int hour = hr;
  if (hr == 0)
  {
    hour = 12;
  }
  if (hr > 12)
  {
    hour = hr - 12;
  }
  cout << hour << "h:" << min << "m " << meridiem << ", " << dd << " " << month << ", " << yy << endl;
}

// Apply timezone 
void apply_timezone(int hr, int minute, int day, int mon, int yr, int timezone)
{
  hr += timezone;
  int max_days_in_month = get_days_in_month(mon, yr);

  // If the time is pass 24 hour -- pass a day
  while (hr >= 24)
  {
    // minus 24 hour & plus 1 day for the accurate time
    hr -= 24;
    day++;

    // check if the day pass the number of day in a month
    // if yes, it is another month, and day is reset to lower
    if (day > max_days_in_month)
    {
      day = 1;
      mon++;

      // but if month is pass 12, mean it is already passed a year
      if (mon > 12)
      {
        mon = 1;
        yr++;
      }
    }
  }

  // If time is less than 0, it is in previous day
  while (hr < 0)
  {
    hr -= 24;
    day--;

    if (day < 1)
    {
      mon--;

      if (mon < 1)
      {
        mon = 12;
        yr--;
      }
    }
    day = get_days_in_month(mon, yr);
  }

  cout << "Time is updated to timezone UTC " << timezone << " is " << hr << " : " << minute << " , " << day << " " << mon << " " << yr << ", " << ", UTC " << timezone;
}

int main()
{
  cout << "========================================" << endl;
  cout << "SET TIME FOR YOUR CAR" << endl;
  cout << "---------------------------------------" << endl;
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
  day = validate_day(day, month, year);

  cout << "   Hour: ";
  cin >> hour;
  hour = validate_hour(hour);

  cout << "   Minute: ";
  cin >> minute;
  minute = validate_minute(minute);

  cout << "---------------------------------------" << endl;
  display_date_24format(hour, minute, day, month, year);
  cout << "---------------------------------------" << endl;

  cout << "Choose a time format" << endl;
  cout << "Enter '12' for 12-hour, '24' for 24-hour format: ";
  int time_format;
  cin >> time_format;
  time_format = validate_time_format(time_format);
  cout << endl << "---------------------------------------" << endl;
  if (time_format == 12)
  {
    display_date_12format(hour, minute, day, month, year);
  }
  else
  {
    display_date_24format(hour, minute, day, month, year);
  }
  

  cout << "---------------------------------------" << endl;
  cout << "By default, the timezone is set to UTC 00:00 timezone." << endl;
  cout << "Enter the current time zone from -12 to 12 only: ";

  int time_zone_selection = 0;
  cin >> time_zone_selection;
  time_zone_selection = validate_time_zone_selection(time_zone_selection);
  
  apply_timezone(hour, minute, day, month, year, time_zone_selection);

  return 0;
};
