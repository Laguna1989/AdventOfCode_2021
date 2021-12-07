#include "implementation.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(ImplementationTest, IsThisWorking)
{
	ASSERT_EQ(answer(), 42);
}

