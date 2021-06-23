#include<iostream>
#include<array>
#include<stdio.h>
#include<algorithm>
#include<utility>
#include<sstream>
#include<fstream>
#include<vector>
#include<cstring>
#include<string>
#include <iomanip>


/*
## Class Date
Implement a class `Date`. This class must meet the following requirements:
- it has three **private** attributes to represent day, month and year
- use a scoped enum for month
- it has the following **public** functions:
	- constructor that takes as arguments a day, a month and a year. (Forget about the validation for now)
	- `day()` function that returns the day
	- `month()` function that returns the month
	- `year()` function that returns the year
	- `add_days(const unsigned int n)` which adds `n` days. You have to take care to increment months and years accordingly (neglect leap years)

*Hints*:
- you can add more functions, maybe private, to simplify the implementation of the above (e.g., you can implement a function that adds 1 single day)
- remember to properly mark the member functions that do not modify the class as `const`
- you should think where to implement the member functions, i.e. inside the class declaration or outside


Member functions that are *defined* inside the class are **inlined** meaning that the compiler will replace the function call to its
implementation (thus the executable becomes bigger). A good rule of thumb is that functions that are simple (e.g. a simple return or few
lines of code) should be inlined. Bigger functions are recommended to be implemented outside the class. Remember that the name of the
function is prefixed with the class name (see the implementation of `bar()` above).

- In a switch-case statement you can use several `case` labels for a single case
```c++
int a;
...
switch (a){
	case 0: case 2: case 4:
	case 6: case 8: case 10:
		std::cout << "a is even\n";
		break;

	case 1: case 3: case 5:
	case 7: case 9:
		std::cout << "a is odd\n";
		break;
	default:
		std::cout << "a > 10\n";
		break;
}
```*/

enum class months{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class Date{
    int _day, _year;
    months _month;

 public:
    Date(const int d, const months m, const int y): _day{d}, _year{y}, _month{m} {}
    ~Date() = default;

    int day() const {return _day;}
    int year() const{return _year;}
    months month() const{return _month;}

    bool is_leap(){
        return _year%4 == 0;
    }

    void add_months (const unsigned int n);
    void add_days(const unsigned int n);
};

void Date::add_months(const unsigned int n){
    if ((unsigned int)_month + n > 11){
        unsigned int old = (unsigned int)_month;
        _month = months::jan;
        _year++;
        add_months(n - (12 - old));
    }
    else {
        _month = (months)((int)_month + n);
    }
}

void Date::add_days(const unsigned int n){
    unsigned int tot_days;
    switch(_month){
        case months::feb:
            if (is_leap()) tot_days = 29;
            else tot_days = 28;
            break;
        
        case months::nov: case months::apr: case months::jun: case months::sep:
            tot_days = 30;
            break;

        default: 
            tot_days = 31; 
            break;
    }

    if(_day + n > tot_days) {
        unsigned int old = _day;
        _day = 1;
        add_months(1);
        add_days(n-(tot_days-old));
    }
    else {
        _day += n;
    }
}


bool operator==(const Date& lhs, const Date& rhs){
    if (lhs.year() == rhs.year() && lhs.month() == rhs.month() && lhs.day() == rhs.day()) return true;
    return false;
}

bool operator!=(const Date& lhs, const Date& rhs){
    return !(lhs==rhs);
}

std::ostream& operator<<(std::ostream& os, const Date& d){
    os << d.day() << '/' << (unsigned int)d.month() + 1 << '/' << d.year();
    return os;
}

int main(){
    Date my = Date(10, months::jul, 1998);
    std::cout << my << " is leap: \t" << std::boolalpha << my.is_leap() << std::endl;

    Date my2 = Date(10, months::jul, 1998);
    std::cout << "equality: (true) \t"<< std::boolalpha << (my == my2) << std::endl;
    std::cout << "not equality: (false) \t "<< std::boolalpha << (my != my2) << std::endl;

    my.add_months(13);
    std::cout << my << std::endl;
    my.add_days(50);
    std::cout << my << std::endl;
    my.add_days(1000);
    std::cout << my << std::endl;
}