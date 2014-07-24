/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/07/2014 08:29:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>
#define TERMCOL 4
void usage() {
	printf("-h [Start hour as int e.g. 9]\n");
	printf("-m [Start minute as int e.g. 54]\n");
	printf("-r [rate as int e.g. 400]\n");
	printf("-d [Duration as int e.g. 8 (for 8 hours)]\n");
	printf("==Optional==\n");
	printf("-c [Set currency e.g. $]\n");
	exit(0);
}
float calculate_eps(float dr,float h) {
	return (((dr / h) / 60) /60);
}	
float calculate_already_earnt(int h, int m, int sh, int sm,float eps) {
	int oh = h - sh;
	int om = m - sm;

	float oh_eps = (((eps * 60) * 60)* oh);
	float om_eps = ((eps *60) * om);
	return oh_eps + om_eps;
}
int is_work_over(int sh,int sm,int hours,time_t *current_time, struct tm *current_time_now) {
	current_time_now = localtime(current_time);	

	int eh = sh + hours;
	int em = 0;
	if(current_time_now->tm_hour <= eh && current_time_now->tm_min != 0) {	
		return 0;
	}
	return 1;
}
int main(int argc, char **argv) {

	int c;
	int DAILY_RATE = 0;
	int START_HOUR = 0;
	int START_MINUTE =0;
	int DURATION = 0;
	char *currency = "£";
	while(((c = getopt(argc,argv,"c:h:m:r:d:"))) != -1) {

		switch(c) {
			case 'c':
				currency = optarg;
				break;
			case 'h':
				START_HOUR = atoi(optarg);
				break;
			case 'm':
				START_MINUTE = atoi(optarg);
				break;
			case 'r':
				DAILY_RATE = atoi(optarg);
				break;
			case 'd':
				DURATION = atoi(optarg);
				break;
			case '?':
				usage();
				break;
			default:
				usage();
				break;
		};

	}
	float eps = calculate_eps(DAILY_RATE,DURATION);	

	time_t current_time;
	struct tm *current_time_now;
	time(&current_time);
	current_time_now = localtime(&current_time);
	int hour = current_time_now->tm_hour;
	int minute = current_time_now->tm_min;

	float base_earning = calculate_already_earnt(hour,minute,START_HOUR,START_MINUTE,eps);

	float current_earning = base_earning;
	while(!is_work_over(START_HOUR,START_MINUTE,DURATION,&current_time,current_time_now)) {
		current_earning += eps;
		fflush(stdout);
		printf("You've Earnt %c[%d;%dm%s%f%c[0m\r",0x1b,TERMCOL,2+30,currency,current_earning,0x1B);
		sleep(1);
		time(&current_time);
	}	
	return 0;
}
