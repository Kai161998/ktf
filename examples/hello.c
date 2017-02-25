#include <linux/module.h>
#include "ktf.h"

MODULE_LICENSE("GPL");

DECLARE_DEFAULT_HANDLE();

TEST(examples, hello_ok)
{
	EXPECT_TRUE(true);
}

TEST(examples, hello_fail)
{
	EXPECT_TRUE(false);
}


static void add_tests(void)
{
	ADD_TEST(hello_ok);
	ADD_TEST(hello_fail);
}


static int __init hello_init(void)
{
	add_tests();
	tlog(T_INFO, "hello: loaded\n");
	return 0;
}

static void __exit hello_exit(void)
{
	KTF_CLEANUP();
	tlog(T_INFO, "hello: unloaded\n");
}


module_init(hello_init);
module_exit(hello_exit);