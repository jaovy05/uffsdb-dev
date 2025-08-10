#pragma once // não inclui o arquivo novamente

typedef enum NodeTag
{
	T_Invalid = 0,
    T_List, 
    T_IntList
} NodeTag;

typedef struct Node
{
	NodeTag		type;
} Node;