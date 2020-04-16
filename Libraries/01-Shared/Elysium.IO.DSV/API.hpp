/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_IO_DSV_API

#ifdef _MSC_VER
#pragma once
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
#ifdef ELYSIUMIODSV_EXPORTS
#define ELYSIUM_IO_DSV_API __declspec(dllexport)
#else
#define ELYSIUM_IO_DSV_API __declspec(dllimport)
#endif
#elif defined(__ANDROID__)
#define EXPORT
#else
#error "undefined os"
#endif

#endif
