========================================
CPP101x - Assignment 1: Setting Time for Cars
========================================

Author: [Your Name]
Email: [Your Email]
Date: December 17, 2025

========================================
IDE and Environment
========================================

This program has been developed and tested with:
- C++ Compiler: g++ (compatible with C++11 or later)
- IDE: Visual Studio Code / Visual Studio / Dev-C++
- Operating System: macOS / Windows / Linux

To compile and run:
1. Using g++:
   g++ assignment-1.cpp -o assignment-1
   ./assignment-1

2. Using Visual Studio: Open the .cpp file and press F5 to build and run

3. Using Dev-C++: Open the .cpp file and press F11 to compile and run

========================================
Program Functions
========================================

This program simulates a time setting system for a car with the following features:

1. INPUT AND VALIDATION
   - Accepts user input for date (day, month, year) and time (hour, minute)
   - Validates year: must be positive and not greater than 2025 (current year)
   - Validates month: must be between 1 and 12
   - Validates day: checks correct number of days based on month and leap year
     * Months with 31 days: January, March, May, July, August, October, December
     * Months with 30 days: April, June, September, November
     * February: 28 days (29 in leap years)
   - Validates hour: must be between 0 and 23 (24-hour format)
   - Validates minute: must be between 0 and 59
   - Implements leap year detection (divisible by 400, or by 4 but not 100)

2. TIME DISPLAY
   - Displays time in Vietnamese format: HHg:MMp, Ngay DD, Thang <Name>, YYYY
   - Example: 23g:25p, Ngay 05, Thang Chin, 2022
   - Month names displayed in Vietnamese (Mot, Hai, Ba, etc.)

3. TIME FORMAT CONVERSION
   - Supports both 12-hour and 24-hour time formats
   - User can select preferred format (input 12 or 24)
   - 12-hour format includes AM/PM indicators
   - Example 12-hour: 11g:25p PM, Ngay 05, Thang Chin, 2022
   - Example 24-hour: 23g:25p, Ngay 05, Thang Chin, 2022

4. TIMEZONE CONVERSION
   - Default input time is in UTC+0 (Greenwich Mean Time)
   - Supports timezone conversion from UTC-12:00 to UTC+14:00
   - User enters timezone offset (-12 to +12)
   - Automatically adjusts date when timezone conversion crosses day boundaries
   - Handles month and year transitions correctly

========================================
Program Flow
========================================

1. User inputs date (day, month, year)
2. User inputs time (hour, minute in 24-hour format)
3. Program validates all inputs
4. Program displays current time in UTC+0 with 24-hour format
5. User selects time format (12-hour or 24-hour)
6. Program displays time in selected format
7. User enters timezone offset
8. Program converts and displays time in the selected timezone

========================================
Code Structure
========================================

The program follows modular design with these functions:

- is_leap_year(year): Checks if a year is a leap year
- get_days_in_month(month, year): Returns the number of days in a given month
- get_month_name(month): Converts month number to Vietnamese name
- validate_year(year): Validates and prompts for correct year
- validate_month(month): Validates and prompts for correct month
- validate_day(day, month, year): Validates day based on month and year
- validate_hour(hour): Validates hour in 24-hour format
- validate_minute(minute): Validates minute
- display_time(): Displays time in specified format (12/24 hour)
- apply_timezone(): Converts time to different timezone with date adjustment
- main(): Orchestrates the program flow

========================================
Notes
========================================

- All validation functions use while loops to repeatedly prompt until valid input
- The program handles edge cases like leap years and timezone date transitions
- Code follows Google C++ style guide for naming conventions
- Comments are included throughout the code for clarity

========================================
