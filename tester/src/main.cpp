#include "pamsi_tester/Tester.hpp"
#include "spdlog/spdlog.h"
#include <fstream>
#include <numeric>
#include <vector>

/*
class SumTester : public Tester<int, std::vector<int>>
{
  protected:
    int runAlgorithm(const std::vector<int>& inputData) override;
    std::vector<int> readSingleInput(std::istream& inputStream) override;
};

int SumTester::runAlgorithm(const std::vector<int>& inputData)
{
    return std::accumulate(std::begin(inputData), std::end(inputData), 0,
                           std::plus<int>{});
}

std::vector<int> SumTester::readSingleInput(std::istream& inputStream)
{
    int numOfData = 0;

    inputStream >> numOfData;

    std::vector<int> result;
    result.reserve(numOfData);

    for(auto i = 0; i < numOfData; ++i)
    {
        int dataElement;
        inputStream >> dataElement;

        result.push_back(dataElement);
    }

    return result;
}
*/

struct Matrix
{
  int rowsNumber, columnsNumber;
  std::vector<float> data;
};

std::ostream& operator << (std::ostream& output, const Matrix& matrix)
{
    std::ostream_iterator<float> outIterator(output, " ");
    std::copy(matrix.data.begin(), matrix.data.end(), outIterator);
    return output;
}

struct MatrixSumInput
{
    Matrix first;
    Matrix second;
};

class MatrixSumTester: public Tester<Matrix, MatrixSumInput>
{
protected:
  Matrix runAlgorithm(const MatrixSumInput& inputData) override;
  MatrixSumInput readSingleInput(std::istream& inputStream) override;
};

Matrix MatrixSumTester::runAlgorithm(const MatrixSumInput& inputData)
{
  const auto rowsNumber = inputData.first.rowsNumber;
  const auto columnsNumber = inputData.first.columnsNumber;

  Matrix result;

  result.rowsNumber = rowsNumber;
  result.columnsNumber = columnsNumber;

  for(int i = 0; i < rowsNumber*columnsNumber; ++i)
    {
      result.data.push_back(inputData.first.data[i] + inputData.second.data[i]);
    }

  return result;
}

void readToMatrix(std::istream& inputStream, Matrix& matrix, int numOfElements)
{
  for(int i = 0; i < numOfElements; ++i)
    {
      float matrixElement = 0.f;
      inputStream >> matrixElement;

      matrix.data.push_back(matrixElement);
    }
}

MatrixSumInput MatrixSumTester::readSingleInput(std::istream& inputStream)
{
  int rowsNumber = 0, columnsNumber = 0;

  inputStream >> rowsNumber >> columnsNumber;

  MatrixSumInput input;

  input.first.rowsNumber = rowsNumber;
  input.second.rowsNumber = rowsNumber;
  input.first.columnsNumber = columnsNumber;
  input.second.columnsNumber = columnsNumber;

  readToMatrix(inputStream, input.first, rowsNumber*columnsNumber);
  readToMatrix(inputStream, input.second, rowsNumber*columnsNumber);

  return input;
}

int main(int /*argc*/, char* /*argv*/[])
{

    std::ifstream inputFile{"input.txt"};
    std::ofstream dataOutputFile{"output.txt"}, timeOutputFile{"times.csv"};

    MatrixSumTester tester;

    if(!inputFile)
    {
        spdlog::error("input.txt cannot be opened!");
        return -1;
    }

    tester.runAllTests(inputFile, dataOutputFile, timeOutputFile);
}
