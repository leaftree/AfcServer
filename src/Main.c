
/**
 * Main.c
 *
 * Copyright (C) 2017 by Liu YunFeng.
 *
 *        Create : 2017-11-05 22:22:36
 * Last Modified : 2017-11-05 22:22:36
 */

#include "defs.h"

int main(int argc, char *argv[])
{
	DBUG_PUSH ("d:t:O");

	int iRetValue = 0;

    //DBUG_PRINT(__func__, ("%d", __LINE__));
	char *p = String_Create("i love ShenSiYuan", 17);
	char *q = String_Create("i love ShenSiYuan agin", 22);

    char *v = String_Concat(p, q);

    if(!v)
        printf("return null string");
    else
    {
        printf("%s\n", v);
    }

	return iRetValue;
}
