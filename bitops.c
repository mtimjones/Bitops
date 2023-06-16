// Bitops.c
#include <stdio.h>
#include <stdlib.h>
#include "bitops.h"

Bitmap_t *BitmapAllocate( int numBits )
{
    Bitmap_t *bitmap = ( Bitmap_t *) NULL;

    if ( numBits > 0 && numBits < 4096 )
    {
        int size = numBits / 32;
        if ( numBits % 32 )
        {
            size++;
        }

        bitmap = ( Bitmap_t * )malloc( sizeof( Bitmap_t ) );

        bitmap->block = ( unsigned int * )calloc( sizeof( unsigned int ), size );
        bitmap->num = numBits;
    }

    return bitmap;
}


void BitmapSet( Bitmap_t *bitmap, int bit )
{
    if ( bitmap != ( Bitmap_t *)NULL )
    {
        if ( bit < bitmap->num )
        {
            bitmap->block[ ( bit / 32 ) ] |= ( 1 << ( bit % 32 ) );
        }
    }
}


void BitmapReset( Bitmap_t *bitmap, int bit )
{
    if ( bitmap != ( Bitmap_t *)NULL )
    {
        if ( bit < bitmap->num )
        {
            bitmap->block[ ( bit / 32 ) ] &= ~( 1 << ( bit % 32 ) );
        }
    }
}


bool IsBitmapSet( Bitmap_t *bitmap, int bit )
{
    bool result = false;

    if ( bitmap != ( Bitmap_t *)NULL )
    {
        if ( bit < bitmap->num )
        {
            result = bitmap->block[ ( bit / 32 ) ] & ( 1 << ( bit % 32 ) );
        }
    }

    return result;
}


bool IsBitmapReset( Bitmap_t *bitmap, int bit )
{
    bool result = false;

    if ( bitmap != ( Bitmap_t *)NULL )
    {
        if ( bit < bitmap->num )
        {
            result = bitmap->block[ ( bit / 32 ) ] & ~( 1 << ( bit % 32 ) );
        }
    }

    return result;
}


void BitmapClear( Bitmap_t *bitmap )
{
    bool result = false;

    if ( bitmap != ( Bitmap_t *)NULL )
    {
        int size = bitmap->num / 32;
        if ( bitmap->num % 32 )
        {
            size++;
        }

        for ( int i = 0 ; i < size ; i++ )
        {
            bitmap->block[ i ] = 0;
        }
    
    }

}


void BitmapDeallocate( Bitmap_t *bitmap )
{
    if ( bitmap != ( Bitmap_t *)NULL )
    {
        free( bitmap->block );
        free( bitmap );
    }
}


