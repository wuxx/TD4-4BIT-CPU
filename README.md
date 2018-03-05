#### 自己动手做CPU 之 TD4 前言 ####
#### 自己动手做CPU 之 TD4 原理分析0-系统综述 ####
#### 自己动手做CPU 之 TD4 原理分析1-[时钟、复位] ####
#### 自己动手做CPU 之 TD4 原理分析2-[存储器、输入、输出] ####
#### 自己动手做CPU 之 TD4 原理分析3-[控制器、运算器] ####
\#LOAD0 = D6 | D7  
\#LOAD1 = #D6 | D7  
\#LOAD2 = #(#D6 & D7)  
\#LOAD3 = #(D6 & D7 & (#C | D4))  
SEL_A   = D4 | D7  
SEL_B   = D5


#### 自己动手做CPU 之 TD4 PCB及元器件 ####
#### 自己动手做CPU 之 TD4 焊接测试0-说明 ####
A.  先焊接尺寸小，低的元器件，再焊接高的元器件，推荐焊接顺序如下:  
    1. 发光LED，二极管1N4148，直插电阻，USB接口。  
    2. IC插座  
    3. 8位拨码开关、4位拨码开关  
    4. 按键开关，电解电容，拨动开关  

B.  注意芯片插座，8位拨码开关和4位拨码开关的焊接方向  
#### 自己动手做CPU 之 TD4 焊接测试1-[焊接] ####
#### 自己动手做CPU 之 TD4 焊接测试2-[测试] ####

#### 自己动手做CPU 之 TD4 后记 ####

reference0:  
[指令格式](https://github.com/wuxx/TD4-4BIT-CPU/blob/master/doc/instruction.md)  
[TD4套件](https://item.taobao.com/item.htm?spm=a230r.1.14.1.207040ddEhBO68&id=565392942677&ns=1&abbucket=10#detail)

reference1:  
https://hackaday.io/project/8442-ttl-based-4-bit-cpu  
https://hackaday.io/project/26215-td4-cpu  
http://kamakurium.com/wp-content/uploads/2016/01/cpu_td4  
http://visual6502.org/  
http://www.4004.com/  
