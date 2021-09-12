#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NGTU_InfSecur_Laba2/DesEncrypt.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DesEncryptTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		bitset<8> *Bitset8Generate(const size_t BitsetSize = 8)
		{
			bitset<8> *GeneratedBitset = new bitset<8>[BitsetSize];
			for (int ByteInd = 0; ByteInd < BitsetSize; ByteInd++)
			{
				GeneratedBitset[ByteInd] = rand() % (int)pow(2, 8);
			}
			return GeneratedBitset;
		}
		
		void BitSetArrayEqualCheck(bitset<8> *Expected, bitset<8> *Actual, const size_t ArraySize)
		{
			for (int ByteInd = 0; ByteInd < ArraySize; ByteInd++)
			{
				Assert::AreEqual(Expected[ByteInd].to_ulong(), Actual[ByteInd].to_ulong());
			}
		}

		TEST_METHOD(FitArrayTest)
		{
			size_t BlockSize = 8;
			size_t BitsetArraySize = 100;
			size_t FittedBitsetArraySize = BitsetArraySize;
			bitset<8> *InBitset = Bitset8Generate(BitsetArraySize);
			bitset<8> *FittedBitset = FitArray(InBitset, &FittedBitsetArraySize, BlockSize);
			BitSetArrayEqualCheck(InBitset, FittedBitset, BitsetArraySize);
			delete[] InBitset;
			delete[] FittedBitset;
		}
	};
}