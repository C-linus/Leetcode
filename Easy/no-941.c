

bool validMountainArray(int* arr, int arrSize)
{
    if(arrSize < 2) return false;

    int index = 0;
    for(;index < arrSize - 1; index++)
    {
        if(*(arr + index) > *(arr + index + 1))
            break;
        else if(*(arr + index) == *(arr + index + 1))
            return false;

    }

    int peak = index + 1;
    if(peak < 2 || peak >= arrSize) return false;

    for(; peak < arrSize - 1; peak++)
    {
        if(*(arr + peak) <= *(arr + peak + 1))
           return false;
    }
    return true;

}
