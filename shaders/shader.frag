#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;

layout(set = 1, binding = 0) uniform sampler2D material;

layout(location = 0) out vec4 outColor;

void main() {
	outColor = vec4(fragColor, 1.0) * texture(material, fragTexCoord);
}
