#include "utils.h"

size_t my_hash_value(const char *str_key)
{
	char *pt = (char *)str_key;
	unsigned int hash = 1315423911;

	if (pt[0] == 0) goto end;
	hash ^= ((hash << 5) + pt[0] + (hash >> 2));
	if (pt[1] == 0) goto end;
	hash ^= ((hash << 5) + pt[1] + (hash >> 2));
	if (pt[2] == 0) goto end;
	hash ^= ((hash << 5) + pt[2] + (hash >> 2));
	if (pt[3] == 0) goto end;
	hash ^= ((hash << 5) + pt[3] + (hash >> 2));

	if (pt[4] == 0) goto end;
	hash ^= ((hash << 5) + pt[4] + (hash >> 2));
	if (pt[5] == 0) goto end;
	hash ^= ((hash << 5) + pt[5] + (hash >> 2));
	if (pt[6] == 0) goto end;
	hash ^= ((hash << 5) + pt[6] + (hash >> 2));
	if (pt[7] == 0) goto end;
	hash ^= ((hash << 5) + pt[7] + (hash >> 2));

	pt = (char *)(str_key + 8);
	while (*pt != 0) {
		hash ^= ((hash << 5) + *pt + (hash >> 2));
		pt++;
	}

end:
	return hash;
}

size_t strlcpy(char * dst, const char * src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';              /* NUL-terminate dst */
		while (*s++);
	}

	return(s - src - 1);    /* count does not include NUL */
}

#define CHAR_EQUAL_ZERO(a, b, c) do{\
	if (a != b) goto end;\
	if (a == 0) {c = 0; goto end;}\
}while(0)

int my_strcmp(const char *s1, const char *s2)
{
	int ret = -1;
	CHAR_EQUAL_ZERO(s1[0], s2[0], ret);
	CHAR_EQUAL_ZERO(s1[1], s2[1], ret);
	CHAR_EQUAL_ZERO(s1[2], s2[2], ret);
	CHAR_EQUAL_ZERO(s1[3], s2[3], ret);
	CHAR_EQUAL_ZERO(s1[4], s2[4], ret);
	CHAR_EQUAL_ZERO(s1[5], s2[5], ret);
	CHAR_EQUAL_ZERO(s1[6], s2[6], ret);
	CHAR_EQUAL_ZERO(s1[7], s2[7], ret);

	ret = strcmp(s1 + 8, s2 + 8);
end:
	return ret;
}