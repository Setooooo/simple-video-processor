# 贡献指南 / Contributing Guide

感谢您对 simple-video-processor 项目感兴趣！

Thank you for your interest in the simple-video-processor project!

[中文](#中文) | [English](#english)

---

## 中文

### 如何贡献

我们欢迎各种形式的贡献：

- 🐛 报告 Bug
- 💡 提出新功能建议
- 📝 改进文档
- 🔧 提交代码修复或新功能
- ✅ 添加测试用例
- 🌍 翻译文档

### 开始之前

1. **Fork 仓库**: 点击页面右上角的 "Fork" 按钮
2. **克隆你的 Fork**:
   ```bash
   git clone https://github.com/YOUR_USERNAME/simple-video-processor.git
   cd simple-video-processor
   ```
3. **添加上游仓库**:
   ```bash
   git remote add upstream https://github.com/Setooooo/simple-video-processor.git
   ```

### 开发流程

#### 1. 创建新分支

```bash
git checkout -b feature/your-feature-name
# 或
git checkout -b fix/bug-description
```

分支命名规范：
- `feature/` - 新功能
- `fix/` - Bug 修复
- `docs/` - 文档更新
- `refactor/` - 代码重构
- `test/` - 测试相关

#### 2. 进行修改

确保您的代码：
- ✅ 遵循项目的代码风格
- ✅ 包含适当的注释
- ✅ 通过现有测试（如果有）
- ✅ 添加新的测试（对于新功能）

#### 3. 提交更改

```bash
git add .
git commit -m "简短描述您的更改"
```

提交信息规范：
```
类型: 简短描述（不超过50字符）

详细描述（可选）：
- 为什么需要这个更改
- 如何解决问题
- 相关的 Issue 编号
```

提交类型：
- `feat`: 新功能
- `fix`: Bug 修复
- `docs`: 文档更新
- `style`: 代码格式（不影响功能）
- `refactor`: 代码重构
- `test`: 添加测试
- `chore`: 构建或辅助工具的变动

示例：
```
feat: 添加视频合并功能

实现了多个视频文件的合并功能，支持：
- 按顺序合并多个视频
- 保持原始视频的编码格式
- 自动处理不同分辨率的视频

Fixes #123
```

#### 4. 保持更新

```bash
git fetch upstream
git rebase upstream/main
```

#### 5. 推送到您的 Fork

```bash
git push origin feature/your-feature-name
```

#### 6. 创建 Pull Request

1. 访问您的 Fork 页面
2. 点击 "Pull Request" 按钮
3. 填写 PR 描述：
   - 说明更改的内容
   - 为什么需要这个更改
   - 如何测试
   - 相关的 Issue

### 代码规范

#### C++ 编码风格

```cpp
// 1. 类名使用 PascalCase
class VideoProcessor {
public:
    // 2. 公共方法使用 PascalCase
    bool ProcessVideo(const std::string& input);
    
    // 3. 成员变量使用 snake_case + 下划线后缀
private:
    int total_frames_;
    std::string output_path_;
};

// 4. 函数参数使用 snake_case
void ProcessFile(const std::string& file_name, int max_size);

// 5. 常量使用 UPPER_SNAKE_CASE
constexpr int MAX_BUFFER_SIZE = 1024;

// 6. 使用有意义的名称
// ❌ 不好
int n, x, temp;
// ✅ 好
int frame_count, video_width, buffer_size;
```

#### 注释规范

```cpp
/**
 * @brief 处理视频文件
 * @param input_path 输入视频文件路径
 * @param output_path 输出视频文件路径
 * @param options 处理选项
 * @return 成功返回 true，失败返回 false
 * @throws VideoException 当视频格式不支持时
 * 
 * 该函数会异步处理视频文件，可以通过 GetProgress() 
 * 查询处理进度。
 */
bool ProcessVideo(
    const std::string& input_path,
    const std::string& output_path,
    const ProcessOptions& options
);
```

#### 错误处理

```cpp
// 优先使用返回值
TaskResult result = ProcessVideo(input);
if (!result.IsSuccess()) {
    LOGERROR(result.error_message);
    return;
}

// 或使用异常（对于严重错误）
try {
    ProcessCriticalOperation();
} catch (const VideoException& e) {
    LOGERROR(std::string("Failed: ") + e.what());
    throw;
}
```

### 文档规范

- 使用 Markdown 格式
- 中英文之间添加空格（中文文档）
- 代码块指定语言
- 添加适当的标题层级
- 提供代码示例

### 测试

如果添加新功能，请包含测试：

```cpp
// tests/unit/video_processor_test.cpp
#include <gtest/gtest.h>
#include "video_processor.h"

TEST(VideoProcessorTest, BasicCutting) {
    VideoProcessor processor;
    TaskData data;
    data.src = "test_data/sample.mp4";
    data.des = "output/cut.mp4";
    data.begin_sec = 5;
    data.end_sec = 10;
    
    ASSERT_TRUE(processor.Process(data));
    // 验证输出...
}
```

### 代码审查

所有的 Pull Request 都需要经过审查。审查者会关注：

- ✅ 代码质量和可读性
- ✅ 是否符合项目风格
- ✅ 是否有适当的测试
- ✅ 是否更新了相关文档
- ✅ 是否有安全问题

### 报告问题

创建 Issue 时，请提供：

1. **问题描述**: 清晰描述问题
2. **重现步骤**: 如何重现问题
3. **期望行为**: 应该发生什么
4. **实际行为**: 实际发生了什么
5. **环境信息**: 
   - 操作系统
   - 编译器版本
   - FFmpeg 版本
6. **相关日志**: 如有错误信息，请提供

模板：
```markdown
## 问题描述
简短描述问题

## 重现步骤
1. 执行 '...'
2. 输入 '...'
3. 查看错误

## 期望行为
应该显示...

## 实际行为
实际显示...

## 环境
- OS: Windows 10
- Compiler: MSVC 2019
- FFmpeg: 4.4.0

## 日志
```
粘贴相关日志
```
```

### 提出功能建议

创建功能请求时，请说明：

1. **功能描述**: 您想要什么功能
2. **使用场景**: 为什么需要这个功能
3. **预期行为**: 功能应该如何工作
4. **替代方案**: 有哪些替代方案（可选）

### 优先处理的改进

参考 [CODE_REVIEW_CN.md](CODE_REVIEW_CN.md) 中标识的问题：

1. 🔴 **高优先级**:
   - 修复 `checkTime` 逻辑错误
   - 修复密码读取错误
   
2. 🟡 **中优先级**:
   - 改进错误处理
   - 删除重复代码
   - 添加单元测试
   
3. 🟢 **低优先级**:
   - 统一命名规范
   - 改进注释
   - 添加更多文档

### 社区准则

- 🤝 尊重他人
- 💬 友好交流
- 🎯 保持专业
- 📚 乐于学习和分享
- 🌟 支持新贡献者

### 许可证

贡献代码即表示您同意将代码按照项目许可证发布。

### 问题？

如有任何问题，欢迎：
- 📮 创建 Issue
- 💬 在 Discussions 中讨论
- 📧 联系维护者

---

## English

### How to Contribute

We welcome all kinds of contributions:

- 🐛 Bug reports
- 💡 Feature suggestions
- 📝 Documentation improvements
- 🔧 Code fixes or new features
- ✅ Test cases
- 🌍 Documentation translation

### Getting Started

1. **Fork the repository**: Click the "Fork" button at the top right
2. **Clone your fork**:
   ```bash
   git clone https://github.com/YOUR_USERNAME/simple-video-processor.git
   cd simple-video-processor
   ```
3. **Add upstream remote**:
   ```bash
   git remote add upstream https://github.com/Setooooo/simple-video-processor.git
   ```

### Development Workflow

#### 1. Create a Branch

```bash
git checkout -b feature/your-feature-name
# or
git checkout -b fix/bug-description
```

Branch naming:
- `feature/` - New features
- `fix/` - Bug fixes
- `docs/` - Documentation updates
- `refactor/` - Code refactoring
- `test/` - Test related

#### 2. Make Changes

Ensure your code:
- ✅ Follows project code style
- ✅ Includes appropriate comments
- ✅ Passes existing tests (if any)
- ✅ Adds new tests (for new features)

#### 3. Commit Changes

```bash
git add .
git commit -m "Brief description of your changes"
```

Commit message format:
```
type: Short description (max 50 chars)

Detailed description (optional):
- Why this change is needed
- How it solves the problem
- Related issue numbers
```

Commit types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation update
- `style`: Code formatting (no functional change)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Build or auxiliary tools

Example:
```
feat: Add video merge functionality

Implemented merging multiple video files with support for:
- Sequential merging of multiple videos
- Preserving original video encoding
- Auto-handling videos with different resolutions

Fixes #123
```

#### 4. Keep Updated

```bash
git fetch upstream
git rebase upstream/main
```

#### 5. Push to Your Fork

```bash
git push origin feature/your-feature-name
```

#### 6. Create Pull Request

1. Visit your fork page
2. Click "Pull Request" button
3. Fill in PR description:
   - What changes were made
   - Why this change is needed
   - How to test
   - Related issues

### Code Style

#### C++ Coding Style

```cpp
// 1. Class names use PascalCase
class VideoProcessor {
public:
    // 2. Public methods use PascalCase
    bool ProcessVideo(const std::string& input);
    
    // 3. Member variables use snake_case + trailing underscore
private:
    int total_frames_;
    std::string output_path_;
};

// 4. Function parameters use snake_case
void ProcessFile(const std::string& file_name, int max_size);

// 5. Constants use UPPER_SNAKE_CASE
constexpr int MAX_BUFFER_SIZE = 1024;

// 6. Use meaningful names
// ❌ Bad
int n, x, temp;
// ✅ Good
int frame_count, video_width, buffer_size;
```

### Testing

If adding new features, please include tests:

```cpp
// tests/unit/video_processor_test.cpp
#include <gtest/gtest.h>
#include "video_processor.h"

TEST(VideoProcessorTest, BasicCutting) {
    VideoProcessor processor;
    TaskData data;
    data.src = "test_data/sample.mp4";
    data.des = "output/cut.mp4";
    data.begin_sec = 5;
    data.end_sec = 10;
    
    ASSERT_TRUE(processor.Process(data));
    // Verify output...
}
```

### Code Review

All Pull Requests require review. Reviewers will check:

- ✅ Code quality and readability
- ✅ Adherence to project style
- ✅ Appropriate tests
- ✅ Updated documentation
- ✅ Security issues

### Reporting Issues

When creating an issue, please provide:

1. **Description**: Clear problem description
2. **Steps to Reproduce**: How to reproduce the issue
3. **Expected Behavior**: What should happen
4. **Actual Behavior**: What actually happens
5. **Environment**:
   - Operating System
   - Compiler version
   - FFmpeg version
6. **Logs**: Error messages if any

### Priority Improvements

Refer to issues identified in [CODE_REVIEW_CN.md](CODE_REVIEW_CN.md):

1. 🔴 **High Priority**:
   - Fix `checkTime` logic error
   - Fix password reading bug
   
2. 🟡 **Medium Priority**:
   - Improve error handling
   - Remove duplicate code
   - Add unit tests
   
3. 🟢 **Low Priority**:
   - Unify naming conventions
   - Improve comments
   - Add more documentation

### Community Guidelines

- 🤝 Respect others
- 💬 Friendly communication
- 🎯 Stay professional
- 📚 Eager to learn and share
- 🌟 Support new contributors

### License

By contributing, you agree that your contributions will be licensed under the project license.

### Questions?

Feel free to:
- 📮 Create an Issue
- 💬 Discuss in Discussions
- 📧 Contact maintainers

---

**Thank you for contributing to simple-video-processor! 🎉**
