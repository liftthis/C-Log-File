// Frogger3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <time.h>
#include <string>
#include <stdlib.h>

#include <windows.h>

using namespace std;

//-------- Prototypes

void writeLog( char *, char *);
void writeLogMS( char *, char *);

//-------------------


int _tmain()
{
	char location[] = "FCM_data_rcv_subfunction";
	char label[] = "test";
	

	writeLog(location,label);

	writeLogMS("location","issue");


}

//void writeLog( char *msg ) 
void writeLog( char loc[], char msg[] )
{
   
FILE *fp;
char logfile[] = "Logfile.log";
time_t logtime;
struct tm *logtm;

logtime = time( NULL );
logtm = localtime( &logtime );

fp = fopen( logfile, "a" );

	if ( fp ) 
	{

		fprintf(fp,"%04d-%02d-%02d %02d:%02d:%02d - %s- %s \n", 1900 + logtm->tm_year, logtm->tm_mon + 1,
                    logtm->tm_mday, logtm->tm_hour, logtm->tm_min, logtm->tm_sec , loc, msg );

		fclose(fp);

	} 
	else 
	{

		printf( "Error opening logfile %s\n", logfile );

	}
}

void writeLogMS( char loc[], char msg[] )
{
   
   FILE *fp;
   char logfile[] = "Logfile.log";

   SYSTEMTIME t;
   //GetSystemTime(&t); // 24 hour clock
   GetLocalTime(&t);    // 12 hour clock

   fp = fopen( logfile, "a" );

	if ( fp ) 
	{

		fprintf(fp,"%04d-%02d-%02d %02d:%02d:%02d.%03d - %s- %s \n",
			t.wYear, t.wMonth, t.wDay,
            t.wHour, t.wMinute, t.wSecond, t.wMilliseconds , loc, msg );

		fclose(fp);

	} 
	else 
	{
		printf( "Error opening logfile %s\n", logfile );
	}
}