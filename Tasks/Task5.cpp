#include "Header.h"

vec3 multiply(mat4 matrix, vec3 vec) {
	vec3 result = vec3(0, 0, 0);

	result.x = matrix.m[0] * vec.x + matrix.m[1] * vec.y + matrix.m[2] * vec.z + matrix.m[3];
	result.y = matrix.m[4] * vec.x + matrix.m[5] * vec.y + matrix.m[6] * vec.z + matrix.m[7];
	result.z = matrix.m[8] * vec.x + matrix.m[9] * vec.y + matrix.m[10] * vec.z + matrix.m[11];

	return result;
}

int task5() {
	mat4 matrix;

	matrix.m[0] = 2.0f;
	matrix.m[5] = 1.5f;
	matrix.m[14] = 1.5f;

	vec3 vec = vec3(1.0f, 2.0f, 3.0f);
	vec3 result = multiply(matrix, vec);

	std::cout << "x = " << result.x << " y = " << result.y << " z = " << result.z << std::endl;
	
	system("pause");

	return 0;
}