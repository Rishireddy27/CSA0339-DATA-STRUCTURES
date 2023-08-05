#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Hash table structure
struct HashTable {
    int data[SIZE];
    int flag[SIZE]; // flag[i] = 0 indicates empty cell, flag[i] = 1 indicates occupied cell, flag[i] = -1 indicates deleted cell
};

// Function to initialize the hash table
void initHashTable(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        ht->data[i] = 0;
        ht->flag[i] = 0;
    }
}

// Function to compute the hash value for a given key
int hash(int key) {
    return key % SIZE;
}

// Function to insert an element into the hash table
void insert(struct HashTable* ht, int key) {
    int index = hash(key);

    while (ht->flag[index] == 1) {
        index = (index + 1) % SIZE; // Linear probing to find the next available slot
    }

    ht->data[index] = key;
    ht->flag[index] = 1;
}

// Function to search for an element in the hash table
int search(struct HashTable* ht, int key) {
    int index = hash(key);

    while (ht->flag[index] != 0) {
        if (ht->data[index] == key && ht->flag[index] == 1) {
            return index; // Element found at the index
        }

        index = (index + 1) % SIZE; // Linear probing to search for the element
    }

    return -1; // Element not found
}

// Function to delete an element from the hash table
void delete(struct HashTable* ht, int key) {
    int index = search(ht, key);

    if (index != -1) {
        ht->flag[index] = -1; // Mark the cell as deleted
    }
}

// Function to display the hash table
void display(struct HashTable* ht) {
    printf("Hash Table:\n");
    printf("Index  Data\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%-7d", i);
        if (ht->flag[i] == 1) {
            printf("%d", ht->data[i]);
        } else {
            printf("-");
        }
        printf("\n");
    }
}

int main() {
    struct HashTable ht;
    initHashTable(&ht);

    insert(&ht, 5);
    insert(&ht, 25);
    insert(&ht, 15);
    insert(&ht, 35);

    display(&ht);

    int key = 25;
    int index = search(&ht, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the hash table\n", key);
    }

    delete(&ht, key);

    display(&ht);

    return 0;
}

