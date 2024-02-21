#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100000

typedef struct Entry {
    char date[11];
    int count;
    struct Entry *next;
} Entry;

typedef struct HashTable {
    Entry *buckets[TABLE_SIZE];
} HashTable;

unsigned int hash(char *key) {
    unsigned int value = 0;
    for (char *p = key; *p != '\0'; p++) {
        value = value * 37 + *p;
    }
    return value % TABLE_SIZE;
}

Entry *create_entry(char *key, int value) {
    Entry *entry = malloc(sizeof(Entry));
    strncpy(entry->date, key, 10);
    entry->date[10] = '\0';
    entry->count = value;
    entry->next = NULL;
    return entry;
}

void insert(HashTable *table, char *key, int value) {
    unsigned int bucket = hash(key);
    Entry *entry = table->buckets[bucket];
    while (entry != NULL) {
        if (strncmp(entry->date, key, 10) == 0) {
            entry->count += value;
            return;
        }
        entry = entry->next;
    }
    entry = create_entry(key, value);
    entry->next = table->buckets[bucket];
    table->buckets[bucket] = entry;
}

int compare(const void *a, const void *b) {
    Entry *entryA = *(Entry **)a;
    Entry *entryB = *(Entry **)b;
    return strcmp(entryA->date, entryB->date);
}

int main() {
    freopen("data.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    HashTable table = { { NULL } };
    char cmd[50];

    while (fgets(cmd, sizeof(cmd), stdin)) {
        if (cmd[0] == '*')
            break;
        insert(&table, cmd, 1);
    }

    Entry *entries[TABLE_SIZE];
    int count = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = table.buckets[i];
        while (entry != NULL) {
            entries[count++] = entry;
            entry = entry->next;
        }
    }

    qsort(entries, count, sizeof(Entry *), compare);

    for (int i = 0; i < count; i++) {
        printf("%s %d\n", entries[i]->date, entries[i]->count);
    }
}
