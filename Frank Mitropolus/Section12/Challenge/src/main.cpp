// Section 12
// Challenge

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/
  
#include <iostream>

int *combine(const int *array1, const int *array2, const int Array1Size, const int Array2Size)
{
    int *ArrayPtr {new int[Array1Size*Array2Size]};
    int x {0};

    for(size_t i {0}; i < Array2Size; i++)
    {
        for(size_t j {0}; j < Array1Size; j++)
        {
            ArrayPtr[x] = array2[i] * array1[j];
            x++;
        }
    }
    return ArrayPtr;
}

void print(const int *array, const int size)
{
    std::cout << "[ ";
    for(size_t i {0}; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() 
{
    const int Arr1Size {5}, Arr2Size {3};
    int arr1[] {1,2,3,4,5};
    int arr2[] {10,20,30};

    print(arr1, Arr1Size);
    print(arr2, Arr2Size);
    int *result = combine(arr1, arr2, Arr1Size, Arr2Size);
    print(result, Arr1Size * Arr2Size);
    delete [] result;
}