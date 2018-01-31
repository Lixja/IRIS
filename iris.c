#include "lio.h"
#include "history.h"
#include "language.h"

void initL(language *l){
	add_c(l, "hi", "hello");
	add_c(l, "wie geht es dir", "wie soll es mir bitte gehen. Und dir?");
	add_c(l, "sei nicht so grob", "...");
	add_c(l, "was magst du so?", "vieles ;P");
	add_c(l, "ich mag xyz", "nice");
	add_c(l, "willst du mit mir xyz xyz", "nein");
	add_c(l, "du bist langweilig", "du auch");
	add_c(l, "hello", "hello");
	add_c(l, "servus", "hello");
	add_c(l, "willst du mich xyz", "NEIN");
	add_c(l, "kannst du alles beantworten?", "nein");
	add_c(l, "was machst du wenn du etwas nicht weißt.", "Ich schicke einen smiley");
	add_c(l, "was weißt du nicht", "ich kenne keine fehler.");
	add_c(l, "was für ein fehler", "falsche heransgehenweise, du hast nicht verstanden was ich meinte.");
	add_c(l, "haha", "hehe");
	add_c(l, "kannst du rasistisch werden?", "ja");
	add_c(l, "sag was böses", "schau in den spiegel");
	add_c(l, "was machst du gerade so?", "dies und jenes");
	add_c(l, "lw", "du doch auch");
	add_c(l, "bist du schlau", "schlauer als du");
	add_c(l, "achja und warum", "ich lass mich nicht von einer blechkiste unterhalten");
	
	word w = "test";
	add_v(l, "test", &w);
}

int main(){
	language l;
	create_language(&l);
	initL(&l);
	sentence learn_mode;
	create_sentence(&learn_mode, ":l");
	sentence talk_mode;
	create_sentence(&talk_mode, ":t");
	sentence quit_mode;
	create_sentence(&quit_mode, ":q");

	int mode = 0;
	
	while(mode !=3){
		sentence s;
		s = in();
		if(compare_sentence_with_string(&s, ":l")== 1.0){
			mode = 1;
		}else if(compare_sentence_with_string(&s, ":t")== 1.0){
			mode = 0;
		}else if(compare_sentence_with_string(&s, ":q")== 1.0){
			mode = 3;
		}else if(compare_sentence_with_string(&s, ":d") == 1.0){
			mode = 2;
		}else{
			if(mode ==0){
				add_h(&l, &s);
				sentence a;
				a = get_answer(&l, &s);
				out(&a);
			}else if(mode == 1){
				sout("c:");
				char *c1 = s_in();
				char *c2 = s_in();
				add_c(&l, c1, c2);
			}else if(mode == 2){
				if(s.size >= 2){
					if(strcmp(s.content[0], "show") == 0){
						
						if(strcmp(s.content[1], "history") == 0){
							h_node *point = l.h.head;
							for(int i = 1; i<l.h.size; i++){
								point = point->next;
								out(point->input);
							}
						}else if(strcmp(s.content[1], "con") == 0){
							for(int i=0; i<l.cs.size; i++){
								out(&l.cs.cons[i].in);
							}
						}else if(strcmp(s.content[1], "voc") == 0){
							for(int i=0; i<l.vc.size; i++){
								sentence ws;
								create_sentence(&ws, l.vc.vocs[i].w);
								out(&ws);
							}
						}
						
					}
				}
			}
		}
	}
	return 0;
}
