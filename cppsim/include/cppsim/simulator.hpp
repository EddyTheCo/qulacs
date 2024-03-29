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

#include <cstdlib>
#include "type.hpp"
#include "circuit.hpp"
class QuantumStateBase;
class HermitianQuantumOperator;
typedef HermitianQuantumOperator Observable;


/**
 * \~japanese-en 量子回路をシミュレートするためのクラス
 */
class DllExport QuantumCircuitSimulator {
private:
    QuantumCircuit* _circuit;
    QuantumStateBase* _state;
    QuantumStateBase* _buffer;
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param circuit シミュレートする量子回路 
     * @param initial_state 初期量子状態。デフォルト値はNULLで、NULLの場合は0状態に初期化される。
     */
    QuantumCircuitSimulator(QuantumCircuit* circuit, QuantumStateBase* initial_state = NULL);

    /**
     * \~japanese-en デストラクタ
     */
    ~QuantumCircuitSimulator();

    /**
     * \~japanese-en 量子状態を計算基底に初期化する
     * 
     * @param computationl_basis 初期化する計算基底を二進数にした値
     */
    void initialize_state(ITYPE computationl_basis = 0);
    /**
     * \~japanese-en ランダムな量子状態に初期化する。
     */
    void initialize_random_state();

    /**
     * \~japanese-en 量子回路全体シミュレートする。
     */
    void simulate();

    /**
     * \~japanese-en 量子回路を<code>start</code>から<code>end</code>までの区間シミュレートする
     * 
     * @param start シミュレートを開始する添え字
     * @param end シミュレートを終了する添え字
     */
    void simulate_range(UINT start, UINT end);

    /**
     * \~japanese-en 現在の量子状態の受け取ったオブザーバブルの期待値を計算する。
     * 
     * @param observable オブザーバブル
     * @return 期待値
     */
    CPPCTYPE get_expectation_value(const Observable* observable);

    /**
     * \~japanese-en 量子回路中のゲートの数を取得する
     * 
     * @return ゲートの数
     */
    UINT get_gate_count();

    /**
     * \~japanese-en 量子状態をバッファへコピーする
     */
    void copy_state_to_buffer();
    /**
     * \~japanese-en バッファの量子状態を現在の量子状態へコピーする
     */
    void copy_state_from_buffer();
    /**
     * \~japanese-en 現在の量子状態をバッファと交換する
     */
    void swap_state_and_buffer();

    /**
     * \~japanese-en 現在の量子状態のポインタを取得する
     * 
     * @return 量子状態のポインタ
     */
    const QuantumStateBase* get_state_ptr() const { return _state; }
};


