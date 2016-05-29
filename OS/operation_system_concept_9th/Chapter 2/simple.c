#include <linux/init.h>
#include <linuxe/kernel.h>
#include <linux/module.h>

int simple_ini(void) {
  printk(KERN_INFO "Loading Module\n");
  return 0;
}

void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("puma");
