# 快速参考指南

## 命令速查表

### 基本命令

| 命令 | 说明 | 示例 |
|------|------|------|
| `cv` | 视频处理（剪切/加密） | `cv -s input.mp4 -d output.mp4` |
| `play` | 播放视频 | `play -s video.mp4` |
| `exit` | 退出程序 | `exit` |

### 参数选项

| 参数 | 说明 | 类型 | 示例 |
|------|------|------|------|
| `-s` | 源文件/目录 | string | `-s input.mp4` |
| `-d` | 目标文件/目录 | string | `-d output.mp4` |
| `-b` | 开始时间（秒） | int | `-b 10` |
| `-e` | 结束时间（秒） | int | `-e 20` |
| `-p` | 加密密码 | string | `-p mypassword` |
| `-dp` | 解密密码 | string | `-dp mypassword` |

## 使用场景

### 1. 视频剪辑

#### 剪切单个视频片段
```bash
>> cv -s input.mp4 -d output.mp4 -b 10 -e 30
```
说明：从第10秒到第30秒，提取20秒的视频片段

#### 从开始剪切
```bash
>> cv -s input.mp4 -d output.mp4 -e 15
```
说明：从开始到第15秒

#### 从某处到结尾
```bash
>> cv -s input.mp4 -d output.mp4 -b 10
```
说明：从第10秒到视频结尾

### 2. 视频格式转换

```bash
>> cv -s input.avi -d output.mp4
```
说明：将AVI转换为MP4格式（实际由FFmpeg处理）

### 3. 视频加密

#### 使用自定义密码加密
```bash
>> cv -s video.mp4 -d encrypted.mp4 -p MySecretPassword123
```

#### 使用默认密码加密
```bash
>> cv -s video.mp4 -d encrypted.mp4 -p
```
说明：如果不输入密码，将使用默认密钥

### 4. 视频解密

#### 使用密码解密
```bash
>> cv -s encrypted.mp4 -d decrypted.mp4 -dp MySecretPassword123
```

#### 交互式输入密码
```bash
>> cv -s encrypted.mp4 -d decrypted.mp4 -dp
```
说明：程序会提示输入密码

### 5. 批量处理

#### 批量剪切目录中的所有视频
```bash
>> cv -s ./videos -d ./output -b 5 -e 15
```
说明：处理 `./videos` 目录下的所有视频文件

#### 批量加密
```bash
>> cv -s ./videos -d ./encrypted -p mypassword
```

### 6. 视频播放

#### 播放本地视频
```bash
>> play -s movie.mp4
```

#### 播放剪切后的片段
```bash
>> play -s video.mp4 -b 10 -e 20
```
说明：播放第10秒到第20秒的片段

### 7. 组合操作

#### 剪切并加密
```bash
>> cv -s input.mp4 -d output.mp4 -b 10 -e 30 -p password123
```
说明：先剪切10-30秒，然后加密

#### 解密并剪切
```bash
>> cv -s encrypted.mp4 -d output.mp4 -dp password123 -b 5 -e 25
```
说明：先解密，然后剪切5-25秒

## 时间格式

程序内部使用秒为单位，但FFmpeg支持多种时间格式：

| 格式 | 示例 | 说明 |
|------|------|------|
| 秒 | `90` | 90秒 |
| 分:秒 | `01:30` | 1分30秒 |
| 时:分:秒 | `00:01:30` | 1分30秒 |

**注意**: 当前程序版本使用秒为单位输入。

## 支持的视频格式

理论上支持所有FFmpeg支持的格式，常见的包括：

- **容器格式**: MP4, AVI, MKV, MOV, FLV, WebM
- **视频编码**: H.264, H.265, VP8, VP9, MPEG-4
- **音频编码**: AAC, MP3, Opus, Vorbis

## 进度显示

处理视频时会显示进度：

```
% 45
```

显示当前处理进度为 45%

## 常见工作流程

### 工作流1: 从长视频提取精彩片段

```bash
>> cv -s long_video.mp4 -d clip1.mp4 -b 100 -e 120
% 100
>> cv -s long_video.mp4 -d clip2.mp4 -b 300 -e 350
% 100
>> play -s clip1.mp4
```

### 工作流2: 加密敏感视频

```bash
# 1. 剪切敏感片段
>> cv -s original.mp4 -d sensitive.mp4 -b 60 -e 120

# 2. 加密
>> cv -s sensitive.mp4 -d secure.mp4 -p MyStrongPassword

# 3. 验证（解密并播放）
>> cv -s secure.mp4 -d verify.mp4 -dp MyStrongPassword
>> play -s verify.mp4
```

### 工作流3: 批量视频预处理

```bash
# 假设有一批视频需要剪掉前5秒和后5秒
>> cv -s ./raw_videos -d ./processed -b 5 -e -5
```

## 错误处理

### 常见错误信息

| 错误 | 原因 | 解决方法 |
|------|------|----------|
| `File not found` | 源文件不存在 | 检查文件路径 |
| `ffmpeg not found` | FFmpeg未安装 | 安装FFmpeg并添加到PATH |
| `Invalid password` | 解密密码错误 | 使用正确的密码 |
| `Permission denied` | 无文件权限 | 检查文件权限 |

### 调试技巧

1. **查看详细命令**：程序会打印执行的FFmpeg命令
   ```
   cmd: ffmpeg -y -ss 10 -t 10 -i input.mp4 output.mp4
   ```

2. **手动测试FFmpeg命令**：复制打印的命令在终端中执行
   ```bash
   ffmpeg -y -ss 10 -t 10 -i input.mp4 output.mp4
   ```

3. **检查FFmpeg安装**：
   ```bash
   ffmpeg -version
   ffplay -version
   ```

## 性能提示

### 1. 避免重复编码

如果只是剪切，不要同时加密：
```bash
# 好：只剪切，不重新编码
>> cv -s input.mp4 -d output.mp4 -b 10 -e 20

# 慢：剪切+加密，需要重新编码
>> cv -s input.mp4 -d output.mp4 -b 10 -e 20 -p password
```

### 2. 批量处理时的注意事项

- 确保有足够的磁盘空间
- 大文件处理可能需要较长时间
- 可以先测试单个文件

### 3. 硬件加速

当前版本未启用硬件加速。如果需要，可以手动使用FFmpeg命令。

## 限制和已知问题

1. ❌ 时间输入只支持秒，不支持 `HH:MM:SS` 格式
2. ❌ 加密方案为学习用途，安全性有限
3. ❌ 不支持实时进度条，只有百分比
4. ❌ 批量处理时出错会停止整个任务
5. ⚠️ 密码硬编码有默认值（不安全）

详细问题请参考 [CODE_REVIEW_CN.md](CODE_REVIEW_CN.md)

## 快速示例汇总

```bash
# 启动程序
./xvideo_edit

# 1. 简单剪切
>> cv -s test.mp4 -d out.mp4 -b 10 -e 20

# 2. 播放
>> play -s out.mp4

# 3. 加密
>> cv -s test.mp4 -d enc.mp4 -p mypass

# 4. 解密
>> cv -s enc.mp4 -d dec.mp4 -dp mypass

# 5. 批量处理
>> cv -s ./videos -d ./output -b 0 -e 30

# 6. 退出
>> exit
```

## 获取帮助

- 📖 完整文档: [README.md](README.md)
- 🔧 构建指南: [BUILD.md](BUILD.md)
- 📝 代码审查: [CODE_REVIEW_CN.md](CODE_REVIEW_CN.md)
- 🐛 报告问题: GitHub Issues
- 💡 功能建议: GitHub Discussions

---

**提示**: 建议先用小文件测试命令，确认无误后再处理大文件。
