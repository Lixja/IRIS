#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "conversation.h"
#include "voc.h"
#include "sentence.h"
#include "voc.h"

typedef struct{
	vocabulary vc;
	conversation cs;
}language;

static const language EMPTY_LANGUAGE;

void create_language(language *l){
	*l = EMPTY_LANGUAGE;
	create_vocabulary(&l->vc);
	create_conversation(&l->cs);
}

void add_v(language *l, char *name, word *w){
	add_voc(&l->vc, name, w);
}

void add_c(language *l, char *in, char *out, char*cat){
	add_con(&l->cs, in, out, cat);
}

sentence get_answer(language *l, sentence *s){
	asentence as = analyse_sentence(&l->vc, s);
	sentence res =  get_optimal_answer(&l->cs, &as);
	return res;
}


#endif // LANGUAGE_H
