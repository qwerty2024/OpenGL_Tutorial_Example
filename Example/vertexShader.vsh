attribute lowp vec4 colAttr;
uniform mat4 mvpMatrix;
in vec4 vertex;
varying lowp vec4 color;

void main(void)
{
    color = colAttr;
    gl_Position = mvpMatrix * vertex;
}

