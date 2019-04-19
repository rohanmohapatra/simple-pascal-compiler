#include<stdlib.h>
#include<stdio.h>
#include <time.h> //link with -lrt
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

void print_license() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("*****************************************************************\n");
	printf("*\tSimple Pascal Compiler version 0.0.1 [%d/%02d/%02d]\t*\n",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday );
	printf("*\t\t\tCopyright (c) 2019.\t\t\t*\n");
	printf("*\t\t\t\tAuthors\t\t\t\t*\n");
	printf("*   Rohan Mohapatra, Rohan R. Talesara and Saahitya Edamadaka   *\n");
	printf("*****************************************************************\n\n");
}

void print_figlet() {
	FILE *fp;
	fp = fopen("spc/FIGLET.txt","r");
	char c;
	c = fgetc(fp); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fp); 
    } 
    fclose(fp);
}