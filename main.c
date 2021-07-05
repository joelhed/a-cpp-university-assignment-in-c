#include <stdio.h>

#define STR(s) #s
#define XSTR(s) STR(s)

#define MAX_KEY_LENGTH 10
#define NUM_SLOTS 26

typedef enum Status {
    NEVER_USED,
    TOMBSTONE,
    OCCUPIED
} Status;

typedef struct Slot {
    Status status;
    char key[MAX_KEY_LENGTH + 1];
} Slot;

typedef struct HashTable {
    Slot slots[NUM_SLOTS];
} HashTable;


void ht_init(HashTable *table) {
    printf("ht_init\n");
}

/* Returns an integer representing the slot index if found, -1 otherwise. */
int ht_search(HashTable *table, char *key) {
    printf("ht_search\n");
    return -1;
}

void ht_insert(HashTable *table, char *key) {
    printf("ht_insert %s\n", key);
}

void ht_delete(HashTable *table, char *key) {
    printf("ht_delete %s\n", key);
}

void ht_print(HashTable *table) {
    printf("ht_print\n");
}

void ht_print_debug(HashTable*table) {
}

int main(int argc, char *argv[]) {
    HashTable table;

    ht_init(&table);

    /* Input processing */

    for (;;) {
        char op;
        char key[MAX_KEY_LENGTH + 1];
        int res = scanf(" %c%" XSTR(MAX_KEY_LENGTH) "s", &op, key); 

        if (res == EOF) {
            break;
        }

        switch (op) {
            case 'A':
                ht_insert(&table, key);
                break;
            case 'D':
                ht_delete(&table, key);
                break;
            /* No default, because we should ignore invalid inputs. */
        }
    }

    ht_print(&table);

    return 0;
}
