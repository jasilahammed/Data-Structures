#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;  // key is a string
    char* value;  // value is also a string
    struct node* next;
};

// Function to set the key-value pair in a node
void setNode(struct node* node, char* key, char* value) {
    node->key = key;
    node->value = value;
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements;  // Current number of elements in hashMap
    int capacity;  // Capacity of hashMap
    struct node** arr;  // Array of linked list nodes
};

// Function to initialize the hashMap
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;  // Default capacity
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);  // Allocate memory for the array of linked lists
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function to calculate bucket index
int hashFunction(struct hashMap* mp, char* key) {
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    bucketIndex = sum;
    return bucketIndex;
}

// Function to insert a key-value pair into the hashMap
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));  // Create a new node
    setNode(newNode, key, value);  // Set key-value pair in the node
    
    // Insert the new node in the linked list at the bucket index
    newNode->next = mp->arr[bucketIndex];
    mp->arr[bucketIndex] = newNode;
}

// Function to delete a key-value pair from the hashMap
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];  // Head of the linked list at the bucket index
    
    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {  // Key is matched, delete this node from linked list
            if (currNode == mp->arr[bucketIndex]) {  // Head node deletion
                mp->arr[bucketIndex] = currNode->next;
            } else {  // Last node or middle node deletion
                prevNode->next = currNode->next;
            }
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a key in the hashMap
char* search(struct hashMap*
