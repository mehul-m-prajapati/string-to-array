#ifndef STR_TO_ARR_H
#define STR_TO_ARR_H


/* includes */
#include <stdint.h>
#include <stdbool.h>


/* defines */
#define DELIM_CNT_MAX			  20
#define OUT_STR_LEN_MAX			512


/* function prototype */
bool parse_str_with_delim(char *pInStr, const char *pDelim, char outStr[DELIM_CNT_MAX][OUT_STR_LEN_MAX], uint8_t *pCnt);
uint16_t get_delim_count(char *pInStr, const char *pDelim);

#endif // STR_TO_ARR_H
