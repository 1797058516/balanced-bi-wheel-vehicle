# balanced-bi-wheel-vehicle
尝试用cube来做一次项目，并且尝试用c++来解耦代码
# 遇到的问题  
1.用cube生成代码的时候名字要跟你创建的工程名字一样，并且cube选择生成文件位置是你文件的上一级目录。选择不对的话会照成cube生成的代码不能覆盖到clion；   
2.在clion创建新文件夹或者目录的时候不要勾选下面这个。勾选了cmake编译会失败，你删除cmakelist相关命令的时候可以编译但是烧录文件的时候会报错！  
![image](https://user-images.githubusercontent.com/58476906/177524810-154220d3-1251-4ff9-a848-30222b8bdda5.png)
3.所创建的头文件和文件夹需要在CMakeList.txt中添加头文件的目录。利用这两个命令增加include_directories();file();  
4.莫名bug：我先用cube初始化iic，然后编写完mpu6050的代码的时候，准备去cube初始化定时器的代码，生成的工程中MX_TIM3_Init();MX_TIM4_Init(); MX_TIM2_Init();这几个函数都是空发的函数！所以在cube初始化的时候就把所有的外设引脚先初始化好。  
