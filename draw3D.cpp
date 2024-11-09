#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

// 4个控制点的3D坐标
GLfloat ctrlpoints[4][3] = {
    { -4, -4, 4 },
    { -2, 4, 1 },
    { 2, -4, 2 },
    { 4, 0, 0 }
};

// 用于存储旧的控制点位置
GLfloat old_ctrlpoints[4][3];

void init(void)
{
    // 背景色
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // 将控制点映射为参数t或u取值范围[0,1]的曲线
    // 参数1：GL_MAP1_VERTEX_3，表示3维顶点坐标
    // 参数2和3：控制t或u取值范围[0,1]
    // 参数4：3维坐标步长为3——曲线内插值步长
    // 参数5：曲线顶点数为4——顶点间隔为4
    // 参数6：二维数组首元素地址
    // 注意：若是后续在此设置中对ctrlpoints内容变更，曲线不变
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
    // 打开开关——允许3D控制点坐标到t或u取值的转换开关
    glEnable(GL_MAP1_VERTEX_3);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST); // 启用深度测试
}

void drawGrid() {
    glColor4f(0.5, 0.5, 0.5, 0.3); // 灰色网格线，带透明度
    glBegin(GL_LINES);
    for (int i = -5; i <= 5; i++) {
        glVertex3f(i, -5, 0);
        glVertex3f(i, 5, 0);
        glVertex3f(-5, i, 0);
        glVertex3f(5, i, 0);
    }
    glEnd();
}

void drawAxes() {
    glLineWidth(2.0);
    // X轴（红色）
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-5, 0, 0);
    glVertex3f(5, 0, 0);
    glEnd();
    // Y轴（绿色）
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0, -5, 0);
    glVertex3f(0, 5, 0);
    glEnd();
    // Z轴（蓝色）
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, -5);
    glVertex3f(0, 0, 5);
    glEnd();
}

// 3D空间中绘制Bezier曲线的效果
void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除颜色和深度缓冲区
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    // 绘制连续线段
    glBegin(GL_LINE_STRIP);
    // 参数t或u取值为i/30，共计31个点
    for (i = 0; i <= 30; i++)   // 根据4个控制点坐标的参数化插值
        glEvalCoord1f((GLfloat)i / 30.0);
    glEnd();
    /* 显示控制点 */
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (i = 0; i < 4; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();

    // 绘制旧的控制点位置以保留轨迹
    glPointSize(2.0);
    glColor3f(0.5, 0.5, 0.5); // 灰色轨迹
    glBegin(GL_POINTS);
    for (i = 0; i < 4; i++)
        glVertex3fv(&old_ctrlpoints[i][0]);
    glEnd();

    drawGrid(); // 绘制3D网格
    drawAxes(); // 绘制3D坐标轴

    glutSwapBuffers();
}

// 3D空间中绘制Bezier曲线的效果
void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0); // 透视投影矩阵

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0, // 眼睛位置
              0.0, 0.0, 0.0, // 观察目标位置
              0.0, 1.0, 0.0); // 上方向向量
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'x':
    case 'X':
    case 'y':
    case 'Y':
    case 'z':
    case 'Z':
    case 27: // ESC键
        exit(0);
        break;
    default:
        break;
    }
}

void updateControlPoints(int value) {
    // 动态更新控制点的位置，产生动画效果
    for (int t = 0; t < 4; t++) {
        for (int j = 0; j < 3; j++) {
            old_ctrlpoints[t][j] = ctrlpoints[t][j]; // 保存旧的控制点位置
            ctrlpoints[t][j] = (rand() % 1024 / 512.0 - 1) * 10; // 更新控制点位置
        }
    }
    // 动态映射
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
    glutPostRedisplay(); // 标记当前窗口需要重新绘制
    glutTimerFunc(1000, updateControlPoints, 0); // 设置定时器，每隔1秒调用一次updateControlPoints函数
}

int main(int argc, char** argv)
{
    srand((unsigned int)time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 使用双缓存模式和深度缓存
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("3D Bezier曲线");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000, updateControlPoints, 0); // 设置定时器，每隔1秒调用一次updateControlPoints函数
    glutMainLoop();
    return 0;
}
