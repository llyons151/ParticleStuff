#version 330 core
in vec3 vWorldPos;
out vec4 FragColor;

uniform vec3 viewPos; 

void main() {
    float d = length(vWorldPos - viewPos);
    float shade = 1.0 / (1.0 + 0.2 * d);
    vec3 base = vec3(18.0/255.0, 8.0/255.0, 1.0);
    FragColor = vec4(base * shade, 0.8);
}
