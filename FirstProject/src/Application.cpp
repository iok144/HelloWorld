#include <GLFW/glfw3.h>

void PerformOperation(GLfloat& number, bool& addNumber);
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

	GLfloat a[2] = { -0.5f, -0.5f };
	GLfloat b[2] = { 0, 0.5f };
	GLfloat c[2] = { 0.5f, -0.5f };

	bool addA[2] = { true, true };
	bool addB[2] = { true, true };
	bool addC[2] = { true, true };

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(a[0], a[1]);
		glVertex2f(b[0], b[1]);
		glVertex2f(c[0], c[1]);

		PerformOperation(a[0], addA[0]);
		PerformOperation(a[1], addA[1]);
		PerformOperation(b[0], addB[0]);
		PerformOperation(b[1], addB[1]);
		PerformOperation(c[0], addC[0]);
		PerformOperation(c[1], addC[1]);

		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void PerformOperation(GLfloat& number, bool &addNumber)
{
	if (number >= 1.0f)
	{
		addNumber = false;
	}

	if (number <= -1.0f)
	{
		addNumber = true;
	}

	if (addNumber)
	{
		AddNumber(number);
	}
	else
	{
		SubNumber(number);
	}
}

void AddNumber(GLfloat &number)
{
	number += 0.01f;
}

void SubNumber(GLfloat& number)
{
	number -= 0.01f;
}