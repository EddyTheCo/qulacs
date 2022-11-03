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
 * @file state.h
 * @brief Definition and basic functions for state vector
 */

#pragma once

#include "type.h"

/**
 * allocate quantum state in memory
 * 
 * allocate quantum state in memory
 * @param[in] dim dimension, i.e. size of vector
 * @return pointer to allocated vector
 */
DllExport CTYPE* dm_allocate_quantum_state(ITYPE dim);

/**
 * intiialize quantum state to zero state
 * 
 * intiialize quantum state to zero state
 * @param[out] state pointer of quantum state
 * @param[in] dim dimension
 */
DllExport void dm_initialize_quantum_state(CTYPE *state, ITYPE dim);

/**
 * release allocated quantum state
 * 
 * release allocated quantum state
 * @param[in] state quantum state
 */
DllExport void dm_release_quantum_state(CTYPE* state);

/**
 * initialize density matrix from pure state
 *
 * initialize density matrix from pure state
 * @param[out] state pointer of quantum state
 * @param[out] pure_state pointer of quantum state
 * @param[in] dim dimension
 */
DllExport void dm_initialize_with_pure_state(CTYPE *state, const CTYPE *pure_state, ITYPE dim);
