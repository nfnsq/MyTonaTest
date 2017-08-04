#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <random>
#include <stdlib.h>
#include <regex>
#include <memory.h>

int task1();
int task2();
int task3();
int task4();
int task5();

void PrintArray(int *array, int arraySize);

int MaxElemInArray(int *array, int arraySize);

struct mat4 {
	mat4() {
		memset(m, 0, sizeof(float) * 16);
		m[0] = m[5] = m[10] = m[15] = 1.0f;
	}

	float m[16];
};

struct vec3 {
	vec3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	float x;
	float y;
	float z;
};

struct vec4 {
	vec4(float _a, float _b, float _c, float _d) {
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}

	float a;
	float b;
	float c;
	float d;
};

vec3 multiply(mat4 matrix, vec3 vec);

