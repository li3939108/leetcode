#include <stdint.h>
#define N 3


uint64_t PE (uint32_t in){
	static int32_t result = 0;
	int16_t a = in & 0xffff ;
	int16_t b = (in  >> 16 ) & 0xffff;
	result += a * b;
	return (result << 32) | (a << 16) | b ;
}

/*
 * n = [1, N] 
 */
void level(uint32_t in[], uint32_t out[], uint32_t result[], unsigned int n){
	uint64_t res =  PE( in[n - 1] );
	out[n - 1] = res & 0xffff;
	result[n - 1] = res >> 32 ;
	if(n == 1){
		return;
	} else {
		level(in, out, n - 1);
	}
}


/*
 * n = [1, 2 x N - 1] 
 */
void samm_level(uint32_t in[N], uint32_t out[N], uint32_t result[N*N],  unsigned int n) {
	if (n <= N){
		*(uint16_t*)out = in[0] & 0xffff;
		*( (uint16_t*)out + 1 + 2 * (n - 1) = in[0] >> 16 ;
		level(out, (uint32_t*)( ( (uint16_t*)out ) + 1 ), result + n * (n - 1) / 2, n );
		samm_level(in, out, result, n + 1) ;
	}else if (n < 2*N - 1) {
		level((uint32_t*)( ( (uint16_t*)out ) + 1 ), out, result + N*N - (2*N - n)*(2*N - n + 1) / 2, n ) ;
		samm_level(in, out, result, n + 1) ;
	}
}

void systolic_array_matrix_multiplication(uint32_t in[N][N], uint32_t out[N*N]){
	uint32_t interout[N];
	for(int i = 1; i <= 2*N - 1; ++i){
		samm_level(in[i] ,interout, result, 1) ;  
	}
}
