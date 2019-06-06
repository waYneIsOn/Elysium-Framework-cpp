/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_EXPORT
#define ELYSIUM_IO_PDF_EXPORT

#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
#define EXPORT __declspec(dllexport)
#elif defined(__ANDROID__)
#define EXPORT
#else
#error "undefined os"
#endif

#endif
