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
#include <csim/type.h>
}
#else
#include <csim/type.h>
#endif

#include <complex>
#include <Eigen/Core>
#include <Eigen/Sparse>
typedef std::complex<double> CPPCTYPE;
typedef Eigen::VectorXcd ComplexVector;

// In order to use matrix raw-data without reordering, we use RowMajor as default.
typedef Eigen::Matrix<CPPCTYPE, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> ComplexMatrix;
typedef Eigen::SparseMatrix<CPPCTYPE> SparseComplexMatrix;

#ifdef __GNUC__
#if __GNUC__ >= 8
using namespace std::complex_literals;
#endif
#endif

#ifdef _MSC_VER
inline static FILE* popen(const char* command, const char* mode) { return _popen(command, mode); }
inline static void pclose(FILE* fp) { _pclose(fp);  }
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif


#if defined(__MINGW32__) || defined(_MSC_VER)
#define DllExport __declspec(dllexport)
#else
#define DllExport __attribute__((visibility ("default")))
#endif
