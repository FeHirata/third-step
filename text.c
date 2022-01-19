#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SDT 20

int cmpnum(const void * n1, const void * n2){
	if(*(int *)n1 > *(int *)n2){
		return 1;
	} else if (*(int *)n1 < *(int *)n2){
		return -1;
	}else{
		return 0;
	}
}

int sum(int s[]){
	int i = 0;
	int sum = 0;	

	for(i = 0; i < SDT; i++){
		sum += s[i];
	}

	return sum;
}

double average(int a[]){
	double avg = 0.0;
	double s = 0.0;

	s = (double)sum(a);
	avg = s / (double)SDT;

	return avg;
}

double std_deviation(int d[]){
	int i = 0;
	double dst = 0.0;
	double tmp = 0.0;
	double avg = 0.0;
	double dvt = 0.0;
		
	avg = average(d);

	for(i = 0; i < SDT; i++){
		tmp += ((double)d[i] - avg) * ((double)d[i] - avg);
	}

	dst = tmp / (double)SDT;

	dvt = sqrt(dst);

	return dvt;
}

double dvt_value(int pnt, double avg, double dvt){
	double value = 0;
	
	value = ( ( 10 * ((double)pnt - avg) ) / (dvt) ) + 50;

	return value;
}

int main(){
	int scn[SDT] = {65, 80, 67, 35, 58, 60, 72 ,75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
	int eng[SDT] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
	double scn_value[SDT] = {0.0};
	double eng_value[SDT] = {0.0};

	int scn_sum = 0, eng_sum = 0;
	double scn_avg = 0.0, eng_avg = 0.0;
	double scn_dvt = 0.0, eng_dvt = 0.0;
	
	int i = 0;

	scn_sum = sum(scn);
	eng_sum = sum(eng);
	scn_avg = average(scn);
	eng_avg = average(eng);
	scn_dvt = std_deviation(scn);
	eng_dvt = std_deviation(eng);

	printf("scn_sum = %d, eng_sum = %d, \n", scn_sum, eng_sum);
	printf("scn_avg = %.lf, eng_avg = %.lf, \n", scn_avg, eng_avg);
	printf("scn_dvt = %.lf, eng_dvt = %.lf \n", scn_dvt, eng_dvt);

	for(i = 0; i < SDT; i++){
		scn_value[i] = dvt_value(scn[i], scn_avg, scn_dvt);
		eng_value[i] = dvt_value(eng[i], eng_avg, eng_dvt);
	}

	for(i = 0; i < SDT; i++){
		printf("%d : scn_value = %.lf, eng_value = %.lf \n", i + 1, scn_value[i], eng_value[i]);
	}

	qsort(scn, sizeof(scn) / sizeof(scn[0]), sizeof(int), cmpnum);
	qsort(eng, sizeof(eng) / sizeof(eng[0]), sizeof(int), cmpnum);

	for(i = 0; i < SDT; i++){
		if(i == 0)	printf("scn[] = [");
		printf("%d", scn[i]);
		if(i < (SDT - 1)	printf(",");
		if(i == (SDT -1))	printf("]\n");
	}

	for(i = 0; i < SDT; i++){
		if(i == 0)	printf("eng[] = [");
		printf("%d", eng[i]);
		if(i < (SDT - 1))	printf(",");
		if(i == (SDT -1))	printf("]\n");
	}
}
