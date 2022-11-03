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


/*
 rules for arguments of update functions:
   The order of arguments must be 
      information_about_applying_qubits -> Pauli_operator -> information_about_applying_gate_matrix_elements -> a_kind_of_rotation_angle -> state_vector -> dimension
   If there is control-qubit and target-qubit, control-qubit is the first argument.
   If an array of which the size is not known comes, the size of that array follows.
  
  Definition of update function is divided to named_gates, single_target_qubit_gates, multiple_target_qubit_gates, QFT_gates
 */


#pragma once

#include "type.h"
#ifdef _OPENMP
#include <omp.h>
#endif

DllExport void dm_normalize(double squared_norm, CTYPE* state, ITYPE dim);
DllExport void dm_single_qubit_dense_matrix_gate(UINT target_qubit_index, const CTYPE matrix[4], CTYPE *state, ITYPE dim);
DllExport void dm_multi_qubit_control_single_qubit_dense_matrix_gate(const UINT* control_qubit_index_list, const UINT* control_value_list, UINT control_qubit_index_count, UINT target_qubit_index, const CTYPE matrix[4], CTYPE *state, ITYPE dim);
DllExport void dm_multi_qubit_dense_matrix_gate(const UINT* target_qubit_index_list, UINT target_qubit_index_count, const CTYPE* matrix, CTYPE* state, ITYPE dim);
DllExport void dm_multi_qubit_control_multi_qubit_dense_matrix_gate(const UINT* control_qubit_index_list, const UINT* control_value_list, UINT control_qubit_index_count, const UINT* target_qubit_index_list, UINT target_qubit_index_count, const CTYPE* matrix, CTYPE* state, ITYPE dim);


DllExport void dm_X_gate(UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_Y_gate(UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_Z_gate(UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_S_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_Sdag_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_T_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_Tdag_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_sqrtX_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_sqrtXdag_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_sqrtY_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_sqrtYdag_gate(UINT target_qubit_index, CTYPE* state, ITYPE dim);
DllExport void dm_H_gate(UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_CNOT_gate(UINT control_qubit_index, UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_CZ_gate(UINT control_qubit_index, UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_SWAP_gate(UINT target_qubit_index_0, UINT target_qubit_index_1, CTYPE *state, ITYPE dim);
DllExport void dm_P0_gate(UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_P1_gate(UINT target_qubit_index, CTYPE *state, ITYPE dim);
DllExport void dm_RX_gate(UINT target_qubit_index, double angle, CTYPE* state, ITYPE dim);
DllExport void dm_RY_gate(UINT target_qubit_index, double angle, CTYPE* state, ITYPE dim);
DllExport void dm_RZ_gate(UINT target_qubit_index, double angle, CTYPE* state, ITYPE dim);
DllExport void dm_multi_qubit_Pauli_gate_partial_list(const UINT* target_qubit_index_list, const UINT* Pauli_operator_type_list, UINT target_qubit_index_count, CTYPE* state, ITYPE dim);
DllExport void dm_multi_qubit_Pauli_rotation_gate_partial_list(const UINT* target_qubit_index_list, const UINT* Pauli_operator_type_list, UINT target_qubit_index_count, double angle, CTYPE* state, ITYPE dim);
