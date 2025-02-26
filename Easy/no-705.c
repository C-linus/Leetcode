#define HASH_TABLE_MAX 10000

typedef struct Node{
    int value;
    struct Node* next;
} Node;


typedef struct {
  Node** hashtable;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* hashset = (MyHashSet *)malloc(sizeof(MyHashSet));
    hashset->hashtable = (Node **)malloc(sizeof(Node *) * HASH_TABLE_MAX);
    for(int index = 0; index < HASH_TABLE_MAX; index++)
    {
        *(hashset->hashtable + index) = NULL;
    }
    return hashset;
}

int hash_index(int key)
{
    return (key % HASH_TABLE_MAX);
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = hash_index(key);

    if(!(*(obj->hashtable + index)))
    {
        *(obj->hashtable + index) = (Node *)malloc(sizeof(Node));
       (*(obj->hashtable + index))->value = key;
        (*(obj->hashtable + index))->next = NULL;
        return;
    }

    Node* prev = NULL;
    Node* curr = *(obj->hashtable + index);
    while(curr)
    {
        if(curr->value == key)
           return;
        else if(curr->value < key)
        {
            prev = curr;
            curr = curr->next;
        }
        else if(curr->value > key)
        {
            // Insertion at head
            if(!prev)
            {
                *(obj->hashtable + index) = (Node *)malloc(sizeof(Node));
                (*(obj->hashtable + index))->value = key;
                (*(obj->hashtable + index))->next = curr;
                return;
            }

            //Insertion at middle
            prev->next = (Node *) malloc(sizeof(Node));
            prev->next->value = key;
            prev->next->next = curr;
            return;

        }
    }
    // Insertion at end
    prev->next = (Node *)malloc(sizeof(Node));
    prev->next->value = key;
    prev->next->next = NULL;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = hash_index(key);

    if(!(*(obj->hashtable + index)))
       return;

    Node* prev = NULL;
    Node* curr = *(obj->hashtable + index);
    while(curr)
    {
        if(curr->value == key)
        {
            if(!prev)
              *(obj->hashtable + index) = curr->next;
            else
              prev->next = curr->next;

            free(curr);
            return;

        }
        else if(key > curr->value)
        {
           prev = curr;
           curr = curr->next;
        }
        else if(key < curr->value)
           return;
    }

}

bool myHashSetContains(MyHashSet* obj, int key) {
    int index = hash_index(key);

    if(!(*(obj->hashtable + index)))
       return false;


    Node* curr = *(obj->hashtable + index);
    while(curr)
    {
        if(curr->value == key)
           return true;
        else if(curr->value < key)
            curr = curr->next;
        else if(curr->value > key)
            return false;

    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for(int index = 0; index < HASH_TABLE_MAX; index++)
    {
          Node* prev = NULL;
          Node* curr = *(obj->hashtable + index);
          while(curr)
          {
            prev = curr;
            curr = curr->next;
            free(prev);
          }
    }
    free(obj->hashtable);
    free(obj);
}

/*

 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);

*/
