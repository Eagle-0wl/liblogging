/*
Function opens data base
*/
int open_db();
/*
Function closes database
*/
int close_db();
/*
Function creates log table in data base
*/
int create_table();
/*
Function checks if log table exist in database
*/
int check_if_table_exists();

// /*! \fn int write_log(char *message, int level, char *program_name
//  *  \brief Function that writes logs
//  *  \param *text log message
//  *  \param *level int log level  (0 - Info, 1 - Debug, 2 - Warning, 3 - Error)
//  *  \param *name program name
//  *  \return int 0 = success, 1 = failure
//  */
int write_log(char *message, int level, char *program_name);

// /*! \fn int get_logs(char *program_name);
//  *  \brief Function that reads logs from log file
//  *  \param *program_name name of a program that you want to get logs for. ("program" - gets all the logs)
//  *  \return rc (0 - Ok, -1 - error occured)
//  */
int get_logs(char *program_name);


