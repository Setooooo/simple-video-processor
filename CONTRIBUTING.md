# 贡献指南 (Contributing Guide)

感谢您对 simple-video-processor 项目的关注！我们欢迎所有形式的贡献。

## 如何贡献

### 报告 Bug

如果您发现了 bug，请创建一个 Issue 并包含以下信息：

1. 问题的详细描述
2. 重现步骤
3. 期望的行为
4. 实际的行为
5. 系统环境（操作系统、编译器版本等）
6. 相关日志或错误信息

### 提出新功能

如果您有新功能的想法：

1. 先创建一个 Issue 讨论该功能
2. 说明功能的用途和价值
3. 描述可能的实现方案

### 提交代码

1. **Fork 项目**
   ```bash
   # 在 GitHub 上 Fork 项目
   # 然后克隆您的 Fork
   git clone https://github.com/YOUR_USERNAME/simple-video-processor.git
   ```

2. **创建特性分支**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **编写代码**
   - 遵循项目的代码风格
   - 添加必要的注释
   - 确保代码可以通过编译
   - 添加测试（如果适用）

4. **提交更改**
   ```bash
   git add .
   git commit -m "Add: 简短描述您的更改"
   ```

5. **推送到您的 Fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **创建 Pull Request**
   - 在 GitHub 上创建 PR
   - 详细描述您的更改
   - 链接相关的 Issue（如果有）

## 代码规范

### C++ 代码风格

- 使用 4 个空格缩进（不使用 Tab）
- 类名使用 PascalCase：`VideoProcessor`
- 函数和变量使用 camelCase：`processVideo`, `videoFile`
- 常量使用 UPPER_SNAKE_CASE：`MAX_BUFFER_SIZE`
- 私有成员变量以下划线结尾：`formatContext_`

### 代码示例

```cpp
class VideoProcessor {
public:
    VideoProcessor();
    ~VideoProcessor();
    
    // 公共方法使用 camelCase
    bool cutVideo(const std::string& inputFile,
                  const std::string& outputFile,
                  double startTime,
                  double endTime);

private:
    // 私有成员以下划线结尾
    AVFormatContext* formatContext_;
    bool isInitialized_;
    
    // 私有辅助方法
    bool initializeContext();
};
```

### 注释规范

使用 Doxygen 风格的注释：

```cpp
/**
 * @brief 剪切视频文件
 * 
 * @param inputFile 输入视频文件路径
 * @param outputFile 输出视频文件路径
 * @param startTime 开始时间（秒）
 * @param endTime 结束时间（秒）
 * @return true 如果成功
 * @return false 如果失败
 */
bool cutVideo(const std::string& inputFile,
              const std::string& outputFile,
              double startTime,
              double endTime);
```

### 提交信息格式

使用清晰的提交信息：

```
类型: 简短描述（不超过 50 字符）

详细说明（如果需要）
- 更改的原因
- 主要变化
- 影响范围

相关 Issue: #123
```

**类型前缀**：
- `Add:` 添加新功能
- `Fix:` 修复 bug
- `Update:` 更新现有功能
- `Refactor:` 代码重构
- `Docs:` 文档更新
- `Test:` 测试相关
- `Style:` 代码风格调整
- `Perf:` 性能优化

## 测试

在提交 PR 之前，请确保：

1. 代码可以成功编译
2. 所有现有测试通过
3. 为新功能添加了测试
4. 代码没有内存泄漏（使用 valgrind 检查）

```bash
# 编译并运行测试
mkdir build && cd build
cmake ..
make
make test

# 使用 valgrind 检查内存泄漏
valgrind --leak-check=full ./video_processor
```

## 文档

如果您的更改影响了用户接口或添加了新功能，请同时更新：

- README.md
- API 文档
- 使用示例

## 开发环境设置

### 推荐工具

- **编辑器/IDE**: VS Code, CLion, Visual Studio
- **调试器**: GDB, LLDB
- **静态分析**: clang-tidy, cppcheck
- **格式化**: clang-format

### VS Code 配置示例

创建 `.vscode/settings.json`：

```json
{
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "cmake.configureOnOpen": true,
    "files.trimTrailingWhitespace": true,
    "editor.tabSize": 4,
    "editor.insertSpaces": true
}
```

## 代码审查流程

1. 提交 PR 后，维护者会进行代码审查
2. 根据反馈进行必要的修改
3. 一旦获得批准，您的代码将被合并

## 行为准则

- 尊重所有贡献者
- 保持友好和专业的态度
- 接受建设性的批评
- 关注项目的最佳利益

## 许可证

通过贡献代码，您同意您的贡献将在与项目相同的许可证下发布。

## 问题？

如果您有任何问题，请：

1. 查看现有的 Issues
2. 创建新的 Issue 询问
3. 联系项目维护者

---

再次感谢您的贡献！🎉
