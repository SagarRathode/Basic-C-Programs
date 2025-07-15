#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAGAR RATHODE");
MODULE_DESCRIPTION("A Simple hello world Module");
MODULE_VERSION("0.01")
static int hello_init(void)
{
	
	printk(KERN_ALERT "TEST:HELLO WORLD\n");
	return 0;
}
static void hello_exit(void)
{
	printk(KERN_ALERT "TEST:GOOD BYE");
}
module_init(hello_init);
module_exit(hello_exit);
