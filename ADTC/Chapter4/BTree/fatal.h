//
// Created by HZWNB147 on 2017/12/4.
//
#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str );
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 );
