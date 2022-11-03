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


#ifndef _STAT_OPS_CU_H_
#define _STAT_OPS_CU_H_

#include "util_type.h"
#include "util_export.h"


DllExport double state_norm_squared_cublas_host(void *state, ITYPE dim);
DllExport double state_norm_squared_host(void *state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double measurement_distribution_entropy_host(void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport void state_add_host(void *state_added, void *state, ITYPE dim, void* stream, unsigned int device_number);
DllExport void state_multiply_host(CPPCTYPE coef, void *state, ITYPE dim, void* stream, unsigned int device_number);
DllExport CPPCTYPE inner_product_host(const void *bra_state, const void *ket_state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double expectation_value_single_qubit_Pauli_operator_host(unsigned int operator_index, unsigned int target_qubit_index, void *state, ITYPE dim, void* stream, unsigned int device_number);
DllExport void multi_Z_gate_host(int* gates, void *state, ITYPE dim, int n_qubits, void* stream, unsigned int device_number);
DllExport double multipauli_get_expectation_value_host(unsigned int* gates, void *state, ITYPE dim, int n_qubits, void* stream, unsigned int device_number);
DllExport double M0_prob_host(UINT target_qubit_index, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double M1_prob_host(UINT target_qubit_index, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double marginal_prob_host(UINT* sorted_target_qubit_index_list, UINT* measured_value_list, UINT target_qubit_index_count, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double expectation_value_multi_qubit_Pauli_operator_XZ_mask_host(ITYPE bit_flip_mask, ITYPE phase_flip_mask, UINT global_phase_90rot_count, UINT pivot_qubit_index, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double expectation_value_multi_qubit_Pauli_operator_Z_mask_host(ITYPE phase_flip_mask, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double expectation_value_multi_qubit_Pauli_operator_partial_list_host(const UINT* target_qubit_index_list, const UINT* Pauli_operator_type_list, UINT target_qubit_index_count, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport double expectation_value_multi_qubit_Pauli_operator_whole_list_host(const UINT* Pauli_operator_type_list, UINT qubit_count, void* state, ITYPE dim, void* stream, unsigned int device_number);
DllExport CPPCTYPE transition_amplitude_multi_qubit_Pauli_operator_XZ_mask_host(ITYPE bit_flip_mask, ITYPE phase_flip_mask, UINT global_phase_90rot_count, UINT pivot_qubit_index, void* state_bra, void* state_ket, ITYPE dim, void* stream, unsigned int device_number);
DllExport CPPCTYPE transition_amplitude_multi_qubit_Pauli_operator_Z_mask_host(ITYPE phase_flip_mask, void* state_bra, void* state_ket, ITYPE dim, void* stream, unsigned int device_number);
DllExport CPPCTYPE transition_amplitude_multi_qubit_Pauli_operator_partial_list_host(const UINT* target_qubit_index_list, const UINT* Pauli_operator_type_list, UINT target_qubit_index_count, void* state_bra, void* state_ket, ITYPE dim, void* stream, unsigned int device_number);
DllExport CPPCTYPE transition_amplitude_multi_qubit_Pauli_operator_whole_list_host(const UINT* Pauli_operator_type_list, UINT qubit_count, void* state_bra, void* state_ket, ITYPE dim, void* stream, unsigned int device_number);

#endif // _STAT_OPS_CU_H_
