#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e, mpool *pool)
{
    /* TODO: implement mem pool */
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) pool_alloc(pool, sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    /* Because we won't put any detail data for now, comment it to save memory */
    // e->pDetail = (detail *) malloc(sizeof(detail));
    e->pNext = NULL;

    return e;
}

mpool *pool_create(size_t size)
{
    mpool *p = (mpool *) malloc(sizeof(mpool));
    p->head = p->next = (char *) malloc(size);
    p->tail = p->head + size;

    return p;
}

void *pool_alloc(mpool *p, size_t size)
{
    if (p->tail - p->next < size)
        return NULL;

    void *m = (void *) p->next;
    p->next += size;

    return m;
}

void pool_free(mpool *p)
{
    free(p->head);
    free(p);
}
