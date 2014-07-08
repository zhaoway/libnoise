/**********************************************************************
 *
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
#ifndef LIBNOISE_EXPORT_H
#define LIBNOISE_EXPORT_H

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || \
    defined( __BCPLUSPLUS__)  || defined( __MWERKS__)

#  if defined(LIBNOISE_DLL_EXPORT)
#    define LIBNOISE_DLL   __declspec(dllexport)
#  elif defined(LIBNOISE_DLL_IMPORT)
#    define LIBNOISE_DLL   __declspec(dllimport)
#  else
#    define LIBNOISE_DLL
#  endif
#else
#  define LIBNOISE_DLL
#endif

#endif
