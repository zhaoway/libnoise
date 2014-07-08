# Copyright (C) 2013 LuaDist.
# Created by Peter Kapec
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

project( libnoise CXX )
cmake_minimum_required ( VERSION 2.8 )
include( cmake/dist.cmake )

# Determine install host
if ( WIN32 AND NOT CYGWIN )
	if( MSVC )
		add_definitions( -D_CRT_SECURE_NO_DEPRECATE )
	


		set( DLL_RC_FILE src/win32/noise.rc )
	endif()
endif()

# Build Libraries
include_directories( src src/model src/module )
file( GLOB_RECURSE SRC_MODEL "src/model/*.cpp" )
file( GLOB_RECURSE SRC_MODULE "src/module/*.cpp" )

file( GLOB HEADERS "src/*.h" )
file( GLOB HEADERS_MODEL "src/model/*.h" )
file( GLOB HEADERS_MODULE "src/module/*.h" )

set( LIBRARY_NAME noise)
if( MSVC )
	set( LIBRARY_NAME libnoise)



endif()

add_library( ${LIBRARY_NAME} src/latlon.cpp src/noisegen.cpp ${SRC_MODEL} ${SRC_MODULE} ${DEF_FILE} ${DLL_RC_FILE})


if ( WIN32  )
          		
	set_target_properties( ${LIBRARY_NAME}    PROPERTIES
    DEFINE_SYMBOL LIBNOISE_DLL_EXPORT )

endif()



################################################################################
# Installation stuff

SET(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
SET(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
SET(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "add a postfix, usually empty on windows")
SET(CMAKE_MINSIZEREL_POSTFIX "s" CACHE STRING "add a postfix, usually empty on windows")

# Set the build postfix extension according to what configuration is being built.
IF (CMAKE_BUILD_TYPE MATCHES "Release")
    SET(CMAKE_BUILD_POSTFIX "${CMAKE_RELEASE_POSTFIX}")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "MinSizeRel")
    SET(CMAKE_BUILD_POSTFIX "${CMAKE_MINSIZEREL_POSTFIX}")
ELSEIF(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
    SET(CMAKE_BUILD_POSTFIX "${CMAKE_RELWITHDEBINFO_POSTFIX}")
ELSEIF(CMAKE_BUILD_TYPE MATCHES "Debug")
    SET(CMAKE_BUILD_POSTFIX "${CMAKE_DEBUG_POSTFIX}")
ELSE()
    SET(CMAKE_BUILD_POSTFIX "")
ENDIF()




# Install
install_library( ${LIBRARY_NAME} )
install_header( ${HEADERS} INTO libnoise)
install_header( ${HEADERS_MODEL} INTO libnoise/model )
install_header( ${HEADERS_MODULE} INTO libnoise/module )
install_doc( COPYING.txt doc/readme.txt doc/html doc/htmldata doc/img )
