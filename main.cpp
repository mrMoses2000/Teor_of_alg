#include <iostream>
#define LENGHT 73
using namespace std;

void simple_search(int sought_num, int* array)
{
    int count = 0;
    for(int i = 0; i < LENGHT; i++)
    {
        if (sought_num == array[i])
        {
            count++;
            cout << '\n' << "amount of the iteration "<< count << '\n' << "Element was found, it is " << array[i];
            break;
        }
        count++;
    }
}

void binary_search(int sought_num, int* array)
{
    int left_border = 0;
    int right_border = LENGHT;
    int middle_value = LENGHT / 2;
    int count = 0;
    while (true)
    {
        if (sought_num < array[middle_value])
        {
            right_border = middle_value;
            middle_value = (right_border + left_border) / 2;
            count++;
        }
        if (sought_num > array[middle_value])
        {
            left_border = middle_value;
            middle_value = (left_border + right_border) / 2;
            count++;
        }
        if (sought_num == array[middle_value])
        {
            count++;
            cout << "amount of the iteration "<< count << '\n' << "Element was found, it is " << array[middle_value];
            break;
        }

    }
}

int main()
{
    int array[LENGHT]{};
    int sought_num;
    for(int i = 0; i < LENGHT; i++)
    {
        array[i] += i;
        cout << array[i] << " ";
    }
    cout << '\n' << "Выберите элемент массива, который хотите найти" << '\n';
    cin >> sought_num;
    binary_search(sought_num, array);
    simple_search(sought_num, array);

    return 0;
}
