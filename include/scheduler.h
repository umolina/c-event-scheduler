#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

/*
 * scheduler.h
 * 
 * MODUL        Module that provide event scheduler (thread-safe)
 * 
 */

//---------------    INCLUDES       -------------  //

#include <time.h>

//---------------    DEFINES       -------------  //

typedef int event_id;


//---------------    PROTOTIPES    -------------  //

//  --------    Event List Functions   -----------------------

event_id event_list_add(    time_t previous_alarm,
                            time_t next_alarm,
                            unsigned long int time_incr,
                            long int time_shift,
                            void (* callback)(void *),
                            void *data                      );

void event_list_clean();

int count_events();



#endif /*_SCHEDULER_H_*/
