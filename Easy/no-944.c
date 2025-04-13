int minDeletionSize(char** strs, int strsSize) {
    int count=0;
    int colSize = strlen(*strs);
    for(int row = 0; row < colSize; row++)
    {
        for(int col = 0; col < strsSize; col++)
        {
            if(col + 1 < strsSize && *(*(strs + col) + row) > *(*(strs + col + 1) + row))
            {
                count++;
                break;
            }
        }

    }
   return count;
}
