#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#if 0
#ifdef  __cplusplus
extern "C" {
#endif
#endif

#ifndef __YBASIS__H_
#define __YBASIS__H_

#define  OUT
#define  IN


#define YINT_MAX        2147483647
#define YUCHAR_MAX        255

#define Kbyte(x) (1024 * (x))
#define Mbyte(x) (1024 * 1024 * (x))
#define Gbyte(x) (1024 * 1024 * 1024 * (x))
#define Tbyte(x) (1024 * 1024 * 1024 * 1024 * (x))

#define Second(x) (x)
#define Minute(x) (x * 60)
#define Hour(x) (x * 3600)
#define Day(x) (x * 3600 * 24)

#define MINBUFFER_SIZE  (256)
#define BUFFER_SIZE     (1024)

#define swp16(V) (((V >> 8) & 0xff) | ((V << 8) & 0xff00))
#define swp32(V) ( ((V >> 24) & 0xff) | ((V >> 8) & 0x0000ff00) | ((V << 8) & 0x00ff0000) | ((V << 24) & 0xff000000))
#define IN8(p, v) {(v) = (*((p)++));}
#define IN16(p, v) {(v) = *((p)++); (v) = (((v)<<8) & 0xff00 | *((p)++));}
#define IN32(p, v) {IN16(p, v); (v) = (((v)<<8) & 0xffff00 | *((p)++));(v) = (((v)<<8) & 0xffffff00 | *((p)++));}
#define OUT8(p, v) {*((p)++) = v;}
#define OUT16(p, v) {*((p)++) = (((v)>>8) & 0xff); *((p)++) = ((v) & 0xff);}
#define OUT32(p, v) {OUT16((p), ((v)>>16) & 0xffff); OUT16((p), ((v) & 0xffff));}

typedef unsigned char u_8;
typedef unsigned short u_16;
typedef unsigned int u_32;

void* Ymalloc(u_32 size)
{
	void *p = NULL;
	if (size > YINT_MAX)
		return NULL;
	else {
		p = malloc(size);
		if (!p)
			return NULL;
		memset(p, 0, size);
	}
	return p;
}

void Yfree(void *p)
{
	if (p) free(p);
}

#endif

#if 0
#ifdef  __cplusplus
}
#endif
#endif