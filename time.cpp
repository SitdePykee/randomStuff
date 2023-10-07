#include <bits/stdc++.h>

using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        day = month = year = 1;
    }

    Date reset(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void in()
    {
        cout << day << "/" << month << "/" << year;
    }

    void nhap()
    {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    }

    Date reset(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    int daysIn()
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
            {
                return 29;
                break;
            }
            else
            {
                return 28;
                break;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        }
    }

    Date normalize()
    {
        if (month > 12)
        {
            year += month / 12;
            month = month - 12 * (month / 12);
        }
        while (day > daysIn())
        {
            day = day - daysIn();
            month++;
        }
    }

    Date advance(int y, int m, int d)
    {
        day += d;
        month += m;
        year += y;
        normalize();
    }

    int operator-(Date d2)
    {
        int count = 0;
        while (day != d2.day || month != d2.month || year != d2.year)
        {
            count++;
            d2.day++;
            d2.normalize();
        }
        return count;
    }
};

int main()
{
    Date a;
    a.nhap();
    a.normalize();
    a.in();
}