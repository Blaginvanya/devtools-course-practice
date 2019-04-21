// Copyright 2019 Konnov Sergey

#include <gtest/gtest.h>
#include "tree.h"

TEST(TreeTest, can_search_elem) {
    // Arrange
    int data = 1;
    Tree t;

    // Act
    t.Add(data);

    // Assert
    EXPECT_EQ(1, t.Search(data));
}

TEST(TreeTest, cant_find_nonexistent_elem) {
    // Arrange
    Tree t;

    // Act & Assert
    EXPECT_EQ(0, t.Search(4));
}

TEST(TreeTest, can_add_elem_multiple_times) {
    // Arrange
    int data = 1;
    Tree t;

    // Act
    t.Add(data);
    t.Add(data);
    t.Add(data);

    // Assert
    EXPECT_EQ(3, t.Search(data));
}

TEST(TreeTest, can_add_different_elems) {
    // Arrange
    int data1 = 1, data2 = 2, data3 = 3;

    // Act
    Tree t;
    t.Add(data2);
    t.Add(data1);
    t.Add(data3);

    // Assert
    EXPECT_EQ(1, t.Search(data3));
}

TEST(TreeTest, delete_nonexistent_tree_doesnt_throw) {
    // Arrange
    Tree t;

    // Act & Assert
    ASSERT_NO_THROW(t.Del(5));
}

TEST(TreeTest, can_delete_element) {
    // Arrange
    int data = 1;
    Tree t;

    // Act
    t.Add(data);
    t.Del(data);

    // Assert
    EXPECT_EQ(0, t.Search(data));
}

TEST(TreeTest, can_delete_element_that_was_added_several_times) {
     // Arrange
     int data = 1;
     Tree t;

     // Act
     t.Add(data);
     t.Add(data);
     t.Add(data);
     t.Del(data);
     EXPECT_EQ(0, t.Search(data));
}

TEST(TreeTest, is_empty_return_true_if_tree_is_empty) {
    // Arrange
    int data = 1;
    Tree t;

    // Act
    t.Add(data);
    t.Del(data);

    // Assert
    EXPECT_EQ(0, t.Search(data));
    EXPECT_EQ(true, t.IsEmpty());
}

TEST(TreeTest, is_empty_return_false_if_tree_is_not_empty) {
    // Arrange
    int data = 1;
    Tree t;

    // Act
    t.Add(data);

    // Assert
    EXPECT_EQ(false, t.IsEmpty());
}

TEST(TreeTest, can_clear_tree) {
    // Arrange
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    Tree t;

    // Act
    t.Add(data2);
    t.Add(data1);
    t.Add(data3);
    t.Clear();

    // Assert
    EXPECT_EQ(true, t.IsEmpty());
}

TEST(TreeTest, can_create_copy_of_tree) {
    // Arrange
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    Tree t1;

    // Act
    t1.Add(data3);
    Tree t2(t1);

    // Assert


    EXPECT_EQ(1, t2.Search(data3));
}

TEST(TreeTest, can_equate_tree_to_other_tree) {
    // Arrange
    int data3 = 3;
    int data4 = 4;
    Tree t1, t2;

    // Act
    t1.Add(data3);
    t2.Add(data4);
    t2 = t1;

    // Assert
    EXPECT_EQ(1, t2.Search(data3));
    EXPECT_EQ(0, t2.Search(data4));
}

TEST(TreeTest, copy_tree_has_its_own_memory) {
    // Arrange
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    Tree t1;

    // Act
    t1.Add(data1);
    t1.Add(data2);
    t1.Add(data3);
    Tree t2 = t1;
    t1.Del(data2);

    // Assert
    EXPECT_EQ(1, t2.Search(data2));
}

TEST(TreeTest, equated_tree_has_its_own_memory) {
    // Arrange
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    Tree t1, t2;

    // Act
    t1.Add(data1);
    t1.Add(data2);
    t1.Add(data3);
    t2 = t1;
    t1.Del(data2);

    // Assert
    EXPECT_EQ(1, t2.Search(data2));
}
