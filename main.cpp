/*Part 1) In the first part of this program, start by prompting the user for the size of arrays to
work with (accept any values from 1 to 52).You will write several functions that work with integer arrays.
Start by writing a function (initialize_array) that takes in an array and fills it with sequential whole
numbers (0,1,2 and so on) up to the size of the array.After initialization, display the array and then call a
function that//creates a NEW array by shuffling (algorithm given at the bottom of this document) the current one
and returning that new array through the return statement.By shuffling, I mean the original contents of the array will
be in random locations after the call. So, after this function call, you will have a second array with the numbers shuffled
and the original array unchanged. Display the contents of both arrays after the function call.

Required functions:
void initialize_array(int [], int);
int * shuffle_array(const int [], int);
void print_array(const int [], int);

Part 2) In this part you will write two functions that take in an array and create subarrays from it.
One function will go through the array, count up the number of odd numbers//in the array.It will then
dynamically create a new array, fill it up with the//odd integers in the array and then return the size of this
array through one of the parameters.The second function will do the same for the even numbers in the array.Display
the original array before making your function calls to split the array, then display all 3 arrays afterwards.

Required functions:
int * createOddArray(const int [], int, int &);
int * createEvenArray(const int [], int, int &);

Part 3) Finally, write a function that takes in two integer arrays and their sizes.
This function should then create and allocate an array inside the function of the same size as the
largest of these two arrays.The function should then go through both arrays starting at the lowest index.
At each index, compare their values and put the highest of these values in the 3rd array that we created.
If one array isn’t large enough, the other array will always win at those indices.Output this array. Sort this
3rd array using selection sort and then output the results to the screen again.This array does not need to be
returned to the main body.

Required functions:
void array_war(int *, int, int *, int);
void sort_array(int *,int);

Part 4) Write a main body that feeds each of the parts to each other,one after another.So start by
creating a shuffled array.Then split it up with calls to createOddArray and createEvenArray.Then send
it to array_war and sort the resulting array.

Example:Please enter the size of the array:10
Original array is:[0 1 2 3 4 5 6 7 8 9]
Shuffled array is:[4 5 0 2 3 9 8 1 7 6]
After call to createOddArray, oddArray is:[5 3 1 7]
After call to createEvenArray, evenArray is:[4 0 2 8 6]
ArrayFight winners were:[5 3 2 8 6]
Sorted ArrayFight winners were:[2 3 5 6 8]

Details: For this project, ensure that all your arrays should be dynamically allocated.
Shuffle algorithm: To shuffle an array, you can use the following pseudocode or your own algorithm:

To shuffle an array a of n elements (indices 0..n-1):
  for i from n - 1 down to 1 do
       j = random integer with 0 <= j <= i
       exchange a[j] and a[i]*/

#include <iostream>
#include <cstdlib>
using namespace std;

void initialize_array(int[], int);
void print_array(const int[], int);
int* shuffle_array(const int[], int);
int* createOddArray(const int[], int, int&);
int* createEvenArray(const int[], int, int&);
void array_war(int*, int, int*, int);
void sort_array(int*, int);

int main()
{
    int size = 0, oddSize = 0, evenSize = 0;

    do
    {
        while (cout << "Enter size of array (from 1 to 52) to work with:"
            && !(cin >> size)) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input for size of array." << endl;
        }
        if (size < 1 || size > 52)
            cout << "Error. Array size should be between 1 and 52." << endl;
    } while (size < 1 || size > 52);
    int* original_arr = new int[size];
    initialize_array(original_arr, size);
    cout << "Contents of newly created array below." << endl;
    print_array(original_arr, size);
    int* shuffled_arr = shuffle_array(original_arr, size);
    cout << "Contents of shuffled array below." << endl;
    print_array(shuffled_arr, size);
    cout << "Contents of original array below." << endl;
    print_array(original_arr, size);
    int* odd_arr = createOddArray(shuffled_arr, size, oddSize);
    cout << "Contents of odd numbers array below." << endl;
    print_array(odd_arr, oddSize);
    int* even_arr = createEvenArray(shuffled_arr, size, evenSize);
    cout << "Contents of even numbers array below." << endl;
    print_array(even_arr, evenSize);
    array_war(odd_arr, oddSize, even_arr, evenSize);


    return 0;
}

void initialize_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
        *(a + i) = i;
}

void print_array(const int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << *(a + i) << " ";
    cout << endl;
}

int* shuffle_array(const int a[], int size)
{
    int* shuffled_arr = new int[size];
    unsigned seed = 0;
    seed = time(0);
    srand(seed);

    for (int i = 0; i < size; i++)
        *(shuffled_arr + i) = a[i];
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % i;
        int temp = shuffled_arr[i];
        shuffled_arr[i] = shuffled_arr[j];
        shuffled_arr[j] = temp;
    }

    return shuffled_arr;
}

int* createOddArray(const int a[], int size, int& oddSize)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
        {
            oddSize++;
        }
    }
    int* odd = new int[oddSize];
    for (int i = 0, y = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
        {
            *(odd + y) = a[i];
            y++;
        }
    }

    return odd;
}

int* createEvenArray(const int a[], int size, int& evenSize)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            evenSize++;
        }
    }
    int* even = new int[evenSize];
    for (int i = 0, y = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            *(even + y) = a[i];
            y++;
        }
    }

    return even;
}

void array_war(int* odd, int oddSize, int* even, int evenSize)
{
    int* win = nullptr, winSize = 0;

    if (oddSize > evenSize)
        winSize = oddSize;
    else if (evenSize > oddSize)
        winSize = evenSize;
    else                //if both odd and even arrays are same size
        winSize = evenSize;
    win = new int[winSize];
    for (int i = 0; i < winSize; i++)
    {
        if (*(odd + i) > *(even + i))
            *(win + i) = *(odd + i);
        else if (*(even + i) > *(odd + i))
            *(win + i) = *(even + i);
    }

    cout << "Contents of Fight winning array below." << endl;
    print_array(win, winSize);
    sort_array(win, winSize);
    cout << "Contents of sorted Fight winning array below." << endl;
    print_array(win, winSize);
}

void sort_array(int* a, int size)
{
    int minIndex;
    int minValue;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = *(a + start);
        for (int index = start + 1; index < size; index++)
        {
            if (*(a + index) < minValue)
            {
                minValue = *(a + index);
                minIndex = index;
            }
        }
        int temp = *(a + minIndex);   //swap smallest value in array with starting value in array
        *(a + minIndex) = *(a + start);
        *(a + start) = temp;
    }
}
