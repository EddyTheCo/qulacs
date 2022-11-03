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


#pragma once

#include "type.h"

DllExport double dm_state_norm_squared(const CTYPE *state, ITYPE dim) ;
DllExport double dm_measurement_distribution_entropy(const CTYPE *state, ITYPE dim);
DllExport void dm_state_add(const CTYPE *state_added, CTYPE *state, ITYPE dim);
DllExport void dm_state_multiply(CTYPE coef, CTYPE *state, ITYPE dim);

DllExport void dm_state_tensor_product(const CTYPE* state_left, ITYPE dim_left, const CTYPE* state_right, ITYPE dim_right, CTYPE* state_dst);
DllExport void dm_state_permutate_qubit(const UINT* qubit_order, const CTYPE* state_src, CTYPE* state_dst, UINT qubit_count, ITYPE dim);
DllExport void dm_state_partial_trace_from_density_matrix(const UINT* target, UINT target_count, const CTYPE* state_src, CTYPE* state_dst, ITYPE dim);
DllExport void dm_state_partial_trace_from_state_vector(const UINT* target, UINT target_count, const CTYPE* state_src, CTYPE* state_dst, ITYPE dim);

DllExport double dm_M0_prob(UINT target_qubit_index, const CTYPE* state, ITYPE dim);
DllExport double dm_M1_prob(UINT target_qubit_index, const CTYPE* state, ITYPE dim);
DllExport double dm_marginal_prob(const UINT* sorted_target_qubit_index_list, const UINT* measured_value_list, UINT target_qubit_index_count, const CTYPE* state, ITYPE dim);

DllExport double dm_expectation_value_multi_qubit_Pauli_operator_partial_list(const UINT* target_qubit_index_list, const UINT* Pauli_operator_type_list, UINT target_qubit_index_count, const CTYPE* state, ITYPE dim);
