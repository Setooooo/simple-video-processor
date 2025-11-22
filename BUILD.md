# 构建指南

本文档提供了在不同平台上构建 simple-video-processor 的详细说明。

## 目录

- [系统要求](#系统要求)
- [依赖安装](#依赖安装)
- [使用CMake构建](#使用cmake构建)
- [使用Visual Studio构建](#使用visual-studio构建)
- [常见问题](#常见问题)

## 系统要求

### 编译器要求

项目需要支持 **C++17** 标准的编译器：

| 平台 | 推荐编译器 | 最低版本 |
|------|-----------|---------|
| Linux | GCC | 7.0+ |
| Linux | Clang | 5.0+ |
| macOS | Apple Clang | 10.0+ |
| Windows | MSVC | 2017 (15.0)+ |

### 构建工具

- **CMake**: 3.15 或更高版本
- **Make** (Linux/macOS) 或 **MSBuild** (Windows)

### 运行时依赖

- **FFmpeg**: 必须安装并在系统 PATH 中
  - `ffmpeg` 用于视频处理
  - `ffplay` 用于视频播放

## 依赖安装

### Windows

#### 1. 安装 Visual Studio

从 [Visual Studio 官网](https://visualstudio.microsoft.com/) 下载并安装：
- Visual Studio 2017 或更高版本
- 确保选择 "使用C++的桌面开发" 工作负载

#### 2. 安装 CMake

- 从 [CMake 官网](https://cmake.org/download/) 下载安装包
- 安装时选择 "Add CMake to system PATH"

#### 3. 安装 FFmpeg

**方法1: 使用 Chocolatey (推荐)**
```powershell
choco install ffmpeg
```

**方法2: 手动安装**
1. 从 [FFmpeg 官网](https://ffmpeg.org/download.html#build-windows) 下载
2. 解压到目录，例如 `C:\ffmpeg`
3. 添加 `C:\ffmpeg\bin` 到系统 PATH

**验证安装**：
```bash
ffmpeg -version
```

### Linux (Ubuntu/Debian)

```bash
# 安装编译器和构建工具
sudo apt update
sudo apt install -y build-essential cmake

# 安装 FFmpeg
sudo apt install -y ffmpeg

# 验证安装
gcc --version
cmake --version
ffmpeg -version
```

### Linux (CentOS/RHEL)

```bash
# 安装编译器和构建工具
sudo yum groupinstall "Development Tools"
sudo yum install cmake

# 安装 FFmpeg
sudo yum install epel-release
sudo yum install ffmpeg ffmpeg-devel

# 或者使用 RPM Fusion
sudo yum localinstall --nogpgcheck https://download1.rpmfusion.org/free/el/rpmfusion-free-release-7.noarch.rpm
sudo yum install ffmpeg ffmpeg-devel
```

### macOS

```bash
# 安装 Homebrew (如果尚未安装)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# 安装 CMake 和 FFmpeg
brew install cmake ffmpeg

# 验证安装
clang --version
cmake --version
ffmpeg -version
```

## 使用CMake构建

### 基本构建步骤

```bash
# 1. 克隆仓库（替换为实际的仓库URL）
git clone https://github.com/<OWNER>/simple-video-processor.git
cd simple-video-processor

# 2. 创建构建目录
mkdir build
cd build

# 3. 配置项目
cmake ..

# 4. 编译
cmake --build .

# 5. 运行
./bin/xvideo_edit  # Linux/macOS
.\bin\Debug\xvideo_edit.exe  # Windows
```

### 指定构建类型

```bash
# Debug 构建（包含调试信息）
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

# Release 构建（优化性能）
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

### Windows 特定选项

```bash
# 使用 Visual Studio 2019
cmake .. -G "Visual Studio 16 2019"

# 使用 Visual Studio 2022
cmake .. -G "Visual Studio 17 2022"

# 指定 64 位
cmake .. -G "Visual Studio 16 2019" -A x64

# 编译 Release 版本
cmake --build . --config Release
```

### 可选构建选项

```bash
# 启用测试（未来功能）
cmake .. -DBUILD_TESTS=ON

# 自定义安装路径
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
```

### 安装

```bash
# 安装到系统目录
sudo cmake --install .

# 或指定安装路径
cmake --install . --prefix /opt/video-processor
```

## 使用Visual Studio构建

如果您更喜欢使用 Visual Studio 的图形界面：

### 方法1: 直接打开现有项目

1. 打开 Visual Studio
2. 选择 "文件" → "打开" → "项目/解决方案"
3. 导航到项目目录：
   - `src/xvideo_edit/xvideo_edit.sln` - 视频处理程序
   - `src/test_log/test_log.sln` - 日志测试程序
4. 选择构建配置（Debug 或 Release）
5. 按 `F7` 或点击 "生成" → "生成解决方案"

### 方法2: 使用CMake生成Visual Studio项目

```bash
# 在项目根目录
mkdir build
cd build

# 生成 Visual Studio 解决方案
cmake .. -G "Visual Studio 16 2019"

# 打开生成的 .sln 文件
start SimpleVideoProcessor.sln
```

然后在 Visual Studio 中构建。

## 构建输出

成功构建后，您将获得以下文件：

```
build/
├── bin/
│   ├── xvideo_edit[.exe]    # 主程序
│   └── test_log[.exe]       # 测试程序
└── lib/
    └── xlog.[dll|so|dylib]  # 日志库
```

## 常见问题

### 问题1: CMake 找不到编译器

**错误信息**：
```
CMake Error: CMAKE_C_COMPILER not set
```

**解决方法**：
- Windows: 确保安装了 Visual Studio 并包含 C++ 工具
- Linux: 安装 `build-essential`
- macOS: 安装 Xcode Command Line Tools: `xcode-select --install`

### 问题2: FFmpeg 未找到

**错误信息**：
```
'ffmpeg' is not recognized as an internal or external command
```

**解决方法**：
1. 确认 FFmpeg 已安装
2. 将 FFmpeg 的 bin 目录添加到系统 PATH
3. 重启终端或命令提示符

**验证**：
```bash
ffmpeg -version
```

### 问题3: 编译时出现C++17错误

**错误信息**：
```
error: 'filesystem' is not a member of 'std'
```

**解决方法**：
- 确保使用支持 C++17 的编译器版本
- GCC: 7.0+
- Clang: 5.0+
- MSVC: 2017+

### 问题4: Windows下找不到xlog.dll

**错误信息**：
```
无法启动此程序，因为计算机中丢失 xlog.dll
```

**解决方法**：
1. 将 `xlog.dll` 复制到 `xvideo_edit.exe` 所在目录
2. 或将 `lib` 目录添加到 PATH

```bash
# 在 build 目录中
copy lib\xlog.dll bin\Debug\
copy lib\xlog.dll bin\Release\
```

### 问题5: Linux下运行时找不到libxlog.so

**错误信息**：
```
error while loading shared libraries: libxlog.so
```

**解决方法**：

```bash
# 方法1: 设置 LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib

# 方法2: 安装到系统目录
sudo cmake --install .
sudo ldconfig
```

### 问题6: 权限错误

**Linux/macOS**：
```bash
# 给予执行权限
chmod +x bin/xvideo_edit
```

## 清理构建

```bash
# 删除构建目录
rm -rf build

# 或在构建目录中
cd build
make clean  # 或 cmake --build . --target clean
```

## 交叉编译

### Linux → Windows (使用 MinGW)

```bash
# 安装 MinGW
sudo apt install mingw-w64

# 配置
cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/mingw-w64.cmake

# 编译
cmake --build .
```

### macOS → iOS (示例)

```bash
cmake .. -G Xcode \
    -DCMAKE_SYSTEM_NAME=iOS \
    -DCMAKE_OSX_ARCHITECTURES=arm64

cmake --build .
```

## 性能优化构建

```bash
# 启用所有优化
cmake .. -DCMAKE_BUILD_TYPE=Release \
         -DCMAKE_CXX_FLAGS="-O3 -march=native"

# 或使用 RelWithDebInfo（Release + 调试信息）
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
```

## 开发者构建选项

```bash
# 启用详细输出
cmake .. -DCMAKE_VERBOSE_MAKEFILE=ON

# 生成编译命令数据库（用于IDE和工具）
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# 启用地址清理器（检测内存错误）
cmake .. -DCMAKE_CXX_FLAGS="-fsanitize=address -g"
```

## 获取帮助

如果您遇到其他构建问题：

1. 查看 [README.md](README.md) 中的项目说明
2. 查看 [CODE_REVIEW_CN.md](CODE_REVIEW_CN.md) 中的已知问题
3. 在 GitHub 上提交 Issue
4. 确保所有依赖都已正确安装

---

**提示**: 首次构建建议使用 Debug 模式以便于调试和学习代码。
