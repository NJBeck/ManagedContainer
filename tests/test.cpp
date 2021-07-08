#include "ManagedContainer.h"
#include "gtest/gtest.h"



namespace{
    class IntContainerTest : public ::testing::Test {
        protected:
            void SetUp() override{
                for(int i = 0; i < count; ++i){
                    container_.insert(i, i);
                }

            }
            // void TearDown() override{}
            int count = 100000;
            ManagedContainer<int> container_;
    };

TEST_F(IntContainerTest, InsertTest){

    for(int i = 0; i < count; ++i){
        EXPECT_EQ(i, container_.get(i));
    }
}

TEST_F(IntContainerTest, EraseTest){
    for(int i = 0; i < count / 2 + 1; ++i){
        container_.erase(i);
    }
    for(int i = count / 2 + 1; i < count; ++i){
        EXPECT_EQ(i, container_.get(i));
    }
}

TEST_F(IntContainerTest, RefillTest){
    for(int i = 0; i < count; ++i){
        container_.erase(i);
    }
    for(int i = 0; i < count; ++i){
        container_.insert(i, i);
    }
    for(int i = 0; i < count; ++i){
        EXPECT_EQ(i, container_.get(i));
    }
}
}






int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}