 // -----------------------------------------------------------------------------------
 // Question 3: Part I Implementation
 // Mohamed Shoeb, March 2018
 // -----------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int** matrix_multiply(int** X, int** Y, int x_rows, int x_cols, int y_rows, int y_cols);

int main()
{
    // --------------------------------------------------------------------------------
    // Declare variables
    // --------------------------------------------------------------------------------

    int dimr1, dimc1, dimr2, dimc2, r, c, tempval;

    // --------------------------------------------------------------------------------
    // Initialize variables
    // --------------------------------------------------------------------------------

    dimr1 = 3;      // X rows
    dimc1 = 3;      // X cols
    dimr2 = 3;      // Y rows
    dimc2 = 2;      // Y cols

    // --------------------------------------------------------------------------------
    // Declare matrices
    // --------------------------------------------------------------------------------

    int **X;
    int **Y;
    int **Z;

    // --------------------------------------------------------------------------------
    // Allocate dynamic memory and initialize
    // --------------------------------------------------------------------------------

    X = (int**)calloc(dimr1, sizeof(int*));

    for (r = 0; r < dimr1; r++)
    {
        X[r] = (int *)calloc(dimc1, sizeof(int));
    }

    // --------------------------------------------------------------------------------
    // Check for allocation success
    // --------------------------------------------------------------------------------

    if (!X)
    {
        printf("\n ** Not enough memory, terminating ..");
        return -1;
    }

    Y = (int**)calloc(dimr2, sizeof(int*));

    for (r = 0; r < dimr2; r++)
    {
        Y[r] = (int *)calloc(dimc2, sizeof(int));
    }

    // --------------------------------------------------------------------------------
    // Check for allocation success
    // --------------------------------------------------------------------------------

    if (!Y)
    {
        printf("\n ** Not enough memory, terminating ..");

        free(X);

        return -1;
    }

    // --------------------------------------------------------------------------------
    // Initialize X with some numbers
    // --------------------------------------------------------------------------------

    printf(" -- Generating Matrix X(%d, %d)\n\n", dimr1, dimc1);

    for (r = 0; r < dimr1; r++)
    {
        for (c = 0; c < dimc1; c++)
        {
            // Generate a random integer

            tempval = rand() % 100;

            printf("%2d  ", tempval);

            X[r][c] = tempval;
        }

        printf("\n");

    }

    printf("\n");

    // --------------------------------------------------------------------------------
    // Initialize Y with some numbers
    // --------------------------------------------------------------------------------

    printf(" -- Generating Matrix Y(%d, %d)\n\n", dimr2, dimc2);

    for (r = 0; r < dimr2; r++)
    {
        for (c = 0; c < dimc2; c++)
        {
            // Generate a random integer

            tempval = rand() % 100;

            printf("%2d  ", tempval);

            Y[r][c] = tempval;
        }

        printf("\n");
    }

    printf("\n");

    // --------------------------------------------------------------------------------
    // Multiply
    // --------------------------------------------------------------------------------

    Z = matrix_multiply(X, Y, dimr1, dimc1, dimr2, dimc2);

    // --------------------------------------------------------------------------------
    // If inner matrix dimensions don't agree, free memory and return
    // --------------------------------------------------------------------------------

    if (Z == X)
    {
        printf("\n ** Could not complete operation, terminating \n");

        // Free memory

        free(X);
        free(Y);

        return -1;
    }

    // --------------------------------------------------------------------------------
    // Display computed Z matrix
    // --------------------------------------------------------------------------------

    printf(" -- Z Matrix (%d, %d)\n\n", dimr1, dimc2);

    for (r = 0; r < dimr1; r++)
    {
        for (c = 0; c < dimc2; c++)
        {
            printf("%2d  ", Z[r][c]);
        }

        printf("\n");
    }

    // --------------------------------------------------------------------------------
    // Free memory
    // --------------------------------------------------------------------------------

    free(X);
    free(Y);
    free(Z);

    return 0;
}

int** matrix_multiply(int** X, int** Y, int x_rows, int x_cols, int y_rows, int y_cols)
{

    // --------------------------------------------------------------------------------
    // Declare variables
    // --------------------------------------------------------------------------------

    int r, c, tc, sum;

    // --------------------------------------------------------------------------------
    // Declare output matrix
    // --------------------------------------------------------------------------------

    int **outmat;

    // --------------------------------------------------------------------------------
    // Initialize return matrix
    // --------------------------------------------------------------------------------

    outmat = (int**)calloc(x_rows, sizeof(int*));

    for (r = 0; r < x_rows; r++)
    {
        outmat[r] = (int *)calloc(y_cols, sizeof(int));
    }

    // --------------------------------------------------------------------------------
    // Check for allocation success
    // --------------------------------------------------------------------------------

    if (!outmat)
    {
        printf("\n ** Not enough memory, terminating ..");

        exit(-1);
    }

    // --------------------------------------------------------------------------------
    // Check inner matrix dimensions
    // --------------------------------------------------------------------------------

    if (x_cols != y_rows)
    {
        printf(" ** Error: Matrix inner dimensions do not agree.. ");

        return X;
    }

    // --------------------------------------------------------------------------------
    // Straight forward implementation via nested for loops
    // --------------------------------------------------------------------------------

    for (c = 0; c < y_cols; c++)
    {
        for (r = 0; r < x_rows; r++)
        {

        sum = 0;

            for (tc = 0; tc < x_cols; tc++)
            {
            sum = sum + X[r][tc] * Y[tc][c];
            }

        // Store result

        outmat[r][c] = sum;

        }
    }

return outmat;

}
