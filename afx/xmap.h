//  Created by 胡兵兵 on 16/4/1.
//  Copyright © 2016年 xxx_orgnization. All rights reserved.
//

#ifndef _H_XMAP_H_
#define _H_XMAP_H_
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
#include "xarray.h"
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
#define SECTION_SIZE 64
#define SECTION_SIZE_1 63
#define SECTION_SIZE_2n 6
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
typedef struct _xmap
{
  xarray2 * map ;
  int i , j ;
  void ** p ;
} xmap ;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
xmap * xmap_alloc () ;
void xmap_free ( xmap ** map ) ;
////////////////////////////////////////////////////////////////////////////
void xmap_set ( xmap * map , int i , int j , void * v ) ;
int  xmap_get ( xmap * map , int i , int j , void * v ) ;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
int xmap2buffer (xmap * map , int left , int bottom , int right , int top ,
                 unsigned char (*pv2gray)(char exist , void * pv) ,
                 unsigned char ** buffer , int * width , int * height ) ;
int buffer2xmap (unsigned char * buffer , int width , int height ,
                 void * (*gray2pv)(unsigned char gray) ,
                 xmap * map , int left , int top , int * right , int * bottom ) ;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////