#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#ifndef DEBUG
#define DEBUG
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAURABH");
MODULE_DESCRIPTION("HELLO WORLD!!!!");


static int __init init_mod(void)
{
	#ifdef DEBUG
		printk(KERN_DEBUG"%s:Begin\n",__func__);
	#endif	
	
	printk(KERN_DEBUG"HELLO WORLD\n");
	
	#ifdef DEBUG
		printk(KERN_DEBUG"%s:END\n",__func__);
	#endif
	
	return 0;
}

static void __exit exit_mod(void)
{
	#ifdef DEBUG
		printk(KERN_DEBUG"%s:Begin\n",__func__);
	#endif	
	
	printk(KERN_DEBUG"BYE\n");
	
	#ifdef DEBUG
		printk(KERN_DEBUG"%s:END\n",__func__);
	#endif	
	
}		
module_init(init_mod);
module_exit(exit_mod);



