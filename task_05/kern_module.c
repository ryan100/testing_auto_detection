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
static struct usb_device_id hello_id_table[] = { 
	{USB_INTERFACE_INFO 
	(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
	USB_INTERFACE_PROTOCOL_KEYBOARD)}, {} /* Terminating entry */ 
};

MODULE_DEVICE_TABLE(usb, hello_id_table);

static int hello_probe(struct usb_interface *interface,
	const struct usb_device_id *id) 
{
	return 0;
}

static void hello_disconnect(struct usb_interface *interface) 
{
	return 0;
}

static struct usb_driver hello_driver = {
	.name = "hello_driver",
	.probe = hello_probe,
	.disconnect = hello_disconnect,
	.id_table = hello_id_table 
};

static int __init init_mod(void) 
{
#ifdef DEBUG
	printk(KERN_DEBUG "%s:Begin\n", __func__);
#endif
	printk(KERN_DEBUG "HELLO WORLD\n");
#ifdef DEBUG
	printk(KERN_DEBUG "%s:END\n", __func__);
#endif
	return 0;
}

static void __exit exit_mod(void) 
{
#ifdef DEBUG
	printk(KERN_DEBUG "%s:Begin\n", __func__);
#endif
	printk(KERN_DEBUG "BYE\n");
#ifdef DEBUG
	printk(KERN_DEBUG "%s:END\n", __func__);
#endif
}

module_init(init_mod);
module_exit(exit_mod);
