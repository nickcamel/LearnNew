#ifndef LEARNNEW_H_INCLUDED
#define LEARNNEW_H_INCLUDED

#include "defines.h"

class LearnNew {

public:

    LearnNew();
    virtual ~LearnNew();

    int learn_new_stuff(char*, int);
    void print_all_knowledge();

    char name[N_CHAR_MAX];

	int rec;
	int is_alive;

private:
	// Properties struct
    struct MyProps {
        MyProps():next(0), rec(0) {}
        char attr[N_CHAR_MAX];
        struct MyProps * next;
		int rec; // increment each time accessed
    } * props;
	
    void learn(char * newAttr, MyProps * inthing);


};

#endif // LEARNNEW_H_INCLUDED
