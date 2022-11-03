/*
MIT License

Copyright (c) 2018 Qulacs Authors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



/**
 * @file type.h
 * @brief basic definitins of types and macros
 */


#pragma once

// When csim is compiled with C++, std::complex<double> is used instead of double _Complex
#ifdef _MSC_VER
#include <complex>
#else
#include <complex.h>
#endif

//! size_t for gcc
#include <stddef.h>

//! unsigned integer
typedef unsigned int UINT;

//! complex value
#ifdef _MSC_VER
typedef std::complex<double> CTYPE;
using namespace std::complex_literals;
inline static double cabs(CTYPE val) { return std::abs(val); }
inline static double creal(CTYPE val) { return std::real(val); }
inline static double cimag(CTYPE val) { return std::imag(val); }
#else
typedef double _Complex CTYPE;
#endif

//! dimension index
#ifdef _MSC_VER
// In MSVC, OpenMP only supports signed index
typedef signed long long ITYPE;
#else
typedef unsigned long long ITYPE;
#endif

//! check AVX2 support
#ifdef _MSC_VER
// MSVC
// In MSVC, flag __AVX2__ is not automatically set by default
#else
// GCC remove simd flag when AVX2 is not supported
#ifndef __AVX2__
#undef _USE_SIMD
#endif
#endif

//! define export command
#if defined(__MINGW32__) || defined(_MSC_VER)
#define DllExport __declspec(dllexport)
#else
#define DllExport __attribute__((visibility ("default")))
#endif
