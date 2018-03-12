#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_DETAIL *pDetail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __PHONE_BOOK_DETAIL {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct _mpool {
    char *head;
    char *next;
    char *tail;
} mpool;

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e, mpool *pool);

mpool *pool_create(size_t s);
void *pool_alloc(mpool *p, size_t size);
void pool_free(mpool *p);

#endif
