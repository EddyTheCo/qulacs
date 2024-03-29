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

#include "gate.hpp"
#include "state.hpp"
#ifndef _MSC_VER
extern "C" {
#include <csim/update_ops.h>
}
#else
#include <csim/update_ops.h>
#endif
#include <csim/update_ops_cpp.hpp>

#include <cmath>

#ifdef _USE_GPU
#include <gpusim/update_ops_cuda.h>
#endif
#include <iostream>

/**
 * \~japanese-en 量子状態を、別の量子状態に対して反射するゲートのクラス
 */
class ClsStateReflectionGate : public QuantumGateBase {
private:
	QuantumStateBase* reflection_state;
public:
	ClsStateReflectionGate(const QuantumStateBase* _reflection_state) {
		reflection_state = _reflection_state->copy();
		UINT qubit_count = _reflection_state->qubit_count;
		for (UINT qubit_index = 0; qubit_index < qubit_count; ++qubit_index) {
			this->_target_qubit_list.push_back(TargetQubitInfo(qubit_index, 0));
		}
		this->_name = "Reflection";
	};
	virtual ~ClsStateReflectionGate() {
		delete reflection_state;
	}

	/**
	 * \~japanese-en 量子状態を更新する
	 *
	 * @param state 更新する量子状態
	 */
	virtual void update_quantum_state(QuantumStateBase* state) override {
		if (state->is_state_vector()) {
#ifdef _USE_GPU
			if (state->get_device_name() != reflection_state->get_device_name()) {
				std::cerr << "Quantum state on CPU (GPU) cannot be reflected using quantum state on GPU (CPU)" << std::endl;
				return;
			}
			if (state->get_device_name() == "gpu") {
				std::cerr << "Not Implemented" << std::endl;
				exit(0);
				//reversible_boolean_gate_gpu(target_index.data(), target_index.size(), function_ptr, state->data_c(), state->dim);
			}
			else {
				reflection_gate(reflection_state->data_c(), state->data_c(), state->dim);
			}
#else
			reflection_gate(reflection_state->data_c(), state->data_c(), state->dim);
#endif
		}
		else {
			std::cerr << "not implemented" << std::endl;
		}
	};
	/**
	 * \~japanese-en 自身のディープコピーを生成する
	 *
	 * @return 自身のディープコピー
	 */
	virtual QuantumGateBase* copy() const override {
		return new ClsStateReflectionGate(this->reflection_state);
	};
	/**
	 * \~japanese-en 自身のゲート行列をセットする
	 *
	 * @param matrix 行列をセットする変数の参照
	 */
	virtual void set_matrix(ComplexMatrix&) const override {
		std::cerr << "ReflectionGate::set_matrix is not implemented" << std::endl;
		exit(0);
	}
};


