
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
	int iRetValue = 0;

    char *p = "  I Love ShenSiYuan";

    char *ssy = String_StripLeadingSpace(p);

    printf("%s\n", ssy);

    String_Destroy(ssy);

	return iRetValue;
}
