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


#ifndef _UTIL_COMMON_CU_H_
#define _UTIL_COMMON_CU_H_

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cuComplex.h>
//#include <cuda_runtime.h>
//#include <cuda.h>

#include <complex>

#define PI 3.141592653589793
//#define HOIST_GPU_DT
//#define CUDA_ERROR_CHECK
//#define CudaSafeCall( err ) __cudaSafeCall( err, __FILE__, __LINE__ )

typedef std::complex<double> CTYPE;
typedef cuDoubleComplex GTYPE;
typedef unsigned int UINT;
typedef unsigned long long ITYPE;

#if defined(__MINGW32__) || defined(_MSC_VER)
#define DllExport __declspec(dllexport)
#else
#define DllExport __attribute__((visibility ("default")))
#endif

#endif // #ifndef _UTIL_COMMON_CU_H_