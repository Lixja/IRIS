#ifndef CONVERSATION_H
#define CONVERSATION_H

#include "sentence.h"
#include "word.h"
#include "string.h"
#include "voc.h"

typedef struct{
	sentence in;
	sentence out;
	word category;
}con;

static const con EMPTY_CON;

typedef struct{
	con cons[20*20];
	int size;
}conversation;

static const conversation EMPTY_CONVERSATION;

void create_conversation(conversation *c){
	*c = EMPTY_CONVERSATION;
	c->size=0;
}

void add_con(conversation *c, char *in, char *out, char*cat){
	con cc = EMPTY_CON;
	create_sentence(&cc.in, in);
	create_sentence(&cc.out, out);
	strcpy(cc.category, cat);
	c->cons[c->size] = cc;
	c->size++;
}

void add_con_without_cat(conversation *c, char *in, char *out){
	add_con(c, in, out, "");
}

sentence get_optimal_answer(conversation *c, asentence *s){
	sentence res;
	create_sentence(&res, ":)");
	double quote = 0.5;
	if(strcmp(s->category, "")==0){
		for(int i=0; i<c->size; i++){
			double n_quote = compare_sentence(&c->cons[i].in, s->s);
			if(quote < n_quote){
				res = c->cons[i].out;
			}
		}
	}else{
		for(int i=0; i<c->size; i++){
			double n_quote = compare_sentence(&c->cons[i].in, s->s);
			if(quote < n_quote){
				res = c->cons[i].out;
			}
		}
	}
	return res;
}



#endif // CONVERSATION_H
