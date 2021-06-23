#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>

/*
Exercises - session 01

## Understanding compiler messages
- Take a simple program (e.g., the hello world one) and put one at a time the following errors. 
Compile it and try to understand the error messages. If you have different compilers compare the messages from the two compilers.
  - do not put the `main` function
  - typos in function name (e.g., `c0ut`)
  - typos in variable name
  - forget to put `;`
  - forget to `#include <iostream>`
  - declare a variable with illegal name like `int double {0};`
*/

// int main(){
//     // int double{0};
//     std::cout << "Hello, world!" << std::endl;
// }

/*
## uniq
- Write a simple version of the Unix program `uniq -c`, which, when fed with a text, outputs the same text 
with **consecutive** identical lines collapsed into one prepended with the number of repetitions. 

You can scan the stdin as follows
```
std::string line;
while(std::getline(std::cin,line))
{...}
```
or
```
for(std::string line; std::getline(std::cin,line);)
{...}
```
What do you think it is better? Why?

Remember that if you type directly from stdin, you should press `Ctr+D` to close the stdin without interrupting the program. 
Moreover, you can redirect the content of a text to stdin trough the `<` operator
```
./a.out <a_file
```

You can compare strings with the `==` operator
```
std::string s1;
std::string s2;
...
if(s1 == s2)
if(s1 != s2)
```

`std::string` and `std::getline` are defined in the header `<string>`, so, remember to include it!

*/

// non funziona
/*
- manca un print se l'ultimo token va in else
- stampa cose in più

esempio:
input: x as as d f
output: 1:x , 1: , 2:as, 1:d

*/
int main(){

    size_t pos = 0;
    std::string line;
    
    while(std::getline(std::cin,line)){
        std::string limit = " ";
        size_t pos = 0;
        std::string token;
        int count = 1;
        token = line.substr(0, line.find(limit)); // first word
        line.erase(0, pos + limit.length());

        while ((pos = line.find(limit)) != std::string::npos) { // until the end of the string
            if (line.substr(0, pos) == token){
                count++;
                line.erase(0, pos + limit.length());
            } else {
                std::cout << count << ": " << token << std::endl;
                count = 1;
                token = line.substr(0, pos);
                line.erase(0, pos + limit.length());
                // std::cout << count << ": " << token << std::endl;
            }
            
        }
    } 
}




/*
## Getters
- write a function `get_int` that reads from stdin until a valid number is fed
- write a function `get_double` that reads from stdin until a valid number is fed.

*Hints*: 
You can keep reading from stdin using one of two statements
```
while(std::cin >> i)
```
or
```
while(!(std::cin >> i))
```
what is the difference?

After that a wrong input has been parsed, you have to clear the error flag from `std::cin` calling
```
std::cin.clear();
```
and ignore what just read
```
std::cin.ignore();
```
*/

int get_int(){
    int i;
    while(!(std::cin >> i)){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Not an int, insert another value" << std::endl;
    }
    return i;
}

double get_double(){
    double i;
    while(!(std::cin >> i)){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Not a double, insert another value" << std::endl;
    }
    return i;
}


// int main(){
//     int i = get_int();
//     std::cout << "I got the variable i = " << i << ", whose size is " << sizeof(i) << std::endl;
//     std::cin.clear();
//     double d = get_double();
//     std::cout << "I got the variable d = " << d << ", whose size is " << sizeof(d) << std::endl;

// }



/*
## Units of measure

- Write a code that reads a number with its proper unit of measure, and prints back that number according to the SI units, e.g.

```
1 inch
0.0254 m
```
*/


// int main(){
//     std::string unit;
//     float value;
//     std::cin >> value >> unit;
    
//     if (value >= 0){
//         if (unit == "inch" || unit == "inches" || unit == "in")
//           std::cout << "the value in SI is " << value*0.0254 << " m" << std::endl;

//         if (unit == "foot" || unit == "feet" || unit == "ft")
//           std::cout << "the value in SI is " << value*0.3048 << " m" << std::endl;

//         if (unit == "mile" || unit == "miles" || unit == "mi")
//           std::cout << "the value in SI is " << value*1609.34 << " m" << std::endl; 

//         if (unit == "ounce" || unit == "ounces" || unit == "oz")
//           std::cout << "the value in SI is " << value*0.0283495 << " kg" << std::endl; 

//         if (unit == "pound" || unit == "pounds" || unit == "lb" || unit == "lbs")
//           std::cout << "the value in SI is " << value*0.453592 << " kg" << std::endl;
        
//         else{
//             std::cout << "This unit of measure is not supported" << std::endl;
//         }
        
//     }
// }