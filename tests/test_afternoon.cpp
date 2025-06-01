#include <gtest/gtest.h>
#include "../include/AfternoonState.h"
#include "../include/Work.h"

class AfternoonStateTest : public ::testing::Test {
protected:
    Work* work;
    AfternoonState* state;

    void SetUp() override {
        work = new Work();
        state = new AfternoonState();
    }

    void TearDown() override {
        delete work;
        delete state;
    }
};

TEST_F(AfternoonStateTest, EveningTime_NoOutput) {
    work->setHour(18);
    testing::internal::CaptureStdout();
    state->writeProgram(work);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}
