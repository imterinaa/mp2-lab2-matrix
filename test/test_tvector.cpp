#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
TVector<int> v1(10);

ASSERT_NO_THROW(TVector<int> v2(v1));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
TVector<int> v1(10), v2(v1);

EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
TVector<int> v1(3);

v1[0] = 0;

TVector<int> v2(v1);

v1[0] = 1;

EXPECT_EQ(0, v2[0]);
}

TEST(TVector, can_get_size)
{
const int SIZE = 4;

TVector<int> v(SIZE);

EXPECT_EQ(SIZE, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
const int SIZE = 4, SI = 2;

TVector<int> v(SIZE, SI);

EXPECT_EQ(SI, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
TVector<int> v(4);
v[0] = 4;

EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
TVector<int> v(2);

ASSERT_ANY_THROW(v[-1] = 0);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
TVector<int> v(4, 2);

ASSERT_ANY_THROW(v[6] = 0);
}

TEST(TVector, can_assign_vector_to_itself)
{
TVector<int> v(3);

ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
TVector<int> v1(5), v2(5);

v2 = v1;

EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
const int SIZE1 = 5, SIZE2 = 3;

TVector<int> v1(SIZE1), v2(SIZE2);

v2 = v1;

EXPECT_EQ(SIZE1, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
const int SIZE1 = 5, SIZE2 = 3;

TVector<int> v1(SIZE1), v2(SIZE2);

v2 = v1;

EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
TVector<int> v1(5), v2(v1);

EXPECT_EQ(1, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
TVector<int> v(5);

EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
const int SIZE1 = 5, SIZE2 = 3;

TVector<int> v1(SIZE1), v2(SIZE2);

EXPECT_EQ(1, v1 != v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
const int SIZE = 5;

TVector<int> v1(SIZE), v2(SIZE);

for (int i = 0; i < v1.GetSize(); i++)
v1[i] = 1;

for (int i = 0; i < v2.GetSize(); i++)
v2[i] = 5;

v1 = v1 + 4;

EXPECT_EQ(v1, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
const int SIZE = 5;

TVector<int> v1(SIZE), v2(SIZE);

for (int i = 0; i < v1.GetSize(); i++)
v1[i] = 1;

for (int i = 0; i < v2.GetSize(); i++)
v2[i] = 5;

v2 = v2 - 4;

EXPECT_EQ(v1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
const int SIZE = 5;

TVector<int> v1(SIZE), v2(SIZE);

for (int i = 0; i < v1.GetSize(); i++)
v1[i] = 1;

for (int i = 0; i < v2.GetSize(); i++)
v2[i] = 5;

v1 = v1 * 5;

EXPECT_EQ(v1, v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
const int SIZE = 5;

TVector<int> v1(SIZE), v2(SIZE), v3(SIZE);

for (int i = 0; i < v1.GetSize(); i++)
v1[i] = 1;

for (int i = 0; i < v2.GetSize(); i++)
v2[i] = 5;

for (int i = 0; i < v3.GetSize(); i++)
v3[i] = 6;

EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
const int SIZE1 = 5, SIZE2 = 3;

TVector<int> v1(SIZE1), v2(SIZE2);

ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
const int SIZE = 5;

TVector<int> v1(SIZE), v2(SIZE), v3(SIZE);

for (int i = 0; i < v1.GetSize(); i++)
v1[i] = 1;

for (int i = 0; i < v2.GetSize(); i++)
v2[i] = 5;

for (int i = 0; i < v3.GetSize(); i++)
v3[i] = 4;

EXPECT_EQ(v3, v2 - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
const int SIZE1 = 5, SIZE2 = 3;

TVector<int> v1(SIZE1), v2(SIZE2);

ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
const int SIZE = 5;

TVector<int> v1(SIZE), v2(SIZE);

for (int i = 0; i < v1.GetSize(); i++)
v1[i] = 1;

for (int i = 0; i < v2.GetSize(); i++)
v2[i] = 5;

EXPECT_EQ(25, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
const int SIZE1 = 5, SIZE2 = 3;

TVector<int> v1(SIZE1), v2(SIZE2);

ASSERT_ANY_THROW(v1 * v2);
}