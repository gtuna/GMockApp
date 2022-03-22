// GMockApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class IFeaCatDubler
{
public:
	IFeaCatDubler();
	virtual ~IFeaCatDubler();
	virtual void NullCheckFieldOfApplication() = 0;
};

class FeaCatDubler :IFeaCatDubler
{
public:
	void NullCheckFieldOfApplication() override;
};

void FeaCatDubler::NullCheckFieldOfApplication()
{
	std::cout << "NullCheckFieldOfApplication";
}


//example inspired from
//https://github.com/google/googletest/blob/main/docs/gmock_cook_book.md#mocking-class-templates
class MockFeatureCatalogue : public IFeaCatDubler
{
public:

	MOCK_METHOD(void, NullCheckFieldOfApplication, (), (override));
};

////gmock example
//TEST(MockTest, MockFeaCat)
//{
//	//FeatureCatalogue fc;
//	//fc.Read(L"../SampleData/S-101_FC.xml");
//
//	MockFeatureCatalogue mock_fea_cat;
//
//
//	EXPECT_CALL(mock_fea_cat, NullCheckFieldOfApplication);
//	mock_fea_cat.NullCheckFieldOfApplication();
//
//	ASSERT_EQ(false, false);
//
//}


//gtest example
TEST(TestG, sumTest)
{
	int a(0), b(1);

	EXPECT_EQ(1, (a + b));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}