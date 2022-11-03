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


#ifndef _MEMORY_OPS_CU_DEVICE_H_
#define _MEMORY_OPS_CU_DEVICE_H_

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cuda_runtime.h>
#include <curand.h>
#include <curand_kernel.h>

#include "util_export.h"
#include "util_type.h"
#include "util_type_internal.h"


__global__ void init_qstate(GTYPE* state_gpu, ITYPE dim);
__global__ void init_rnd(curandState *const rnd_state, const unsigned int seed);
__global__ void rand_normal_xorwow(curandState* rnd_state, GTYPE* state, ITYPE dim);


#endif // _MEMORY_OPS_CU_DEVICE_H_

