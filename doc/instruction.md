| instruction | bit7-bit4 | bit3-bit0 | C | SEL_B | SEL_A | #LOAD0 | #LOAD1 | #LOAD2 | #LOAD3 
|:------------|:---------:|:----------|:-:|:------:|:-----:|:-----:|:------:|:------:|:------:|
|ADD A, Im    |0000       |Im         |X  |   L    |   L   |   L   |   H    |   H   |   H    |
|MOV A, B     |0001       |0000       |X  |   L    |   H   |   L   |   H    |   H   |   H    |
|IN  A        |0010       |0000       |X  |   H    |   L   |   L   |   H    |   H   |   H    |
|MOV A, Im    |0011       |Im         |X  |   H    |   H   |   L   |   H    |   H   |   H    |
|MOV B, A     |0100       |0000       |X  |   L    |   L   |   H   |   L    |   H   |   H    |
|ADD B, Im    |0101       |Im         |X  |   L    |   H   |   H   |   L    |   H   |   H    |
|IN  B        |0110       |0000       |X  |   H    |   L   |   H   |   L    |   H   |   H    |
|MOV B, Im    |0111       |Im         |X  |   H    |   H   |   H   |   L    |   H   |   H    |
|OUT B        |1001       |0000       |X  |   L    |   H   |   H   |   H    |   L   |   H    |
|OUT Im       |1011       |Im         |X  |   H    |   H   |   H   |   H    |   L   |   H    |
|JZ  Im       |1110       |Im         |L  |   H    |   H   |   H   |   H    |   H   |   L    |
|JZ  Im       |1110       |Im         |H  |   X    |   X   |   H   |   H    |   H   |   H    |
|JMP Im       |1111       |Im         |X  |   H    |   H   |   H   |   H    |   H   |   L    |

说明: SEL_B SEL_A 信号用于选择ALU的数据源，#LOAD0-#LOAD3则用于选择ALU的数据终点，说的官方一点，就是  
分别用于控制指令的源操作数和目的操作数。