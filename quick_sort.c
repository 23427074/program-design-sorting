#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "quick.h"
#define MAX 1000000

int main()
{
    struct  timeval start;
    struct  timeval end;
    double t;
    FILE *ifile = NULL;
    ifile = fopen("dataset1.txt", "r");
    int *number = malloc(sizeof(int)*MAX);
    for(int i=0;i<MAX;i++)
    {	
    	fscanf(ifile, "%d", &*(number+i));
    }
    gettimeofday(&start,NULL);
    quickSortInt(number, 0, MAX-1);
    gettimeofday(&end,NULL);
    t = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
    printf("Quick sort Int time : %lf(s)\n",t);
    free(number);
    fclose(ifile);
    
    
    FILE *sfile = NULL;
    sfile = fopen("dataset2.txt", "r");
    char **str = malloc(sizeof(char*)*MAX);
    for(int y=0;y<MAX;y++)
    {
    	*(str+y) = malloc(sizeof(char)*101);
    }
    for(int i=0;i<MAX;i++)
    {	
    	fscanf(sfile, "%s", str[i]);
    }
    gettimeofday(&start,NULL);
    quickSortString(str, 0, MAX-1);
    gettimeofday(&end,NULL);
    t = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
    /*for(int g=0; g<MAX;g++)
    {
    	printf("%s\n", *(str+g));
    }*/
    printf("Quick sort String time : %lf(s)\n",t);
    free(str);
    fclose(sfile);
    return 0;
}
