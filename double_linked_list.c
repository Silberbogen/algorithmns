#include <stdio.h>

typedef struct {
    void * data;
    struct dbl_ll_s *prev;
    struct dbl_ll_s *next;
} dbl_ll_s;

typedef struct {
    struct dbl_ll_s begin;
    struct dbl_ll_s end;
    int elements;
} dbl_ll_s_anchor;


void dbl_ll_insert_begin(dbl_ll_s_anchor *db, dbl_ll_s *element) {
    element->prev = db->begin;
    element->next = db->begin.next;
    db->begin.next = element;
}

void dbl_ll_insert_end(dbl_ll_s_anchor *db, dbl_ll_s *element) {
    element->next = db->end;;
    element->prev = db->end.prev;
    db->end.prev = element;
}

