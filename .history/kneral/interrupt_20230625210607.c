#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/io.h>
#include </home/heige/source/include/printx.h>
#include </home/heige/source/include/screen.h>
struct idt idt[idt_size];//中断向量表
struct idt_point idt_point;//idtr指针
void* handles_point[idt_size];//处理函数指针集
extern unsigned int handle_table[idt_size];

static char *message[] = {
        "abcdefg",
        "opqrst"
    };
// char test[] = {"abcd"};
void set_error(int vector){

    print(message[vector]);
    
}

void task1(){
    // interrupt_disalow();
    // outb(0x70,0x8C);
    // inb(0x71);
    // interrupt_allow();
    //print("88888888888888 ");
    print("     task_1111111111111111     ");
    int i = 1000;
    asm volatile("movl $0x9000,%esp");
    while (i--)
    {
       
    }
   

    
    //asm volatile("int $0x29");
}
void task2(){
    // interrupt_disalow();
    // outb(0x70,0x8C);
    // inb(0x71);
    // interrupt_allow();

    //print("BH OOOP@@@@@@@@@@@@@@@@@ ");
    print("     task_22222222222222222      ");
    int i = 1000;
    while (i--)
    {
       
    }

    // outb(0x20,0x20);
    // outb(0xa0,0x20);
    //asm volatile("int $0x27");
}

void task3(){
    // interrupt_disalow();
    // outb(0x70,0x8C);
    // inb(0x71);
    // interrupt_allow();
    print("   task_333333333333333333    ");
}

void interrupt_allow(){
    asm volatile("sti");
}

//第10位为if位
//启用sti
//关闭cli
//1110中断门
//1111陷阱们
void interrupt_disalow(){
    asm volatile("cli");
}


char interrupt_getstate(){
    asm volatile("pushf \n "
                "pop %eax \n "
                "shrl $9,%eax \n"
                "addl $1,%eax");
}



void stop_interrupt(){
    outb(main_control_l,0b0010000);
    outb(slice_control_l,0b00100000);
}


void set_priority(char irq){
    if(irq>7){
        outb(slice_control_l,(0b01000000+irq-8));
    }
    else{
        outb(main_control_l,(0b01000000+irq));
    }

}

//初始化外中断
void init_control(){
    //初始化主控制器
    outb(main_control_l,0b00010001);//icw1xxxxxxxxxxxxx
    outb(main_control_h,0x20);//icw2
    outb(main_control_h,0b00000100);//icw3
    outb(main_control_h,0b00000011);//icw4xxxxxxxx
    outb(main_control_h,0b11111011);//屏蔽任何中断xxxxxxxxxxxxxxxxx
    //初始化片控制器
    outb(slice_control_l,0b00010001);//icw1xxxxxxxxxxxxxxxxxxxx
    outb(slice_control_h,0x28);//icw2xxxxxxxxxxxxxxxxx
    outb(slice_control_h,2);//icw3xxxxxxxxxxxxxxxxxxxxxxxxx
    outb(slice_control_h,0b00000011);//icw4xxxxxxxx
    outb(slice_control_h,0b11111110);//屏蔽任何中断xxxxxxxxxxxxxxxxxxx

}


void set_handles(int vector,int handles_address){

    handles_point[vector] = handles_address;
}



void init_idt(){
    int i = 0;
    for (;i<idt_size;i++){

    idt[i].keep0 = 0;
    idt[i].access = 0b10001110;
    idt[i].offset_l = handle_table[i];
    idt[i].selector = 1<<3;
    idt[i].offset_h =  (int)(((int)(handle_table[i])&0xffff0000)>>16);//(int)强制转换
    }
    idt_point.idt_address = &idt;
    idt_point.idt_sizes = sizeof(idt)-1;
    asm volatile("lidt idt_point \n");
    i=0;
    for (;i<idt_size;i++){
        handles_point[i] = &set_error;
    };  
    set_handles(0x27,&task1);
    set_handles(0x28,&task_change);//实时时钟中断处理函数

}


void init_interrupt(){
    init_control();
    init_idt();
};


