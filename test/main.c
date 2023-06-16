#include <stdio.h>
#include "../bitops.h"

void main( void )
{
    Bitmap_t *bm = BitmapAllocate( 65 );
    int err = 0;

    if ( IsBitmapSet( bm, 65 ) ) err++;

    BitmapSet( bm, 0 );

    if ( IsBitmapSet( bm, 65 ) ) err++;

    if ( IsBitmapReset( bm, 0 ) ) err++;

    BitmapSet( bm, 65 );

    BitmapReset( bm, 0 );

    if ( IsBitmapReset( bm, 65 ) ) err++;

    if ( IsBitmapSet( bm, 0 ) ) err++;

    BitmapDeallocate( bm );

    printf( "Errors: %d\n", err );

    return;
}
