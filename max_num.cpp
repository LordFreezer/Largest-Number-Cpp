#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
using namespace std;

// function that finds the max. It is paired with fun1.
int max(int L, int R) 
{
    // base case
    if (L == R)
        return L;
    // recursive call
    if (L < R) 
        return max(L + 1, R);
    // last resort case
    else 
        return L;
}
// function that divides the array
int traverse(int A[], int L, int R)
{
    // base case
    if (L == R)
        return (A[L]);
    int M = (L + R) / 2;
    // recursive tail call
    return max(traverse(A, L, M), traverse(A, M + 1, R));
}
// populates array with N random numbers
int populate(int A[], int N)
{
    // allows for different random numbers every execution
    srand(time(NULL)); 
    for (int i = 0; i < N; i++)
    {
        A[i] = (rand() % 1000) + 1;
  //      cout << A[i] << " ";
    }
    return *A;
}
int main()
{ 
    auto start = chrono::high_resolution_clock::now();
    const int N = 100000; // number of randomly generated numbers
    int A[N]; 
    populate(A, N); // function populates array with random numbers
    int R = N - 1; // right most element
    int L = 0; // left most element
    auto end = chrono::high_resolution_clock::now();
    cout << "Elapsed time in nanosecond : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " μs" << endl;
    cout << "max is " << traverse(A, L, R) << endl;
    cout << "upper bound of values " << 1000 << endl;
    cout << "number of numbers generated is " << N << endl;
}
