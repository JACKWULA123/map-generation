# map-generation
a simple map generation algorithm with cellular automaton.
## Map 类:
    1.使用噪声函数初始化地图，目前完成的有：
        柏林噪声，基于https://github.com/Reputeless/PerlinNoise.git
    2.通过细胞自动机生成地图
    3.可视化的输出细胞自动机迭代过程，但是没有接入任何图形api，因为不会。
### 地图文件的格式：
    每次生成的地图会以当前时间命名，保存在/outputs目录下
    用txt凑活凑活的样子。
## 如何使用
    编译运行 main.cpp即可

