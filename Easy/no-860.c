#define DOLLAR_FIVE 5
#define DOLLAR_TEN 10
#define DOLLAR_FIFTEEN 15

bool lemonadeChange(int* bills, int billsSize) {
    int tenBills = 0 , fiveBills = 0; int change; int bill;
    for(int i = 0; i < billsSize; i++)
    {
        bill = *(bills + i);
        if(bill == DOLLAR_FIVE)
            fiveBills++;

        else if(bill == DOLLAR_TEN)
            tenBills++;

        change = bill - 5;

        if(!change) continue;

        else if(change == DOLLAR_FIVE)
        {
            if(fiveBills >= 1)
                fiveBills--;
            else
                return false;
        }

        else if(change == DOLLAR_FIFTEEN)
        {
            if(fiveBills >= 1 && tenBills >= 1)
            {
                fiveBills--;
                tenBills--;
            }
            else if(fiveBills >= 3)
                fiveBills -= 3;
            else
                return false;

        }
    }
    return true;

}
