#include <stdio.h>
#define N 3

void mm_core(double *a_in, double *b_in, double *a_out, double *b_out, int i, int j, double *element){
	if(a_in != NULL && b_in != NULL){
		*element += (*a_in) * (*b_in) ;
	}
	if(a_out != NULL) { *a_out = *a_in ; }
	if(b_out != NULL) { *b_out = *b_in ; }
}
void mm_processor(int n, double A[n], double B[n], double result[n][n]){
	int i = 0, j = 0, level = 0;
	static double a[N ][N ] = {0}, b[N ][N ] = {0};
	for(i = 0; i < n; i ++){
		a[i][0] = A[i] ;
		b[0][i] = B[i] ;
	}
	int total_level = (n << 1) - 1 , clevel = total_level / 2;
	while(level <  total_level ){ //(n - 1) + (n - 1) + 1 
		int  inc, limit;
		if(level - clevel > 0){
			inc =  level - clevel;
			limit = clevel;  
		}else{
			inc = 0;
			limit = level ;
		}
		while(inc <= limit){
			if(inc == level - clevel && inc == clevel ){
				mm_core(&a[level - inc][inc] ,&b[level - inc][inc] , 
				NULL, NULL,
				level - inc, inc, &result[level - inc][inc] ) ;
			}else if( inc == level - clevel ){
				mm_core(&a[level - inc][inc] ,&b[level - inc][inc] , 
				&a[level - inc][inc + 1], NULL,
				level - inc, inc, &result[level - inc][inc] ) ;
			}else if(inc == clevel  ){
				mm_core(&a[level - inc][inc] ,&b[level - inc][inc] , 
				NULL, &b[level - inc + 1][inc],
				level - inc, inc, &result[level - inc][inc] ) ;
			}else{
				mm_core(&a[level - inc][inc] ,&b[level - inc][inc] , 
				&a[level - inc][inc + 1], &b[level - inc + 1][inc] ,
				level - inc, inc, &result[level - inc][inc] ) ;
			}
			inc = inc + 1;
		}
		level = level + 1;
	}
}

int main(){
	double result[N][N] = {0} ;
	double A[(N<<1) - 1][3] = {
		{1,0,0},
        {2,4,0},
        {3,5,3},
        {0,6,2},
        {0,0,5}};
	double B[(N<<1) - 1][3] ={
		{1,0,0},
		{4,2,0},
		{3,5,3},
		{0,2,6},
		{0,0,5}};
	double AA[N][N] = {
		{1,4,3},
		{2,5,2},
		{3,6,5}};
	double BB[N][N] = {
		{1,2,3},
		{4,5,6},
		{3,2,5}};
	double zero[N] = {0} ;
/*
	for(int i = 0 ; i < (N<<1) - 1 ; i ++){
		mm_processor(N, A[ i ], B[i], result ) ;
	}
*/
	int i = 0, j;
	for(i = 0; i < 3; i ++){
		mm_processor(N, AA[i] , BB[i] , result ) ;
	}
	for(i = 0; i < 3 ; i ++){
		
		for(j = 0; j < 3; j ++){
			printf("%f\t", result[i][j] ) ;
		}	
		printf("\n" );
	}
}
