#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

#ifndef DEBUG
#define DEBUG
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAURABH");
MODULE_DESCRIPTION("HELLO WORLD!!!!");


static int __init init_mod(void)
{
#ifdef DEBUG
	pr_debug("%s:Begin\n", __func__);
#endif
	pr_info("HELLO WORLD\n");
#ifdef DEBUG
	pr_debug("%s:END\n", __func__);
#endif
	return 0;
}

static void __exit exit_mod(void)
{
#ifdef DEBUG
	pr_debug("%s:Begin\n", __func__);
#endif
	pr_info("BYE\n");
#ifdef DEBUG
	pr_debug("%s:END\n", __func__);
#endif
}

module_init(init_mod);
module_exit(exit_mod);
