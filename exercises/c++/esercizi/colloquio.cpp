#include<iostream>
#include<vector>
#include<numeric>

template<typename I, typename pred>
I lin_search(I first, I last, pred cmp){
    // if (first == last){
    //     return last;
    // }
    // else{
    // while (first != last){
    //     if (cmp(*first)) return first;
    //     ++first;
    // }
    // return last;

    while(first != last && !cmp(*first)){
        ++first;
    }
    return first;
}

template <typename T>
class equal {
    T val;

    public:
    equal(T x):
        val{std::move(x)} {}

    bool operator()(const T& x){
        return x == val;
    }
};

// template<> class equal{
//     bool val;
// }

int main(){
    std::vector<int> a(1024*1024*100);
    std::iota(a.begin(), a.end(), 0);

    auto sol = lin_search(a.begin(), a.end(), equal<int>(99'000'000));
    if(sol == a.end()){}
}