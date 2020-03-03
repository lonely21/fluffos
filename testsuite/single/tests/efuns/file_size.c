void do_tests() {
    string str = "This is a test";
    rm("/test_file");

    // no such file returns -1
    ASSERT_EQ(-1, file_size("/test_file"));

    write_file("/test_file", str);
    ASSERT(file_size("test_file") == strlen(str));

    ASSERT_EQ(strlen(read_file("/single/master.c")), file_size("/single/master.c"));

    // Directory returns -2
    ASSERT_EQ(-2, file_size("/single/tests"));
    ASSERT_EQ(-2, file_size("/single/tests/"));
}
