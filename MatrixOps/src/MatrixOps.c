/*
 * MatrixOps.c
 *
 *  Created on: Aug 9, 2016
 *      Author: robertirwin
 */

#include 	"MatrixOps.h"


/* Name: 		MyMatInit
 * Description: Initializes the structure MyMat. Takes a pointer to the MyMat
 * 				structure, the number of desired rows, the number of desired columns,
 * 				a void pointer to the array containing all elements of the desired matrix,
 * 				and the type of the elements in the matrix. The type of the elements
 * 				must be defined according to the types in the MyMatType enum.
 * 	***NOTE***: The elements array must adhere to the following format.
 * 	--       --
 * 	| a b c d | ------\       [a, b, c, d, e, f, g, h]
 * 	| e f g h | ------/
 * 	--       --
 */
void MyMatInit(MyMat * mat, uint16_t rows, uint16_t cols, void * elements, MyMatType type)
{
	mat->numrows = rows;
	mat->numcols = cols;
	mat->type = type;

	// initialize the pointer to array of pointers
	//
	mat->rows = malloc(sizeof(mat->rows));
	switch(type){
	case TYPE_INT:
		// allocate memory and fill the matrix
		//
		mat->matrix = malloc(rows * cols * sizeof(int));

		// copy the elements vector into the matrix vector
		//
		memmove(mat->matrix, elements, rows * cols * sizeof(int));

		// allocate memory for the array of pointers (each pointer in the
		// array points to the first element of a row of the matrix)
		//
		*(mat->rows) = malloc(rows * sizeof(int *));

		// ensure rows points to the first pointer in the array
		//
		mat->rows = *(mat->rows);

		// assign the row pointers to the proper place in the matrix
		//
		for (int i = 0; i < rows; i++)
		{
			mat->rows[i] = (int *) (mat->matrix + (i * cols * sizeof(int)));
		}
		break;
	case TYPE_FLOAT:
		// allocate memory and fill the matrix
		//
		mat->matrix = malloc(rows * cols * sizeof(float));

		// copy the elements vector into the matrix vector
		//
		memmove(mat->matrix, elements, rows * cols * sizeof(float));

		// allocate memory for the array of pointers (each pointer in the
		// array points to the first element of a row of the matrix)
		//
		*(mat->rows) = malloc(rows * sizeof(float *));

		// assign the row pointers to the proper place in the matrix
		//
		for (int i = 0; i < rows; i++)
		{
			mat->rows[i] = (float *) (mat->matrix + (i * cols * sizeof(float)));
		}
		break;
	case TYPE_UINT32:
		// allocate memory and fill the matrix
		//
		mat->matrix = malloc(rows * cols * sizeof(uint32_t));

		// copy the elements vector into the matrix vector
		//
		memmove(mat->matrix, elements, rows * cols * sizeof(uint32_t));

		// allocate memory for the array of pointers (each pointer in the
		// array points to the first element of a row of the matrix)
		//
		*(mat->rows) = malloc(rows * sizeof(uint32_t *));

		// ensure rows points to the first pointer in the array
		//
		mat->rows = *(mat->rows);

		// assign the row pointers to the proper place in the matrix
		//
		for (int i = 0; i < rows; i++)
		{
			mat->rows[i] = (uint32_t *) (mat->matrix + (i * cols * sizeof(uint32_t)));
		}
		break;
	case TYPE_UINT16:
		// allocate memory and fill the matrix
		//
		mat->matrix = malloc(rows * cols * sizeof(uint16_t));

		// copy the elements vector into the matrix vector
		//
		memmove(mat->matrix, elements, rows * cols * sizeof(uint16_t));

		// allocate memory for the array of pointers (each pointer in the
		// array points to the first element of a row of the matrix)
		//
		*(mat->rows) = malloc(rows * sizeof(uint16_t *));

		// ensure rows points to the first pointer in the array
		//
		mat->rows = *(mat->rows);

		// assign the row pointers to the proper place in the matrix
		//
		for (int i = 0; i < rows; i++)
		{
			mat->rows[i] = (uint16_t *) (mat->matrix + (i * cols * sizeof(uint16_t)));
		}
		break;
	case TYPE_CHAR:
		// allocate memory and fill the matrix
		//
		mat->matrix = malloc(rows * cols * sizeof(char));

		// copy the elements vector into the matrix vector
		//
		memmove(mat->matrix, elements, rows * cols * sizeof(char));

		// allocate memory for the array of pointers (each pointer in the
		// array points to the first element of a row of the matrix)
		//
		*(mat->rows) = malloc(rows * sizeof(char *));

		// ensure rows points to the first pointer in the array
		//
		mat->rows = *(mat->rows);

		// assign the row pointers to the proper place in the matrix
		//
		for (int i = 0; i < rows; i++)
		{
			mat->rows[i] = (char *) (mat->matrix + (i * cols * sizeof(char)));
		}
		break;
	case TYPE_UCHAR:
		// allocate memory and fill the matrix
		//
		mat->matrix = malloc(rows * cols * sizeof(uint8_t));

		// copy the elements vector into the matrix vector
		//
		memmove(mat->matrix, elements, rows * cols * sizeof(uint8_t));

		// allocate memory for the array of pointers (each pointer in the
		// array points to the first element of a row of the matrix)
		//
		*(mat->rows) = malloc(rows * sizeof(uint8_t *));

		// ensure rows points to the first pointer in the array
		//
		mat->rows = *(mat->rows);

		// assign the row pointers to the proper place in the matrix
		//
		for (int i = 0; i < rows; i++)
		{
			mat->rows[i] = (uint8_t *) (mat->matrix + (i * cols * sizeof(uint8_t)));
		}
		break;
	}
}

/* Name: 		displayMatrix
 * Description: Prints the matrix defined in the MyMat structure to stdout.
 */
void displayMatrix(MyMat * mat)
{
	int j = 0;
	switch(mat->type)
	{
	case(TYPE_INT):
		for (int i = 0; i < mat->numrows; i++)
		{
			for (j = 0; j < mat->numcols; j++)
			{
				// this line goes to the pointer to thecurrent row being
				// printed (mat->rows[i]), moves to the correct column in the row
				// (+ j * sizeof(int)), casts the pointer as an int pointer, (rows is
				// actually a void pointer) and obtains the value at that location in
				// memory.
				//
				fprintf(stdout,"%d ", *((int *) (mat->rows[i] + j * sizeof(int))));
			}
			j = 0;
			printf("\n");
		}
		break;
	case(TYPE_FLOAT):
		for (int i = 0; i < mat->numrows; i++)
		{
			for (j = 0; j < mat->numcols; j++)
			{
				// this line goes to the pointer to thecurrent row being
				// printed (mat->rows[i]), moves to the correct column in the row
				// (+ j * sizeof(int)), casts the pointer as an int pointer, (rows is
				// actually a void pointer) and obtains the value at that location in
				// memory.
				//
				fprintf(stdout,"%f ", *((float *) (mat->rows[i] + j * sizeof(float))));
			}
			j = 0;
			printf("\n");

		}
		break;
	case(TYPE_UINT32):
		for (int i = 0; i < mat->numrows; i++)
		{
			for (j = 0; j < mat->numcols; j++)
			{
				// this line goes to the pointer to thecurrent row being
				// printed (mat->rows[i]), moves to the correct column in the row
				// (+ j * sizeof(int)), casts the pointer as an int pointer, (rows is
				// actually a void pointer) and obtains the value at that location in
				// memory.
				//
				fprintf(stdout,"%u ", *((uint32_t *) (mat->rows[i] + j * sizeof(uint32_t))));
			}
			j = 0;
			printf("\n");
		}
		break;
	case(TYPE_UINT16):
		for (int i = 0; i < mat->numrows; i++)
		{
			for (j = 0; j < mat->numcols; j++)
			{
				// this line goes to the pointer to thecurrent row being
				// printed (mat->rows[i]), moves to the correct column in the row
				// (+ j * sizeof(int)), casts the pointer as an int pointer, (rows is
				// actually a void pointer) and obtains the value at that location in
				// memory.
				//
				fprintf(stdout,"%u ", *((uint16_t *) (mat->rows[i] + j * sizeof(uint16_t))));
			}
			j = 0;
			printf("\n");
		}
		break;
	case(TYPE_CHAR):
		for (int i = 0; i < mat->numrows; i++)
		{
			for (j = 0; j < mat->numcols; j++)
			{
				// this line goes to the pointer to the current row being
				// printed (mat->rows[i]), moves to the correct column in the row
				// (+ j * sizeof(int)), casts the pointer as an int pointer, (rows is
				// actually a void pointer) and obtains the value at that location in
				// memory.
				//
				fprintf(stdout,"%c ", *((char *) (mat->rows[i] + j * sizeof(char))));
			}
			j = 0;
			printf("\n");
		}
		break;
	case(TYPE_UCHAR):
		for (int i = 0; i < mat->numrows; i++)
		{
			for (j = 0; j < mat->numcols; j++)
			{
				// this line goes to the pointer to thecurrent row being
				// printed (mat->rows[i]), moves to the correct column in the row
				// (+ j * sizeof(int)), casts the pointer as an int pointer, (rows is
				// actually a void pointer) and obtains the value at that location in
				// memory.
				//
				fprintf(stdout,"%u ", *((uint8_t *) (mat->rows[i] + j * sizeof(uint8_t))));
			}
			j = 0;
			printf("\n");
		}
		break;
	}
}
