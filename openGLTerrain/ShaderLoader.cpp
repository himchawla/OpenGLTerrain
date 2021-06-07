
//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name 	: ShaderLoader.cpp
// Description	: ShaderLoader Class
// Author 		: Himanshu Chawla | Callan Moore
// Mail 		: Himanshu.Cha8420
//
//Implementation

#include "ShaderLoader.h" 
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <glm.hpp>

ShaderLoader::ShaderLoader(void){}
ShaderLoader::~ShaderLoader(void){}

GLuint ShaderLoader::CreateProgram(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
	// Create the shaders from the filepath
	
	GLuint vertexID = 0;
	GLuint fragmentID = 0;

	vertexID = CreateShader(GL_VERTEX_SHADER, vertexShaderFilename);
	fragmentID = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderFilename);

	// Create the program handle, attach the shaders and link it
	GLuint program = 0;
	// ...
	program = glCreateProgram();
	glAttachShader(program, vertexID);
	glAttachShader(program, fragmentID);
	glLinkProgram(program);

	// Check for link errors
	int link_result = 0;
	
	glGetProgramiv(program, GL_LINK_STATUS, &link_result);
	if (link_result == GL_FALSE)
	{
		std::string programName = vertexShaderFilename + *fragmentShaderFilename;
		PrintErrorDetails(false, program, programName.c_str());
		return 0;
	}
	return program;
}

GLuint ShaderLoader::CreateShader(GLenum shaderType, const char* shaderName)
{
	std::string shaderSource = ReadShaderFile(shaderName);
	// Read the shader files and save the source code as strings
	const GLchar *shaderData = shaderSource.c_str();
	const int shaderSize = shaderSource.size();

	// Create the shader ID and create pointers for source code string and length
	GLuint shaderID = 0;
	// ...
	shaderID = glCreateShader(shaderType);
	// Populate the Shader Object (ID) and compile
	glShaderSource(shaderID, 1, &shaderData, &shaderSize);
	glCompileShader(shaderID);


	// Check for errors
	int compile_result = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compile_result);
	if (compile_result == GL_FALSE)
	{
		PrintErrorDetails(true, shaderID, shaderName);
		return 0;
	}
	return shaderID;
}

std::string ShaderLoader::ReadShaderFile(const char *filename)
{
	// Open the file for reading
	std::ifstream file(filename, std::ios::in);
	std::string shaderCode;

	// Ensure the file is open and readable
	if (!file.good()) {
		std::cout << "Cannot read file:  " << filename << std::endl;
		return "";
	}

	// Determine the size of of the file in characters and resize the string variable to accomodate
	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());

	// Set the position of the next character to be read back to the beginning
	file.seekg(0, std::ios::beg);
	// Extract the contents of the file and store in the string variable
	file.read(&shaderCode[0], shaderCode.size());
	file.close();
	return shaderCode;
}

void ShaderLoader::PrintErrorDetails(bool isShader, GLuint id, const char* name)
{
	int infoLogLength = 0;
	// Retrieve the length of characters needed to contain the info log
	(isShader == true) ? glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLogLength) : glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> log(infoLogLength);

	// Retrieve the log info and populate log variable
	(isShader == true) ? glGetShaderInfoLog(id, infoLogLength, NULL, &log[0]) : glGetProgramInfoLog(id, infoLogLength, NULL, &log[0]);		
	std::cout << "Error compiling " << ((isShader == true) ? "shader" : "program") << ": " << name << std::endl;
	std::cout << &log[0] << std::endl;
}




void ShaderLoader::SetUniform(GLuint program, std::string sName, float* fValues, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform1fv(iLoc, iCount, fValues);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const float fValue)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform1fv(iLoc, 1, &fValue);
}

// Setting vectors

void ShaderLoader::SetUniform(GLuint program, std::string sName, glm::vec2* vVectors, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform2fv(iLoc, iCount, (GLfloat*)vVectors);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const glm::vec2 vVector)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform2fv(iLoc, 1, (GLfloat*)&vVector);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, glm::vec3* vVectors, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform3fv(iLoc, iCount, (GLfloat*)vVectors);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const glm::vec3 vVector)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform3fv(iLoc, 1, (GLfloat*)&vVector);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, glm::vec4* vVectors, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform4fv(iLoc, iCount, (GLfloat*)vVectors);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const glm::vec4 vVector)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform4fv(iLoc, 1, (GLfloat*)&vVector);
}

// Setting 3x3 matrices

void ShaderLoader::SetUniform(GLuint program, std::string sName, glm::mat3* mMatrices, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniformMatrix3fv(iLoc, iCount, FALSE, (GLfloat*)mMatrices);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const glm::mat3 mMatrix)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniformMatrix3fv(iLoc, 1, FALSE, (GLfloat*)&mMatrix);
}

// Setting 4x4 matrices

void ShaderLoader::SetUniform(GLuint program, std::string sName, glm::mat4* mMatrices, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniformMatrix4fv(iLoc, iCount, FALSE, (GLfloat*)mMatrices);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const glm::mat4 mMatrix)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniformMatrix4fv(iLoc, 1, FALSE, (GLfloat*)&mMatrix);
}

// Setting integers

void ShaderLoader::SetUniform(GLuint program, std::string sName, int* iValues, int iCount)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform1iv(iLoc, iCount, iValues);
}

void ShaderLoader::SetUniform(GLuint program, std::string sName, const int iValue)
{
	int iLoc = glGetUniformLocation(program, sName.c_str());
	glUniform1i(iLoc, iValue);
}
