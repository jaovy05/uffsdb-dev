#pragma once // não inclui o arquivo novamente

#include "base.h"
#include "node.h"

typedef union ListCell
{
	void *ptr_value;
	int int_value;
} ListCell;

typedef struct List
{
	NodeTag		type;			/* T_List or T_IntList */
	int			length;			/* number of elements currently present */
	int			max_length;		/* allocated length of elements[] */
	ListCell   *elements;		/* re-allocatable array of cells */
	/* We may allocate some cells along with the List header: */
	ListCell	initial_elements[FLEXIBLE_ARRAY];
	/* If elements == initial_elements, it's not a separate allocation */
} List;

