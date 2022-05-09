#include <iostream> 
#include <random> 
 
using namespace std; 
 
int main() 
{ 
    const int NUM_CHARS = 1000; 
 
    // using C++11's better PRNG 
    std::default_random_engine gen; 
    gen.seed(); // using default seed 
     
    for (int i = 0; i < NUM_CHARS; i++) { 
        char letter = ((char) gen() % 26) + 'a'; 
        cout << letter; 
    } 
    cout << '\n'; 
} 
