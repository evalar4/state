#include <gtest/gtest.h>
#include "../include/ForenoonState.h"
#include "../include/Work.h"

class ForenoonStateTest : public ::testing::Test {
protected:
    Work* work;
    ForenoonState* state;

    void SetUp() override {
        work = new Work();
        state = new ForenoonState();
    }

    void TearDown() override {
        delete work;
        delete state;
    }
};

TEST_F(ForenoonStateTest, NoonTime_TransitionsToNoonState) {
    work->setHour(12);
    testing::internal::CaptureStdout();
    state->writeProgram(work);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("after lunch") != std::string::npos);
}
