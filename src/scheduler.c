//============================================================================
// Name        : scheduler.c
// Author      : Unai Molina
// Version     : 1.0
// Description : Event scheduler
//============================================================================

/*  System Libraries */

#include <sys/select.h> 
#include <sys/time.h>           /* select */
#include <sys/types.h>          /* select */
#include <time.h>               /* time, localtime, mktime */
#include <stdlib.h>             /* malloc, free */
#include <sys/sysinfo.h>        /* sysinfo */
#include <errno.h>              /* errno */
#include <signal.h>             /* signal */
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*  Program Files Headers   */

#include <scheduler.h>


/*  Constants & Defines */


/*  Internal Structures */


typedef struct event_list_node
{
    event_id id;
    time_t previous_alarm;
    time_t next_alarm;
    unsigned long int time_incr;
    long int time_shift;
    void (* callback)(void *);
    void *data;
    struct event_list_node *next;

}event_list_node_t;

__thread event_list_node_t *event_list = 0;     // Using thread local storage




/*  -----------------------------------------   */


/* Add a node to the event list.
 *
 * @param time_t previous_alarm
 * @param time_t next_alarm
 * @param unsigned long int time_incr
 * @param long int time_shift
 * @param void (* callback)(void *)
 * @param void *data
 * @return event_id
 */

event_id event_list_add(    time_t previous_alarm,
                            time_t next_alarm,
                            unsigned long int time_incr,
                            long int time_shift,
                            void (* callback)(void *),
                            void *data                      )
{
    event_list_node_t *new_node;

    new_node = malloc( sizeof( event_list_node_t ) );
    new_node->id = event_list ? event_list->id + 1 : 0;
    new_node->previous_alarm = previous_alarm;
    new_node->next_alarm = next_alarm;
    new_node->time_incr = time_incr;
    new_node->time_shift = time_shift;
    new_node->callback = callback;
    new_node->data = data;
    new_node->next = event_list;
    event_list = new_node;

    return new_node->id;
}


/* Remove all nodes from the event list.
 *
 * @param void
 * @return void
 */

void event_list_clean()
{
    event_list_node_t *node, *next;

    for (node = event_list; node; node = next)
    {
        next = node->next;
        free( node );
    }
    event_list = (void *)0;
}

/* Count number of events in list
 *
 * @param void
 * @return int
 */

int count_events()
{
    event_list_node_t *node, *next;
    int counter = 0;

    for (node = event_list; node; node = next)
    {
        next = node->next;
        counter = counter + 1;
    }

    return counter;
}




/*  ####################################################################################    */
