#define HASH_TABLE_MAX 1000

typedef struct Node
{
    int key;
    int value;
    struct Node* next;
} Node;


typedef struct {
    Node** hashtable;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* hashmap = (MyHashMap *)malloc(sizeof(MyHashMap));
    hashmap->hashtable = (Node **)malloc(sizeof(Node *) * HASH_TABLE_MAX);
    for(int index = 0; index < HASH_TABLE_MAX; index++)
    {
        *(hashmap->hashtable + index) = NULL;
    }
    return hashmap;
}

int hash_index(int key)
{
    return (key % HASH_TABLE_MAX);
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = hash_index(key);
    if(!(*(obj->hashtable + index)))
    {
        *(obj->hashtable + index) = (Node *)malloc(sizeof(Node));
        (*(obj->hashtable + index))->key = key;
        (*(obj->hashtable + index))->value = value;
        (*(obj->hashtable + index))->next = NULL;
        return;
    }
    Node* prev = NULL;
    Node* curr = *(obj->hashtable + index);

    while(curr)
    {
        if(curr->key == key)
        {
          curr->value = value;
          return;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    prev->next = (Node *)malloc(sizeof(Node));
    prev->next->key = key;
    prev->next->value = value;
    prev->next->next = NULL;
}


int myHashMapGet(MyHashMap* obj, int key) {
    int index = hash_index(key);
    if(!(*(obj->hashtable + index)))
       return -1;

    Node* prev = NULL;
    Node* curr = *(obj->hashtable + index);
    while(curr)
    {
        if(curr->key == key)
          return curr->value;
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = hash_index(key);

    if(!(*(obj->hashtable + index)))
       return;

    Node* prev = NULL;
    Node* curr = *(obj->hashtable + index);
    while(curr)
    {
        if(curr->key == key)
        {
            if(!prev)
                *(obj->hashtable + index) = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void myHashMapFree(MyHashMap* obj) {
    Node* prev;
    Node* curr;
    for(int index = 0; index < HASH_TABLE_MAX; index++)
    {
        prev = NULL;
        curr = *(obj->hashtable + index);
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

 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/
