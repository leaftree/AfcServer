
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

	char *p = "	  I Love ShenSiYuan		  ";

	char *ssy = String_StripLeadingAndTrailingSpace(p);

	printf("%s\n", ssy);
	printf("lengths: %d\n", STRING_LENGTH(ssy));
	String_Destroy(ssy);

	char *v = String_Dup(ssy);
	if(!v)
		printf("String_Dup fail\n");
	else
	{
		printf("String_Dup succ\n");
		printf("%s\n", v);
		printf("lengths: %d\n", STRING_LENGTH(v));
	}

	char * x = String_Concat("const char *s1", strlen("const char *s1"), "const char *s2", strlen("const char *s2"));
	char * y = String_Concat(x, 28, x, 28);
	printf("%s\n", y);
	printf("lengths: %d\n", STRING_LENGTH(y));

	String_Destroy(ssy);
	String_Destroy(v);
	String_Destroy(x);
	String_Destroy(y);

	return iRetValue;
}
