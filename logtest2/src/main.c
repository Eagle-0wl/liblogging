#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>

#include "log_lib.h"

volatile int interrupt = 0;

void sigHandler(int signo) {
    signal(SIGINT, NULL);
    interrupt = 1;
}

/* Main program */
int main(int argc, char *argv[])
{   
    char *msgOut;
    int counter = 0;
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    /* Set signal handlers */
    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);
    sigaction(SIGTERM, &action, NULL);
    open_db();
    if (check_if_table_exists() != 0){
    	create_table();
    }
    
    write_log("test level 0", 0, argv[0]);
    write_log("test level 1", 1, argv[0]);
    write_log("test level 2", 2, argv[0]);
    write_log("test level 3", 3, argv[0]);
    while (interrupt!=1){
        asprintf(&msgOut, "Count: %d", counter+=100);
        write_log(msgOut, 3, argv[0]);
        sleep (3);
    }
    close_db ();
    return 0;
}
