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
#include "utility.hpp"


/**
 * \~japanese-en 1量子ビットを対象とする回転角固定のゲートのクラス
 */
class QuantumGate_OneQubit : public QuantumGateBase{
protected:
    typedef void (T_UPDATE_FUNC)(UINT, CTYPE*, ITYPE);
	typedef void (T_GPU_UPDATE_FUNC)(UINT, void*, ITYPE, void*, UINT);
	T_UPDATE_FUNC* _update_func;
	T_UPDATE_FUNC* _update_func_dm;
	T_GPU_UPDATE_FUNC* _update_func_gpu;
    ComplexMatrix _matrix_element;

    QuantumGate_OneQubit() {};
public:
    /**
     * \~japanese-en 量子状態を更新する
     * 
     * @param state 更新する量子状態
     */
    virtual void update_quantum_state(QuantumStateBase* state) override{
		if (state->is_state_vector()) {
#ifdef _USE_GPU
			if (state->get_device_name() == "gpu") {
				_update_func_gpu(this->target_qubit_list[0].index(), state->data(), state->dim, state->get_cuda_stream(), state->device_number);
			}
			else {
				_update_func(this->_target_qubit_list[0].index(), state->data_c(), state->dim);
			}
#else
			_update_func(this->_target_qubit_list[0].index(), state->data_c(), state->dim);
#endif
		}
		else {
			_update_func_dm(this->_target_qubit_list[0].index(), state->data_c(), state->dim);
		}
    };
    /**
     * \~japanese-en 自身のディープコピーを生成する
     * 
     * @return 自身のディープコピー
     */
    virtual QuantumGateBase* copy() const override{
        return new QuantumGate_OneQubit(*this);
    };
    /**
     * \~japanese-en 自身のゲート行列をセットする
     * 
     * @param matrix 行列をセットする変数の参照
     */
    virtual void set_matrix(ComplexMatrix& matrix) const override{
        matrix = this->_matrix_element;
    }
};

/**
 * \~japanese-en 2量子ビットを対象とする回転角固定のゲートのクラス
 */
class QuantumGate_TwoQubit : public QuantumGateBase{
protected:
    typedef void (T_UPDATE_FUNC)(UINT, UINT, CTYPE*, ITYPE);
	typedef void (T_GPU_UPDATE_FUNC)(UINT, UINT, void*, ITYPE, void*, UINT);
	T_UPDATE_FUNC* _update_func;
	T_UPDATE_FUNC* _update_func_dm;
	T_GPU_UPDATE_FUNC* _update_func_gpu;
    ComplexMatrix _matrix_element;

    QuantumGate_TwoQubit() {};
public:
    /**
     * \~japanese-en 量子状態を更新する
     * 
     * @param state 更新する量子状態
     */
    virtual void update_quantum_state(QuantumStateBase* state) override{
		if (state->is_state_vector()) {
#ifdef _USE_GPU
			if (state->get_device_name() == "gpu") {
				_update_func_gpu(this->_target_qubit_list[0].index(), this->_target_qubit_list[1].index(), state->data(), state->dim, state->get_cuda_stream(), state->device_number);
			}
			else {
				_update_func(this->_target_qubit_list[0].index(), this->_target_qubit_list[1].index(), state->data_c(), state->dim);
			}
#else
			_update_func(this->_target_qubit_list[0].index(), this->_target_qubit_list[1].index(), state->data_c(), state->dim);
#endif
		}
		else {
			_update_func_dm(this->_target_qubit_list[0].index(), this->_target_qubit_list[1].index(), state->data_c(), state->dim);
		}
	};
    /**
     * \~japanese-en 自身のディープコピーを生成する
     * 
     * @return 自身のディープコピー
     */
    virtual QuantumGateBase* copy() const override{
        return new QuantumGate_TwoQubit(*this);
    };
    /**
     * \~japanese-en 自身のゲート行列をセットする
     * 
     * @param matrix 行列をセットする変数の参照
     */
    virtual void set_matrix(ComplexMatrix& matrix) const override {
        matrix = this->_matrix_element;
    }
};

/**
 * \~japanese-en 1量子ビットを対象とし1量子ビットにコントロールされる回転角固定のゲートのクラス
 */
class QuantumGate_OneControlOneTarget : public QuantumGateBase {
protected:
    typedef void (T_UPDATE_FUNC)(UINT, UINT, CTYPE*, ITYPE);
	typedef void (T_GPU_UPDATE_FUNC)(UINT, UINT, void*, ITYPE, void*, UINT);
	T_UPDATE_FUNC* _update_func;
	T_UPDATE_FUNC* _update_func_dm;
	T_GPU_UPDATE_FUNC* _update_func_gpu;
    ComplexMatrix _matrix_element;

    QuantumGate_OneControlOneTarget() {};
public:
    /**
     * \~japanese-en 量子状態を更新する
     * 
     * @param state 更新する量子状態
     */
    virtual void update_quantum_state(QuantumStateBase* state) override {
		if (state->is_state_vector()) {
#ifdef _USE_GPU
			if (state->get_device_name() == "gpu") {
				_update_func_gpu(this->_control_qubit_list[0].index(), this->_target_qubit_list[0].index(), state->data(), state->dim, state->get_cuda_stream(), state->device_number);
			}
			else {
				_update_func(this->_control_qubit_list[0].index(), this->_target_qubit_list[0].index(), state->data_c(), state->dim);
			}
#else
			_update_func(this->_control_qubit_list[0].index(), this->_target_qubit_list[0].index(), state->data_c(), state->dim);
#endif
		}
		else {
			_update_func_dm(this->_control_qubit_list[0].index(), this->_target_qubit_list[0].index(), state->data_c(), state->dim);
		}
    };
    /**
     * \~japanese-en 自身のディープコピーを生成する
     * 
     * @return 自身のディープコピー
     */
    virtual QuantumGateBase* copy() const override {
        return new QuantumGate_OneControlOneTarget(*this);
    };
    /**
     * \~japanese-en 自身のゲート行列をセットする
     * 
     * @param matrix 行列をセットする変数の参照
     */
    virtual void set_matrix(ComplexMatrix& matrix) const override {
        matrix = this->_matrix_element;
    }
};

/**
 * \~japanese-en 1量子ビットを対象とする回転ゲートのクラス
 */
class QuantumGate_OneQubitRotation : public QuantumGateBase{
protected:
	typedef void (T_UPDATE_FUNC)(UINT, double, CTYPE*, ITYPE);
	typedef void (T_GPU_UPDATE_FUNC)(UINT, double, void*, ITYPE, void*, UINT);
	T_UPDATE_FUNC* _update_func;
	T_UPDATE_FUNC* _update_func_dm;
	T_GPU_UPDATE_FUNC* _update_func_gpu;
    ComplexMatrix _matrix_element;
    double _angle;

    QuantumGate_OneQubitRotation(double angle) : _angle(angle) {};
public:
    /**
     * \~japanese-en 量子状態を更新する
     * 
     * @param state 更新する量子状態
     */
    virtual void update_quantum_state(QuantumStateBase* state) override{
		if (state->is_state_vector()) {
#ifdef _USE_GPU
			if (state->get_device_name() == "gpu") {
				_update_func_gpu(this->_target_qubit_list[0].index(), _angle, state->data(), state->dim, state->get_cuda_stream(), state->device_number);
            }
			else {
				_update_func(this->_target_qubit_list[0].index(), _angle, state->data_c(), state->dim);
			}
#else
			_update_func(this->_target_qubit_list[0].index(), _angle, state->data_c(), state->dim);
#endif
		}
		else {
			_update_func_dm(this->_target_qubit_list[0].index(), _angle, state->data_c(), state->dim);
		}
    };
    /**
     * \~japanese-en 自身のディープコピーを生成する
     * 
     * @return 自身のディープコピー
     */
    virtual QuantumGateBase* copy() const override{
        return new QuantumGate_OneQubitRotation(*this);
    };
    /**
     * \~japanese-en 自身のゲート行列をセットする
     * 
     * @param matrix 行列をセットする変数の参照
     */
    virtual void set_matrix(ComplexMatrix& matrix) const override {
        matrix = this->_matrix_element;
    }
};


