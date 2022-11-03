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


#ifndef _MEMORY_OPS_CU_H_
#define _MEMORY_OPS_CU_H_

#include "util_export.h"
#include "util_type.h"

DllExport void* allocate_cuda_stream_host(unsigned int max_cuda_stream, unsigned int device_number);
DllExport void release_cuda_stream_host(void* cuda_stream, unsigned int max_cuda_stream, unsigned int device_number);
DllExport void* allocate_quantum_state_host(ITYPE dim, unsigned int device_number);
DllExport void initialize_quantum_state_host(void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport void release_quantum_state_host(void* state, unsigned int device_number);
DllExport void initialize_Haar_random_state_host(void *state, ITYPE dim, void* stream, unsigned int device_number);
DllExport void initialize_Haar_random_state_with_seed_host(void *state, ITYPE dim, UINT seed, void* stream, unsigned int device_number);

#endif // _MEMORY_OPS_CU_H_

