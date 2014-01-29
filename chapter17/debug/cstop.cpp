float point_color(int point_number) {
	float correction;
	extern float red, green, blue;

	extern float lookup(int point_number);

	correction = lookup(point_number);
	return (red * correction * 100.0 +
		blue * correction * 10.0 +
		green * correction);
}
