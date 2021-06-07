
//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name 	: ShaderLoader.h
// Description	: Header File for ShaderLoader
// Author 		: Himanshu Chawla | Callan Moore
// Mail 		: Himanshu.Cha8420
//
//Local Includes


#pragma once

// Dependency Includes
#include <glew.h>
#include <glm.hpp>
#include <freeglut.h>

// Library Includes
#include <iostream>

class ShaderLoader
{
	
public:	

	//Create program
	static GLuint CreateProgram(const char* VertexShaderFilename, const char* FragmentShaderFilename);

private:
	ShaderLoader(static void);
	~ShaderLoader(static void);
	
	
	static GLuint CreateShader(GLenum shaderType, const char* shaderName);
	static std::string ReadShaderFile(const char *filename);
	static void PrintErrorDetails(bool isShader, GLuint id, const char* name);


	// Setting vectors
	static void SetUniform(GLuint program, std::string sName, glm::vec2* vVectors, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const glm::vec2 vVector);
	static void SetUniform(GLuint program, std::string sName, glm::vec3* vVectors, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const glm::vec3 vVector);
	static void SetUniform(GLuint program, std::string sName, glm::vec4* vVectors, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const glm::vec4 vVector);

	// Setting floats
	static void SetUniform(GLuint program, std::string sName, float* fValues, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const float fValue);

	// Setting 3x3 matrices
	static void SetUniform(GLuint program, std::string sName, glm::mat3* mMatrices, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const glm::mat3 mMatrix);

	// Setting 4x4 matrices
	static void SetUniform(GLuint program, std::string sName, glm::mat4* mMatrices, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const glm::mat4 mMatrix);

	// Setting integers
	static void SetUniform(GLuint program, std::string sName, int* iValues, int iCount = 1);
	static void SetUniform(GLuint program, std::string sName, const int iValue);
	
};
