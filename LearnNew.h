#ifndef LEARNNEW_H_INCLUDED
#define LEARNNEW_H_INCLUDED

#include "defines.h"

class LearnNew {

public:

    LearnNew();
    virtual ~LearnNew();

    int learn_new_stuff(char*, int);
    void print_all_knowledge(int * dev);
	
	
	
    char name[N_CHAR_MAX];

	int rec;
	int is_alive;
	
	// Properties struct
	// TODO:	REALLY don't want this in public. So make an effort in sorting this under private.
	//			Only reason was cuz I developed the 'loop_to_connect' in main. That should/could be
	//			moved to this object. Anyway.. at least, it's now on the to do list
    struct MyProps {
        MyProps():next(0), rec(0) {}
        char attr[N_CHAR_MAX];
        struct MyProps * next;
		int rec; // increment each time accessed
    } * props;
	
    void learn(char * newAttr, MyProps * inthing);
	


};

#endif // LEARNNEW_H_INCLUDED
