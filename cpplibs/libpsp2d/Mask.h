
/**
 * @file Mask.h
 */

/**********************************************************************

  Created: 13 Nov 2005

    Copyright (C) 2005 J�r�me Laheurte

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The names of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**********************************************************************/
// $Id: Mask.h 1481 2005-11-26 11:33:45Z fraca7 $

#ifndef _MASK_H
#define _MASK_H

#include <psptypes.h>
#include <libpsp2d/Image.h>

namespace PSP2D
{
    /**
     * 2-dimensional bit mask, intended for collision detection
     */

    class Mask
    {
      public:
       /**
        * Constructor
        */

       Mask(Image *img, u16 x, u16 y, u16 w, u16 h, unsigned char threshold = 127,
            u16 xcoord = 0, u16 ycoord = 0);

       ~Mask();

       /**
        * Changes this mask position
        */

       void move(u16 x, u16 y);

       /**
        * Sets a bit to 1
        */

       void set(u16 x, u16 y);

       /**
        * Sets all the bits that are set in another mask
        */

       void set(Mask *msk);

       /**
        * Clears a bit
        */

       void clear(u16 x, u16 y);

       /**
        * Returns true if the bit is set
        */

       bool isSet(u16 x, u16 y);

       /**
        * Returns the number of common bits
        */

       u32 collide(Mask *msk);

      protected:
       u32 *_data;
       u16 _width, _height, _wcap;
       u16 _x, _y;
    };
};

// Inline methods
#include <libpsp2d/Mask.il>

#endif /* _MASK_H */
