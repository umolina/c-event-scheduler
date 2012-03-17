#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <scheduler.h>


int main( int argc, char **argv )
{
    int id = 0;
    time_t now = time( NULL );
    int seconds = 100;
    int shift = 0;

    id = event_list_add( 0, now + seconds, seconds, shift, NULL, NULL );
    printf("Event id: %d\n", id);

    id = event_list_add( 0, now + seconds, seconds, shift, NULL, NULL );
    printf("Event id: %d\n", id);

    int numEvents = 0;
    numEvents = count_events();
    printf("Number of events: %d\n", numEvents);

    event_list_clean();

    numEvents = count_events();
    printf("Number of events: %d\n", numEvents);

    return 0;
}
