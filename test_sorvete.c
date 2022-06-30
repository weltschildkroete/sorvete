/*
 * Copyright (c) 2022 Leonardo Duarte
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <string.h>

#include "sorvete.h"

#define ZIDANE_IMPLEMENTATION
#include "zidane.h"

ZIDANE_TEST(sanity)
{
	const char *cstr = "Hello, world";

	struct sorvete_sv sv = { 12, cstr };

	ZIDANE_VERIFY(sv.size == 12);
	ZIDANE_VERIFY(memcmp(sv.data, cstr, sv.size) == 0);
}

ZIDANE_TEST(macro_constructor)
{
	struct sorvete_sv sv = SORVETE_SV("Hello, world");

	ZIDANE_VERIFY(sv.size == 12);
	ZIDANE_VERIFY(memcmp(sv.data, "Hello, world", sv.size) == 0);
}

ZIDANE_TEST(from_parts)
{
	const char *cstr = "Hello, world";

	struct sorvete_sv sv = sorvete_sv_from_parts(cstr, strlen(cstr));

	ZIDANE_VERIFY(sv.size == 12);
	ZIDANE_VERIFY(memcmp(sv.data, cstr, sv.size) == 0);
}

ZIDANE_TEST(from_cstr)
{
	const char *cstr = "Hello, world";

	struct sorvete_sv sv = sorvete_sv_from_cstr(cstr);

	ZIDANE_VERIFY(sv.size == 12);
	ZIDANE_VERIFY(memcmp(sv.data, cstr, sv.size) == 0);
}

ZIDANE_TEST(eq)
{
	struct sorvete_sv sv1 = SORVETE_SV("Hello, world");
	struct sorvete_sv sv2 = SORVETE_SV("Hello, world");
	struct sorvete_sv sv3 = SORVETE_SV("Hei, verden");
	struct sorvete_sv sv4 = SORVETE_SV("Hallo, Welt");

	ZIDANE_VERIFY(sorvete_sv_eq(sv1, sv2));
	ZIDANE_VERIFY(!sorvete_sv_eq(sv1, sv3));
	ZIDANE_VERIFY(!sorvete_sv_eq(sv1, sv4));
	ZIDANE_VERIFY(!sorvete_sv_eq(sv3, sv4));
}

ZIDANE_TEST(printing_macros)
{
	char text[13] = { 0 };

	struct sorvete_sv sv = SORVETE_SV("world");

	sprintf(text, "Hello, " SORVETE_SV_FMT, SORVETE_SV_ARG(sv));

	ZIDANE_VERIFY(memcmp(text, "Hello, world", sv.size) == 0);
}
