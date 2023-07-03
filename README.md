# ClassIn-Mover

You can find the download in the branch: Version Release 你可以在Version Release中找到发布的版本

Download Link 下载链接：https://github.com/PythonSmall-Q/ClassinMover/releases
## Propoganda 广告
开发者自制的一些加速器：
GitHub镜像:
seangithubproxy.eu.org
GitHub下载加速:
1. githubdown1.eu.org
2. githubdown2.eu.org
3. ghdownproxy.eu.org
  [为确保安全，部分地区登录网站时可能需要人机验证，点击灰色框即可]

### Service Monitor服务监控

实时监控：githubproxy.eu.org
问题发布：seanoj.edu.eu.org

### FAQ Email 客服邮箱

For Chinese Users, cn@seanoj.edu.eu.org
For English Users, en@seanoj.edu.eu.org
#Contact Admin 侵权举报
admin@seanoj.edu.eu.org

### About

A program to move `ClassIn` classroom window in order to exit from focused learning mode.

Supported `ClassIn` version: `3.0.2.130` to `5.0.2.42`, as well as newer versions. (`ClassIn` prior to `3.0.2.130` does not have focused learning mode at all)

Maybe the program will lose efficacy in the future versions.

## Usage

Run this program before entering the classroom, then get into the classroom as normal.

After that, the program will automatically detect the classroom window, and make it unable to occupy the whole screen.

If working well, the program should output one line of log each second, showing the current working status.

## Known issues

- **This program calls native API and thus can only work on Windows.**

- The patched classroom window will still be maximized, but you can place other windows above it or simply switch to another window.

- Occasionally the program will not work, please reopen `ClassIn` and this program.

- The program will only patch one classroom window if you open two or more at the same time.

  This is not a big matter, since few people need to login into multiple accounts at once.
