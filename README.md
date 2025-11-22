# simple-video-processor

一个基于FFmpeg的C++命令行视频处理工具。这是我的在线学习项目，跟着教程一步步实现的，用于记录C++编程、外部工具集成和软件开发的实践过程。项目支持视频剪切、加密/解密、播放，并包括自定义日志系统和用户输入解析。

## ✨ 主要功能

- 🎬 **视频剪切**: 按时间范围裁剪视频
- 🔒 **视频加密/解密**: 使用AES-CTR加密保护视频内容
- ▶️ **视频播放**: 直接播放视频文件
- 📁 **批量处理**: 支持目录批量处理
- 📝 **日志系统**: 独立可复用的日志库

## 🏗️ 项目结构

```
simple-video-processor/
├── CMakeLists.txt          # CMake构建配置
├── README.md               # 本文件
├── CODE_REVIEW_CN.md      # 详细的代码审查和改进建议
├── config.example.json     # 配置文件示例
├── lib/                    # 编译输出的库文件
└── src/
    ├── xlog/              # 日志系统模块（可独立复用）
    ├── test_log/          # 日志测试程序
    └── xvideo_edit/       # 视频处理主程序
```

## 📋 依赖要求

- **C++编译器**: 支持C++17的编译器
  - GCC 7+ (Linux)
  - Clang 5+ (macOS)
  - MSVC 2017+ (Windows)
- **CMake**: 3.15 或更高版本
- **FFmpeg**: 需要在系统PATH中可用
  - [FFmpeg下载地址](https://ffmpeg.org/download.html)

## 🔧 编译指南

### Linux / macOS

```bash
# 克隆仓库（替换为实际的仓库URL）
git clone https://github.com/<OWNER>/simple-video-processor.git
cd simple-video-processor

# 创建构建目录
mkdir build && cd build

# 配置项目
cmake ..

# 编译
make

# 运行
./bin/xvideo_edit
```

### Windows (Visual Studio)

```bash
# 克隆仓库（替换为实际的仓库URL）
git clone https://github.com/<OWNER>/simple-video-processor.git
cd simple-video-processor

# 创建构建目录
mkdir build
cd build

# 配置项目 (使用Visual Studio 2019为例)
cmake .. -G "Visual Studio 16 2019"

# 编译
cmake --build . --config Release

# 运行
.\bin\Release\xvideo_edit.exe
```

### Windows (使用原有的Visual Studio项目)

直接打开 `src/xvideo_edit/xvideo_edit.sln` 或 `src/test_log/test_log.sln` 编译即可。

## 📖 使用说明

### 基本命令格式

启动程序后，会进入交互式命令行界面：

```bash
>>
```

### 命令说明

#### 1. 视频剪切 (cv - Cut Video)

```bash
>> cv -s 源文件 -d 目标文件 -b 开始秒 -e 结束秒
```

**示例**：
```bash
# 从第10秒到第20秒剪切视频
>> cv -s input.mp4 -d output.mp4 -b 10 -e 20
```

#### 2. 视频加密

```bash
>> cv -s 源文件 -d 目标文件 -p 密码
```

**示例**：
```bash
# 加密视频
>> cv -s input.mp4 -d encrypted.mp4 -p mypassword123
```

#### 3. 视频解密

```bash
>> cv -s 源文件 -d 目标文件 -dp 密码
```

**示例**：
```bash
# 解密视频
>> cv -s encrypted.mp4 -d decrypted.mp4 -dp mypassword123
```

#### 4. 视频播放

```bash
>> play -s 视频文件
```

**示例**：
```bash
# 播放视频
>> play -s video.mp4
```

#### 5. 批量处理

```bash
>> cv -s 源目录 -d 目标目录 [其他参数]
```

**示例**：
```bash
# 批量处理目录中的所有视频
>> cv -s ./videos -d ./output -b 5 -e 15
```

#### 6. 退出程序

```bash
>> exit
```

## 🎯 设计模式

项目采用了多种设计模式，展现良好的软件工程实践：

- **单例模式**: `LogFac` 日志工厂
- **工厂模式**: `XTaskFactory` 任务创建
- **策略模式**: `LogOutput`、`LogFormat` 日志输出和格式化
- **接口与实现分离**: `XTask` 接口和 `FFTask` 实现

## 📚 核心模块

### 1. 日志系统 (xlog)

独立的日志库，可以在其他项目中复用：

- 支持多种输出方式（控制台、文件）
- 支持多种日志级别（DEBUG、INFO、ERROR、FATAL）
- 线程安全的文件输出
- 可配置的日志格式

### 2. 视频处理 (xvideo_edit)

基于FFmpeg的视频处理模块：

- `XTask`: 任务接口
- `FFTask`: FFmpeg具体实现
- `XVideoInput`: 用户输入处理
- `XTaskFactory`: 任务工厂

### 3. 工具类

- `XExec`: 异步执行外部进程
- `UserInput`: 命令行参数解析
- `XDir`: 文件和目录操作

## ⚠️ 已知问题

详细的代码审查和改进建议请查看 [CODE_REVIEW_CN.md](CODE_REVIEW_CN.md)

主要问题：
1. ❌ `checkTime` 函数逻辑错误（已在审查文档中说明修复方法）
2. ❌ 密码读取变量错误（已在审查文档中说明修复方法）
3. ⚠️ 缺少详细的错误处理和验证
4. ⚠️ 硬编码的默认密钥
5. ⚠️ 平台特定的代码（但已提供CMake支持）

## 🔜 未来改进计划

- [ ] 修复已知的代码bug
- [ ] 改进错误处理机制
- [ ] 添加配置文件支持
- [ ] 支持更多视频处理功能
- [ ] 添加单元测试
- [ ] 改进文档和注释
- [ ] 支持GUI界面

## 📄 许可证

本项目是个人学习项目，仅供学习和参考使用。

## 🙏 致谢

- FFmpeg项目提供了强大的视频处理能力
- 感谢所有在学习过程中提供帮助的教程和资源

## 📮 联系方式

如有问题或建议，欢迎提Issue或Pull Request。

---

**注意**: 这是一个学习项目，视频加密功能仅供学习使用，不应用于生产环境的安全保护。
