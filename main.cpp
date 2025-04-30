#ifdef NDEBUG
#pragma comment(linker,"/entry:mainCRTStartup") 
#pragma comment(linker,"/subsystem:windows")
#endif

#include <iostream>
#include "GL/freeglut.h"
#include "Utility/Uti.h"
#include "./game.h"

// The width of the screen
unsigned int SCREEN_WITDTH = 500;

// The height of the screen
unsigned int SCREEN_HEIGHT = 650;

Game RacingGame(SCREEN_WITDTH, SCREEN_HEIGHT);

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	try
	{
		RacingGame.update();
		RacingGame.Render();
	}
	catch (const std::exception& e)
	{
		// 捕获标准异常
		std::cerr << "Exception caught in update: " << e.what() << std::endl;
	}


	glutSwapBuffers();
}

void spc_key(int key, int x, int y)
{
	RacingGame.ProcessInputSpec(key);
}

void processKeys(unsigned char key, int x, int y)
{
	RacingGame.ProcessInput(key);
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	Uti::aspect = (GLfloat)w / (GLfloat)h;

	if (Uti::aspect > 1.0f) {
		// 宽度大于高度，扩展宽度
		glOrtho(0, 100 * Uti::aspect, 0, 100, -1, 1);
	}
	else {
		// 高度大于宽度，扩展高度
		glOrtho(0, 100, 0, 100 / Uti::aspect, -1, 1);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void init()
{
	glClearColor(0.184, 0.310, 0.310, 1);
	glShadeModel(GL_SMOOTH);
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / RacingGame.FPS, timer, value);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WITDTH, SCREEN_HEIGHT);

	int width = glutGet(GLUT_SCREEN_WIDTH);
	int height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((width - SCREEN_WITDTH) / 2, (height - SCREEN_HEIGHT) / 2);
	glutCreateWindow("Car Raceing game");

	init();
	RacingGame.init();
	glutDisplayFunc(display);
	glutSpecialFunc(spc_key);
	glutKeyboardFunc(processKeys);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000, timer, 0);
	glutMainLoop();

	return 0;
}

