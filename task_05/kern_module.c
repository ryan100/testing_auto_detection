#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAURABH");
MODULE_DESCRIPTION("HELLO WORLD!!!!");

static const struct usb_device_id id_table[] = {
	/*
	 * USB_INTERFACE_INFO(class, subclass, protocol)
	 */
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{}
};

MODULE_DEVICE_TABLE(usb, id_table);


static int __init init_mod(void)
{
	pr_info("HELLO WORLD\n");
	return 0;
}

static void __exit exit_mod(void)
{
	pr_info("BYE\n");
}

module_init(init_mod);
module_exit(exit_mod);
