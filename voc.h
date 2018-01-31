#ifndef VOC_H
#define VOC_H

#include "sentence.h"
#include "word.h"

typedef struct{
	word name;
	word w;
}voc;

static const voc EMPTY_VOC;

typedef struct{
	voc vocs[20*20];
	int size;
}vocabulary;

static const vocabulary EMPTY_VOCABULARY;

typedef struct{
	sentence *s;
	word category;
}asentence;

void create_vocabulary(vocabulary *v){
	*v = EMPTY_VOCABULARY;
	v->size=0;
}

void add_voc(vocabulary *v, char *name, word *w){
	voc vc = EMPTY_VOC;
	strcpy(vc.name, name);
	strcpy(vc.w, *w);
	v->vocs[v->size] = vc;
	v->size++;
}

asentence analyse_sentence(vocabulary *v, sentence *s){
	asentence res;
	res.s = s;
	voc *vc;
	vc = malloc(sizeof(voc));
	double quote = 0.0;
	for(int i=0; i<v->size; i++){
		int n_quote = contains_word(s, &v->vocs[i].w);
		if(quote < n_quote){
			quote = n_quote;
			vc = &v->vocs[i];
		}
	}
	if(quote >0.0){
		strcpy(res.category, vc->name);
	}else{
		strcpy(res.category,"");
	}
	return res;
}

#endif // VOC_H
