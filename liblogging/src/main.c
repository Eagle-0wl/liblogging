#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include "log_lib.h"

/* Usage text */
void usage() {
    printf ("This program used to read logs for all or one specific program\n\n");
    printf ("Usage: log_reading [Flag] [argument]\n");
    printf ("Flags: -P, --program [Program_name] prints log only for specific program\n");
    printf ("       -H, --help\n");
    exit(1);
}
/* Get and process command line options */
char *getopts(int argc, char** argv)
{   
    if (argc == 1){
        return NULL;
    }
    if (argc == 2){
        usage();
    }
    if (argc > 2){
        if (strcmp(argv[1], "--program") == 0  || strcmp(argv[1], "-P")  == 0){
            return argv[2];
        }
        else {
            usage();
        }
    }
}

/* Main program */
int main(int argc, char *argv[])
{   
    int rc = 0;
    char* prog_name = NULL;
    /* get argument options */
    prog_name = getopts(argc, argv);
   
    if (open_db() != 0){
        printf ("Failed to open log file");
        return 1;
    }
    if (prog_name == NULL){
        rc = get_logs("program");
    }
    else {
        rc = get_logs(prog_name);
    }
    if (rc == -1){
        printf("Failed to retrieve log information from logging file\n");
    }
    close_db ();
    return 0;
}
