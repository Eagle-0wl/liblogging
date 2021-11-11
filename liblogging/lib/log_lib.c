#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <sqlite3.h>

#define PATH "/var/log/log_lib.log"

sqlite3 *data_base = NULL;

/*
Function opens data base
*/
int open_db(){
    int rc = 0;
    if (sqlite3_open(PATH, &data_base) != 0){
        rc=-1;
    }
    return rc;
}
/*
Function closes database
*/
int close_db(){
    return sqlite3_close(data_base);;
}

/*
Function creates messages table in data base
*/
int create_table(){
    int rc = 0;
    char *err = NULL;
    const char *table_query = "create table if not exists Log(id integer primary key autoincrement not null, message TEXT, warn_level TEXT, Time timestamp default (datetime('now', 'localtime')) not null, program TEXT)";

    sqlite3_exec(data_base, table_query, 0, NULL, err);     //creates database table if there is none
    if (err != NULL){
        sqlite3_free(err);
        rc = -1;
    }
    return rc;
}

/*
Function checks if messages table exist in database
*/
int check_if_table_exists(){
    int rc = 0;
    char *err = NULL;
    const char *table_query = "SELECT name FROM sqlite_master WHERE type='table' AND name='Log';";
    struct sqlite3_stmt *selectstmt;

    rc = sqlite3_prepare_v2(data_base, table_query, 0, &selectstmt, NULL);
    if (rc == SQLITE_OK ){   
        if (sqlite3_step(selectstmt) != SQLITE_ROW){
            rc = -1;
            sqlite3_free(err);
        }
    } 
    sqlite3_finalize(selectstmt);
    return rc;
}

/*
Function inserts message into database table
*/
int write_log(char *message, int level, char *program_name){
    char *err = NULL;
    char *level_list[4] = {"Info", "Debug", "Warning", "Error"};
    char  *query;
    if (level >= 0 && level <=3){
        query = sqlite3_mprintf("insert into Log(message, warn_level, program) values ('%q','%q' ,'%q');",message, level_list[level], program_name);
        sqlite3_exec(data_base, query, 0, NULL, err);
        sqlite3_free(query);
        if (err != NULL){
            return -1;
        }
        return 0;
    }
    else {
        return -2;
    }
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i = 0;
    while( i < argc-1) {
        printf("%s %s from: (%s) %s %s", argv[i], argv[i+2], argv[i+4], argv[i+1] , argv[i+3]);
        i+=5;
    }
    printf("\n");
    return 0;
}

int get_logs(char *program_name) {
    char *err = NULL;
    char query[256] = "select * from Log where program = \"";
    strncat(query, program_name, sizeof(query) - 1);
    strncat(query, "\"", sizeof(query) - 1);

    int rc = sqlite3_exec(data_base, query, callback, NULL, err);
    if( rc!=SQLITE_OK ) {
        return -1;
    }
    return 0;
}
