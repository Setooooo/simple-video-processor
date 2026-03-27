# simple-video-processor

一个基于 FFmpeg 的 C++ 命令行视频处理工具。这是我的在线学习项目，跟着教程一步步实现的，用于记录 C++ 编程、外部工具集成和软件开发的实践过程。项目支持视频剪切、加密/解密、播放，并包括自定义日志系统和用户输入解析。

## 项目结构

- `src/xlog`: 日志库和控制台输入、进程执行等基础能力
- `src/xvideo_edit`: 视频处理主程序
- `src/test_log`: 日志和输入模块的简单测试程序

## 构建

项目现在同时保留了 Visual Studio 工程和 `CMake` 构建方式。

### CMake

```powershell
cmake -S . -B build
cmake --build build --config Release
```

生成文件默认位于：

- 可执行文件: `build/bin/<Config>`
- 库文件: `build/lib/<Config>`

可选参数：

```powershell
cmake -S . -B build -DLESSON_CODE_BUILD_SHARED_XLOG=ON -DLESSON_CODE_BUILD_TEST_LOG=ON
```

## 运行说明

- 需要本机可直接调用 `ffmpeg` / `ffplay`
- 如果没有加入系统 `PATH`，当前版本会执行失败
- 推荐后续把 FFmpeg 路径做成配置项，而不是依赖全局环境
