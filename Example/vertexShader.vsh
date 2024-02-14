//attribute lowp vec4 colAttr;
uniform mat4 mvpMatrix;
in vec4 vertex;
varying lowp vec4 color;
in vec2 textureCoordinate;
varying vec2 varyingTextureCoordinate;

void main(void)
{
    //color = colAttr;
    varyingTextureCoordinate = textureCoordinate;
    gl_Position = mvpMatrix * vertex;
}
