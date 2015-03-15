/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file Structtest.c
 * @author gewu(com@baidu.com)
 * @date 2015/03/10 08:44:28
 * @brief 
 *  
 **/

#include <stdio.h>
#include <assert.h>

typedef struct T *T;

struct T{
    int count;
    struct elem {
        void *x;
        struct elem *link;
    }*head;
};

T Stack_new(void) {
    T stk;
    stk = malloc(sizeof(T));
    stk->count = 2;
    stk->head = NULL;
    return stk;
}

int Stack_empty(T stk){
    assert(stk);
    return stk->count == 0;
}

void Stack_push(T stk, void *x){
    struct elem *t;
    
    assert(stk);
    t = malloc(sizeof(elem));
    t->x = x;
    t->link = stk->head;
    stk->head = t;
    stk->count++;
}

void *Stack_pop(T stk){
    void *x;
    struct elem *t;

    assert(stk);
    assert(stk->count > 0);
    t = stk->head;
    stk->head = t->link;
    stk->count --;
    x = t->x;
    free(t);
    return x;
}

void Stack_free(T *stk) {
    struct elem *t, *u;

    assert(stk && *stk);
    for (t = (*stk)->head; t; t = u){
        u = t->link;
        free(t);
    }
    free(*stk);
    *stk = NULL;
}

int main(){
    T p = Stack_new();
    printf ("%d", p->count);
    printf ("Hello \n");
    
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
