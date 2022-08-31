/* Implementation for log parameters and functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib1000log.h"

/****************************************************
	Declaration of private functions
****************************************************/

/* Returns pointer to the right file */
FILE *Log_Set_File(char *PathToLogFolder, char *Type);

/* Format time string 
*
* Type:
*   a - Append to file name
*   p - Print to log entry
*
*/
void Log_FormatTime(char Type, char *String);

/* Count number of file lines */
int Log_Count_File_Lines(char *Path);

/****************************************************
	Implementation of public functions
****************************************************/

/* Add an entry to log file */
void Log_Entry(char *PathToLogFolder,char *Type, char *Message) {
	FILE *F;
	char TimeString[200];
	
	F = Log_Set_File(PathToLogFolder,Type);

	Log_FormatTime('p',TimeString);

	fprintf(F,"%s : %s\n",TimeString,Message);
	fclose(F);
}

/****************************************************
	Implementation of private functions
****************************************************/

/* Returns pointer to the right file */
FILE *Log_Set_File(char *PathToLogFolder, char *Type) {
	FILE *F;
	char TimeString[200];
	char *Path = NULL, *Old = NULL;
	int l;

	Path = (char *)calloc(strlen(PathToLogFolder)+strlen(Type)+10,sizeof(char));
	if ( Path == NULL ) return NULL;

	strcpy(Path,PathToLogFolder);
	strcat(Path, "/");
	strcat(Path, Type);
	strcat(Path, ".log");

	F = fopen(Path,"r");
	if ( F != NULL ) {
		l = Log_Count_File_Lines(Path);
		fclose(F);
		if ( l > 999 ) {
			Old = (char *)calloc(strlen(PathToLogFolder)+strlen(Type)+210,sizeof(char));
			if ( Old == NULL ) {
				free(Path);
				return NULL;
			}
			strcpy(Old,PathToLogFolder);
			strcat(Old, "/");
			strcat(Old, Type);
			Log_FormatTime('a',TimeString);
			strcat(Old,TimeString);
			strcat(Old,".log");
			rename(Path,Old);
			free(Old);
		}
	}
	F = fopen(Path,"a");
	free(Path);

	return F;
}

/* Format time string 
*
* Type:
*   a - Append to file name
*   p - Print to log entry
*
*/
void Log_FormatTime(char Type, char *String) {
	time_t Now;
	struct tm *NowInfo;
	char Str[100];

	time(&Now);
	NowInfo = localtime(&Now);

	if ( Type == 'p' ) {
		sprintf(Str,"%d-",NowInfo->tm_year+1900);
		strcpy(String,Str);
		if ( NowInfo->tm_mon + 1 < 10 ) {
			sprintf(Str,"0%d-",NowInfo->tm_mon + 1);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d-",NowInfo->tm_mon + 1);
			strcat(String,Str);
		}
		if ( NowInfo->tm_mday  < 10 ) {
			sprintf(Str,"0%d ",NowInfo->tm_mday);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d ",NowInfo->tm_mday);
			strcat(String,Str);
		}
		if ( NowInfo->tm_hour  < 10 ) {
			sprintf(Str,"0%d:",NowInfo->tm_hour);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d:",NowInfo->tm_hour);
			strcat(String,Str);
		}
		if ( NowInfo->tm_min  < 10 ) {
			sprintf(Str,"0%d:",NowInfo->tm_min);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d:",NowInfo->tm_min);
			strcat(String,Str);
		}
		if ( NowInfo->tm_sec  < 10 ) {
			sprintf(Str,"0%d",NowInfo->tm_sec);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d",NowInfo->tm_sec);
			strcat(String,Str);
		}
	}
	else if ( Type == 'a' ) {
		sprintf(Str,"%d",NowInfo->tm_year+1900);
		strcpy(String,Str);
		if ( NowInfo->tm_mon + 1 < 10 ) {
			sprintf(Str,"0%d",NowInfo->tm_mon + 1);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d",NowInfo->tm_mon + 1);
			strcat(String,Str);
		}
		if ( NowInfo->tm_mday  < 10 ) {
			sprintf(Str,"0%d",NowInfo->tm_mday);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d",NowInfo->tm_mday);
			strcat(String,Str);
		}
		if ( NowInfo->tm_hour  < 10 ) {
			sprintf(Str,"0%d",NowInfo->tm_hour);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d",NowInfo->tm_hour);
			strcat(String,Str);
		}
		if ( NowInfo->tm_min  < 10 ) {
			sprintf(Str,"0%d",NowInfo->tm_min);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d",NowInfo->tm_min);
			strcat(String,Str);
		}
		if ( NowInfo->tm_sec  < 10 ) {
			sprintf(Str,"0%d",NowInfo->tm_sec);
			strcat(String,Str);
		}
		else {
			sprintf(Str,"%d",NowInfo->tm_sec);
			strcat(String,Str);
		}
	}
}

/* Count number of file lines */
int Log_Count_File_Lines(char *Path) {
	int Lines = 0;
	FILE *F;
	char c;

	F = fopen(Path,"r");
	if ( F == NULL ) return 0;

	while ( (c = fgetc(F) ) != EOF ) if ( c == '\n' ) Lines++;

	fclose(F);

	return Lines;
}
