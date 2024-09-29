#pragma once
#include <gtest/gtest.h>
#include "SequentialContainer.h"  
#include "ListContainer.h"       


// Тесты для SequentialContainer
TEST(SequentialContainerTest, CreateEmptyContainer) {
    SequentialContainer container;
    EXPECT_EQ(container.size(), 0);
}

TEST(SequentialContainerTest, PushBackElements) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    EXPECT_EQ(container.size(), 2);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
}

TEST(SequentialContainerTest, InsertAtBeginning) {
    SequentialContainer container;
    container.push_back(2);
    container.insert(0, 1);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
}

TEST(SequentialContainerTest, InsertInMiddle) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(3);
    container.insert(1, 2);
    EXPECT_EQ(container[1], 2);
}

TEST(SequentialContainerTest, InsertAtEnd) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.insert(2, 3);
    EXPECT_EQ(container[2], 3);
}

TEST(SequentialContainerTest, EraseFromBeginning) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(0);
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 2);
}

TEST(SequentialContainerTest, EraseFromMiddle) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.erase(1);
    EXPECT_EQ(container[1], 3);
}

TEST(SequentialContainerTest, EraseFromEnd) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(1);
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 1);
}

TEST(SequentialContainerTest, AccessElements) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
}

TEST(SequentialContainerTest, GetSize) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    EXPECT_EQ(container.size(), 2);
}

// Тесты для ListContainer
TEST(ListContainerTest, CreateEmptyContainer) {
    ListContainer container;
    EXPECT_EQ(container.size(), 0);
}

TEST(ListContainerTest, PushBackElements) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    EXPECT_EQ(container.size(), 2);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
}

TEST(ListContainerTest, InsertAtBeginning) {
    ListContainer container;
    container.push_back(2);
    container.insert(0, 1);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
}

TEST(ListContainerTest, InsertInMiddle) {
    ListContainer container;
    container.push_back(1);
    container.push_back(3);
    container.insert(1, 2);
    EXPECT_EQ(container[1], 2);
}

TEST(ListContainerTest, InsertAtEnd) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    container.insert(2, 3);
    EXPECT_EQ(container[2], 3);
}

TEST(ListContainerTest, EraseFromBeginning) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(0);
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 2);
}

TEST(ListContainerTest, EraseFromMiddle) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.erase(1);
    EXPECT_EQ(container[1], 3);
}

TEST(ListContainerTest, EraseFromEnd) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(1);
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 1);
}

TEST(ListContainerTest, AccessElements) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
}

TEST(ListContainerTest, GetSize) {
    ListContainer container;
    container.push_back(1);
    container.push_back(2);
    EXPECT_EQ(container.size(), 2);
}

