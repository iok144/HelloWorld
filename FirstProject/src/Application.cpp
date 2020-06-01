#include <GLFW/glfw3.h>

void Move(GLfloat& number, bool& addNumber);
void AddNumber(GLfloat& number);
void SubNumber(GLfloat& number);

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	GLfloat aVertice[2] = { -0.5f, -0.5f };
	GLfloat bVertice[2] = { 0, 0.5f };
	GLfloat cVertice[2] = { 0.5f, -0.5f };

	bool moveAPositive[2] = { true, true };
	bool moveBPositive[2] = { true, true };
	bool moveCPositive[2] = { true, true };

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(aVertice[0], aVertice[1]);
		glVertex2f(bVertice[0], bVertice[1]);
		glVertex2f(cVertice[0], cVertice[1]);

		Move(aVertice[0], moveAPositive[0]);
		Move(aVertice[1], moveAPositive[1]);
		Move(bVertice[0], moveBPositive[0]);
		Move(bVertice[1], moveBPositive[1]);
		Move(cVertice[0], moveCPositive[0]);
		Move(cVertice[1], moveCPositive[1]);

		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void Move(GLfloat& coordinate, bool &increaseCoordinate)
{
	if (coordinate >= 1.0f)
	{
		increaseCoordinate = false;
	}

	if (coordinate <= -1.0f)
	{
		increaseCoordinate = true;
	}

	if (increaseCoordinate)
	{
		coordinate += 0.01f;
	}
	else
	{
		coordinate -= 0.01f;
	}
}