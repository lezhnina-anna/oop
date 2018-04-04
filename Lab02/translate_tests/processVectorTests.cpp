#include "stdafx.h"
#include "..\vector\ProcessVector.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	} 

	// не изменяет содержимое вектора, где min = max
	BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_with_same_numbers)
	{
		vector<double> numbers = { 4, 4, 4 };
		auto copy(numbers); // аналог vector<double> copy(numbers);
		ProcessVector(numbers);
		BOOST_CHECK(numbers == copy);
	}
	
	// при обработке вектора, где max = 0 
	BOOST_AUTO_TEST_SUITE(when_processing_a_vector_where_max_number_is_zero)
		// должна умножить все элементы на минимальный
		BOOST_AUTO_TEST_CASE(should_multiply_each_element_to_min_number)
		{
			vector<double> numbers = { -1, -0.5, 0 };
			const double min = -1;
			ProcessVector(numbers);

			BOOST_CHECK(VectorsAreEqual( numbers, 
				{ (-1 * min), (-0.5 * min), (0 * min) }
			));
		}
	BOOST_AUTO_TEST_SUITE_END()
		
	// при обработке вектора с положительными и отрицательными элементами
	BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_several_positive_elements_and_several_negative_elements)
		// должен добавить их среднее арифметическое к каждому элементу
		BOOST_AUTO_TEST_CASE(should_myltiply_each_element_to_min_and_divide_to_max)
		{
			vector<double> numbers = { -4, -2, 1, 2 };
			ProcessVector(numbers);

			const double min = -4;
			const double max = 2;
			BOOST_CHECK(VectorsAreEqual(numbers,
			{ (-4 * min / max), (-2 * min / max), (1 * min / max), (2 * min / max) }
			));
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


