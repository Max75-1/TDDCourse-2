#include "Core.h"
#include "unity.h"
#include "cmock.h"
#include "mock_LED.h"
#include "Main.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Main_Should_InitializeTheLedDriver(void)
{
    LED_Init_Expect();
	TEST_ASSERT_EQUAL(0,TestableMain());
}

