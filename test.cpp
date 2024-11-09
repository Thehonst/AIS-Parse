#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Display *display;
    Window window;
    XEvent event;
    const char *msg = "hello, yxy, 2024"; // 修改这里
    int s;

    /* 与Xserver建立连接 */
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(display);

    /* 创建一个窗口 */
    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 500, 200, 1,
                                 BlackPixel(display, s), WhitePixel(display, s));

    const char* title = "yxy x11 window";
    XStoreName( display, window, title );
    XSetIconName( display, window, title );

    /* 选择一种感兴趣的事件进行监听 */
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    /* 显示窗口 */
    XMapWindow(display, window);

    /* 事件遍历 */
    for (;;)
    {
        XNextEvent(display, &event);

        /* 绘制窗口或者重新绘制 */
        if (event.type == Expose)
        {
            XFillRectangle(display, window, DefaultGC(display, s), 20, 20, 10, 10);
            XDrawString(display, window, DefaultGC(display, s), 50, 50, msg, strlen(msg));
        }
        /* 当检测到键盘按键,退出消息循环 */
        if (event.type == KeyPress)
            break;
    }

    /* 关闭与Xserver服务器的连接 */
    XCloseDisplay(display);

    return 0;
}
