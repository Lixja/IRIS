#ifndef WORD_H
#define WORD_H

#include <string.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef char word[20];


char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}

double compare_word(word w1, word w2){
	size_t w1_len = strlen(w1);
	size_t w2_len = strlen(w2);
	word ww1, ww2;
	strcpy(ww1, w1);
	strcpy(ww2, w2);
	strlwr(ww1);
	strlwr(ww2);
	
	double rightchars = 0;
	
	for(int i=0; i<w1_len && i<w2_len; i++){
		if(ww1[i] == ww2[i]){
			rightchars++;
		}
	}
	if(&w2_len > &w1_len){
		rightchars -= w2_len-w1_len;
	}else if(w2_len < w1_len){
		rightchars -= w1_len-w2_len;
	}
	return rightchars/w1_len;
}

word *to_word(char *str){
	word *w = malloc(sizeof(word));
	strcpy(*w, str);
	return w;
}

#endif // WORD_H
