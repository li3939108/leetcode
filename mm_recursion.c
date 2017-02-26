/*
 * Chaofan Li <chaof@tamu.edu>
 * Feb 2017
 *
 * Systolic Array for Matrix Multiplication for 16-bit integer
 * To simplify the representation of arguments
 * The two arguments for a single Processing Element (PE)
 * are stored in a single 32-bit integer
 * With support of vector type, this should work for longer integer
 */
#include <stdint.h>
#include <stdio.h>

#define N 4


uint32_t PE(uint32_t in, uint32_t *result)
{
    int16_t a = (int16_t) (in & 0xffff);
    int16_t b = (int16_t) ((in >> 16) & 0xffff);
    result[0] += (a * b);
    return ((uint32_t) a << 16) | b;
}

/*
 * n = [1, N]
 */
void PE_recursive(uint32_t *in, uint32_t *out, uint32_t *result, unsigned int n)
{
    out[n - 1] = PE(in[n - 1], result + n - 1);
    if (n > 1)
    {
        PE_recursive(in, out, result, n - 1);
    }
}

/*
 * n = [1, 2 x N - 1]
 * Use recursion to
 */
void level_recursive(uint32_t *in,
                     uint32_t *out,
                     uint32_t *result,
                     unsigned int n,
                     unsigned int start)
{
    if (n < N)
    {
        uint32_t interout[n + 1];
        *(uint16_t *) out = (uint16_t) (in[n - 1] & 0xffff);
        *((uint16_t *) out + 1 + 2 * (n - 1)) = (uint16_t) (in[n - 1] >> 16);
        PE_recursive(out, (uint32_t *) (((uint16_t *) interout) + 1),
                     result + start,
                     n);
        level_recursive(in, interout, result, n + 1, start + n);
    } else if (n == N)
    {
        uint32_t interout[n];
        *(uint16_t *) out = (uint16_t) (in[n - 1] & 0xffff);
        *((uint16_t *) out + 1 + 2 * (n - 1)) = (uint16_t) (in[n - 1] >> 16);
        PE_recursive(out, interout, result + start, n);
        level_recursive(in, interout, result, n + 1, start + n);
    } else if (n <= 2 * N - 1)
    {
        uint32_t interout[2 * N - n];
        PE_recursive((uint32_t *) ((uint16_t *) out + 1), interout,
                     result + start,
                     N * 2 - n);
        level_recursive(in, interout, result, n + 1, start + N * 2 - n);
    }
}

void systolic_array_matrix_multiplication(uint32_t in[N][N],
                                          uint32_t out[N * N])
{
    for (int i = 0; i < N; ++i)
    {
        uint32_t interout[1];
        level_recursive(in[i], interout, out, 1, 0);
    }

}

int main()
{
    uint32_t in[N][N];
    uint32_t out[N * N] = {0};
    int16_t A_T[N][N] = {
            {1, 4, 3, 8},
            {2, 5, 2, 3},
            {3, 6, 5, 2},
            {2, 3, 1, 8},
    };
    int16_t B[N][N] = {
            {1, 2, 3, 3},
            {4, 5, 6, 2},
            {3, 2, 5, 7},
            {2, 3, 9, 9}
    };
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            in[i][j] = ((uint32_t) A_T[i][j] << 16) | B[i][j];
        }
    }
    systolic_array_matrix_multiplication(in, out);
    /*
     * The output is stored in a zig-zag way
     */
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%d ", out[i * N + j]);
        }
        printf("\n");
    }

}