#include <stdio.h>
#include <string.h>

#define STR(s) #s
#define XSTR(s) STR(s)

#define MAX_KEY_LENGTH 10
#define NUM_SLOTS 26

typedef enum Status {
    NEVER_USED,
    TOMBSTONE,
    OCCUPIED
} Status;

char *STATUS_STRINGS[] = {
    "never used",
    "tombstone",
    "occupied"
};

typedef struct Slot {
    Status status;
    char key[MAX_KEY_LENGTH + 1];
} Slot;

typedef struct HashTable {
    Slot slots[NUM_SLOTS];
} HashTable;


void ht_init(HashTable *table) {
    printf("ht_init\n");
    memset(table, 0, sizeof(HashTable));
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

void ht_print_debug(HashTable *table) {
    printf("ht_print_debug\n");
    for (int i = 0; i < NUM_SLOTS; i++) {
        Slot slot = table->slots[i];
        printf("%d: %s: %s\n", i, STATUS_STRINGS[slot.status], slot.key);
    }
}

int main(int argc, char *argv[]) {
    HashTable table;

    ht_init(&table);
    ht_print_debug(&table);

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
