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

#ifndef _MSC_VER
extern "C" {
#include <csim/update_ops.h>
}
#else
#include <csim/update_ops.h>
#endif

#include "gate_named.hpp"
#include "state.hpp"

/**
 * \~japanese-en CNOTゲート
 */
class ClsCNOTGate : public QuantumGate_OneControlOneTarget{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param control_qubit_index コントロール量子ビットの添え字
     * @param target_qubit_index ターゲット量子ビットの添え字
     */
    ClsCNOTGate(UINT control_qubit_index, UINT target_qubit_index) {
        this->_update_func = CNOT_gate;
		this->_update_func_dm = dm_CNOT_gate;
#ifdef _USE_GPU
		this->_update_func_gpu = CNOT_gate_host;
#endif
        this->_name = "CNOT";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_X_COMMUTE ));
        this->_control_qubit_list.push_back(ControlQubitInfo(control_qubit_index, 1 ));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << 0,1,1,0;
    }
};

/**
 * \~japanese-en Control-Zゲート
 */
class ClsCZGate : public QuantumGate_OneControlOneTarget {
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param control_qubit_index コントロール量子ビットの添え字
     * @param target_qubit_index ターゲット量子ビットの添え字
     */
    ClsCZGate(UINT control_qubit_index, UINT target_qubit_index) {
        this->_update_func = CZ_gate;
		this->_update_func_dm = dm_CZ_gate;
#ifdef _USE_GPU
		this->_update_func_gpu = CZ_gate_host;
#endif
        this->_name = "CZ";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Z_COMMUTE ));
        this->_control_qubit_list.push_back(ControlQubitInfo(control_qubit_index, 1 ));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << 1,0,0,-1;
    }
};

/**
 * \~japanese-en SWAPゲート
 */
class ClsSWAPGate : public QuantumGate_TwoQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index1 ターゲット量子ビットの添え字
     * @param target_qubit_index2 もう一つのターゲット量子ビットの添え字
     */
    ClsSWAPGate(UINT target_qubit_index1, UINT target_qubit_index2) {
        this->_update_func = SWAP_gate;
		this->_update_func_dm = dm_SWAP_gate;
#ifdef _USE_GPU
		this->_update_func_gpu = SWAP_gate_host;
#endif
        this->_name = "SWAP";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index1, 0 ));
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index2, 0 ));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(4,4);
        this->_matrix_element << 1,0,0,0 , 0,0,1,0 , 0,1,0,0 , 0,0,0,1;
    }
};
