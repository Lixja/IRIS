#ifndef SENTENCE_H
#define SENTENCE_H

#include <string.h>
#include "word.h"


typedef struct{
	word content[20];
	int size;
}sentence;

static const sentence EMPTY_SENTENCE;

void add_word(sentence *dest, word *src){
	strcpy(dest->content[dest->size], *src);
	dest->size++;
}

void copy_sentence(sentence *dest, sentence *src){
	dest = malloc(sizeof(sentence));
	*dest = EMPTY_SENTENCE;
	for(int i=0; i<src->size; i++){
		strcpy(dest->content[i], src->content[i]);
	}
}

void create_sentence(sentence *dest, char str[])
{
	*dest = EMPTY_SENTENCE;
	word *w;
	w = malloc(sizeof(word));
	int pos = 0;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == ' '){
			add_word(dest, w);
			w = malloc(sizeof(word));
			pos = 0;
		}else{
				(*w)[pos] = str[i];
				pos++;
		}
	}
	add_word(dest, w);
}

double compare_sentence(sentence *s1, sentence *s2){	
	double quote = 0;
	
	for(int i=0; i<s1->size && i<s2->size; i++){
		quote += compare_word(s1->content[i], s2->content[i]);
	}
	return quote/s1->size;
}

double compare_sentence_with_string(sentence *s1, char str[]){	
	sentence s2;
	create_sentence(&s2, str);
	return compare_sentence(s1, &s2);
}

double contains_word(sentence *s1, word *w1){
	double res = 0.0;
	for(int i=0; i< s1->size; i++){
		double w_quote = compare_word(s1->content[i], *w1);
		if(res < w_quote){
			res = w_quote;
		}
	}
	return res;
}

char *to_string(sentence *s1){
	char *str = malloc(sizeof(char)*20*20);
	strcat(str, s1->content[0]);
	for(int i=1; i<s1->size; i++){
		strcat(str, " ");
		strcat(str, s1->content[i]);
	}
	return str;
}

#endif // SENTENCE_H
