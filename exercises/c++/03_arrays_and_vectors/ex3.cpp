#include<iostream>
#include<array>
#include<stdio.h>
#include<algorithm>
#include<utility>
#include<sstream>
#include<fstream>
#include<vector>
#include<cstring>
#include<chrono>
#include<map>
#include<string>
#include <thread>

/*
## Matrix transpose

- Write a function that computes the transpose of a matrix. The matrix is represented by a simple `std::array<double,N>` 
where N is the total size of the matrix (i.e., number of rows times number of columns). The original array must be modified inside the function `transpose`. 

*Hints*: 

- In C/C++, the matrices are accessed row-wise
- You are not required to do the transpose *in place*
- Test with both square and rectangular matrices.
- Use `std::swap` defined in header `<utility>`
*/

template <typename T>
void matrix_init(T& a){
    int i = 0;
    for (auto& x : a){
        x = i;
        i++;
    }
}

template <typename T>
void matrix_print(const T& a, const int row, const int col){
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            std::cout << a[i*col +j] << " ";
        }
        std::cout << std::endl;
    }
}


template <typename T>
void transpose(T& a, const int row, const int col){
    if (row == col){
        for (int i = 0; i<row; i++)
            for (int j = 0; j<i; j++)
                std::swap(a[i*row + j], a[j*col +i]);      // no funzia
    } else {
        T b{a};
        for (int i = 0; i<row; i++)
            for (int j = 0; j<col; j++)
                a[j*row +i] = b[i*col +j]; 
    }

}

// int main(){
//     const int rows = 3;
//     const int cols = 3;
//     std::array<double, rows*cols> A{};
//     matrix_init(A);
//     matrix_print(A, rows, cols);
//     transpose(A, rows, cols);
//     std::cout << "\ntransposed: " << std::endl;
//     matrix_print(A, cols, rows);

//     return 0;
// }


/*
## Convert `argv` to types

- Modify the above program such that the number of rows and columns are read from command line arguments.

*Hints*:
 - Use `std::istringstream` defined in the header `<sstream>`

 ```c++
#include <sstream>

std::size_t rows;
{
  std::istringstream is{argv[1]};
  is >> rows;
}
 ```
*/
// int main(int argc, char **argv){
//     std::size_t rows, cols;
//     std::istringstream r{argv[1]};
//     r >> rows;
//     std::istringstream c{argv[2]};
//     c >> cols;

//     std::array<double, rows*cols> A{};
//     matrix_init(A);
//     matrix_print(A, rows, cols);
//     transpose(A, rows, cols);
//     matrix_print(A, rows, cols);

//     return 0;
// }


/*
## Mean and Median

- Store the numbers contained in file `temperatures.txt` into a `std::vector<double>` and compute:
  - the mean
  - the median

*Hints*:

- use `push_back()`
- you can increment a variable using `+=` operator
- you can **sort** the elements of a vector `v` as follows
```c++
#include <algorithm>

std::vector<double> v;
...
std::sort( v.begin(), v.end() );
```
*/
// int main(){
//     std::ifstream fin("/Users/ireneferfoglia/Desktop/adv_programming/advanced_programming_2020/exercises/c++/03_arrays_and_vectors/temperatures.txt");
//     std::vector<double> v;
//     double element;
//     while (fin >> element){
//         v.push_back(element);
//     }

//     std::sort(v.begin(), v.end());
//     double median = v[v.size()/2];    // conversion from double to int 
//     double total;
//     for (auto& x : v){
//         total += x;
//     }
//     double mean = total/v.size();

//     std::cout << mean << "     " << median << std::endl;
// }


/*
## Avoid repeated words

- Read from stdin a sequence of words. Store each word in a `std::vector<std::string>`. Then, print the words without repetitions.

*Hints*:

- you can print the words in any order you want (i.e., you are not required to print the words in the order you have read them)
*/


// int main(){
//     std::vector<std::string> s{};
//     std::string string;
//     while (std::cin >> string){ // use ctrl + D to stop input
//         s.push_back(string);
//     }

//     std::sort(s.begin(), s.end());

//     for (size_t i = 0; i < s.size(); i++){
//         for (size_t j = 0; j < (s.size() - i); j++){
//             if (s[i] == s[i+j]) 
//                 s.erase(s.begin()+i+j);
//         }
//     } 

//     std::cout << "\nHere's what you gave me: ";
//     for (size_t i =0; i < s.size(); i++){
//         std::cout << s[i] << " "; 
//     }
// }

/*
## **Optional**: Use `std::map` and `std::unordered_map`

- Read the `LittleWomen.txt` and then print all the read words (without repetitions) followed by the number of repetitions of that word. 
Compare the time to do the same using `std::vector`, `std::map`, `std::unordered_map`. The order in which the words are printed is **not** relevant.

- You can measure the elapsed time as follows:
```c++
#include <chrono>

auto t0 = std::chrono::high_resolution_clock::now();
auto t1 = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
```

- Compile with the flag `-O3` (is a capital O, not a zero)
*/
using namespace std::chrono;

// int main(){
//     std::ifstream fin("/Users/ireneferfoglia/Desktop/adv_programming/advanced_programming_2020/exercises/c++/03_arrays_and_vectors/LittleWomen.txt");

//     auto t0 = high_resolution_clock::now();

//     // std::vector<std::string> text{};               // VEC
//     // std::vector<unsigned int> count{};             // VEC

//     std::map<std::string, unsigned int> map{};        // MAP

//     std::string word;
//     while (fin >> word){
//         // text.push_back(word);                      // VEC
//         // count.push_back(1);                        // VEC

//         word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end()); // remove punctuation

//         if (map.find(word) == map.end()){
//             map.insert(std::pair<std::string, unsigned int> (word, 1));      // MAP
//         } else {
//             map[word]++;
//         }
//     }

//     // std::sort(text.begin(), text.end());                   // VEC

//     // for (size_t i = 0; i < text.size(); i++){              // VEC
//         // for (size_t j = 0; j < (text.size() - i); j++){    // VEC
//             // if (text[i] == text[i+j]) {
//             //     text.erase(text.begin()+i+j);
//             //     count.erase(count.begin()+i+j);
//             //     count[i] +=1;
//             // }

//     auto t1 = high_resolution_clock::now();
//     duration<double> time_span = duration_cast<duration<double>>(t1 - t0);

//     std::cout << "\nOutput:\n";

//     //  for (size_t i =0; i < 20; i++){                         // VEC
//         // std::cout << text[i] << "\t" << count[i] << '\n';    // VEC

//     for (auto elem : map){                                        // MAP
//         std::cout << elem.first << " " << elem.second << "\n";    // MAP
//     }
//     std::cout << "total time:\t" << time_span.count() << " seconds" << std:: endl; 
// }

// time with std::vector: 24.1296 seconds
// time with std::map: 	0.0896311 seconds



/*
## **Optional**: Conway's Game of Life
- Implement the [Game of Life](https://www.wikidata.org/wiki/Q244615#sitelinks-wikipedia)
- You can slow down your code by forcing a "nap".
```c++
#include <chrono>
#include <thread>
...
std::this_thread::sleep_for (std::chrono::milliseconds(50));
```
*/


