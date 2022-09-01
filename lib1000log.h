/**********************************************************
*                                                         *
* lib1000log.h                                            *
*                                                         *
* Description:                                            *
*  Interface of a simple module to log to small files     *
*  Max 1000 lines per file                                *
*                                                         *
* Bernardo Castelo Branco                                 *   
* https://github.com/bascb                                *
*                                                         * 
**********************************************************/

#ifndef LIB1000LOG_H
# define LIB1000LOG_H

/* Add an entry to log file */
extern void	Log_Entry(char *PathToLogFolder, char *Type, char *Message);

#endif
