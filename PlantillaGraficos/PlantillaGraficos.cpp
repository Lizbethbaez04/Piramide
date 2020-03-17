// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>
#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include <vector>

using namespace std;

//Cada elemento que se quiera renderear necesita un vertex arrary y un buffer

vector<Vertice> suelo;
GLuint vertexArraySueloID;
GLuint bufferSueloID;

vector<Vertice> nubes;
GLuint vertexArrayNubesID;
GLuint bufferNubesID;

vector<Vertice> piramide;
GLuint vertexArrayPiramideID;
GLuint bufferPiramideID;

//Instancia del shader
Shader *shader;
//Identificadores para mapeo de atributos de entrada del vertex shader
GLuint posicionID;
GLuint colorID;


void inicializarSuelo()
{
	Vertice v1 =
	{
		vec3(-1.0f, -1.0f, 0.0f),
		vec4(0.1f, 0.8f, 0.2f, 1.0f)
	};
	Vertice v2 =
	{
		vec3(1.0f, -1.0f, 0.0f),
		vec4(0.1f, 0.8f, 0.2f, 1.0f)
	};
	Vertice v3 =
	{
		vec3(1.0f, -0.5f, 0.0f),
		vec4(0.1f, 0.8f, 0.2f, 1.0f)
	};
	Vertice v4 =
	{
		vec3(-1.0f, -0.5f, 0.0f),
		vec4(0.1f, 0.8f, 0.2f, 1.0f)
	};
	suelo.push_back(v1);
	suelo.push_back(v2);
	suelo.push_back(v3);
	suelo.push_back(v4);
}

void inicializarNubes()
{
	for(double i = 0; i < 360.0; i += 9.0)
	{
		Vertice v1 =
		{
			vec3((0.28 * cos(i * 3.14159 / 180.0)) - 0.25, (0.065 * sin(i * 3.14159 / 180.0)) + 0.65, 0.0f),
			vec4(0.6745098039215686f, 0.8156862745098039f, 0.9058823529411765f, 1.0)
		};
		nubes.push_back(v1);
	}
	for (double i = 0; i < 360.0; i += 9.0)
	{
		Vertice v2 =
		{
			vec3((0.38 * cos(i * 3.14159 / 180.0)) - 0.35, (0.065 * sin(i * 3.14159 / 180.0)) + 0.6, 0.0f),
			vec4(0.6745098039215686f, 0.8156862745098039f, 0.9058823529411765f, 1.0)
		};
		nubes.push_back(v2);
	}
	for (double i = 0; i < 360.0; i += 9.0)
	{
		Vertice v3 =
		{
			vec3((0.48 * cos(i * 3.14159 / 180.0)) + 0.35, (0.065 * sin(i * 3.14159 / 180.0)) + 0.65, 0.0f),
			vec4(0.6745098039215686f, 0.8156862745098039f, 0.9058823529411765f, 1.0)
		};
		nubes.push_back(v3);
	}
}

void inicializarPiramide()
{
	Vertice v1 =
	{
		vec3(-0.6f, -0.5f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.6f, -0.6f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v3 =
	{
		vec3(0.6f, -0.6f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v4 =
	{
		vec3(0.6f, -0.5f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v5 =
	{
		vec3(0.55f, -0.5f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v6 =
	{
		vec3(-0.55f, -0.5f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v7 =
	{
		vec3(-0.55f, -0.4f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v8 =
	{
		vec3(0.55f, -0.4f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v9 =
	{
		vec3(0.5f, -0.4f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v10 =
	{
		vec3(-0.5f, -0.4f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v11 =
	{
		vec3(-0.5f, -0.3f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v12 =
	{
		vec3(0.5f, -0.3f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v13 =
	{
		vec3(0.45f, -0.3f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v14 =
	{
		vec3(-0.45f, -0.3f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v15 =
	{
		vec3(-0.45f, -0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v16 =
	{
		vec3(0.45f, -0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v17 =
	{
		vec3(0.4f, -0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v18 =
	{
		vec3(-0.4f, -0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v19 =
	{
		vec3(-0.4f, -0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v20 =
	{
		vec3(0.4f, -0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v21 =
	{
		vec3(0.35f, -0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v22 =
	{
		vec3(-0.35f, -0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v23 =
	{
		vec3(-0.35f, 0.0f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v24 =
	{
		vec3(0.35f, 0.0f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v25 =
	{
		vec3(0.3f, 0.0f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v26 =
	{
		vec3(-0.3f, 0.0f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v27 =
	{
		vec3(-0.3f, 0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v28 =
	{
		vec3(0.3f, 0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v29 =
	{
		vec3(0.25f, 0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v30 =
	{
		vec3(-0.25f, 0.1f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v31 =
	{
		vec3(-0.25f, 0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v32 =
	{
		vec3(0.25f, 0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v33 =
	{
		vec3(0.1f, 0.2f, 0.0f),
		vec4(0.803921568627451f,0.7294117647058824f,0.3254901960784314f, 1.0f)
	};
	Vertice v34 =
	{
		vec3(-0.1f, 0.2f, 0.0f),
		vec4(0.803921568627451f,0.7294117647058824f,0.3254901960784314f, 1.0f)
	};
	Vertice v35 =
	{
		vec3(-0.1f, -0.6f, 0.0f),
		vec4(0.803921568627451f,0.7294117647058824f,0.3254901960784314f, 1.0f)
	};
	Vertice v36 =
	{
		vec3(0.1f, -0.6f, 0.0f),
		vec4(0.803921568627451f,0.7294117647058824f,0.3254901960784314f, 1.0f)
	};
	Vertice v37 =
	{
		vec3(0.15f, 0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v38 =
	{
		vec3(-0.15f, 0.2f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v39 =
	{
		vec3(-0.15f, 0.4f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};
	Vertice v40 =
	{
		vec3(0.15f, 0.4f, 0.0f),
		vec4(0.8705882352941176f, 0.7882352941176471f,0.3490196078431373f, 1.0f)
	};

	piramide.push_back(v1);
	piramide.push_back(v2);
	piramide.push_back(v3);
	piramide.push_back(v4);
	piramide.push_back(v5);
	piramide.push_back(v6);
	piramide.push_back(v7);
	piramide.push_back(v8);
	piramide.push_back(v9);
	piramide.push_back(v10);
	piramide.push_back(v11);
	piramide.push_back(v12);
	piramide.push_back(v13);
	piramide.push_back(v14);
	piramide.push_back(v15);
	piramide.push_back(v16);
	piramide.push_back(v17);
	piramide.push_back(v18);
	piramide.push_back(v19);
	piramide.push_back(v20);
	piramide.push_back(v21);
	piramide.push_back(v22);
	piramide.push_back(v23);
	piramide.push_back(v24);
	piramide.push_back(v25);
	piramide.push_back(v26);
	piramide.push_back(v27);
	piramide.push_back(v28);
	piramide.push_back(v29);
	piramide.push_back(v30);
	piramide.push_back(v31);
	piramide.push_back(v32);
	piramide.push_back(v33);
	piramide.push_back(v34);
	piramide.push_back(v35);
	piramide.push_back(v36);
	piramide.push_back(v37);
	piramide.push_back(v38);
	piramide.push_back(v39);
	piramide.push_back(v40);
}


void dibujar()
{
	//Elegir shader
	shader->enlazar();
	//Elegir el vertexArray 
	//Llamar la funcion de dibujo-Dibujar

	//Suelo
	glBindVertexArray(vertexArraySueloID);
	glDrawArrays(GL_QUADS, 0, suelo.size());
	//Piramide
	glBindVertexArray(vertexArrayPiramideID);
	glDrawArrays(GL_QUADS, 0, piramide.size());//tipo de primitiva de dibujo, leerlo desde el principio, cuantos elementos tiene el vertexarray
	//Nubes
	glBindVertexArray(vertexArrayNubesID);
	glDrawArrays(GL_POLYGON, 0, nubes.size());
	//Soltar Bind
	glBindVertexArray(0);
	//Soltar/desenlazar Shader
	shader->desenlazar();
}

int main()
{
    //Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW terminamos ejecucion
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW, inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);
	//Si no se pudo crear la ventana, terminamos la ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto, se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);

	cout << "Version OpenGL: " << versionGL;
	
	inicializarNubes();
	
	inicializarSuelo();
	inicializarPiramide();

	const char* rutaVertexShader = "VertexShader.shader";
	const char* rutaFragmentShader = "FragmentShader.shader";
	shader = new Shader(rutaVertexShader, rutaFragmentShader);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	shader->desenlazar();

	//Crear el vertex array del triangulo
	//Vertex buffer	
	//Asociar datos al buffer	
	//Habilitar atributos de shader	
	//Especificar a openGL cómo comunicarse


	//Suelo
	glGenVertexArrays(1, &vertexArraySueloID);
	glBindVertexArray(vertexArraySueloID);
	glGenBuffers(1, &bufferSueloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferSueloID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * suelo.size(), suelo.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Nubes
	glGenVertexArrays(1, &vertexArrayNubesID);
	glBindVertexArray(vertexArrayNubesID);
	glGenBuffers(1, &bufferNubesID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferNubesID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * nubes.size(), nubes.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Piramide
	glGenVertexArrays(1, &vertexArrayPiramideID);
	glBindVertexArray(vertexArrayPiramideID);
	glGenBuffers(1, &bufferPiramideID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPiramideID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)* piramide.size(), piramide.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	//Soltar el vertexArray y el buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.3254901960784314, 0.6156862745098039, 0.803921568627451, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo, eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}


