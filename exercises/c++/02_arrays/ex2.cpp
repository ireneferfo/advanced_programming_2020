#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

/*
# Exercises - session 02

## Reverse order

- Write a program that reads from stdin the length of an array and then stores in it the numbers given from stdin. 
The program should then print the numbers in **reverse order**. Remember to free the used memory properly. Divide the problem into two parts:
  1. Write one **template** function that allocates on the *heap* one array of a given size, initializes its elements, and returns the pointer to the first element.
  2. Write a **template** function that prints the elements of an array in the reverse order.

- Test with integers and doubles.
- Use `std::size_t`.

*Hints*: 
- If you have to pass an array to a function, pass the pointer to its first element and the size of the array itself.
- Remember to check your code with `valgrind`. If you have a MAC, you might have nasty surprises. Run `valgrind` on a **Linux**  system. 
Alternatively, compile and link your code with the following flags
  `-g -fsanitize=address`  and then run your executable. If it runs fine, you have no memory leaks. If it doesn't, you have some.
*/

template <typename T>
T* allocate_array(size_t size){
    return new T[size]; // no mi lascia inizializzarlo con {}
}

template<typename T>
void print_reverse(T* array, size_t size){
    for (size_t i = 0; i< size; ++i){
        std::cout << array[size-i-1] << " ";
    }
}

// int main(){
//     size_t size;

//     std::cout << "insert size: ";
//     std::cin >> size;

//     int* array = allocate_array<int>(size);

//     std::cout << "insert elements: ";
//     for(size_t i= 0; i < size; ++i)
//         std::cin >> array[i];

//     print_reverse(array, size);

//     delete[] array;
// }

/*
## Prime numbers

- Populate an array named `primes` containing the first prime numbers smaller than 100. Consider 2 as the first prime (i.e. `primes[0] == 2`).
- you are free to choose the design and the implementation.
- please comment and motivate your choices (e.g., allocate one big array, or every time I find a new prime number I increase the size of
  the previous `primes` array, etc.)

*Hints*:
- The remainder of a division between two integers is computed as follows:
```
unsigned int remainder = 6%3;
```
- Inside a for loop, you can use `continue` to immediately go to the next iteration, `break` to exit the loop. 
Note that if you have two or more nested loops, the statements affect only the innermost loop.
*/

// int main(){
//     std::vector<int> primes;
//     bool prime;
//     for (int i = 2; i < 100; i++){
//         prime = true;
//         for (int j = 2; j < i/2; j++){
//             if (i%j == 0){
//                 prime = false;
//                 break;
//             }
//         }
//         if (prime){
//             primes.push_back(i);
//         }
//     } 
//     std::cout << "here's primes:" << std::endl;
//     for (int i = 0; i < primes.size(); i++){
//         std::cout << primes[i] << ' ';
//     }
// }


/*
## Sieve of Eratosthenes

- Implement the Sieve of Eratosthenes algorithm. Write a code that prints on screen the first prime numbers up to `N` **included**, 
where `N` is read from stdin. The first printed number is `2`.

```shell
$ ./a.out 
insert number: 5
2
3
5

*Hints*:
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes :)

- the function `std::sqrt`, which computes the square root of a number, is defined in `<cmath>`
```c++
#include <cmath>
...
std::cout << std::sqrt(4) << std::endl;
```
*/

void sieve_eratosthenes(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p*p <=n; p++){
        if (prime[p] == true){
            for (int i = p*p; i <= n; i+=p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <=n; p++){
        if (prime[p])
            std::cout << p << " ";
    }
}


int main(){
    int n;
    std::cout << "insert a number: ";
    std::cin >> n;
    sieve_eratosthenes(n);
}
