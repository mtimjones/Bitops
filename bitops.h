#ifndef __BITOPS_H__

// Bitops.h
#include <stdbool.h>

typedef struct
{
    int           num;
    unsigned int *block;
} Bitmap_t;


Bitmap_t *BitmapAllocate( int numBits );

void BitmapSet( Bitmap_t *bitmap, int bit );

void BitmapReset( Bitmap_t *bitmap, int bit );

bool IsBitmapSet( Bitmap_t *bitmap, int bit );

bool IsBitmapReset( Bitmap_t *bitmap, int bit );

void BitmapClear( Bitmap_t *bitmap );

void BitmapDeallocate( Bitmap_t *bitmap );

#endif // __BITOPS_H__

