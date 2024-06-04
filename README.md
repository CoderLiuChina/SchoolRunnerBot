# SchoolRunnerBot
基于不想跑校园跑的摸鱼念头而设计的运载手机的小车

## 运行平台
基于STM32F030C8T6，使用STM32CubeMX设计，代码内容可移植至其它MCU
电机基于TB6612驱动板设计，采用10kHz PWM波
遥控部分基于串口USART1通讯，数据结构已在代码中给出，可进行扩展

## 功能
通过PWM波控制马达，进而驱动小车运动
可通过串口发送信息进行操控

## 运行数据
- 电机全功率运行时电流：约2A
- 电机驱动电压：DC12V
- MCU电压：3.3V

其他数据有待测试

## 引脚配置
开发使用STM32F030C8T6，电机驱动板TB6612，移植时请注意引脚分配，
- GPIO
    - AIN1: PB3
    - AIN2: PB4
    - BIN1: PB5
    - BIN2: PB6
- TIM
    - TIM3
        - PWM Generation CH1: PA6
        - PWM Generation CH2: PA7
- USART
    - USART1
        - Tx: PA9
        - Rx: PA10

## 中断配置
仅写出非默认优先级，默认优先级为0
- Time base: System tick timer: 3
- TIM3 global interrupt: 3
- USART1 global interrupt: 2

## 扩展开发相关
基于STM32CubeMX生成配置文件，使用HAL库编写单片机控制部分
主体编程语言为C，可使用Keil v5编辑