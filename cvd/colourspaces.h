/*
	This file is part of the CVD Library.

	Copyright (C) 2005 The Authors

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef CVD_COLOURSPACES_H
#define CVD_COLOURSPACES_H

//#include <cvd/internal/is_pod.h>
#include <cvd/internal/builtin_components.h>
#include <cvd/internal/pixel_traits.h>

namespace CVD
{

	/// A dedicated bayer datatype to configure the V4L1 device to return bayer images.
    /// It is probably only supported in Ethan's hacked driver for USB2.0 devices.
    /// @ingroup gVideoBuffer
	struct bayer
	{
		unsigned char val;
                operator unsigned char(){
                    return val;
                };
	};

	/// A datatype to represent yuv411 (uyyvyy) data, typically from firewire
	/// cameras. It can be used to configure dvbuffer to return this format.
	/// @ingroup gVideoBuffer
	struct yuv411
	{
		unsigned char val;
	};

    namespace Pixel {
        template<> struct Component<bayer> : public component_base<bayer, 1>
        {
        };

        template<int LIFT> struct traits<bayer, LIFT>
        {
            typedef int wider_type;
            typedef float float_type;
            static const bool integral = true;
            static const bool is_signed = false;
            static const int bits_used = 8;
            static const unsigned char max_intensity=(1 << bits_used) - 1;
        };
    }

/*
	#ifndef DOXYGEN_IGNORE_INTERNAL
	namespace Internal
	{
		template<> struct is_POD<bayer>
		{
			static const bool is_pod = 1;
		};
		template<> struct is_POD<yuv411>
		{
			static const bool is_pod = 1;
		};
	}
	#endif
*/
}

#endif
