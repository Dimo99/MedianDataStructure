#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MedianFindDataStructure/MedianDataStructure.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MedianDataStructureTests
{
	TEST_CLASS(MedianDataStructureCorrectBehaviour)
	{
	public:

		TEST_METHOD(WhenNoElementsAreInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Assert
			Assert::IsTrue(dataStructure.size() == 0);
		}

		TEST_METHOD(When_MaxHeapSizeIsEqualToMinHeapSize_And_SmallerThanMedianElementIsInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Act
			dataStructure.add(-10);

			// Assert
			Assert::IsTrue(dataStructure.size() == 1);
			Assert::IsTrue(dataStructure.getMedian() == -10);
		}

		TEST_METHOD(When_MaxHeapSizeIsLargerThanMinHeapSize_And_SmallerThanTheMedianElementIsInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Act
			dataStructure.add(-5);
			dataStructure.add(-15);

			// Assert
			Assert::IsTrue(dataStructure.size() == 2);
			Assert::IsTrue(dataStructure.getMedian() == -10);
		}

		TEST_METHOD(When_MaxHeapSizeIsSmallerThanMinHeapSize_And_SmallerThanTheMedianElementIsInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Act
			dataStructure.add(5);
			dataStructure.add(15);

			// Assert
			Assert::IsTrue(dataStructure.size() == 2);
			Assert::IsTrue(dataStructure.getMedian() == 10);
		}

		TEST_METHOD(When_MaxHeapSizeIsEqualToMinHeapSize_And_LargerThanMedianElementIsInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Act
			dataStructure.add(5);

			// Assert
			Assert::IsTrue(dataStructure.size() == 1);
			Assert::IsTrue(dataStructure.getMedian() == 5);
		}

		TEST_METHOD(When_MaxHeapSizeIsLargerMinHeapSize_And_LargerThanTheMedianElementIsInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Act
			dataStructure.add(-5);
			dataStructure.add(15);

			// Assert
			Assert::IsTrue(dataStructure.size() == 2);
			Assert::IsTrue(dataStructure.getMedian() == 5);
		}

		TEST_METHOD(When_MaxHeapSizeIsSmallerMinHeapSize_And_LargerThanTheMedianElementIsInserted)
		{
			// Arrange
			MedianDataStructure<double> dataStructure;

			// Act
			dataStructure.add(5);
			dataStructure.add(15);

			// Assert
			Assert::IsTrue(dataStructure.size() == 2);
			Assert::IsTrue(dataStructure.getMedian() == 10);
		}
	};
}