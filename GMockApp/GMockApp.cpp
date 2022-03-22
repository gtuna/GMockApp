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

//gmock example
TEST(MockTest, MockFeaCat)
{
	//FeatureCatalogue fc;
	//fc.Read(L"../SampleData/S-101_FC.xml");

	MockFeatureCatalogue mock_fea_cat;


	EXPECT_CALL(mock_fea_cat, NullCheckFieldOfApplication);
	mock_fea_cat.NullCheckFieldOfApplication();

	ASSERT_EQ(false, false);

}


//gtest example
TEST(TestG, sumTest)
{
	int a(0), b(1);

	ASSERT_EQ(1, (a + b));
}

int main()
{
	RUN_ALL_TESTS();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
