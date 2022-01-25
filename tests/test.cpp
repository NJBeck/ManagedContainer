// TODO:    test for more types
//          test reference counting

#include "ManagedContainer.h"
#include "gtest/gtest.h"



namespace{
    class IntContainerTest : public ::testing::Test {
        protected:
            // void SetUp() override{}
            // void TearDown() override{}
            int count = 10000;
            ManagedContainer<int> container_;
            std::vector<size_t> indices_;
    };

TEST_F(IntContainerTest, SizeTest){
    for(int i = 0; i < count; ++i){
        container_.insert(i);
    }
    ASSERT_EQ(container_.size(), count);
}

TEST_F(IntContainerTest, InsertTest){
    for(int i = 0; i < count; ++i){
        indices_.push_back(container_.insert(i));
    }
    for(int i = 0; i < count; ++i){
        ASSERT_EQ(indices_[i], container_[i]);
    }
}

TEST_F(IntContainerTest, EraseTest){
    for(int i = 0; i < count; ++i){
        container_.insert(i);
    }
    for(int i = 0; i < count; ++i){
        container_.decrement_reference(i);
    }
    for(int i = 0; i < count; ++i){
        ASSERT_THROW(auto result = container_[i], std::out_of_range);
    }
    ASSERT_EQ(0, container_.size());
}

TEST_F(IntContainerTest, FillEraseRefillTest){
    for(int i = 0; i < count; ++i){
        container_.insert(i);
    }
    for(int i = 0; i < count; ++i){
        container_.decrement_reference(i);
    }
    for(int i = 0; i < count; ++i){
        indices_.emplace_back(container_.insert(i));
    }
    for (int i = 0; i < count; ++i) {
        ASSERT_EQ(i, container_[indices_[i]]);
    }
    
}

}






int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}