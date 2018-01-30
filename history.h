#ifndef HISTORY_H
#define HISTORY_H

#include "sentence.h"

typedef struct h_node h_node;

struct h_node{
	sentence *input;
	h_node *prev;
	h_node *next;
};

typedef struct{
	h_node *head;
	h_node *last;
	int size;
}history;

static const history EMPTY_HISTORY;


void add_to_history(history *h, sentence *s){
	h_node *nn;
	nn = malloc(sizeof(h_node));
	nn->input = s;
	nn->prev = h->last;
	if(h->last != NULL){
	h->last->next = nn;
	}
	h->last = nn;
	h->size++;
}

void create_history(history *h){ 
	*h = EMPTY_HISTORY;
	h->size = 1;
	sentence s1;
	create_sentence(&s1, "-");
	add_to_history(h, &s1);
	h->head = h->last;
}

sentence search_for(history *h, word w){
	sentence s;
	create_sentence(&s, "Sorry Not Found");

	return s;
}

#endif // HISTORY_H
