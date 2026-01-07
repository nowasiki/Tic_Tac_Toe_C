# 三子棋游戏

一个用 C 实现的三子棋游戏。

## 项目简介
- 开发环境：Visual Studio 2026
- 语言：C
- 项目类型：C语言游戏
- 主要功能：
  - 显示棋盘
  - 人机对战
  - 判定胜负
  - 自定义胜利棋子数
  - 自定义棋盘大小

这是我在大一学习C语言课程完成的实践项目，主要练习了：
- 函数传参
- JavaDoc风格的注释
- 通过循环寻找最长连续相同元素的字串
- 函数的输入内容的边界判定

## 运行截图

![主界面](images/main.png)

![对战部分](images/battle.png)

![主要代码展示](images/main_fuction.png)


## 如何运行项目
1. 确保安装 Visual Studio（推荐 2022 或以上社区版，免费）
2. 下载本仓库（点绿色的 Code → Download ZIP，或用 git clone）
3. 双击打开 `XXX.sln` 文件（解决方案文件）
4. 在 Visual Studio 中按 F5 运行（或 Ctrl + F5 无调试运行）

## 项目结构

本项目采用简单的目录结构，适合小型 C 语言游戏开发。主要源代码放在 Tic_Tac_Toe/ 子目录中，图片资源在 images/ 中，其他配置文件在根目录。以下是详细列表：

### 根目录文件
- **.gitattributes**：Git 属性文件，用于处理换行符等平台兼容性问题。
- **.gitignore**：Git 忽略文件，排除临时文件（如 .exe、.obj）以保持仓库干净。
- **README.md**：项目文档，包括简介、功能、运行方法和本结构描述。
- **Tic_Tac_Toe.slnx**：Visual Studio 解决方案文件，双击打开整个项目。
- **battle.png**：游戏运行截图，用于展示对战界面（例如，人机对弈过程）。

### 子目录
- **Tic_Tac_Toe/**：核心源代码和 Visual Studio 项目文件夹。
  - **Tic_Tac_Toe.vcxproj**：Visual Studio 项目文件，定义编译设置、源文件列表等。
  - **Tic_Tac_Toe.vcxproj.filters**：Visual Studio 文件过滤器，用于在 IDE 中组织文件视图。
  - **game.c**：游戏逻辑源文件，实现棋盘初始化、胜负判断、电脑 AI 下棋、步数记录、非法输入检测等核心功能。
  - **game.h**：头文件，定义函数原型、常量（如棋盘大小、胜利子数）和数据结构（如二维数组表示棋盘）。
  - **test.c**：测试源文件，包含单元测试或游戏调试代码，用于验证胜负逻辑和输入处理。

- **images/**：图片资源文件夹，包含游戏相关截图（最近添加了 3 张照片）。
  - 示例文件：battle.png 或类似（用于 README 演示或游戏文档），展示自定义棋盘、胜负结果等界面。

这个结构便于 Visual Studio 开发和 Git 管理。如果项目扩展（如添加多人模式），可以创建 src/ 子目录分离源代码，或 include/ 用于头文件。所有 C 文件均为纯 C 实现，无外部依赖。

## 个人信息
- 作者：曾祥龙
- 学校：宁波工程学院 统计与数据科学学院
- 专业：信息与计算科学
- 年级：2025级
- 邮箱：zengxianglong@nbut.edu.cn
- GitHub： https://github.com/nowasiki

> 欢迎 Star ⭐ 和 Fork！如果代码有问题或建议，欢迎提 Issue～

感谢查看我的项目！