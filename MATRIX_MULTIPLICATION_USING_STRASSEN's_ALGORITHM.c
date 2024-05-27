#include <stdio.h>

void strassen(int a[10][10], int b[10][10], int c[10][10], int n);
void add(int a[10][10], int b[10][10], int c[10][10], int n);
void subtract(int a[10][10], int b[10][10], int c[10][10], int n);

void multiply(int a[10][10], int b[10][10], int c[10][10], int n)
{
    if (n <= 2)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    else
    {

        int m = n / 2;

        int A[m][m], B[m][m], C[m][m], D[m][m];
        int E[m][m], F[m][m], G[m][m], H[m][m];
        int P[m][m], Q[m][m], R[m][m], S[m][m];
        int T[m][m], U[m][m], V[m][m];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                A[i][j] = a[i][j];
                B[i][j] = a[i][j + m];
                C[i][j] = a[i + m][j];
                D[i][j] = a[i + m][j + m];

                E[i][j] = b[i][j];
                F[i][j] = b[i][j + m];
                G[i][j] = b[i + m][j];
                H[i][j] = b[i + m][j + m];
            }
        }

        subtract(F, H, P, m);
        add(A, B, Q, m);
        add(C, D, R, m);
        subtract(G, E, S, m);
        add(A, D, T, m);
        add(E, H, U, m);
        subtract(B, D, V, m);

        multiply(A, P, A, m);
        multiply(Q, H, B, m);
        multiply(R, E, C, m);
        multiply(D, S, D, m);
        multiply(T, U, E, m);
        multiply(V, Q, F, m);
        multiply(S, R, G, m);
        multiply(T, H, H, m);

        add(A, B, c, m);
        subtract(H, D, c, m);
        add(G, D, c, m);
        add(E, H, c, m);
    }
}

void add(int a[10][10], int b[10][10], int c[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int a[10][10], int b[10][10], int c[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void inputMatrix(int matrix[10][10], int n)
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the size of the square matrices (n x n):\n ");
    scanf("%d", &n);

    int A[10][10], B[10][10], C[10][10];

    printf("Enter elements of matrix A:\n");
    inputMatrix(A, n);

    printf("Enter elements of matrix B:\n");
    inputMatrix(B, n);
    printf("The first matrix is :\n");
    printMatrix(A, n);
    printf("The second matrix is :\n");
    printMatrix(B, n);

    multiply(A, B, C, n);
    printf("The final matrix is :\n");
    printMatrix(C, n);

    return 0;
}
