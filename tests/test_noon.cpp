#include <gtest/gtest.h>
#include "../include/NoonState.h"
#include "../include/Work.h"

class NoonStateTest : public ::testing::Test {
protected:
    Work* work;
    NoonState* state;

    void SetUp() override {
        work = new Work();
        state = new NoonState();
    }

    void TearDown() override {
        delete work;
        delete state;
    }
};

TEST_F(NoonStateTest, NoonTime_ShowsSleepyMessage) {
    work->setHour(12.5);
    testing::internal::CaptureStdout();
    state->writeProgram(work);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("feeling sleepy") == std::string::npos);
}
