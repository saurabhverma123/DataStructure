#ifndef SEARCHINGALGO
#define SEARCHINGALGO

#endif // SEARCHINGALGO
//return index in array where searchItem is stored
int binarySearch(arr[], int left, int right, int searchItem)
{
    if (right < left )
        return;

    int mid = left + ((right -left) / 2);
    if (arr[mid] == searchItem)
     return mid;

    if (arr[mid] < searchItem)
    {
        binarySearch(arr, left)
    }
}
