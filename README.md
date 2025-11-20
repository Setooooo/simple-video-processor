# Simple Video Processor

一个基于FFmpeg的C++命令行视频处理工具。这是我的在线学习项目，跟着教程一步步实现的，用于记录C++编程、外部工具集成和软件开发的实践过程。

## ✨ 功能特性

- 🎬 **视频剪切**: 精确剪切视频片段
- 🔒 **加密/解密**: 保护视频文件安全
- ▶️ **视频播放**: 内置播放器功能
- 📝 **日志系统**: 自定义日志记录
- ⚙️ **参数解析**: 灵活的命令行界面

## 🚀 快速开始

### 依赖要求

- C++17 或更高版本
- CMake 3.10+
- FFmpeg 库 (libavformat, libavcodec, libavutil)
- OpenSSL (用于加密功能)

### 安装依赖

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential cmake
sudo apt-get install libavformat-dev libavcodec-dev libavutil-dev libswscale-dev
sudo apt-get install libssl-dev
```

#### macOS
```bash
brew install cmake ffmpeg openssl
```

### 编译

```bash
# 克隆仓库
git clone https://github.com/Setooooo/simple-video-processor.git
cd simple-video-processor

# 创建构建目录
mkdir build && cd build

# 配置和编译
cmake ..
make

# 安装（可选）
sudo make install
```

## 📖 使用示例

```bash
# 剪切视频
./video_processor --cut --input video.mp4 --output output.mp4 --start 10 --end 60

# 加密视频
./video_processor --encrypt --input video.mp4 --output encrypted.dat --password mypassword

# 解密视频
./video_processor --decrypt --input encrypted.dat --output decrypted.mp4 --password mypassword

# 播放视频
./video_processor --play --input video.mp4

# 获取视频信息
./video_processor --info --input video.mp4
```

## 📁 项目结构

```
simple-video-processor/
├── include/          # 头文件
├── src/              # 源代码
├── tests/            # 测试代码
├── examples/         # 示例文件
├── docs/             # 文档
└── CMakeLists.txt    # 构建配置
```

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

## 📄 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件

## 📮 联系方式

- GitHub: [@Setooooo](https://github.com/Setooooo)

## 🙏 致谢

- FFmpeg 项目
- 所有贡献者

---

**注意**: 这是一个学习项目，代码可能还不够完善。欢迎提出改进建议！
