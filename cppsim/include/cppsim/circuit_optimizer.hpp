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

#include "type.hpp"

class QuantumCircuit;
class QuantumGateBase;
class QuantumGateMatrix;

/**
 * \~japanese-en 量子回路の圧縮を行うクラス
 * 
 * 量子回路の圧縮を行う。
 * 与えらえた量子回路を適切なサイズまで圧縮したり、まとめたゲートに変換するなどの処理を行う。
 */
class DllExport QuantumCircuitOptimizer{
private:
    QuantumCircuit* circuit;
    UINT get_rightmost_commute_index(UINT gate_index);
    UINT get_leftmost_commute_index(UINT gate_index);
    UINT get_merged_gate_size(UINT gate_index1, UINT gate_index2);
    bool is_neighboring(UINT gate_index1, UINT gate_index2);
public:
    /**
     * \~japanese-en コンストラクタ
     */
    QuantumCircuitOptimizer() {};

    /**
     * \~japanese-en デストラクタ
     */
    virtual ~QuantumCircuitOptimizer() {};

    /**
     * \~japanese-en 与えられた量子回路のゲートを指定されたブロックまで纏める。
     * 
     * 与えられた量子回路において、若い添え字から任意の二つのゲートを選び、二つが他のゲートに影響を与えず合成可能なら合成を行う。
     * これを合成可能なペアがなくなるまで繰り返す。
     * 二つのゲートが合成可能であるとは、二つのゲートそれぞれについて隣接するゲートとの交換を繰り返し、二つのゲートが隣接した位置まで移動できることを指す。
     * 
     * @param[in] circuit 量子回路のインスタンス
     * @param[in] max_block_size 合成後に許されるブロックの最大サイズ
     */
    void optimize(QuantumCircuit* circuit, UINT max_block_size=2);

	/**
	 * \~japanese-en 与えられた量子回路のゲートを指定されたブロックまで纏める。
	 *
	 * 与えられた量子回路において、若い添え字から任意の二つのゲートを選び、二つが他のゲートに影響を与えず合成可能なら合成を行う。
	 * これを合成可能なペアがなくなるまで繰り返す。
	 * 二つのゲートが合成可能であるとは、二つのゲートそれぞれについて隣接するゲートとの交換を繰り返し、二つのゲートが隣接した位置まで移動できることを指す。
	 *
	 * @param[in] circuit 量子回路のインスタンス
	 */
	void optimize_light(QuantumCircuit* circuit);

    /**
     * \~japanese-en 量子回路を纏めて一つの巨大な量子ゲートにする
     * 
     * @param[in] circuit 量子回路のインスタンス
     * @return 変換された量子ゲート
     */
    QuantumGateMatrix* merge_all(const QuantumCircuit* circuit);
};


