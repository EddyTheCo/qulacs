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
#include "type.hpp"

/**
 * \~japanese-en �s��v�f�Ŏ��g����p������e��ێ�����N���X
 */
class DllExport QuantumGateSparseMatrix : public QuantumGateBase {
private:
	SparseComplexMatrix _matrix_element;     /**< list of elements of unitary matrix as 1D array with length dim*dim (only for dense gate))*/
public:
	/**
	 * \~japanese-en �R���X�g���N�^
	 *
	 * �s��v�f�̓R�s�[����邽�߁Amatrix�͍ė��p�ł��邪�ᑬ�ł���
	 * @param target_qubit_index_list �^�[�Q�b�g�ƂȂ�ʎq�r�b�g�̓Y�����̃��X�g
	 * @param matrix_element �s��v�f
	 * @param control_qubit_index_list �R���g���[���ƂȂ�ʎq�r�b�g�̃��X�g <code>control_value</code>�͂��ׂ�1�ɂȂ�B
	 */
	QuantumGateSparseMatrix(const std::vector<UINT>& target_qubit_index_list, const SparseComplexMatrix& matrix_element, const std::vector<UINT>& control_qubit_index_list = {});

	/**
	 * \~japanese-en �R���X�g���N�^
	 *
	 * �s��v�f��swap����邽�߁Amatrix�͍ė��p�ł��Ȃ��������ł���B
	 * @param target_qubit_index_list �^�[�Q�b�g�ƂȂ�ʎq�r�b�g�̓Y�����̃��X�g
	 * @param matrix_element �s��v�f
	 * @param control_qubit_index_list �R���g���[���ƂȂ�ʎq�r�b�g�̃��X�g <code>control_value</code>�͂��ׂ�1�ɂȂ�B
	 */
	QuantumGateSparseMatrix(const std::vector<UINT>& target_qubit_index_list, SparseComplexMatrix* matrix_element, const std::vector<UINT>& control_qubit_index_list = {});

	/**
	 * \~japanese-en �R���X�g���N�^
	 *
	 * �s��v�f�̓R�s�[����邽�߁Amatrix�͍ė��p�ł��邪�ᑬ�ł���
	 * @param target_qubit_index_list �^�[�Q�b�g�ƂȂ�ʎq�r�b�g�̏��̃��X�g
	 * @param matrix_element �s��v�f
	 * @param control_qubit_index_list �R���g���[���ƂȂ�ʎq�r�b�g�̏��̃��X�g
	 */
	QuantumGateSparseMatrix(const std::vector<TargetQubitInfo>& target_qubit_index_list, const SparseComplexMatrix& matrix_element, const std::vector<ControlQubitInfo>& control_qubit_index_list = {});

	/**
	 * \~japanese-en �R���X�g���N�^
	 *
	 * �s��v�f��swap����邽�߁Amatrix�͍ė��p�ł��Ȃ��������ł���B
	 * @param target_qubit_index_list �^�[�Q�b�g�ƂȂ�ʎq�r�b�g�̏��̃��X�g
	 * @param matrix_element �s��v�f
	 * @param control_qubit_index_list �R���g���[���ƂȂ�ʎq�r�b�g�̏��̃��X�g
	 */
	QuantumGateSparseMatrix(const std::vector<TargetQubitInfo>& target_qubit_index_list, SparseComplexMatrix* matrix_element, const std::vector<ControlQubitInfo>& control_qubit_index_list = {});

	/**
	 * \~japanese-en �f�X�g���N�^
	 */
	virtual ~QuantumGateSparseMatrix() {};

	/**
	 * \~japanese-en �R���g���[���̗ʎq�r�b�g��ǉ�����
	 *
	 * <code>qubit_index</code>�̓Q�[�g�̃^�[�Q�b�g��R���g���[���̒l�Ɋ܂܂�Ă͂����Ȃ��B
	 * @param[in] qubit_index �R���g���[���̗ʎq�r�b�g�̓Y����
	 * @param[in] control_value ����<code>qubit_index</code>��<code>control_value</code>�ł���ꍇ�ɂ̂݃Q�[�g����p����B
	 */
	virtual void add_control_qubit(UINT qubit_index, UINT control_value);

	/**
	 * \~japanese-en �Q�[�g�s��ɃX�J���[�l��������
	 *
	 * @param[in] value ������l
	 */
	virtual void multiply_scalar(CPPCTYPE value) {
		_matrix_element *= value;
	}

	/**
	 * \~japanese-en �Q�[�g�̃v���p�e�B��ݒ肷��
	 *
	 * @param[in] gate_property_ �Q�[�g�̃v���p�e�B�l
	 */
	virtual void set_gate_property(UINT gate_property_) {
		_gate_property = gate_property_;
	}

	/**
	 * \~japanese-en �ʎq��Ԃɍ�p����
	 *
	 * @param[in,out] state �X�V����ʎq���
	 */
	virtual void update_quantum_state(QuantumStateBase* state) override;

	/**
	 * \~japanese-en ���g�̃R�s�[���쐬����
	 *
	 * @return �R�s�[���ꂽ�Q�[�g�̃C���X�^���X
	 */
	virtual QuantumGateBase* copy() const override {
		return new QuantumGateSparseMatrix(*this);
	};

	/**
	 * \~japanese-en ���g�̍s��v�f���Z�b�g����
	 *
	 * @param[out] matrix �s��v�f���Z�b�g����s��̎Q��
	 */
	virtual void set_matrix(ComplexMatrix& matrix) const override {
		matrix = this->_matrix_element.toDense();
	}

	/**
	 * \~japanese-en �ʎq��H�̃f�o�b�O���̕�����𐶐�����
	 *
	 * @return ��������������
	 */
	virtual std::string to_string() const override;

	/**
	 * \~japanese-en �Q�[�g�̏��𕶎���ŏo�͂���
	 *
	 * @param os �o�͂���X�g���[��
	 * @param gate ���̏o�͂��s���Q�[�g
	 * @return �󂯎�����X�g���[��
	 */
	friend DllExport std::ostream& operator<<(std::ostream& os, const QuantumGateSparseMatrix& gate);

	/**
	 * \~japanese-en �Q�[�g�̏��𕶎���ŏo�͂���
	 *
	 * @param os �o�͂���X�g���[��
	 * @param gate ���̏o�͂��s���Q�[�g
	 * @return �󂯎�����X�g���[��
	 */
	friend DllExport std::ostream& operator<<(std::ostream& os, QuantumGateSparseMatrix* gate);

};
