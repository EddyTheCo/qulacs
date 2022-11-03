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
class ParametricQuantumCircuit;

/**
 * \~japanese-en 与えられた量子ビットの数に応じて量子回路を生成するアンザッツのクラス
 */
class QuantumCircuitBuilder {
private:
public:
    /**
     * \~japanese-en 量子回路を生成する
     * 
     * @param[in] qubit_count 量子ビット数
     * @return 生成された量子回路
     */
    virtual QuantumCircuit* create_circuit(UINT qubit_count) const = 0;
};

