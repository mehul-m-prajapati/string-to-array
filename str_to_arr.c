/* include */
#include <string.h>
#include "str_to_arr.h"


/* function definition */
bool parse_str_with_delim(char *pInStr, const char *pDelim, char outStr[DELIM_CNT_MAX][OUT_STR_LEN_MAX], uint8_t *pCnt)
{
	char *pFindDelim = NULL;
	size_t length = 0;
	uint8_t idx = 0;

	if (NULL == pInStr || NULL == pDelim || NULL == pCnt)
		return false;

	/* Find delim */
	pFindDelim = strstr(pInStr, pDelim);

	for (idx = 0; idx < DELIM_CNT_MAX && (pFindDelim != NULL); idx++)
	{
		length = pFindDelim - pInStr;

		/* Copy one parsed value */
		memcpy(outStr[idx], pInStr, length);
		outStr[idx][length] = '\0';

		/* Advance the pointer */
		pInStr += length + strlen(pDelim);

		/* Find delim */
		pFindDelim = strstr(pInStr, pDelim);
	}

	if (idx < DELIM_CNT_MAX)
	{
		/* Copy last parsed value */
		strcpy(outStr[idx], pInStr);

		*pCnt = idx;
	}
	else
	{
		*pCnt = idx - 1;
	}

	return true;
}

uint16_t get_delim_count(char *pInStr, const char *pDelim)
{
	char *pFindDelim = NULL;
	uint16_t cnt = 0;
	size_t length = 0;

	if (NULL == pInStr || NULL == pDelim)
		return false;

	/* Find delim */
	pFindDelim = strstr(pInStr, pDelim);

	for (cnt = 0; pFindDelim != NULL; cnt++)
	{
		/* Get length before delim occurs */
		length = pFindDelim - pInStr;

		/* Advance the pointer */
		pInStr += length + strlen(pDelim);

		/* Find delim */
		pFindDelim = strstr(pInStr, pDelim);
	}

	return cnt;
}
