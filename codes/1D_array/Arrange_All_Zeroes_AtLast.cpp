#include <iostream>

void Arrange_Zeroes(int *arr, int size){
    int j = 0;

    for(int i = 0; i < size; ++i){
        if(arr[i] != 0){
            arr[j++] = arr[i];
        }
    }

    for(int i = j; i < size; ++i){
        arr[i] = 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int size = 0;
    std::cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    Arrange_Zeroes(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}