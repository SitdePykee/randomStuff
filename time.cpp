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

    friend bool operator>(Date, Date);
    friend bool operator<(Date, Date);

    int operator-(Date d2)
    {
        int count = 0;
        Date d1;
        d1.day = day;
        d1.month = month;
        d1.year = year;
        while (d1.day != d2.day || d1.month != d2.month || d1.year != d2.year)
        {
            count++;
            if (d1 > d2)
            {
                d2.day++;
                d2.normalize();
            }
            else
            {
                d1.day++;
                d1.normalize();
            }
            return count;
        }
    }
};

bool operator>(Date d1, Date d2)
{
    bool ok = false;
    if (d1.year > d2.year)
    {
        ok = true;
    }
    else if (d1.year = d2.year)
    {
        if (d1.month > d2.month)
        {
            ok = true;
        }
        else
        {
            if (d1.day > d2.day)
            {
                ok = true;
            }
        }
    }
    return (ok);
}

bool operator<(Date d1, Date d2)
{
    bool ok = false;
    if (d1.year < d2.year)
    {
        ok = true;
    }
    else if (d1.year = d2.year)
    {
        if (d1.month < d2.month)
        {
            ok = true;
        }
        else
        {
            if (d1.day < d2.day)
            {
                ok = true;
            }
        }
    }
    return (ok);
}

int main()
{
    Date a, b;
    a.nhap();
    a.normalize();
    b.nhap();
    b.normalize();
    cout << (a > b);
}