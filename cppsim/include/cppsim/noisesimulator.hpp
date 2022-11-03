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


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "state.hpp"
#include "gate_factory.hpp"
#include "gate_merge.hpp"
#include "circuit.hpp"

/**
 * \~japanese-en 回路にDepolarizingNoiseを加えてサンプリングするクラス
 */

class DllExport NoiseSimulator{
	private:
		QuantumCircuit *circuit;
		QuantumStateBase *initial_state;
		
	public: 

		/**
		 * \~japanese-en
		 * コンストラクタ。
		 *
		 * NoiseSimulatorを作成する。
		 * @param[in] init_circuit  
		 * @param[in] prob ノイズが乗る確率
		 * @param[in] init_state 最初の状態。指定されなかった場合は0で初期化される。
		 * @return NoiseSimulatorのインスタンス
		 */
		NoiseSimulator(const QuantumCircuit *init_circuit,const double prob,const QuantumState *init_state = NULL);

		/**
		 * \~japanese-en
		 * デストラクタ。このとき、NoiseSimulatorが保持しているcircuitとinitial_stateは解放される。
		 */
		virtual ~NoiseSimulator();

		/**
		 * \~japanese-en
		 * 
		 * サンプリングを行い、結果を配列で返す。
		 * @param[in] sample_count 行うsamplingの回数
		 */
		virtual std::vector<UINT> execute(const UINT sample_count);
};